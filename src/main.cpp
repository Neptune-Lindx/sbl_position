#include "sbl/base_id.hpp"
#include "sbl/mqtt_source.hpp"
#include "sbl/request.hpp"
#include "sbl/uncertainty.hpp"

#include <json/json.h>

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

namespace {

Json::Value point_json(const sbl::Vec3& point) {
    Json::Value value(Json::arrayValue);
    value.append(point.x);
    value.append(point.y);
    value.append(point.z);
    return value;
}

std::string compact_json(const Json::Value& root) {
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    builder["precision"] = 6;
    builder["precisionType"] = "decimal";
    return Json::writeString(builder, root);
}

std::string solve_and_report(const sbl::SolveRequest& request, const sbl::EvaluateFix& fix) {
    const sbl::PositionResult result = sbl::solve_request(request);
    std::cout << "algorithm: " << sbl::algorithm_name(request.stations) << '\n'
              << "status: " << sbl::status_name(result.status) << '\n'
              << "message: " << result.message << '\n'
              << "solutions: " << result.solution_count << '\n';
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);

    Json::Value base_ids(Json::arrayValue);
    std::cout << "base_ids:";
    for (int id : fix.bases.id) {
        base_ids.append(id);
        std::cout << ' ' << id;
    }
    std::cout << '\n';

    Json::Value message;
    message["schema"] = "sbl.position.v1";
    message["seq"] = fix.seq;
    message["transmitter_id"] = fix.transmitter_id;
    message["base_ids"] = base_ids;
    message["algorithm"] = sbl::algorithm_name(request.stations);
    message["status"] = sbl::status_name(result.status);
    message["message"] = result.message;
    message["solutions"] = result.solution_count;

    double height = fix.height;
    bool has_height = request.stations == sbl::StationCount::Two && fix.has_height;
    if (result.solution_count >= 1) {
        const sbl::Vec3& point = result.solutions[0];
        std::cout << "position: " << point.x << ' ' << point.y << ' ' << point.z << '\n';
        message["position"] = point_json(point);
        if (request.stations == sbl::StationCount::Three) {
            height = point.z;
            has_height = true;
            std::cout << "height: " << point.z << '\n';
        }
    }
    if (has_height) {
        message["height"] = height;
    }
    if (!(result.status == sbl::Status::Ok && result.solution_count >= 1)) {
        return compact_json(message);
    }

    const sbl::Uncertainty uncertainty = sbl::estimate_uncertainty(request);
    std::cout << "combinations: " << uncertainty.combination_count
              << " succeeded: " << uncertainty.success_count << '\n';
    message["combinations"] = uncertainty.combination_count;
    message["succeeded"] = uncertainty.success_count;
    if (uncertainty.success_count < 1) {
        std::cout << "uncertainty: unavailable\n";
        return compact_json(message);
    }
    const double max_error_x = std::abs(uncertainty.x_max - uncertainty.x_min);
    const double max_error_y = std::abs(uncertainty.y_max - uncertainty.y_min);
    std::cout << "max_error_x: " << max_error_x << '\n'
              << "max_error_y: " << max_error_y << '\n';
    message["max_error_x"] = max_error_x;
    message["max_error_y"] = max_error_y;
    if (uncertainty.has_z) {
        const double max_error_z = std::abs(uncertainty.z_max - uncertainty.z_min);
        std::cout << "max_error_z: " << max_error_z << '\n';
        message["max_error_z"] = max_error_z;
    }
    if (!uncertainty.sigma_ok) {
        std::cout << "sigma: unavailable\n";
        return compact_json(message);
    }
    std::cout << "sigma_x: " << uncertainty.sigma_x << '\n'
              << "sigma_y: " << uncertainty.sigma_y << '\n';
    message["sigma_x"] = uncertainty.sigma_x;
    message["sigma_y"] = uncertainty.sigma_y;
    if (uncertainty.has_z) {
        std::cout << "sigma_z: " << uncertainty.sigma_z << '\n';
        message["sigma_z"] = uncertainty.sigma_z;
    }
    return compact_json(message);
}

}  // namespace

int main(int argc, char** argv) {
    const char* path = argc >= 2 ? argv[1] : "config/triangulation.conf";
    sbl::SolveRequest request;
    std::string error;
    if (!sbl::load_request(path, request, error)) {
        std::cerr << error << '\n';
        return 2;
    }

    const char* host = std::getenv("MQTT_HOST");
    const char* port_text = std::getenv("MQTT_PORT");
    if (host == nullptr || host[0] == '\0') {
        host = "127.0.0.1";
    }
    int port = 1883;
    if (port_text != nullptr && port_text[0] != '\0') {
        port = std::atoi(port_text);
    }
    sbl::BaseRegistry registry("config/base_ids.conf");
    if (!registry.load(error)) {
        std::cerr << error << '\n';
        return 2;
    }
    sbl::MqttSubscriber subscriber;
    while (!subscriber.connect(host, port, "sbl-position", error) ||
           !subscriber.subscribe("sbl/evaluate", error) || !subscriber.subscribe("sbl/base/ack", error)) {
        std::cerr << error << "，2 秒后重试\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout << "mqtt: " << host << ':' << port
              << " subscribe sbl/evaluate sbl/base/ack publish sbl/position sbl/base/assign\n";

    for (;;) {
        std::string topic;
        std::string payload;
        if (!subscriber.read_publish(topic, payload, error)) {
            std::cerr << error << '\n';
            return 2;
        }
        if (topic == "sbl/base/ack") {
            std::string summary;
            if (!registry.apply_ack(payload, summary, error)) {
                std::cerr << error << '\n';
                continue;
            }
            if (!summary.empty()) {
                std::cout << summary << '\n';
            }
            continue;
        }
        if (topic != "sbl/evaluate") {
            continue;
        }
        sbl::EvaluateFix fix;
        std::vector<sbl::LayoutReceiver> receivers;
        if (!sbl::read_evaluate(payload, request, fix, receivers, error)) {
            std::cerr << "seq " << fix.seq << ": " << error << '\n';
            continue;
        }
        std::vector<sbl::AssignRequest> pending;
        if (!registry.observe(receivers, pending, error)) {
            std::cerr << error << '\n';
            continue;
        }
        bool publish_failed = false;
        for (const sbl::AssignRequest& assign : pending) {
            if (!subscriber.publish("sbl/base/assign", sbl::assign_message(assign), error)) {
                std::cerr << error << '\n';
                publish_failed = true;
                break;
            }
            std::cout << "published: sbl/base/assign base_id " << assign.base_id << " receiver "
                      << assign.receiver_id << '\n';
        }
        if (publish_failed) {
            return 2;
        }
        if (!sbl::apply_confirmed_bases(registry, receivers, request, fix.bases, error)) {
            std::cerr << "seq " << fix.seq << ": " << error << '\n';
            continue;
        }
        std::cout << "seq: " << fix.seq << " transmitter: " << fix.transmitter_id << '\n';
        if (request.stations == sbl::StationCount::Two && fix.has_height) {
            std::cout.setf(std::ios::fixed);
            std::cout.precision(6);
            std::cout << "height: " << fix.height << '\n';
        }
        const std::string outbound = solve_and_report(request, fix);
        if (!subscriber.publish("sbl/position", outbound, error)) {
            std::cerr << error << '\n';
            return 2;
        }
        std::cout << "published: sbl/position seq " << fix.seq << '\n';
    }
}

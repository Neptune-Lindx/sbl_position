#include "sbl/mqtt_source.hpp"
#include "sbl/request.hpp"
#include "sbl/uncertainty.hpp"

#include <json/json.h>

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

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

    Json::Value message;
    message["schema"] = "sbl.position.v1";
    message["seq"] = fix.seq;
    message["transmitter_id"] = fix.transmitter_id;
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
    sbl::MqttSubscriber subscriber;
    if (!subscriber.connect(host, port, "sbl-position", error) ||
        !subscriber.subscribe("sbl/evaluate", error)) {
        std::cerr << error << '\n';
        return 2;
    }
    std::cout << "mqtt: " << host << ':' << port << " subscribe sbl/evaluate publish sbl/position\n";

    for (;;) {
        std::string topic;
        std::string payload;
        if (!subscriber.read_publish(topic, payload, error)) {
            std::cerr << error << '\n';
            return 2;
        }
        sbl::EvaluateFix fix;
        if (!sbl::apply_evaluate_payload(payload, request, fix, error)) {
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

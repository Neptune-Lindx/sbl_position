#include "sbl/mqtt_source.hpp"

#include <json/json.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>

namespace sbl {
namespace {

std::string encode_remaining(std::size_t length) {
    std::string out;
    do {
        unsigned char byte = static_cast<unsigned char>(length % 128);
        length /= 128;
        if (length > 0) {
            byte = static_cast<unsigned char>(byte | 0x80);
        }
        out.push_back(static_cast<char>(byte));
    } while (length > 0);
    return out;
}

void append_mqtt_string(std::string& packet, const std::string& text) {
    packet.push_back(static_cast<char>((text.size() >> 8) & 0xff));
    packet.push_back(static_cast<char>(text.size() & 0xff));
    packet += text;
}

bool read_u16(const std::string& body, std::size_t& offset, int& value) {
    if (offset + 2 > body.size()) {
        return false;
    }
    value = (static_cast<unsigned char>(body[offset]) << 8) |
            static_cast<unsigned char>(body[offset + 1]);
    offset += 2;
    return true;
}

const Json::Value* find_result(const Json::Value& root, std::string& error) {
    const Json::Value& results = root["results"];
    if (!results.isArray() || results.empty()) {
        error = "报文没有 results";
        return nullptr;
    }
    const Json::Value* fallback = nullptr;
    for (const Json::Value& item : results) {
        if (!item.isObject() || !item.get("ok", false).asBool()) {
            continue;
        }
        if (fallback == nullptr) {
            fallback = &item;
        }
        if (item.get("role", "").asString() == "robot") {
            return &item;
        }
    }
    if (fallback == nullptr) {
        error = "报文中没有成功的定位结果";
        return nullptr;
    }
    return fallback;
}

}  // namespace

MqttSubscriber::~MqttSubscriber() {
    if (fd_ >= 0) {
        ::close(fd_);
    }
}

bool MqttSubscriber::send_all(const unsigned char* data, std::size_t size, std::string& error) {
    std::size_t sent = 0;
    while (sent < size) {
        const ssize_t n = ::send(fd_, data + sent, size - sent, 0);
        if (n <= 0) {
            error = "MQTT 发送失败";
            return false;
        }
        sent += static_cast<std::size_t>(n);
    }
    return true;
}

bool MqttSubscriber::connect(const std::string& host, int port, const std::string& client_id,
                             std::string& error) {
    addrinfo hints{};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    addrinfo* result = nullptr;
    const std::string port_text = std::to_string(port);
    if (getaddrinfo(host.c_str(), port_text.c_str(), &hints, &result) != 0) {
        error = "无法解析 MQTT 地址: " + host;
        return false;
    }
    int fd = -1;
    for (addrinfo* item = result; item != nullptr; item = item->ai_next) {
        fd = ::socket(item->ai_family, item->ai_socktype, item->ai_protocol);
        if (fd < 0) {
            continue;
        }
        if (::connect(fd, item->ai_addr, item->ai_addrlen) == 0) {
            break;
        }
        ::close(fd);
        fd = -1;
    }
    freeaddrinfo(result);
    if (fd < 0) {
        error = "无法连接 MQTT Broker " + host + ":" + port_text;
        return false;
    }
    fd_ = fd;

    std::string variable;
    append_mqtt_string(variable, "MQTT");
    variable.push_back(4);
    variable.push_back(0x02);
    variable.push_back(0);
    variable.push_back(60);
    append_mqtt_string(variable, client_id);
    std::string packet;
    packet.push_back(0x10);
    packet += encode_remaining(variable.size());
    packet += variable;
    std::string body;
    unsigned char header = 0;
    if (!send_all(reinterpret_cast<const unsigned char*>(packet.data()), packet.size(), error) ||
        !read_packet(header, body, error)) {
        return false;
    }
    if (header != 0x20 || body.size() < 2 || static_cast<unsigned char>(body[1]) != 0) {
        error = "MQTT 连接被拒绝";
        return false;
    }
    return true;
}

bool MqttSubscriber::subscribe(const std::string& topic, std::string& error) {
    std::string variable;
    variable.push_back(0);
    variable.push_back(1);
    append_mqtt_string(variable, topic);
    variable.push_back(0);
    std::string packet;
    packet.push_back(static_cast<char>(0x82));
    packet += encode_remaining(variable.size());
    packet += variable;
    if (!send_all(reinterpret_cast<const unsigned char*>(packet.data()), packet.size(), error)) {
        return false;
    }
    unsigned char header = 0;
    std::string body;
    if (!read_packet(header, body, error)) {
        return false;
    }
    if (header != 0x90 || body.size() < 3 || static_cast<unsigned char>(body[2]) > 2) {
        error = "订阅 " + topic + " 失败";
        return false;
    }
    return true;
}

bool MqttSubscriber::publish(const std::string& topic, const std::string& payload, std::string& error) {
    std::string variable;
    append_mqtt_string(variable, topic);
    variable += payload;
    std::string packet;
    packet.push_back(0x30);
    packet += encode_remaining(variable.size());
    packet += variable;
    return send_all(reinterpret_cast<const unsigned char*>(packet.data()), packet.size(), error);
}

bool MqttSubscriber::read_packet(unsigned char& header, std::string& body, std::string& error) {
    unsigned char first = 0;
    if (::recv(fd_, &first, 1, MSG_WAITALL) != 1) {
        error = "MQTT 连接已断开";
        return false;
    }
    header = first;
    std::size_t value = 0;
    int multiplier = 1;
    for (int i = 0; i < 4; ++i) {
        unsigned char byte = 0;
        if (::recv(fd_, &byte, 1, MSG_WAITALL) != 1) {
            error = "MQTT 报文长度不完整";
            return false;
        }
        value += static_cast<std::size_t>(byte & 0x7f) * static_cast<std::size_t>(multiplier);
        if ((byte & 0x80) == 0) {
            break;
        }
        multiplier *= 128;
        if (i == 3) {
            error = "MQTT 剩余长度非法";
            return false;
        }
    }
    body.assign(value, '\0');
    std::size_t got = 0;
    while (got < value) {
        const ssize_t n = ::recv(fd_, body.data() + got, value - got, 0);
        if (n <= 0) {
            error = "MQTT 报文不完整";
            return false;
        }
        got += static_cast<std::size_t>(n);
    }
    return true;
}

bool MqttSubscriber::read_publish(std::string& topic, std::string& payload, std::string& error) {
    for (;;) {
        unsigned char header = 0;
        std::string body;
        if (!read_packet(header, body, error)) {
            return false;
        }
        const unsigned char type = static_cast<unsigned char>(header & 0xf0);
        if (type == 0xc0) {
            const unsigned char pingresp[] = {0xd0, 0x00};
            if (!send_all(pingresp, sizeof pingresp, error)) {
                return false;
            }
            continue;
        }
        if (type != 0x30) {
            continue;
        }
        std::size_t offset = 0;
        int topic_length = 0;
        if (!read_u16(body, offset, topic_length) || offset + static_cast<std::size_t>(topic_length) > body.size()) {
            error = "PUBLISH 主题长度非法";
            return false;
        }
        topic.assign(body, offset, static_cast<std::size_t>(topic_length));
        offset += static_cast<std::size_t>(topic_length);
        const int qos = (header >> 1) & 0x03;
        if (qos > 0) {
            if (offset + 2 > body.size()) {
                error = "PUBLISH 缺少报文标识";
                return false;
            }
            offset += 2;
        }
        payload.assign(body, offset, std::string::npos);
        return true;
    }
}

bool apply_evaluate_payload(const std::string& payload, SolveRequest& request, EvaluateFix& fix,
                            std::string& error) {
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    Json::Value root;
    std::string parse_error;
    std::istringstream input(payload);
    if (!Json::parseFromStream(builder, input, &root, &parse_error) || !root.isObject()) {
        error = "评估报文不是 JSON 对象";
        return false;
    }
    fix.seq = root.get("seq", 0).asInt();
    const std::string schema = root.get("schema", "").asString();
    if (schema != "sbl.evaluate.v1" && schema != "sbl.evaluate.v2") {
        error = "不支持的 schema: " + schema;
        return false;
    }
    const Json::Value* result = find_result(root, error);
    if (result == nullptr) {
        return false;
    }
    fix.transmitter_id = result->get("transmitter_id", "").asString();
    fix.has_height = false;
    if ((*result)["z"].isNumeric()) {
        fix.height = (*result)["z"].asDouble();
        fix.has_height = true;
    }
    const Json::Value& transmitters = root["layout"]["transmitters"];
    if (!fix.has_height && transmitters.isArray()) {
        for (const Json::Value& transmitter : transmitters) {
            if (transmitter.get("id", "").asString() != fix.transmitter_id || !transmitter["z"].isNumeric()) {
                continue;
            }
            fix.height = transmitter["z"].asDouble();
            fix.has_height = true;
            break;
        }
    }
    if (!fix.has_height) {
        const Json::Value& position = (*result)["position"];
        if (position.isArray() && position.size() >= 3 && position[2].isNumeric()) {
            fix.height = position[2].asDouble();
            fix.has_height = true;
        }
    }
    if (request.stations == StationCount::Two) {
        if (!fix.has_height || !std::isfinite(fix.height)) {
            error = "报文缺少发射信标高度";
            return false;
        }
        request.slant_range.set_mobile_height(fix.height);
    }

    std::vector<std::pair<std::string, double>> ranges;
    const Json::Value& range_rows = (*result)["ranges"];
    if (!range_rows.isArray()) {
        error = "结果缺少 ranges";
        return false;
    }
    for (const Json::Value& row : range_rows) {
        if (!row.get("used", false).asBool() || !row.get("los", false).asBool()) {
            continue;
        }
        if (!row["range_m"].isNumeric() || !row["receiver_id"].isString()) {
            error = "斜距字段无效";
            return false;
        }
        ranges.emplace_back(row["receiver_id"].asString(), row["range_m"].asDouble());
    }

    const Json::Value& receivers = root["layout"]["receivers"];
    if (!receivers.isArray()) {
        error = "报文缺少 layout.receivers";
        return false;
    }
    struct Station {
        Vec3 position;
        double range{0.0};
    };
    std::vector<Station> stations;
    for (const Json::Value& receiver : receivers) {
        const std::string id = receiver.get("id", "").asString();
        const auto found = std::find_if(ranges.begin(), ranges.end(),
                                         [&](const std::pair<std::string, double>& item) { return item.first == id; });
        if (found == ranges.end()) {
            continue;
        }
        if (!receiver["x"].isNumeric() || !receiver["y"].isNumeric() || !receiver["z"].isNumeric()) {
            error = "基站 " + id + " 坐标无效";
            return false;
        }
        stations.push_back(Station{Vec3{receiver["x"].asDouble(), receiver["y"].asDouble(), receiver["z"].asDouble()},
                                   found->second});
    }

    const int need = request.stations == StationCount::Three ? 3 : 2;
    if (static_cast<int>(stations.size()) < need) {
        error = "已使用的直视斜距只有 " + std::to_string(stations.size()) + " 条，需要 " + std::to_string(need);
        return false;
    }
    request.triangulation.set_base_a(stations[0].position);
    request.slant_range.set_base_a(stations[0].position);
    request.triangulation.set_slant_range_a(stations[0].range);
    request.slant_range.set_slant_range_a(stations[0].range);
    request.triangulation.set_base_b(stations[1].position);
    request.slant_range.set_base_b(stations[1].position);
    request.triangulation.set_slant_range_b(stations[1].range);
    request.slant_range.set_slant_range_b(stations[1].range);
    if (need == 3) {
        request.triangulation.set_base_c(stations[2].position);
        request.triangulation.set_slant_range_c(stations[2].range);
    }
    return true;
}

}  // namespace sbl

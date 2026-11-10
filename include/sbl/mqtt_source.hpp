#pragma once

#include "sbl/request.hpp"

#include <string>

namespace sbl {

struct EvaluateFix {
    int seq{0};
    std::string transmitter_id;
    double height{0.0};
    bool has_height{false};
};

// 从 sbl.evaluate.v1 报文写入基站坐标和已使用的斜距。
// stations 为 3 时按 receivers 顺序取前 3 条，为 2 时取前 2 条。
// 接受 sbl.evaluate.v1 与 v2。双站的已知高度优先取结果里的 z。
bool apply_evaluate_payload(const std::string& payload, SolveRequest& request, EvaluateFix& fix,
                            std::string& error);

class MqttSubscriber {
public:
    MqttSubscriber() = default;
    ~MqttSubscriber();

    MqttSubscriber(const MqttSubscriber&) = delete;
    MqttSubscriber& operator=(const MqttSubscriber&) = delete;

    bool connect(const std::string& host, int port, const std::string& client_id, std::string& error);
    bool subscribe(const std::string& topic, std::string& error);
    // QoS 0，不保留。
    bool publish(const std::string& topic, const std::string& payload, std::string& error);
    // QoS 0 的 PUBLISH。收到断开或协议错误时返回 false。
    bool read_publish(std::string& topic, std::string& payload, std::string& error);

private:
    int fd_{-1};

    bool send_all(const unsigned char* data, std::size_t size, std::string& error);
    bool read_packet(unsigned char& header, std::string& body, std::string& error);
};

}  // namespace sbl

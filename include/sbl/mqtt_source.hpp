#pragma once

#include "sbl/base_id.hpp"
#include "sbl/request.hpp"

#include <string>
#include <vector>

namespace sbl {

struct EvaluateFix {
    int seq{0};
    std::string transmitter_id;
    double height{0.0};
    bool has_height{false};
    UsedBaseIds bases;
};

// 从 sbl.evaluate.v1 或 v2 取出本轮基站、斜距和高度。不按数组顺序填 A、B、C。
bool read_evaluate(const std::string& payload, SolveRequest& request, EvaluateFix& fix,
                   std::vector<LayoutReceiver>& receivers, std::string& error);

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

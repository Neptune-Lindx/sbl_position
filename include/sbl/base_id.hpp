#pragma once

#include "sbl/request.hpp"

#include <string>
#include <utility>
#include <vector>

namespace sbl {

struct LayoutReceiver {
    std::string receiver_id;
    std::string name;
    int base_id{0};
    bool has_base_id{false};
    Vec3 position{};
    double range{0.0};
    bool has_range{false};
};

// 本次解算用到的指定站号。固定 4 个，没用到的为 0。
struct UsedBaseIds {
    static constexpr int count = 4;
    int id[count]{0, 0, 0, 0};
};

struct AssignRequest {
    int base_id{0};
    std::string receiver_id;
    std::string name;
};

// 持久站号表。receiver_id 认站，base_id 一旦写出就不再改。
class BaseRegistry {
public:
    explicit BaseRegistry(std::string path);

    // 文件不存在时从 next_id 1 开始。
    bool load(std::string& error);
    bool observe(const std::vector<LayoutReceiver>& receivers, std::vector<AssignRequest>& pending,
                 std::string& error);
    // accepted 与 already_set 且站号一致时写成已完成。rejected 或站号不一致保持待确认。
    bool apply_ack(const std::string& payload, std::string& summary, std::string& error);

    bool confirmed(int base_id, std::string& receiver_id) const;
    std::vector<std::pair<int, std::string>> confirmed_stations() const;

private:
    struct Record {
        int base_id{0};
        std::string receiver_id;
        bool confirmed{false};
    };

    std::string path_;
    int next_id_{1};
    std::vector<Record> records_;

    Record* find_receiver(const std::string& receiver_id);
    const Record* find_receiver(const std::string& receiver_id) const;
    bool save(std::string& error) const;
};

std::string assign_message(const AssignRequest& request);

// 三站用已完成的 1、2、3。双站取 Y 轴之差绝对值最大的两座有效站，站号较小的在前。不足两座时返回 false。
bool apply_confirmed_bases(const BaseRegistry& registry, const std::vector<LayoutReceiver>& receivers,
                           SolveRequest& request, UsedBaseIds& used, std::string& error);

}  // namespace sbl

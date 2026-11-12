#include "sbl/base_id.hpp"

#include <json/json.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>

namespace sbl {
namespace {

std::string trim_copy(const std::string& text) {
    const auto begin = text.find_first_not_of(" \t\r");
    if (begin == std::string::npos) {
        return {};
    }
    const auto end = text.find_last_not_of(" \t\r");
    return text.substr(begin, end - begin + 1);
}

bool parse_positive_int(const std::string& text, int& value) {
    if (text.empty()) {
        return false;
    }
    char* end = nullptr;
    const long parsed = std::strtol(text.c_str(), &end, 10);
    if (end == text.c_str() || *end != '\0' || parsed <= 0 || parsed > 1000000) {
        return false;
    }
    value = static_cast<int>(parsed);
    return true;
}

}  // namespace

BaseRegistry::BaseRegistry(std::string path) : path_(std::move(path)) {}

BaseRegistry::Record* BaseRegistry::find_receiver(const std::string& receiver_id) {
    for (Record& record : records_) {
        if (record.receiver_id == receiver_id) {
            return &record;
        }
    }
    return nullptr;
}

const BaseRegistry::Record* BaseRegistry::find_receiver(const std::string& receiver_id) const {
    for (const Record& record : records_) {
        if (record.receiver_id == receiver_id) {
            return &record;
        }
    }
    return nullptr;
}

bool BaseRegistry::load(std::string& error) {
    records_.clear();
    next_id_ = 1;
    std::ifstream in(path_);
    if (!in) {
        return true;
    }
    bool seen_next = false;
    std::string line;
    int line_no = 0;
    while (std::getline(in, line)) {
        ++line_no;
        const auto comment = line.find('#');
        if (comment != std::string::npos) {
            line = line.substr(0, comment);
        }
        line = trim_copy(line);
        if (line.empty()) {
            continue;
        }
        std::istringstream row(line);
        std::string first;
        row >> first;
        if (first == "next_id") {
            std::string value;
            if (seen_next || !(row >> value) || !parse_positive_int(value, next_id_) || row >> value) {
                error = "编号表第 " + std::to_string(line_no) + " 行 next_id 无效";
                return false;
            }
            seen_next = true;
            continue;
        }
        int base_id = 0;
        std::string receiver_id;
        std::string state;
        if (!parse_positive_int(first, base_id) || !(row >> receiver_id >> state) || (row >> first)) {
            error = "编号表第 " + std::to_string(line_no) + " 行无法解析";
            return false;
        }
        if (receiver_id.find_first_of(" \t") != std::string::npos ||
            (state != "confirmed" && state != "pending")) {
            error = "编号表第 " + std::to_string(line_no) + " 行状态无效";
            return false;
        }
        if (find_receiver(receiver_id) != nullptr) {
            error = "编号表中 receiver_id 重复: " + receiver_id;
            return false;
        }
        for (const Record& record : records_) {
            if (record.base_id == base_id) {
                error = "编号表中 base_id 重复: " + std::to_string(base_id);
                return false;
            }
        }
        records_.push_back(Record{base_id, receiver_id, state == "confirmed"});
    }
    int max_id = 0;
    for (const Record& record : records_) {
        if (record.base_id > max_id) {
            max_id = record.base_id;
        }
    }
    if (next_id_ <= max_id) {
        error = "next_id 必须大于已有站号";
        return false;
    }
    return true;
}

bool BaseRegistry::save(std::string& error) const {
    const std::string temporary = path_ + ".tmp";
    std::ofstream out(temporary, std::ios::trunc);
    if (!out) {
        error = "无法写入 " + temporary;
        return false;
    }
    out << "next_id " << next_id_ << '\n';
    for (const Record& record : records_) {
        out << record.base_id << ' ' << record.receiver_id << ' '
            << (record.confirmed ? "confirmed" : "pending") << '\n';
    }
    out.close();
    if (!out) {
        error = "写入编号表失败";
        return false;
    }
    if (std::rename(temporary.c_str(), path_.c_str()) != 0) {
        error = "无法替换编号表 " + path_;
        return false;
    }
    return true;
}

bool BaseRegistry::observe(const std::vector<LayoutReceiver>& receivers, std::vector<AssignRequest>& pending,
                           std::string& error) {
    pending.clear();
    const std::vector<Record> saved_records = records_;
    const int saved_next = next_id_;
    std::unordered_map<std::string, std::size_t> index;
    index.reserve(records_.size() + receivers.size());
    for (std::size_t i = 0; i < records_.size(); ++i) {
        index.emplace(records_[i].receiver_id, i);
    }
    bool dirty = false;
    for (const LayoutReceiver& receiver : receivers) {
        if (receiver.receiver_id.empty() || index.find(receiver.receiver_id) != index.end()) {
            continue;
        }
        records_.push_back(Record{next_id_, receiver.receiver_id, false});
        index.emplace(receiver.receiver_id, records_.size() - 1);
        ++next_id_;
        dirty = true;
    }
    if (dirty && !save(error)) {
        records_ = saved_records;
        next_id_ = saved_next;
        return false;
    }
    std::unordered_map<std::string, bool> listed;
    listed.reserve(receivers.size());
    for (const LayoutReceiver& receiver : receivers) {
        const auto found = index.find(receiver.receiver_id);
        if (found == index.end() || !listed.emplace(receiver.receiver_id, true).second) {
            continue;
        }
        const Record& record = records_[found->second];
        pending.push_back(AssignRequest{record.base_id, record.receiver_id, receiver.name});
    }
    return true;
}

bool BaseRegistry::apply_ack(const std::string& payload, std::string& summary, std::string& error) {
    summary.clear();
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    Json::Value root;
    std::string parse_error;
    std::istringstream input(payload);
    if (!Json::parseFromStream(builder, input, &root, &parse_error) || !root.isObject()) {
        error = "基站应答不是 JSON 对象";
        return false;
    }
    if (root.get("schema", "").asString() != "sbl.base_ack.v1") {
        error = "不支持的应答 schema";
        return false;
    }
    if (!root["receiver_id"].isString() || !root["base_id"].isInt() || !root["result"].isString()) {
        error = "基站应答字段无效";
        return false;
    }
    const std::string receiver_id = root["receiver_id"].asString();
    const int base_id = root["base_id"].asInt();
    const std::string result = root["result"].asString();
    Record* record = find_receiver(receiver_id);
    if (record == nullptr) {
        error = "应答的基站不在编号表中: " + receiver_id;
        return false;
    }
    if (record->base_id != base_id) {
        error = "应答站号与待确认站号不一致: " + receiver_id;
        return false;
    }
    if (result == "rejected") {
        summary = "base_id " + std::to_string(base_id) + " 被拒绝 " + receiver_id;
        return true;
    }
    if (result != "accepted" && result != "already_set") {
        error = "应答 result 无效: " + result;
        return false;
    }
    if (record->confirmed) {
        return true;
    }
    record->confirmed = true;
    if (!save(error)) {
        record->confirmed = false;
        return false;
    }
    summary = "base_id " + std::to_string(base_id) + " 已完成 " + receiver_id;
    return true;
}

bool BaseRegistry::confirmed(int base_id, std::string& receiver_id) const {
    for (const Record& record : records_) {
        if (record.base_id == base_id && record.confirmed) {
            receiver_id = record.receiver_id;
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int, std::string>> BaseRegistry::confirmed_stations() const {
    std::vector<std::pair<int, std::string>> stations;
    for (const Record& record : records_) {
        if (record.confirmed) {
            stations.emplace_back(record.base_id, record.receiver_id);
        }
    }
    return stations;
}

std::string assign_message(const AssignRequest& request) {
    Json::Value root;
    root["schema"] = "sbl.base_assign.v1";
    root["receiver_id"] = request.receiver_id;
    root["name"] = request.name;
    root["base_id"] = request.base_id;
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    return Json::writeString(builder, root);
}

namespace {

bool measurement_usable(const LayoutReceiver& receiver) {
    if (!receiver.has_range || !std::isfinite(receiver.range) || receiver.range == 0.0) {
        return false;
    }
    const Vec3& position = receiver.position;
    if (!std::isfinite(position.x) || !std::isfinite(position.y) || !std::isfinite(position.z)) {
        return false;
    }
    return position.x != 0.0 || position.y != 0.0 || position.z != 0.0;
}

const LayoutReceiver* find_ranged(const std::vector<LayoutReceiver>& receivers, const std::string& receiver_id) {
    for (const LayoutReceiver& receiver : receivers) {
        if (receiver.receiver_id == receiver_id && receiver.has_range) {
            return &receiver;
        }
    }
    return nullptr;
}

}  // namespace

bool apply_confirmed_bases(const BaseRegistry& registry, const std::vector<LayoutReceiver>& receivers,
                           SolveRequest& request, UsedBaseIds& used, std::string& error) {
    used = UsedBaseIds{};
    const LayoutReceiver* chosen[3] = {};
    int chosen_ids[3] = {};
    int chosen_count = 0;

    if (request.stations == StationCount::Two) {
        struct Candidate {
            int base_id{0};
            const LayoutReceiver* sight{nullptr};
        };
        std::vector<Candidate> valid;
        for (const std::pair<int, std::string>& station : registry.confirmed_stations()) {
            const LayoutReceiver* sight = find_ranged(receivers, station.second);
            if (sight == nullptr || !measurement_usable(*sight)) {
                continue;
            }
            if (sight->has_base_id && sight->base_id != station.first) {
                error = "基站 " + station.second + " 的报文站号与编号表不一致";
                return false;
            }
            valid.push_back(Candidate{station.first, sight});
        }
        if (valid.size() < 2) {
            error = "没有两座位置和斜距都有效的已完成基站";
            return false;
        }
        std::size_t best_i = 0;
        std::size_t best_j = 1;
        double best_dy = -1.0;
        for (std::size_t i = 0; i < valid.size(); ++i) {
            for (std::size_t j = i + 1; j < valid.size(); ++j) {
                const double dy = std::abs(valid[i].sight->position.y - valid[j].sight->position.y);
                const int low_id = std::min(valid[i].base_id, valid[j].base_id);
                const int high_id = std::max(valid[i].base_id, valid[j].base_id);
                const int best_low = std::min(valid[best_i].base_id, valid[best_j].base_id);
                const int best_high = std::max(valid[best_i].base_id, valid[best_j].base_id);
                const bool larger_span = dy > best_dy;
                const bool same_span_smaller_ids =
                    dy == best_dy && (low_id < best_low || (low_id == best_low && high_id < best_high));
                if (larger_span || same_span_smaller_ids) {
                    best_dy = dy;
                    best_i = i;
                    best_j = j;
                }
            }
        }
        const std::size_t first = valid[best_i].base_id < valid[best_j].base_id ? best_i : best_j;
        const std::size_t second = first == best_i ? best_j : best_i;
        chosen[0] = valid[first].sight;
        chosen_ids[0] = valid[first].base_id;
        chosen[1] = valid[second].sight;
        chosen_ids[1] = valid[second].base_id;
        chosen_count = 2;
    } else {
        for (int base_id = 1; base_id <= 3; ++base_id) {
            std::string receiver_id;
            if (!registry.confirmed(base_id, receiver_id)) {
                error = "基站 " + std::to_string(base_id) + " 尚未分配完成";
                return false;
            }
            const LayoutReceiver* sight = find_ranged(receivers, receiver_id);
            if (sight == nullptr) {
                error = "本轮报文没有已完成基站 " + std::to_string(base_id) + " (" + receiver_id + ") 的斜距";
                return false;
            }
            if (sight->has_base_id && sight->base_id != base_id) {
                error = "基站 " + receiver_id + " 的报文站号与编号表不一致";
                return false;
            }
            chosen[base_id - 1] = sight;
            chosen_ids[base_id - 1] = base_id;
        }
        chosen_count = 3;
    }

    for (int index = 0; index < chosen_count; ++index) {
        used.id[index] = chosen_ids[index];
    }
    request.triangulation.set_base_a(chosen[0]->position);
    request.slant_range.set_base_a(chosen[0]->position);
    request.triangulation.set_slant_range_a(chosen[0]->range);
    request.slant_range.set_slant_range_a(chosen[0]->range);
    request.triangulation.set_base_b(chosen[1]->position);
    request.slant_range.set_base_b(chosen[1]->position);
    request.triangulation.set_slant_range_b(chosen[1]->range);
    request.slant_range.set_slant_range_b(chosen[1]->range);
    if (chosen_count == 3) {
        request.triangulation.set_base_c(chosen[2]->position);
        request.triangulation.set_slant_range_c(chosen[2]->range);
    }
    return true;
}

}  // namespace sbl

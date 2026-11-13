#include "sbl/rod.hpp"

#include <json/json.h>

#include <cmath>
#include <sstream>

namespace sbl {
namespace {

constexpr double kDegToRad = 0.017453292519943295;

Vec3 rod_arm(double yaw_deg, double pitch_deg, double roll_deg, double length_m) {
    const double heading = yaw_deg * kDegToRad;
    const double pitch = pitch_deg * kDegToRad;
    const double roll = roll_deg * kDegToRad;
    const double cos_heading = std::cos(heading);
    const double sin_heading = std::sin(heading);
    const double cos_pitch = std::cos(pitch);
    const double sin_pitch = std::sin(pitch);
    const double cos_roll = std::cos(roll);
    const double sin_roll = std::sin(roll);
    return Vec3{
        length_m * (cos_heading * sin_roll + sin_heading * sin_pitch * cos_roll),
        length_m * (-sin_heading * sin_roll + cos_heading * sin_pitch * cos_roll),
        length_m * (-cos_pitch * cos_roll),
    };
}

bool read_xyz(const Json::Value& node, Vec3& point) {
    if (!node.isObject() || !node["x"].isNumeric() || !node["y"].isNumeric() || !node["z"].isNumeric()) {
        return false;
    }
    point = Vec3{node["x"].asDouble(), node["y"].asDouble(), node["z"].asDouble()};
    return true;
}

}  // namespace

bool read_rods(const std::string& payload, int& seq, std::vector<RodReading>& rods, std::string& error) {
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    Json::Value root;
    std::string parse_error;
    std::istringstream input(payload);
    if (!Json::parseFromStream(builder, input, &root, &parse_error) || !root.isObject()) {
        error = "连杆报文不是 JSON 对象";
        return false;
    }
    seq = root.get("seq", 0).asInt();
    if (root.get("schema", "").asString() != "sbl.rod.v1") {
        error = "不支持的连杆 schema";
        return false;
    }
    const Json::Value& rows = root["rods"];
    if (!rows.isArray()) {
        error = "连杆报文缺少 rods";
        return false;
    }
    rods.clear();
    for (const Json::Value& row : rows) {
        RodReading rod;
        rod.id = row.get("id", "").asString();
        if (rod.id.empty() || !row["length_m"].isNumeric()) {
            error = "连杆 id 或杆长无效";
            return false;
        }
        rod.length_m = row["length_m"].asDouble();
        if (row.isMember("surface") && !row["surface"].isNull()) {
            if (!read_xyz(row["surface"], rod.surface)) {
                error = "连杆 " + rod.id + " 出水端坐标无效";
                return false;
            }
            rod.has_surface = true;
        }
        const Json::Value& solved = row["solved"];
        if (row.isMember("solved") && !solved.isNull()) {
            if (!solved.isObject() || !solved["pitch_deg"].isNumeric() || !solved["roll_deg"].isNumeric() ||
                !solved["yaw_deg"].isNumeric()) {
                error = "连杆 " + rod.id + " 姿态无效";
                return false;
            }
            rod.pitch_deg = solved["pitch_deg"].asDouble();
            rod.roll_deg = solved["roll_deg"].asDouble();
            rod.yaw_deg = solved["yaw_deg"].asDouble();
            rod.has_solved = true;
        }
        rods.push_back(rod);
    }
    return true;
}

Vec3 underwater_from_surface(const RodReading& rod) {
    const Vec3 arm = rod_arm(rod.yaw_deg, rod.pitch_deg, rod.roll_deg, rod.length_m);
    return Vec3{rod.surface.x + arm.x, rod.surface.y + arm.y, rod.surface.z + arm.z};
}

bool rod_position_message(int seq, const std::vector<RodReading>& rods, std::string& payload) {
    Json::Value bases(Json::arrayValue);
    for (const RodReading& rod : rods) {
        if ((rod.id != "rx-1" && rod.id != "rx-3") || !rod.has_surface || !rod.has_solved) {
            continue;
        }
        const Vec3 point = underwater_from_surface(rod);
        Json::Value item;
        item["id"] = rod.id;
        item["x"] = point.x;
        item["y"] = point.y;
        item["z"] = point.z;
        bases.append(item);
    }
    if (bases.empty()) {
        return false;
    }
    Json::Value root;
    root["schema"] = "sbl.rod_position.v1";
    root["seq"] = seq;
    root["bases"] = bases;
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    builder["precision"] = 6;
    builder["precisionType"] = "decimal";
    payload = Json::writeString(builder, root);
    return true;
}

}  // namespace sbl

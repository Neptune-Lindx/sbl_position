#pragma once

#include "sbl/types.hpp"

#include <string>
#include <vector>

namespace sbl {

// sbl/rod 里一座连杆。出水端和姿态都到齐才能反推水下端。
struct RodReading {
    std::string id;
    double length_m{0.0};
    Vec3 surface{};
    double pitch_deg{0.0};
    double roll_deg{0.0};
    double yaw_deg{0.0};
    bool has_surface{false};
    bool has_solved{false};
};

bool read_rods(const std::string& payload, int& seq, std::vector<RodReading>& rods, std::string& error);

// 杆臂从出水端指向水下端。航向 0° 沿船艏，正角度向右舷。
Vec3 underwater_from_surface(const RodReading& rod);

// 只包含已经反推出水下端的 rx-1、rx-3。没有可发的站时返回 false。
bool rod_position_message(int seq, const std::vector<RodReading>& rods, std::string& payload);

}  // namespace sbl

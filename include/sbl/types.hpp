#pragma once

#include <string>

namespace sbl {

// 局部笛卡尔坐标，单位米。Z 向上，与移动站高度同一高程基准。
struct Vec3 {
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

enum class Status {
    Ok,
    NotImplemented,
    InvalidInput,
    NoSolution,
};

// 交会至多两个解。三角定位按高程筛选后通常只留一个；两点高程相同时仍返回两个。
struct PositionResult {
    Status status{Status::NotImplemented};
    int solution_count{0};
    Vec3 solutions[2]{};
    std::string message;
};

const char* status_name(Status status);

}  // namespace sbl

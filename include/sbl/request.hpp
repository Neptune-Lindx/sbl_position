#pragma once

#include "sbl/slant_range.hpp"
#include "sbl/triangulation.hpp"

#include <string>

namespace sbl {

// 配置项 stations 的取值。3 为三站斜距三角定位，2 为双站斜距加已知高度。
enum class StationCount {
    Three = 3,
    Two = 2,
};

struct SolveRequest {
    StationCount stations{StationCount::Three};
    triangulation::Input triangulation;
    slant_range::Input slant_range;
    // 各站共用的坐标误差，以及各条斜距共用的斜距误差。单位米，取非负值。
    double base_error_x{0.0};
    double base_error_y{0.0};
    double base_error_z{0.0};
    double slant_range_error{0.0};
};

const char* algorithm_name(StationCount stations);

bool load_request(const std::string& path, SolveRequest& request, std::string& error);

PositionResult solve_request(const SolveRequest& request);

}  // namespace sbl

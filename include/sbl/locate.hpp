#pragma once

#include "sbl/config.hpp"
#include "sbl/slant_range.hpp"
#include "sbl/triangulation.hpp"

namespace sbl {

// 由 SBL_POSITION_ALGO 绑定当前算法的输入类型与入口。
// 业务侧只包含本头文件，并调用 sbl::locate。

#if SBL_POSITION_ALGO == SBL_ALGO_TRIANGULATION

using ActiveInput = triangulation::Input;
inline constexpr const char* kActiveAlgorithmName = "triangulation";

inline PositionResult locate(const ActiveInput& input) {
    return triangulation::solve(input);
}

#elif SBL_POSITION_ALGO == SBL_ALGO_SLANT_RANGE

using ActiveInput = slant_range::Input;
inline constexpr const char* kActiveAlgorithmName = "slant_range";

inline PositionResult locate(const ActiveInput& input) {
    return slant_range::solve(input);
}

#endif

}  // namespace sbl

#pragma once

#include "sbl/request.hpp"

namespace sbl {

// 同一组配置误差给出两种评估。
// 最大误差：端点组合后 |max-min|。协方差不确定度：在标称解处线性化得到的 1σ。
// 三站定位使用 x、y、z；双站定位只使用 x、y。
struct Uncertainty {
    int combination_count{0};
    int success_count{0};
    bool has_z{false};
    double x_min{0.0};
    double x_max{0.0};
    double y_min{0.0};
    double y_max{0.0};
    double z_min{0.0};
    double z_max{0.0};
    bool sigma_ok{false};
    double sigma_x{0.0};
    double sigma_y{0.0};
    double sigma_z{0.0};
};

// 配置中的斜距误差和基站 xyz 误差，在极限法里当作端点界限，在协方差里当作 1σ。
Uncertainty estimate_uncertainty(const SolveRequest& request);

}  // namespace sbl

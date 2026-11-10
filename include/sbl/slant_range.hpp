#pragma once

#include "sbl/types.hpp"

namespace sbl::slant_range {

// 基线 A→B 左侧或右侧。比较的是水平面内、沿 A→B 方向的左侧（逆时针一侧）。
enum class SideSelect {
    Left,
    Right,
};

// 双站斜距定位的输入。坐标、斜距、高度和左右选择通过设置函数写入。
// 两球面与高度平面一般有两个交点，side_select 留下其中一侧。
class Input {
public:
    void set_base_a(const Vec3& position) { base_a_ = position; }
    void set_base_b(const Vec3& position) { base_b_ = position; }

    void set_slant_range_a(double range) { slant_range_a_ = range; }
    void set_slant_range_b(double range) { slant_range_b_ = range; }

    void set_mobile_height(double height) { mobile_height_ = height; }
    void set_side_select(SideSelect select) { side_select_ = select; }

    const Vec3& base_a() const { return base_a_; }
    const Vec3& base_b() const { return base_b_; }
    double slant_range_a() const { return slant_range_a_; }
    double slant_range_b() const { return slant_range_b_; }
    double mobile_height() const { return mobile_height_; }
    SideSelect side_select() const { return side_select_; }

private:
    Vec3 base_a_{};
    Vec3 base_b_{};
    double slant_range_a_{0.0};
    double slant_range_b_{0.0};
    double mobile_height_{0.0};
    SideSelect side_select_{SideSelect::Left};
};

PositionResult solve(const Input& input);

}  // namespace sbl::slant_range

#pragma once

#include "sbl/types.hpp"

namespace sbl::triangulation {

// 两个镜像解里保留哪一个。比较的是原坐标的 z（高程）。
enum class HeightSelect {
    Higher,
    Lower,
};

// 三站斜距定位的输入。坐标和斜距通过设置函数写入，不直接改成员。
// 三球交点一般有两个。height_select 按高程留下较高或较低的一个。
// 两点高程相同时无法区分，此时仍返回两个解。
class Input {
public:
    void set_base_a(const Vec3& position) { base_a_ = position; }
    void set_base_b(const Vec3& position) { base_b_ = position; }
    void set_base_c(const Vec3& position) { base_c_ = position; }

    void set_slant_range_a(double range) { slant_range_a_ = range; }
    void set_slant_range_b(double range) { slant_range_b_ = range; }
    void set_slant_range_c(double range) { slant_range_c_ = range; }

    void set_height_select(HeightSelect select) { height_select_ = select; }

    const Vec3& base_a() const { return base_a_; }
    const Vec3& base_b() const { return base_b_; }
    const Vec3& base_c() const { return base_c_; }

    double slant_range_a() const { return slant_range_a_; }
    double slant_range_b() const { return slant_range_b_; }
    double slant_range_c() const { return slant_range_c_; }

    HeightSelect height_select() const { return height_select_; }

private:
    Vec3 base_a_{};
    Vec3 base_b_{};
    Vec3 base_c_{};
    double slant_range_a_{0.0};
    double slant_range_b_{0.0};
    double slant_range_c_{0.0};
    HeightSelect height_select_{HeightSelect::Higher};
};

PositionResult solve(const Input& input);

}  // namespace sbl::triangulation

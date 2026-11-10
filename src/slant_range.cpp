#include "sbl/slant_range.hpp"

#include <cmath>

namespace sbl::slant_range {
namespace {

constexpr double kMinLength = 1e-6;
constexpr double kDiscEpsilon = 1e-8;

bool finite_point(const Vec3& point) {
    return std::isfinite(point.x) && std::isfinite(point.y) && std::isfinite(point.z);
}

PositionResult invalid(const char* message) {
    PositionResult result;
    result.status = Status::InvalidInput;
    result.message = message;
    return result;
}

PositionResult no_solution(const char* message) {
    PositionResult result;
    result.status = Status::NoSolution;
    result.message = message;
    return result;
}

}  // namespace

PositionResult solve(const Input& input) {
    if (!finite_point(input.base_a()) || !finite_point(input.base_b()) || !std::isfinite(input.mobile_height()) ||
        !(input.slant_range_a() > 0.0) || !(input.slant_range_b() > 0.0)) {
        return invalid("ranges must be positive and finite, and coordinates and height must be finite");
    }

    const double dx = input.base_b().x - input.base_a().x;
    const double dy = input.base_b().y - input.base_a().y;
    const double baseline = std::sqrt(dx * dx + dy * dy);
    if (baseline < kMinLength) {
        return invalid("base stations have the same horizontal position");
    }

    const double height_a = input.mobile_height() - input.base_a().z;
    const double height_b = input.mobile_height() - input.base_b().z;
    double horizontal_a = input.slant_range_a() * input.slant_range_a() - height_a * height_a;
    double horizontal_b = input.slant_range_b() * input.slant_range_b() - height_b * height_b;
    if (horizontal_a < -kDiscEpsilon || horizontal_b < -kDiscEpsilon) {
        return no_solution("slant range does not reach the given height");
    }
    if (horizontal_a < 0.0) {
        horizontal_a = 0.0;
    }
    if (horizontal_b < 0.0) {
        horizontal_b = 0.0;
    }

    const double ex = dx / baseline;
    const double ey = dy / baseline;
    const double left_x = -ey;
    const double left_y = ex;
    const double along = (horizontal_a - horizontal_b + baseline * baseline) / (2.0 * baseline);
    const double across2 = horizontal_a - along * along;
    if (across2 < -kDiscEpsilon) {
        return no_solution("slant ranges do not intersect at the given height");
    }

    const double across = across2 <= kDiscEpsilon ? 0.0 : std::sqrt(across2);
    const double origin_x = input.base_a().x + along * ex;
    const double origin_y = input.base_a().y + along * ey;

    PositionResult result;
    result.status = Status::Ok;
    result.solution_count = 1;
    if (across == 0.0) {
        result.solutions[0] = {origin_x, origin_y, input.mobile_height()};
        result.message = "single intersection on the baseline";
        return result;
    }

    const double sign = input.side_select() == SideSelect::Left ? 1.0 : -1.0;
    result.solutions[0] = {origin_x + sign * across * left_x, origin_y + sign * across * left_y,
                           input.mobile_height()};
    result.message = sign > 0.0 ? "selected the left solution" : "selected the right solution";
    return result;
}

}  // namespace sbl::slant_range

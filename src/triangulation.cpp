#include "sbl/triangulation.hpp"

#include <cmath>

namespace sbl::triangulation {
namespace {

constexpr double kMinLength = 1e-6;
constexpr double kDiscEpsilon = 1e-8;
constexpr double kHeightTie = 1e-6;

struct Vec {
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

bool finite_point(const Vec3& point) {
    return std::isfinite(point.x) && std::isfinite(point.y) && std::isfinite(point.z);
}

Vec sub(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec add(const Vec& a, const Vec& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec scale(const Vec& v, double factor) {
    return {v.x * factor, v.y * factor, v.z * factor};
}

double dot(const Vec& a, const Vec& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec cross(const Vec& a, const Vec& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

double norm(const Vec& v) {
    return std::sqrt(dot(v, v));
}

Vec3 to_point(const Vec3& origin, const Vec& offset) {
    return {origin.x + offset.x, origin.y + offset.y, origin.z + offset.z};
}

PositionResult invalid(const char* message) {
    PositionResult result;
    result.status = Status::InvalidInput;
    result.message = message;
    return result;
}

}  // namespace

PositionResult solve(const Input& input) {
    if (!finite_point(input.base_a()) || !finite_point(input.base_b()) || !finite_point(input.base_c()) ||
        !(input.slant_range_a() > 0.0) || !(input.slant_range_b() > 0.0) || !(input.slant_range_c() > 0.0)) {
        return invalid("ranges must be positive and finite, and coordinates must be finite");
    }

    const Vec ab = sub(input.base_b(), input.base_a());
    const Vec ac = sub(input.base_c(), input.base_a());
    const Vec bc = sub(input.base_c(), input.base_b());
    const double d = norm(ab);
    if (d < kMinLength || norm(ac) < kMinLength || norm(bc) < kMinLength) {
        return invalid("base stations are coincident");
    }

    const Vec ex = scale(ab, 1.0 / d);
    const Vec normal = cross(ab, ac);
    const double normal_len = norm(normal);
    const double j_abs = normal_len / d;
    if (j_abs < kMinLength) {
        return invalid("base stations are collinear");
    }

    const Vec ez = scale(normal, 1.0 / normal_len);
    const Vec ey = cross(ez, ex);
    const double i = dot(ac, ex);
    const double j = dot(ac, ey);

    const double ra = input.slant_range_a();
    const double rb = input.slant_range_b();
    const double rc = input.slant_range_c();
    const double x = (ra * ra - rb * rb + d * d) / (2.0 * d);
    const double y = (ra * ra - rc * rc + i * i + j * j - 2.0 * i * x) / (2.0 * j);
    const double z2 = ra * ra - x * x - y * y;
    if (z2 < -kDiscEpsilon) {
        PositionResult result;
        result.status = Status::NoSolution;
        result.message = "slant ranges do not intersect";
        return result;
    }

    const Vec xy = add(scale(ex, x), scale(ey, y));
    const double z = z2 <= kDiscEpsilon ? 0.0 : std::sqrt(z2);

    const Vec3 positive = to_point(input.base_a(), add(xy, scale(ez, z)));
    PositionResult result;
    result.status = Status::Ok;
    if (z == 0.0) {
        result.solutions[0] = positive;
        result.solution_count = 1;
        result.message = "single intersection on the station plane";
        return result;
    }

    const Vec3 negative = to_point(input.base_a(), add(xy, scale(ez, -z)));
    const Vec3& higher = positive.z >= negative.z ? positive : negative;
    const Vec3& lower = positive.z >= negative.z ? negative : positive;
    if (std::abs(higher.z - lower.z) <= kHeightTie) {
        result.solutions[0] = positive;
        result.solutions[1] = negative;
        result.solution_count = 2;
        result.message = "two solutions have the same height";
        return result;
    }

    const bool select_higher = input.height_select() == HeightSelect::Higher;
    result.solutions[0] = select_higher ? higher : lower;
    result.solution_count = 1;
    result.message = select_higher ? "selected the higher solution" : "selected the lower solution";
    return result;
}

}  // namespace sbl::triangulation

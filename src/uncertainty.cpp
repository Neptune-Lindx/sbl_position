#include "sbl/uncertainty.hpp"

#include <cmath>
#include <vector>

namespace sbl {
namespace {

enum class Target { BaseX, BaseY, BaseZ, Range };

struct Knob {
    Target target;
    int index{0};
    double delta{0.0};
};

void shift_vec(Vec3& point, Target target, double delta) {
    if (target == Target::BaseX) {
        point.x += delta;
    } else if (target == Target::BaseY) {
        point.y += delta;
    } else if (target == Target::BaseZ) {
        point.z += delta;
    }
}

void apply(triangulation::Input& input, const Knob& knob, double signed_delta) {
    if (knob.target == Target::Range) {
        if (knob.index == 0) {
            input.set_slant_range_a(input.slant_range_a() + signed_delta);
        } else if (knob.index == 1) {
            input.set_slant_range_b(input.slant_range_b() + signed_delta);
        } else {
            input.set_slant_range_c(input.slant_range_c() + signed_delta);
        }
        return;
    }
    Vec3 point = knob.index == 0 ? input.base_a() : knob.index == 1 ? input.base_b() : input.base_c();
    shift_vec(point, knob.target, signed_delta);
    if (knob.index == 0) {
        input.set_base_a(point);
    } else if (knob.index == 1) {
        input.set_base_b(point);
    } else {
        input.set_base_c(point);
    }
}

void apply(slant_range::Input& input, const Knob& knob, double signed_delta) {
    if (knob.target == Target::Range) {
        if (knob.index == 0) {
            input.set_slant_range_a(input.slant_range_a() + signed_delta);
        } else {
            input.set_slant_range_b(input.slant_range_b() + signed_delta);
        }
        return;
    }
    Vec3 point = knob.index == 0 ? input.base_a() : input.base_b();
    shift_vec(point, knob.target, signed_delta);
    if (knob.index == 0) {
        input.set_base_a(point);
    } else {
        input.set_base_b(point);
    }
}

void add_base_knobs(std::vector<Knob>& knobs, int station_count, const SolveRequest& request) {
    const Target axes[] = {Target::BaseX, Target::BaseY, Target::BaseZ};
    const double errors[] = {request.base_error_x, request.base_error_y, request.base_error_z};
    for (int station = 0; station < station_count; ++station) {
        for (int axis = 0; axis < 3; ++axis) {
            if (errors[axis] > 0.0) {
                knobs.push_back(Knob{axes[axis], station, errors[axis]});
            }
        }
    }
}

void add_range_knobs(std::vector<Knob>& knobs, int range_count, double range_error) {
    if (!(range_error > 0.0)) {
        return;
    }
    for (int index = 0; index < range_count; ++index) {
        knobs.push_back(Knob{Target::Range, index, range_error});
    }
}

void include_point(Uncertainty& uncertainty, const Vec3& point) {
    if (uncertainty.success_count == 0) {
        uncertainty.x_min = uncertainty.x_max = point.x;
        uncertainty.y_min = uncertainty.y_max = point.y;
        uncertainty.z_min = uncertainty.z_max = point.z;
        return;
    }
    if (point.x < uncertainty.x_min) {
        uncertainty.x_min = point.x;
    }
    if (point.x > uncertainty.x_max) {
        uncertainty.x_max = point.x;
    }
    if (point.y < uncertainty.y_min) {
        uncertainty.y_min = point.y;
    }
    if (point.y > uncertainty.y_max) {
        uncertainty.y_max = point.y;
    }
    if (point.z < uncertainty.z_min) {
        uncertainty.z_min = point.z;
    }
    if (point.z > uncertainty.z_max) {
        uncertainty.z_max = point.z;
    }
}

template <typename Input, typename Solve>
Uncertainty sweep(const Input& nominal, const std::vector<Knob>& knobs, bool has_z, Solve solve) {
    Uncertainty uncertainty;
    uncertainty.has_z = has_z;
    const int knob_count = static_cast<int>(knobs.size());
    uncertainty.combination_count = 1 << knob_count;
    for (int mask = 0; mask < uncertainty.combination_count; ++mask) {
        Input sample = nominal;
        for (int bit = 0; bit < knob_count; ++bit) {
            const double sign = (mask & (1 << bit)) != 0 ? 1.0 : -1.0;
            apply(sample, knobs[static_cast<std::size_t>(bit)], sign * knobs[static_cast<std::size_t>(bit)].delta);
        }
        const PositionResult result = solve(sample);
        if (result.status != Status::Ok || result.solution_count < 1) {
            continue;
        }
        for (int i = 0; i < result.solution_count; ++i) {
            include_point(uncertainty, result.solutions[i]);
            ++uncertainty.success_count;
        }
    }
    return uncertainty;
}

double range_variance(const Vec3& line_of_sight, const SolveRequest& request) {
    const double site_x = line_of_sight.x * request.base_error_x;
    const double site_y = line_of_sight.y * request.base_error_y;
    const double site_z = line_of_sight.z * request.base_error_z;
    return request.slant_range_error * request.slant_range_error + site_x * site_x + site_y * site_y +
           site_z * site_z;
}

bool line_of_sight(const Vec3& base, const Vec3& mobile, Vec3* unit) {
    const double dx = mobile.x - base.x;
    const double dy = mobile.y - base.y;
    const double dz = mobile.z - base.z;
    const double length = std::sqrt(dx * dx + dy * dy + dz * dz);
    if (!(length > 1e-6)) {
        return false;
    }
    unit->x = dx / length;
    unit->y = dy / length;
    unit->z = dz / length;
    return true;
}

bool invert2(const double m[2][2], double inv[2][2]) {
    const double det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    if (!std::isfinite(det) || std::abs(det) < 1e-14) {
        return false;
    }
    inv[0][0] = m[1][1] / det;
    inv[0][1] = -m[0][1] / det;
    inv[1][0] = -m[1][0] / det;
    inv[1][1] = m[0][0] / det;
    return std::isfinite(inv[0][0]) && std::isfinite(inv[1][1]);
}

bool invert3(const double m[3][3], double inv[3][3]) {
    const double c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
    const double c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
    const double c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
    const double det = m[0][0] * c00 + m[0][1] * c01 + m[0][2] * c02;
    if (!std::isfinite(det) || std::abs(det) < 1e-14) {
        return false;
    }
    inv[0][0] = c00 / det;
    inv[1][0] = c01 / det;
    inv[2][0] = c02 / det;
    inv[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    inv[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    inv[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
    inv[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    inv[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
    inv[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
    return std::isfinite(inv[0][0]) && std::isfinite(inv[1][1]) && std::isfinite(inv[2][2]);
}

void add_information(double normal[], int dim, const double row[], double variance) {
    if (!(variance > 0.0)) {
        return;
    }
    const double weight = 1.0 / variance;
    for (int row_index = 0; row_index < dim; ++row_index) {
        for (int col_index = 0; col_index < dim; ++col_index) {
            normal[row_index * dim + col_index] += weight * row[row_index] * row[col_index];
        }
    }
}

bool observe(const Vec3& base, const Vec3& mobile, int dim, const SolveRequest& request, double normal[]) {
    Vec3 unit;
    if (!line_of_sight(base, mobile, &unit)) {
        return false;
    }
    const double row[] = {unit.x, unit.y, unit.z};
    add_information(normal, dim, row, range_variance(unit, request));
    return true;
}

void fill_sigma(const SolveRequest& request, const Vec3& mobile, int dim, Uncertainty* uncertainty) {
    const int dim2 = dim * dim;
    double normal[9] = {};
    const Vec3 bases[] = {request.stations == StationCount::Three ? request.triangulation.base_a()
                                                                  : request.slant_range.base_a(),
                          request.stations == StationCount::Three ? request.triangulation.base_b()
                                                                  : request.slant_range.base_b(),
                          request.triangulation.base_c()};
    const int station_count = dim == 3 ? 3 : 2;
    bool any_noise = false;
    for (int index = 0; index < station_count; ++index) {
        Vec3 unit;
        if (!line_of_sight(bases[index], mobile, &unit)) {
            return;
        }
        if (range_variance(unit, request) > 0.0) {
            any_noise = true;
        }
        if (!observe(bases[index], mobile, dim, request, normal)) {
            return;
        }
    }
    if (!any_noise) {
        uncertainty->sigma_ok = true;
        return;
    }

    if (dim == 2) {
        double matrix[2][2] = {{normal[0], normal[1]}, {normal[2], normal[3]}};
        double inverse[2][2] = {};
        if (!invert2(matrix, inverse) || inverse[0][0] < 0.0 || inverse[1][1] < 0.0) {
            return;
        }
        uncertainty->sigma_x = std::sqrt(inverse[0][0]);
        uncertainty->sigma_y = std::sqrt(inverse[1][1]);
        uncertainty->sigma_ok = true;
        return;
    }

    double matrix[3][3] = {};
    for (int index = 0; index < dim2; ++index) {
        matrix[index / 3][index % 3] = normal[index];
    }
    double inverse[3][3] = {};
    if (!invert3(matrix, inverse) || inverse[0][0] < 0.0 || inverse[1][1] < 0.0 || inverse[2][2] < 0.0) {
        return;
    }
    uncertainty->sigma_x = std::sqrt(inverse[0][0]);
    uncertainty->sigma_y = std::sqrt(inverse[1][1]);
    uncertainty->sigma_z = std::sqrt(inverse[2][2]);
    uncertainty->sigma_ok = true;
}

}  // namespace

Uncertainty estimate_uncertainty(const SolveRequest& request) {
    std::vector<Knob> knobs;
    Uncertainty uncertainty;
    Vec3 mobile;
    if (request.stations == StationCount::Three) {
        add_base_knobs(knobs, 3, request);
        add_range_knobs(knobs, 3, request.slant_range_error);
        uncertainty = sweep(request.triangulation, knobs, true,
                            [](const triangulation::Input& input) { return triangulation::solve(input); });
        const PositionResult nominal = triangulation::solve(request.triangulation);
        if (nominal.status == Status::Ok && nominal.solution_count >= 1) {
            mobile = nominal.solutions[0];
            fill_sigma(request, mobile, 3, &uncertainty);
        }
        return uncertainty;
    }
    add_base_knobs(knobs, 2, request);
    add_range_knobs(knobs, 2, request.slant_range_error);
    uncertainty = sweep(request.slant_range, knobs, false,
                        [](const slant_range::Input& input) { return slant_range::solve(input); });
    const PositionResult nominal = slant_range::solve(request.slant_range);
    if (nominal.status == Status::Ok && nominal.solution_count >= 1) {
        mobile = nominal.solutions[0];
        fill_sigma(request, mobile, 2, &uncertainty);
    }
    return uncertainty;
}

}  // namespace sbl

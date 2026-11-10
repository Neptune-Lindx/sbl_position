#include "sbl/request.hpp"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

namespace sbl {
namespace {

std::string trim(const std::string& text) {
    std::size_t begin = 0;
    while (begin < text.size() && std::isspace(static_cast<unsigned char>(text[begin]))) {
        ++begin;
    }
    std::size_t end = text.size();
    while (end > begin && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
        --end;
    }
    return text.substr(begin, end - begin);
}

std::string lower_copy(std::string text) {
    for (char& ch : text) {
        ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    }
    return text;
}

bool parse_double(const std::string& text, double* value) {
    char* end = nullptr;
    const double parsed = std::strtod(text.c_str(), &end);
    if (end == text.c_str() || *end != '\0' || !std::isfinite(parsed)) {
        return false;
    }
    *value = parsed;
    return true;
}

bool parse_vec3(const std::string& text, Vec3* point) {
    std::istringstream in(text);
    std::string xs;
    std::string ys;
    std::string zs;
    std::string extra;
    if (!(in >> xs >> ys >> zs) || (in >> extra)) {
        return false;
    }
    return parse_double(xs, &point->x) && parse_double(ys, &point->y) && parse_double(zs, &point->z);
}

bool parse_number(const std::string& text, double* value) {
    std::istringstream in(text);
    std::string token;
    std::string extra;
    if (!(in >> token) || (in >> extra)) {
        return false;
    }
    return parse_double(token, value);
}

std::string line_error(int line_no, const std::string& message) {
    return "配置文件第 " + std::to_string(line_no) + " 行: " + message;
}

}  // namespace

const char* algorithm_name(StationCount stations) {
    return stations == StationCount::Three ? "triangulation" : "slant_range";
}

bool load_request(const std::string& path, SolveRequest& request, std::string& error) {
    std::ifstream in(path);
    if (!in) {
        error = "无法打开配置文件: " + path;
        return false;
    }

    bool seen_stations = false;
    bool seen_base_a = false;
    bool seen_base_b = false;
    bool seen_base_c = false;
    bool seen_range_a = false;
    bool seen_range_b = false;
    bool seen_range_c = false;
    bool seen_height_select = false;
    bool seen_side = false;
    bool seen_base_error_x = false;
    bool seen_base_error_y = false;
    bool seen_base_error_z = false;
    bool seen_range_error = false;
    StationCount stations = StationCount::Three;

    std::string line;
    int line_no = 0;
    while (std::getline(in, line)) {
        ++line_no;
        const std::string trimmed = trim(line);
        if (trimmed.empty() || trimmed[0] == '#') {
            continue;
        }

        const auto gap = trimmed.find_first_of(" \t");
        if (gap == std::string::npos) {
            error = line_error(line_no, "缺少取值");
            return false;
        }
        const std::string key = trimmed.substr(0, gap);
        const std::string value = trim(trimmed.substr(gap));

        auto mark = [&](bool& seen, const char* name) {
            if (seen) {
                error = line_error(line_no, std::string("重复配置项 ") + name);
                return false;
            }
            seen = true;
            return true;
        };

        if (key == "stations") {
            if (!mark(seen_stations, key.c_str())) {
                return false;
            }
            if (value == "3") {
                stations = StationCount::Three;
            } else if (value == "2") {
                stations = StationCount::Two;
            } else {
                error = line_error(line_no, "stations 只能是 3 或 2");
                return false;
            }
        } else if (key == "base_a" || key == "base_b" || key == "base_c") {
            bool& seen = key == "base_a" ? seen_base_a : key == "base_b" ? seen_base_b : seen_base_c;
            if (!mark(seen, key.c_str())) {
                return false;
            }
            Vec3 point;
            if (!parse_vec3(value, &point)) {
                error = line_error(line_no, key + " 需要三个坐标");
                return false;
            }
            if (key == "base_a") {
                request.triangulation.set_base_a(point);
                request.slant_range.set_base_a(point);
            } else if (key == "base_b") {
                request.triangulation.set_base_b(point);
                request.slant_range.set_base_b(point);
            } else {
                request.triangulation.set_base_c(point);
            }
        } else if (key == "slant_range_a" || key == "slant_range_b" || key == "slant_range_c") {
            bool& seen = key == "slant_range_a" ? seen_range_a : key == "slant_range_b" ? seen_range_b : seen_range_c;
            if (!mark(seen, key.c_str())) {
                return false;
            }
            double range = 0.0;
            if (!parse_number(value, &range)) {
                error = line_error(line_no, key + " 需要一个斜距");
                return false;
            }
            if (key == "slant_range_a") {
                request.triangulation.set_slant_range_a(range);
                request.slant_range.set_slant_range_a(range);
            } else if (key == "slant_range_b") {
                request.triangulation.set_slant_range_b(range);
                request.slant_range.set_slant_range_b(range);
            } else {
                request.triangulation.set_slant_range_c(range);
            }
        } else if (key == "height_select") {
            if (!mark(seen_height_select, key.c_str())) {
                return false;
            }
            const std::string choice = lower_copy(value);
            if (choice == "higher" || choice == "selected the higher solution") {
                request.triangulation.set_height_select(triangulation::HeightSelect::Higher);
            } else if (choice == "lower" || choice == "selected the lower solution") {
                request.triangulation.set_height_select(triangulation::HeightSelect::Lower);
            } else {
                error = line_error(line_no, "height_select 只能是 higher 或 lower");
                return false;
            }
        } else if (key == "base_error_x" || key == "base_error_y" || key == "base_error_z" ||
                   key == "slant_range_error") {
            bool& seen = key == "base_error_x"     ? seen_base_error_x
                         : key == "base_error_y"   ? seen_base_error_y
                         : key == "base_error_z"   ? seen_base_error_z
                                                   : seen_range_error;
            if (!mark(seen, key.c_str())) {
                return false;
            }
            double error_value = 0.0;
            if (!parse_number(value, &error_value) || !(error_value >= 0.0)) {
                error = line_error(line_no, key + " 必须是非负误差");
                return false;
            }
            if (key == "base_error_x") {
                request.base_error_x = error_value;
            } else if (key == "base_error_y") {
                request.base_error_y = error_value;
            } else if (key == "base_error_z") {
                request.base_error_z = error_value;
            } else {
                request.slant_range_error = error_value;
            }
        } else if (key == "side_select") {
            if (!mark(seen_side, key.c_str())) {
                return false;
            }
            const std::string choice = lower_copy(value);
            if (choice == "left") {
                request.slant_range.set_side_select(slant_range::SideSelect::Left);
            } else if (choice == "right") {
                request.slant_range.set_side_select(slant_range::SideSelect::Right);
            } else {
                error = line_error(line_no, "side_select 只能是 left 或 right");
                return false;
            }
        } else {
            error = line_error(line_no, "未知配置项 " + key);
            return false;
        }
    }

    if (!seen_stations) {
        error = "配置缺少 stations";
        return false;
    }
    if (!seen_base_error_x || !seen_base_error_y || !seen_base_error_z || !seen_range_error) {
        error = "配置缺少 base_error_x、base_error_y、base_error_z 或 slant_range_error";
        return false;
    }
    request.stations = stations;
    if (stations == StationCount::Three) {
        if (!seen_height_select) {
            error = "三站定位缺少 height_select";
            return false;
        }
        return true;
    }
    if (!seen_side) {
        error = "双站定位缺少 side_select";
        return false;
    }
    return true;
}

PositionResult solve_request(const SolveRequest& request) {
    if (request.stations == StationCount::Three) {
        return triangulation::solve(request.triangulation);
    }
    return slant_range::solve(request.slant_range);
}

}  // namespace sbl

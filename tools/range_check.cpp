#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace {

struct Vec3 {
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

class CheckInput {
public:
    void set_base_a(const Vec3& position) { base_a_ = position; }
    void set_base_b(const Vec3& position) { base_b_ = position; }
    void set_base_c(const Vec3& position) { base_c_ = position; }
    void set_rover(const Vec3& position) { rover_ = position; }
    void set_slant_range_a(double range) { slant_range_a_ = range; }
    void set_slant_range_b(double range) { slant_range_b_ = range; }
    void set_slant_range_c(double range) { slant_range_c_ = range; }
    void set_tolerance(double tolerance) { tolerance_ = tolerance; }

    const Vec3& base_a() const { return base_a_; }
    const Vec3& base_b() const { return base_b_; }
    const Vec3& base_c() const { return base_c_; }
    const Vec3& rover() const { return rover_; }
    double slant_range_a() const { return slant_range_a_; }
    double slant_range_b() const { return slant_range_b_; }
    double slant_range_c() const { return slant_range_c_; }
    double tolerance() const { return tolerance_; }

private:
    Vec3 base_a_{};
    Vec3 base_b_{};
    Vec3 base_c_{};
    Vec3 rover_{};
    double slant_range_a_{0.0};
    double slant_range_b_{0.0};
    double slant_range_c_{0.0};
    double tolerance_{1e-3};
};

double slant(const Vec3& a, const Vec3& b) {
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;
    const double dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

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

bool load_from_file(const std::string& path, CheckInput& input, std::string& error) {
    std::ifstream in(path);
    if (!in) {
        error = "无法打开配置文件: " + path;
        return false;
    }

    bool seen_base_a = false;
    bool seen_base_b = false;
    bool seen_base_c = false;
    bool seen_rover = false;
    bool seen_range_a = false;
    bool seen_range_b = false;
    bool seen_range_c = false;
    bool seen_tolerance = false;

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

        if (key == "base_a" || key == "base_b" || key == "base_c" || key == "rover") {
            bool& seen = key == "base_a"   ? seen_base_a
                         : key == "base_b" ? seen_base_b
                         : key == "base_c" ? seen_base_c
                                           : seen_rover;
            if (!mark(seen, key.c_str())) {
                return false;
            }
            Vec3 point;
            if (!parse_vec3(value, &point)) {
                error = line_error(line_no, key + " 需要三个坐标");
                return false;
            }
            if (key == "base_a") {
                input.set_base_a(point);
            } else if (key == "base_b") {
                input.set_base_b(point);
            } else if (key == "base_c") {
                input.set_base_c(point);
            } else {
                input.set_rover(point);
            }
        } else if (key == "slant_range_a" || key == "slant_range_b" || key == "slant_range_c") {
            bool& seen = key == "slant_range_a"   ? seen_range_a
                         : key == "slant_range_b" ? seen_range_b
                                                  : seen_range_c;
            if (!mark(seen, key.c_str())) {
                return false;
            }
            double range = 0.0;
            if (!parse_number(value, &range)) {
                error = line_error(line_no, key + " 需要一个斜距");
                return false;
            }
            if (key == "slant_range_a") {
                input.set_slant_range_a(range);
            } else if (key == "slant_range_b") {
                input.set_slant_range_b(range);
            } else {
                input.set_slant_range_c(range);
            }
        } else if (key == "tolerance") {
            if (!mark(seen_tolerance, key.c_str())) {
                return false;
            }
            double tolerance = 0.0;
            if (!parse_number(value, &tolerance) || !(tolerance >= 0.0)) {
                error = line_error(line_no, "tolerance 必须是非负数");
                return false;
            }
            input.set_tolerance(tolerance);
        } else {
            error = line_error(line_no, "未知配置项 " + key);
            return false;
        }
    }

    if (!seen_base_a || !seen_base_b || !seen_base_c || !seen_rover || !seen_range_a || !seen_range_b ||
        !seen_range_c) {
        error = "配置缺少基站坐标、流动站坐标或斜距";
        return false;
    }
    return true;
}

void print_usage(std::ostream& out) {
    out << "用法: sbl_range_check [配置文件]\n"
        << "  省略路径时使用 config/range_check.conf。\n"
        << "  配置项：base_a、base_b、base_c、rover、slant_range_a、slant_range_b、slant_range_c。\n"
        << "  tolerance 可选，单位米，默认 0.001。几何斜距与已知斜距之差不超过它则通过。\n";
}

}  // namespace

int main(int argc, char** argv) {
    if (argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        print_usage(std::cout);
        return 0;
    }
    if (argc > 2) {
        print_usage(std::cerr);
        return 2;
    }

    const char* path = argc == 2 ? argv[1] : "config/range_check.conf";
    CheckInput input;
    std::string error;
    if (!load_from_file(path, input, error)) {
        std::cerr << error << '\n';
        return 2;
    }

    const double computed[3] = {slant(input.base_a(), input.rover()), slant(input.base_b(), input.rover()),
                                slant(input.base_c(), input.rover())};
    const double known[3] = {input.slant_range_a(), input.slant_range_b(), input.slant_range_c()};
    const char* labels[3] = {"A", "B", "C"};
    const double tolerance = input.tolerance();

    double max_diff = 0.0;
    bool pass = true;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    for (int i = 0; i < 3; ++i) {
        const double diff = std::abs(computed[i] - known[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
        if (diff > tolerance) {
            pass = false;
        }
        std::cout << labels[i] << ": 几何斜距=" << computed[i] << " 已知斜距=" << known[i]
                  << " 偏差=" << diff << '\n';
    }
    std::cout << "最大偏差=" << max_diff << " 容差=" << tolerance << '\n'
              << (pass ? "结果: 通过\n" : "结果: 不通过\n");
    return pass ? 0 : 1;
}

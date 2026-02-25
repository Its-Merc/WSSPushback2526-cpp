#include "utils.hpp"

namespace utils {

double cubic(int8_t val) {
    return std::pow(val / 127.0, 3) * 127.0;
}

double sinusoidal(int8_t val) {
    constexpr static double pi = M_PI;

    double norm = (val / 127.0) - 0.5;
    double rad = norm * pi;
    double sin = (std::sin(rad) + 1.0) / 2.0;

    return sin * 127.0;
}

}  // namespace utils

#include "api.h"
#include "constants.hpp"

namespace utils {

double cubic(int8_t val);
double sinusoidal(int8_t val);

// lcd::print but with a debug check
template <typename... Args>
void printDebug(int16_t line, const char *fmt, Args... args) {
    if (DEBUG) pros::lcd::print(line, fmt, args...);
}

}  // namespace utils

#pragma once
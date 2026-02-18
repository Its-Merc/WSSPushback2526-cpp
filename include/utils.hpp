#include "api.h"
#include "constants.hpp"

namespace utils {

double cubic(int8_t val);
double sinusoidal(int8_t val);

template <typename... Args>
void printDebug(int16_t line, const char *fmt, Args... args);

}  // namespace utils

#pragma once
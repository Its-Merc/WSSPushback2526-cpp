#include <functional>
#include <variant>

#include "api.h"

namespace ctrler {
static pros::Controller ctrler;

pros::Controller& get();

int8_t get_analog(pros::controller_analog_e_t analog);
int8_t get_lerp_analog(pros::controller_analog_e_t axis, float t);
int8_t get_modified_analog(pros::controller_analog_e_t axis,
                           std::function<std::variant<int, float, double>(int8_t)> modifier);

}  // namespace ctrler

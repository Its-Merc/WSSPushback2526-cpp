#include "ctrler.hpp"

namespace ctrler {

static pros::Controller ctrler(pros::E_CONTROLLER_MASTER);

pros::Controller& get() {
    return ctrler;
}

int8_t get_analog(pros::controller_analog_e_t axis) {
    return ctrler.get_analog(axis);
}

int8_t get_lerp_analog(pros::controller_analog_e_t axis, float t) {
    static int8_t prev = 0;
    static pros::controller_analog_e_t prev_axis = axis;

    int8_t end = ctrler.get_analog(axis);

    if (prev_axis == axis) return (int8_t)std::lerp(prev, end, t);

    prev = end;
    prev_axis = axis;
    return end;
}

int8_t get_modified_analog(pros::controller_analog_e_t axis,
                           std::function<std::variant<int, float, double>(int8_t)> modifier) {
    return std::get<int8_t>(modifier(ctrler.get_analog(axis)));
}

}  // namespace ctrler
#include "api.h"

// front-left/-right | back-left/-right
constexpr int8_t DRIVE_PORTS[4] = {9, 19, 20, 10};

constexpr pros::controller_analog_e_t THROTTLE_AXIS = pros::E_CONTROLLER_ANALOG_LEFT_Y;
constexpr pros::controller_analog_e_t TURN_AXIS = pros::E_CONTROLLER_ANALOG_RIGHT_X;

constexpr uint32_t CTRLER_UPDATE_RATE = 20;  // ms

constexpr bool DEBUG = true;

#pragma once
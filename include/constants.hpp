#include "api.h"

// front-left/-right | back-left/-right
constexpr int8_t kDrivePorts[4] = {9, 19, 20, 10};

constexpr pros::controller_analog_e_t kThrottleAxis = pros::E_CONTROLLER_ANALOG_LEFT_Y;
constexpr pros::controller_analog_e_t kTurnAxis = pros::E_CONTROLLER_ANALOG_RIGHT_X;
constexpr pros::controller_digital_e_t kBtn = pros::E_CONTROLLER_DIGITAL_L2;

constexpr uint32_t CTRLER_UPDATE_RATE = 20;  // ms

constexpr bool DEBUG = true;

#pragma once
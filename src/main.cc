#include "main.h"

/**
 * runs first
 * nothing will run until this is finished
 */
void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(1, "wazza");

    pros::lcd::register_btn1_cb(gui::OnCenterBtnPressed);
}

/**
 * runs when robot is in the disabled mode in the vex competition switch or field management system
 * stops running when enabled
 */
void disabled() {}

/**
 * runs after initialize(), before Auton
 * meant for competition-specific initialization routines, e.g. autonomous selector on the LCD
 *
 * exits when autonomous or opcontrol is started
 */
void competitioninitialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * operator control code
 * runs immediately after initialize() if not connected to competition control
 * if the robot is disabled or communications is lost, this will be stopped
 * re-enabling the robot will restart the task, not resume it from where it left off
 */
void opcontrol() {
    auto ctrler = ctrler::get();

    pros::MotorGroup left_mg({DRIVE_PORTS[0], DRIVE_PORTS[2]});   // Creates the motor group for the left
    pros::MotorGroup right_mg({DRIVE_PORTS[1], DRIVE_PORTS[3]});  // Creates the motor group for the right

    ctrler.set_text(0, 0, "you suck");

    while (true) {
        // pros::lcd::print(
        //     0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
        //     (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
        //     (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen
        //     LCDs

        if (DEBUG) {
            int8_t throttle = ctrler.get_analog(THROTTLE_AXIS);
            int8_t turn = ctrler.get_analog(TURN_AXIS);
            utils::printDebug(1, "%d | %f", throttle, utils::cubic(throttle));
            utils::printDebug(2, "%d | %f", turn, utils::cubic(turn));
        }

        // Arcade control scheme
        int8_t throttle = ctrler::get_modified_analog(THROTTLE_AXIS, utils::cubic);  // forward/backward
        int8_t turn = ctrler::get_modified_analog(TURN_AXIS, utils::cubic);          // left/right turn

        auto left = throttle - turn;
        auto right = throttle + turn;
        utils::printDebug(3, "%d | %d", left, -right);

        left_mg.move(left);     // Sets left motor voltage
        right_mg.move(-right);  // Sets right motor voltage | negative because motors are flipped
        pros::delay(CTRLER_UPDATE_RATE);
    }
}
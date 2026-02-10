#include "main.h"

/**
 * runs first
 * nothing will run until this is finished
 */
void OnInitialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(1, "wazza");

    pros::lcd::register_btn1_cb(gui::OnCenterBtnPressed);
}

/**
 * runs when robot is in the disabled mode in the vex competition switch or field management system
 * stops running when enabled
 */
void OnDisabled() {}

/**
 * runs after initialize(), before Auton
 * meant for competition-specific initialization routines, e.g. autonomous selector on the LCD
 *
 * exits when autonomous or opcontrol is started
 */
void OnCompetitionInitialize() {}

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
void OnAutonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void OnOpControl() {
    pros::Controller ctrler(pros::E_CONTROLLER_MASTER);
    pros::MotorGroup left_mg({9, 20});    // Creates a motor group with forwards ports 9 and 20
    pros::MotorGroup right_mg({19, 10});  // Creates a motor group with forwards port 19 and 10

    ctrler.set_text(0, 0, "wazza");
    while (true) {
        pros::lcd::print(
            0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
            (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
            (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

        // Arcade control scheme
        int dir = ctrler.get_analog(
            pros::E_CONTROLLER_ANALOG_LEFT_Y);  // Gets amount forward/backward from left joystick
        int turn = ctrler.get_analog(
            pros::E_CONTROLLER_ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
        left_mg.move(dir - turn);                // Sets left motor voltage
        right_mg.move(dir + turn);               // Sets right motor voltage
        pros::delay(20);                         // Run for 20 ms then update
    }
}
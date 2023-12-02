#include "main.h"
#include "config.hpp"

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

void opcontrol() {

	// Set booleans for the toggle switches.
	bool expansionActivated = false;

	while (true) {

		// Use the left joystick to move the left wheels of the robot.
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));

		// Use the right joystick to move the right wheels of the robot.
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));

		// Use the L2 button to extend the pneumatic expander, if it is not already activated.
		if (master.get_digital(DIGITAL_L2) && expansionActivated == false) {
            left_expander.set_value(HIGH);
            right_expander.set_value(HIGH);
            expansionActivated = true;
            pros::delay(20);
		}

        // Use the L1 button to retract the pneumatic expander, if it is not already deactivated.
        else if (master.get_digital(DIGITAL_L1) && expansionActivated == true) {
            left_expander.set_value(LOW);
            right_expander.set_value(LOW);
            expansionActivated = false;
            pros::delay(20);
        }

        // Use the R1 button to fire the slingshot.
        if (master.get_digital(DIGITAL_R1)) {
            slingshot.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
            slingshot.move_velocity(100);
            pros::delay(1000);
            slingshot.brake();
        }

	}

}
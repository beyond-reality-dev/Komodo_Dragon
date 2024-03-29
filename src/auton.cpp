#include "main.h"
#include "autoSelect/selection.h"
#include "config.hpp"

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

void autonomous() {

    // Create a chassis with 4 motors, 4 inch wheel diameter, 14 inch wheel track, and configure odometry.
	std::shared_ptr<OdomChassisController> drivetrain = ChassisControllerBuilder()
        // Set the ports of the left and right motors.
        .withMotors(
            {3, 4}, // Left motors are at ports 3 & 4.
            {1, 2} // Right motors are at ports 1 & 2.
        )
        // Use the green gearset, 4 inch wheel diameter, and 14 inch wheel track.
        .withDimensions(AbstractMotor::gearset::green, {{4_in, 14_in}, imev5GreenTPR})
        // Use the same scales as the chassis.
        .withOdometry()
        // Build an odometry chassis.
        .buildOdometry();
    
    // Run the autonomous based on the selector.
    switch (selector::auton) {
        
        // Runs the autonomous code for the left side, red alliance.
        case 1:

            // Set the drivetrain state to zero.
            drivetrain->setState({0_in, 0_in, 0_deg});
            
            // Move the drivetrain backward 2 inches.
            drivetrain->moveDistance(-2_in);

            break;

        // Runs the autonomous code for the right side, red alliance (WIP).
        case 2: 
            
            break;

        // Does nothing for the red alliance.
        case 3: 

            break;
        
        // Runs the autonomous code for the left side, blue alliance (WIP).
        case -1:

            // Set the drivetrain state to zero.
            drivetrain->setState({0_in, 0_in, 0_deg});
            
            // Move the drivetrain backward 2 inches.
            drivetrain->moveDistance(-2_in);

            break;
        
        // Runs the autonomous code for the right side, blue alliance (WIP).
        case -2: 
            
            break;
        
        // Does nothing for the blue alliance.
        case -3: 

            break;
        
        // Runs the skills autonomous code.
        case 0: 

            // Set the drivetrain state to zero.
            drivetrain->setState({0_in, 0_in, 0_deg});
            
            // Move the drivetrain backward 2 inches.
            drivetrain->moveDistance(-2_in);

            // Move the drivetrain forward 24 inches.
            drivetrain->moveDistance(18_in);

            // Wait for 2 seconds.
            pros::delay(2000);

            // Turn the drivetrain 90 degrees to the right.
            drivetrain->turnAngleAsync(90_deg);
            pros::delay(2000);
            if (drivetrain->isSettled() != true) {
                drivetrain->stop();
            }

            // Move the drivetrain backward 24 inches.
            drivetrain->moveDistance(-24_in);

            // Move the drivetrain forward 24 inches.
            drivetrain->moveDistance(24_in);

            break;
    
    }

}
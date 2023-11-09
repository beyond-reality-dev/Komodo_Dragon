#pragma once
#include "main.h"

// Declare the drivetrain ports.
extern int LEFT_BACK_PORT;
extern int LEFT_FRONT_PORT;
extern int RIGHT_BACK_PORT;
extern int RIGHT_FRONT_PORT;

// Declare the other motor ports.
extern int SLINGSHOT_PORT;

// Declare the pneumatic ports.
extern int LEFT_EXPANDER_PORT;
extern int RIGHT_EXPANDER_PORT;

// Declare the sensor ports.
extern int VISION_SENSOR_PORT;

// Declare the controllers.
extern pros::Controller master;

// Declare the sensors.
extern pros::Vision vision_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;
extern pros::vision_signature_s_t GREEN_SIG;

// Declare the drivetrain motors.
extern pros::Motor left_back;
extern pros::Motor left_front;
extern pros::Motor right_back;
extern pros::Motor right_front;
extern pros::Motor_Group left_wheels;
extern pros::Motor_Group right_wheels;

// Declare the other motors.
extern pros::Motor slingshot;

// Declare the pneumatics.
extern pros::ADIDigitalOut left_expander;
extern pros::ADIDigitalOut right_expander;
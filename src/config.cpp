#include "main.h"
#include "config.hpp"

// Define ports for motors and devices.
#define LEFT_BACK_PORT 1
#define LEFT_FRONT_PORT 2
#define RIGHT_BACK_PORT -3
#define RIGHT_FRONT_PORT -4
#define SLINGSHOT_PORT_1 11
#define SLINGSHOT_PORT_2 -20
#define LEFT_EXPANDER_PORT 'A'
#define RIGHT_EXPANDER_PORT 'B'
#define VISION_SENSOR_PORT 20

// Configure controllers.
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Configure the sensors.
extern pros::Vision vision_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;
extern pros::vision_signature_s_t GREEN_SIG;

// Configure drivetrain motors.
pros::Motor left_back(LEFT_BACK_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_front(LEFT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_back(RIGHT_BACK_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_front(RIGHT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group left_wheels({left_back, left_front});
pros::Motor_Group right_wheels({right_back, right_front});

// Configure other motors.
pros::Motor slingshot_1(SLINGSHOT_PORT_1, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor slingshot_2(SLINGSHOT_PORT_2, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor_Group slingshot({slingshot_1, slingshot_2});

// Configure the pneumatics.
pros::ADIDigitalOut left_expander(LEFT_EXPANDER_PORT);
pros::ADIDigitalOut right_expander(RIGHT_EXPANDER_PORT);
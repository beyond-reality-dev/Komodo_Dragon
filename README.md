# Komodo Dragon <!-- omit from toc -->

This is the official repository of VEX Robotics Competition team 5588T. 

## Table of Contents <!-- omit from toc -->

- [Features](#features)
    - [Motor Toggles](#motor-toggles)
    - [Odometry](#odometry)
    - [Autonomous Selector](#autonomous-selector)
    - [Chessboard Pathfinding System](#chessboard-pathfinding-system)
- [Future Changes](#future-changes)

## Features

### Motor Toggles

The program includes the ability to toggle the intake and launcher systems on and off, rather than having to hold a button. This allows form more efficient use of the systems, and makes it easier for the driver to operate them.

### Odometry

The program utilizes the OkapiLib library to create an odometric chassis that uses the integrated encoders in the VEX V5 Smart Motors. This allows the robot to adjust to external stimuli and more accurately perform autonomous routines. It also enables the programming of motion directly to specific points, as opposed to distances.

### Autonomous Selector

The program implements the [VEX Autonomous Selector for PROS](https://github.com/kunwarsahni01/Vex-Autonomous-Selector), a tool that allows the simple configuration of a graphical menu to choose an autonomous before a competition match. The Autonomous Selector is also used by the program to configure the automatic roller, detailed below.

### Chessboard Pathfinding System

In order to allow non-programmers on the team to be able to program autonomous routines, I created a virtual "chessboard" for the game field. The system divides the field into tiles, and allows the robot to be driven directly to those positions. The syntax is similar to that of chess notation or battleship, and will hopefully make it easier for others to create and modify autonomous programs. A visual representation of the board is included below:

## Future Changes

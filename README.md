
# Line Following Robot Using Arduino Uno

An Arduino-based line-following robot developed using two IR sensors, an L298N motor driver, and DC motors.

**Author: Muhammad Usman Shah**

## Project Overview

This project demonstrates a line-following robot that detects and follows a black path on a white surface.

Two infrared (IR) sensors detect the surface, while an Arduino Uno controls the direction of two DC motors through an L298N motor driver.

The project includes Arduino programming, circuit design, Proteus simulation, and hardware implementation.

## Working Principle

The IR sensors detect the surface underneath the robot:

- **LOW:** White surface
- **HIGH:** Black line

The Arduino processes these signals and controls motor movement.

| Right Sensor | Left Sensor | Robot Movement |
|--------------|-------------|----------------|
| LOW | LOW | Move Forward |
| HIGH | LOW | Turn Right |
| LOW | HIGH | Turn Left |
| HIGH | HIGH | Stop |

During turning, one motor reverses while the other moves forward.

## Hardware Components

- Arduino Uno
- L298N Motor Driver
- Two IR Sensors
- Two DC Motors
- Wheels and Chassis
- Jumper Wires and Switch
- 7–12 V Power Supply

## Arduino Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Right IR Sensor | 11 |
| Left IR Sensor | 12 |
| Right Motor Enable (PWM) | 6 |
| Right Motor Inputs | 7, 8 |
| Left Motor Enable (PWM) | 5 |
| Left Motor Inputs | 9, 10 |

## Tools and Technologies

- Arduino IDE
- Arduino C/C++
- Proteus
- Digital Sensors
- Motor Control

## Project Materials

The repository contains:

| Material | Description |
|----------|-------------|
| Arduino Source Code | Robot control program (.ino) |
| Project Report | Circuit design and hardware implementation |
| Project Results | Simulation and experimental results |
| Circuit Diagram | Arduino, sensors, and motor driver connections |
| Proteus Circuit | Circuit simulation |
| Path Followed | Robot testing path |
| Component Images | Images of the hardware components |

**[Browse Project Files](https://github.com/Muhammad-Usman-Shah/Line-Following-Robot-Arduino)**

## How to Run

1. Install Arduino IDE.
2. Download the Arduino source code from this repository.
3. Open `line_following_robot.ino`.
4. Connect the components according to the circuit diagram.
5. Select Arduino Uno as the board.
6. Select the correct communication port.
7. Upload the program.
8. Place the robot on the black-line track.
9. Turn on the power supply.

## Simulation and Results

### Circuit Design

The circuit connects the Arduino Uno with two IR sensors and an L298N motor driver.

### Proteus Simulation

The motor control circuit was designed and simulated using Proteus.

### Hardware Testing

The robot was tested on a black-line track. The IR sensors detected the surface, and the Arduino controlled motor movements according to the programmed logic.

The complete circuit, simulation outputs, and followed path are included in the repository files.

## Technical Notes

- The code modifies the Timer 0 prescaler for motor PWM control.
- Modifying Timer 0 affects Arduino timing functions such as `delay()` and `millis()`.
- IR sensor sensitivity may require adjustment under different lighting conditions.
- The implemented design uses two IR sensors and does not include an LCD.

## Limitations

- Sensor performance depends on lighting and surface contrast.
- Manual sensor calibration may be required.
- The robot follows a predefined line rather than planning routes independently.

## Future Improvements

- PID-based speed control
- Additional IR sensors
- Automatic sensor calibration
- Improved turning and path tracking

## Author

**Muhammad Usman Shah**

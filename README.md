
# Line Following Robot Using Arduino Uno

**EE 252L – Introduction to Embedded Systems**  
Department of Electrical Engineering  
Namal University, Mianwali, Pakistan

## Project Overview

This project implements an Arduino-based robot that follows a black line on a white surface.

Two infrared (IR) sensors detect the line, while an L298N motor driver controls the movement of two DC motors. The Arduino processes sensor inputs and adjusts motor direction to keep the robot on the path.

The project includes circuit design, Proteus simulation, Arduino programming, and hardware implementation.

## Circuit Design

The circuit connects two IR sensors and an L298N motor driver to an Arduino Uno.

[View Circuit Diagram](Images/)

## Working Principle

The IR sensors detect the surface beneath the robot:

- **LOW:** White surface
- **HIGH:** Black line

The Arduino uses these signals to control the motors.

| Right IR Sensor | Left IR Sensor | Robot Action |
|-----------------|----------------|--------------|
| LOW | LOW | Move forward |
| HIGH | LOW | Turn right |
| LOW | HIGH | Turn left |
| HIGH | HIGH | Stop |

During turning, one motor rotates in the opposite direction while the other continues forward.

## Hardware Components

- Arduino Uno
- L298N Motor Driver
- Two IR Sensors
- Two DC Motors
- Robot Wheels and Chassis
- Jumper Wires and Switch
- 7–12 V Power Supply

[View Hardware Component Images](Images/)

## Arduino Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Right IR Sensor | 11 |
| Left IR Sensor | 12 |
| Right Motor Enable (PWM) | 6 |
| Right Motor Inputs | 7, 8 |
| Left Motor Enable (PWM) | 5 |
| Left Motor Inputs | 9, 10 |

## Software and Tools

- Arduino IDE
- Embedded C++
- Proteus Design Suite

## Project Files

| Material | Link |
|----------|------|
| Arduino Source Code | [View Code](Code/line_following_robot/) |
| Project Report | [View Report](Report/) |
| Project Results | [View Results](Results/) |
| Circuit Diagram | [View Images](Images/) |
| Hardware Components | [View Components](Images/) |
| Proteus Simulation | [View Simulation](Images/) |
| Robot Test Path | [View Test Path](Images/) |

## How to Run

1. Install the Arduino IDE.
2. Download the Arduino source code.
3. Open `line_following_robot.ino` in Arduino IDE.
4. Connect the components according to the circuit diagram and pin connections.
5. Select **Arduino Uno** as the board.
6. Select the correct communication port.
7. Upload the code to the Arduino.
8. Place the robot on the black-line path.
9. Switch on the power supply.

## Simulation and Results

### Proteus Simulation

The motor control circuit was designed and simulated in Proteus.

[View Proteus Circuit](Images/)

### Path Followed

The robot was tested on a black-line path containing turns.

[View Robot Test Path](Images/)

The Arduino controls the two motors according to the IR sensor readings, allowing the robot to follow the line.

Detailed circuit diagrams and experimental results are provided in the project report and results document.

## Technical Notes

- The Arduino code modifies the Timer 0 prescaler to adjust motor PWM behaviour.
- Changing Timer 0 settings affects the timing of `delay()` and `millis()`.
- IR sensor thresholds may require adjustment under different lighting conditions.
- Although the report mentions four IR sensors and an LCD in some sections, the implemented circuit and code use two IR sensors without an LCD.

## Limitations

- Sensor readings depend on surface contrast and lighting.
- The IR sensor thresholds may need manual adjustment.
- The robot follows a predefined path and does not perform autonomous route planning.

## Possible Improvements

- PID-based motor speed control
- Additional IR sensors for improved tracking
- Automatic sensor calibration
- Improved performance on sharp turns

## Author

**Muhammad Usman Shah**

**Course:** EE 252L – Introduction to Embedded Systems

**Instructors:**
- Engr. Nureen Shoukat
- Engr. Misbah Batool

**Institution:** Namal University, Mianwali, Pakistan

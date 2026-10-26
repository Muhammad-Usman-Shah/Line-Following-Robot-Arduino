/*
  Line Following Robot

  Introduction to Embedded Systems (EE 252L) semester project.
  Namal University Mianwali, Department of Electrical Engineering.
  Written by Muhammad Usman Shah.

  What it does:
  The robot follows a black line on a white surface.
  Two IR sensors look at the floor, one on the right and one on the left.
  The Arduino Uno reads them and drives two DC motors through an L298N driver.

  How the IR sensors behave here:
  LOW means the sensor sees the white surface.
  HIGH means the sensor sees the black line.

  What the robot does for each case:
  Both sensors LOW: go straight.
  Right sensor HIGH: turn right.
  Left sensor HIGH: turn left.
  Anything else: stop.
*/

// Pins where the two IR sensors are connected.
#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_LEFT 12

// Motor speed from 0 to 255. This is the PWM value.
#define MOTOR_SPEED 180

// Right motor pins on the L298N driver.
// The enable pin sets the speed. The two input pins set the direction.
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor pins on the L298N driver.
int enableLeftMotor = 5;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

void setup() {
  // Change the timer 0 prescaler so the PWM on pins 5 and 6 runs faster.
  // The motors then run smoother and make less noise.
  // This also changes the timing of delay() and millis(), but this program does not use them.
  TCCR0B = TCCR0B & B11111000 | B00000010;

  // The right motor pins send signals out to the driver.
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  // The left motor pins send signals out to the driver.
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // The sensor pins bring signals in to the Arduino.
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  // Make sure the robot stands still when it powers on.
  rotateMotor(0, 0);
}

void loop() {
  // Read both sensors again and again.
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    // Both sensors see white, so the line is in the middle. Go straight.
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    // The right sensor sees the line. Reverse the right motor to turn right.
    rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
  } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    // The left sensor sees the line. Reverse the left motor to turn left.
    rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
  } else {
    // Both sensors see black, so stop.
    rotateMotor(0, 0);
  }
}

// Sets the direction and speed of both motors.
// A positive speed means forward, a negative speed means backward, and zero means stop.
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Right motor direction.
  if (rightMotorSpeed < 0) {
    // Backward.
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    // Forward.
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    // Stop.
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Left motor direction.
  if (leftMotorSpeed < 0) {
    // Backward.
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    // Forward.
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    // Stop.
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // The PWM value only needs the size of the speed, because the direction is already set.
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}

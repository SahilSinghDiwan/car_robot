#include <AccelStepper.h>

// Define stepper motor connection pins
const int stepperPin1 = 2;
const int stepperPin2 = 7;
const int stepperPin3 = 4;
const int stepperPin4 = 8;

// Define stepper motor using 4-wire configuration
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

// Define motor settings
const int stepsPerRevolution = 2038;  // Adjust based on your motor's specification
const int stepsPer180Degrees = stepsPerRevolution / 2; // Half rotation (180 degrees)

void setup() {
  Serial.begin(9600);
  
  // Configure motor settings
  stepper.setMaxSpeed(1000);      // Max speed in steps per second
  stepper.setAcceleration(50);    // Acceleration in steps per second^2

  Serial.println("Rotating stepper motor 180 degrees...");

  // Move the motor 180 degrees
  stepper.moveTo(stepsPer180Degrees);

  // Continue rotating until the target position is reached
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }

  Serial.println("Rotation complete.");
}

void loop() {
  // No actions in loop
}

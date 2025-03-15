#include <AccelStepper.h>

// Stepper motor setup (using a 4-wire stepper motor)
const int stepperPin1 = 2;
const int stepperPin2 = 4;
const int stepperPin3 = 7;
const int stepperPin4 = 8;
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

void setup() {
  // Set maximum speed and acceleration
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
}

void loop() {
  // Rotate stepper motor 180 degrees
  stepper.moveTo(stepper.currentPosition() + 180);
  while (stepper.distanceToGo() != 0) {
    stepper.run();  // Continuously run the stepper until it reaches the target position
  }

  // Pause for a moment before rotating again
  delay(2000); // 2-second delay before rotating again
}

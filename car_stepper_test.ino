#include <AccelStepper.h>

// Stepper motor setup (using a 4-wire stepper motor)
const int stepperPin1 = 2;
const int stepperPin2 = 4;
const int stepperPin3 = 7;
const int stepperPin4 = 8;
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  // Set maximum speed and acceleration
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  Serial.println("Stepper motor initialized.");
}

void loop() {
  // Calculate current and target positions for a 180° rotation
  long currentPos = stepper.currentPosition();
  long targetPos = currentPos + 180;
  
  Serial.print("Current Position: ");
  Serial.println(currentPos);
  Serial.print("Target Position: ");
  Serial.println(targetPos);
  
  // Set the target position
  stepper.moveTo(targetPos);
  
  // Rotate the stepper motor until the target position is reached
  while (stepper.distanceToGo() != 0) {
    stepper.run();  // Move one step towards the target
    Serial.print("Distance to go: ");
    Serial.println(stepper.distanceToGo());
    delay(100); // Short delay to slow down debug prints for readability
  }
  
  Serial.println("Target reached. Pausing before next rotation.");
  
  // Pause for a moment before rotating again
  delay(2000); // 2-second delay before starting the next rotation
}

#include <AccelStepper.h>

// -----------------------
// Stepper Motor Connections (4-wire)
// -----------------------
const int stepperPin1 = 2;
const int stepperPin2 = 4;
const int stepperPin3 = 7;
const int stepperPin4 = 8;
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

// -----------------------
// Adjustable Parameters
// -----------------------
const int stepsPer180Degrees = 1019; // Adjust this based on your motor
const int stepperMaxSpeed = 1000;
const int stepperAcceleration = 500;

const int delayBetweenSteps = 50;   // Delay between stepper movements (ms)
const int pauseAfterRotation = 1000; // Pause time (ms) after stepper rotation
const int numberOfCycles = 9;       // Number of cycles to run

// -----------------------
// Stepper Motor Function
// -----------------------
void rotateStepperMotor() {
  Serial.println("Rotating stepper motor 180 degrees...");
  long currentPos = stepper.currentPosition();
  long targetPos = currentPos + stepsPer180Degrees;

  Serial.print("Current stepper position: ");
  Serial.println(currentPos);
  Serial.print("Target stepper position: ");
  Serial.println(targetPos);

  stepper.moveTo(targetPos);

  while (stepper.distanceToGo() != 0) {
    stepper.run();
    Serial.print("Stepper remaining steps: ");
    Serial.println(stepper.distanceToGo());
    delay(delayBetweenSteps);
  }

  Serial.println("Stepper motor rotation complete.");
}

// -----------------------
// Setup Function
// -----------------------
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing system...");

  // Initialize stepper motor parameters
  stepper.setMaxSpeed(stepperMaxSpeed);
  stepper.setAcceleration(stepperAcceleration);

  Serial.println("Setup complete.");
}

// -----------------------
// Main Loop
// -----------------------
void loop() {
  for (int cycle = 0; cycle < numberOfCycles; cycle++) {
    Serial.print("Cycle ");
    Serial.print(cycle + 1);
    Serial.println(": Rotating stepper motor...");

    // Rotate the stepper motor 180°
    rotateStepperMotor();

    // Pause before starting the next cycle
    Serial.print("Pausing for ");
    Serial.print(pauseAfterRotation);
    Serial.println(" ms before next rotation.");
    delay(pauseAfterRotation);
  }

  Serial.println("All cycles completed. System halting.");
  while (true);  // Halt the program
}

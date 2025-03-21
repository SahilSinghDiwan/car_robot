#include <AccelStepper.h>

// -----------------------
// Stepper Motor Configuration
// -----------------------
#define MotorInterfaceType 4
AccelStepper stepper(MotorInterfaceType, 2, 7, 4, 8);

// -----------------------
// Adjustable Parameters
// -----------------------
int stepperMaxSpeed = 1000;       // Max speed for stepper motor
int stepperAcceleration = 50;     // Acceleration for smoother movement
int stepperSpeed = 200;           // Stepper rotation speed
int stepsPer180Degrees = 2038;    // Adjust this based on actual stepper specs

int leftMotorPin1 = 5;
int leftMotorPin2 = 6;
int leftMotorSpeedPin = 3;

int rightMotorPin1 = 9;
int rightMotorPin2 = 10;
int rightMotorSpeedPin = 11;

int leftMotorSpeed = 200;         // Speed for left motor (0-255)
int rightMotorSpeed = 150;        // Speed for right motor (0-255)
unsigned long travelTime = 3000;  // Time (ms) the car moves before stopping
unsigned long pauseTime = 1000;   // Pause delay (ms) after stepper rotation
int numberOfCycles = 9;           // Number of cycles to run

// -----------------------
// Motor Control Functions
// -----------------------
void moveForward(int leftSpeed, int rightSpeed) {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  analogWrite(leftMotorSpeedPin, leftSpeed);
  analogWrite(rightMotorSpeedPin, rightSpeed);
}

void stopCar() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);

  analogWrite(leftMotorSpeedPin, 0);
  analogWrite(rightMotorSpeedPin, 0);
}

// -----------------------
// Stepper Motor Function
// -----------------------
void rotateStepperMotor() {
  stepper.moveTo(stepper.currentPosition() + stepsPer180Degrees);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500); // Short pause after rotation
}

// -----------------------
// Setup Function
// -----------------------
void setup() {
  Serial.begin(9600);

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);

  stepper.setMaxSpeed(stepperMaxSpeed);
  stepper.setAcceleration(stepperAcceleration);
  stepper.setSpeed(stepperSpeed);
}

// -----------------------
// Main Loop
// -----------------------
void loop() {
  for (int cycle = 0; cycle < numberOfCycles; cycle++) {
    Serial.print("Cycle ");
    Serial.print(cycle + 1);
    Serial.println(": Car moving forward...");

    moveForward(leftMotorSpeed, rightMotorSpeed);
    delay(travelTime);

    stopCar();
    Serial.println("Car stopped. Rotating stepper motor...");

    rotateStepperMotor();

    Serial.print("Pausing for ");
    Serial.print(pauseTime);
    Serial.println(" ms before next cycle.");
    delay(pauseTime);
  }

  stopCar();
  Serial.println("All cycles completed. System halted.");
  while (true);
}

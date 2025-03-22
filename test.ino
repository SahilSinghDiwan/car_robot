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

// Define motor settings
const int stepsPerRevolution = 2038;  // Adjust based on your motor's specification

// Motor pins
int leftMotorPin1 = 5;
int leftMotorPin2 = 6;
int leftMotorSpeedPin = 3;

int rightMotorPin1 = 9;
int rightMotorPin2 = 10;
int rightMotorSpeedPin = 11;

// Speed and timing
int leftMotorSpeed = 160;       
int rightMotorSpeed = 160;        

unsigned long initialTravelTime = 1250;  // Fine-tune first stop
unsigned long subsequentTravelTime = 1000; // Fine-tune subsequent stops
unsigned long pauseTime = 500;  // Pause delay after stepper rotation
int numberOfCycles = 9;

// Stepper rotation
int initialStepperRotationDegrees = 180;  // Initial rotation
int subsequentStepperRotationDegrees = 90;  // Subsequent rotations

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
void rotateStepperMotor(int rotationDegrees) {
  int steps = (rotationDegrees * stepsPerRevolution) / 360;
  stepper.moveTo(stepper.currentPosition() + steps);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500); 
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

    // Fine-tuning initial and subsequent stops
    if (cycle == 0) {
      delay(initialTravelTime);
    } else {
      delay(subsequentTravelTime);
    }

    stopCar();
    Serial.println("Car stopped. Rotating stepper motor...");

    // Fine-tuning stepper rotation
    if (cycle == 0) {
      rotateStepperMotor(initialStepperRotationDegrees);
    } else {
      rotateStepperMotor(subsequentStepperRotationDegrees);
    }

    Serial.print("Pausing for ");
    Serial.print(pauseTime);
    Serial.println(" ms before next cycle.");
    delay(pauseTime);
  }

  stopCar();
  Serial.println("All cycles completed. System halted.");
  while (true);
}

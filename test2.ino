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
const int stepsPer180Degrees = stepsPerRevolution / 2; // Half rotation (180 degrees)


int leftMotorPin1 = 5;
int leftMotorPin2 = 6;
int leftMotorSpeedPin = 3;

int rightMotorPin1 = 9;
int rightMotorPin2 = 10;
int rightMotorSpeedPin = 11;

int leftMotorSpeed = 160;         // Speed for left motor (0-255)
int rightMotorSpeed = 160;        // Speed for right motor (0-255)
unsigned long travelTime = 1250;  // Time (ms) the car moves before stopping
unsigned long pauseTime = 10;   // Pause delay (ms) after stepper rotation
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
  delay(500); // Short pause after rotation
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

  delay(4000);

  // First stop
  Serial.println(": Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Second Stop
  Serial.println(": Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Third Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Fourth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Fifth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Sixth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Seventh Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Eighth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Ninth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);

  // Final Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor();
  delay(500);
}

void loop() {
  // Do nothing, as all actions are in the setup() function
}

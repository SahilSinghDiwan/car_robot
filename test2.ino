// Include the AccelStepper Library
#include <AccelStepper.h>

// Define step constant
#define MotorInterfaceType 4

// Creates an instance
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper myStepper(MotorInterfaceType, 2, 7, 4, 8);

// -----------------------
// Adjustable Parameters
// -----------------------
int stepperMaxSpeed = 1000;       // Max speed for stepper motor
int stepperAcceleration = 50;     // Acceleration for smoother movement
int stepperSpeed = 200;           // Stepper rotation speed

// Define motor settings
const int stepsPerRevolution = 2038;  // Adjust based on your motor's specification
const int stepsPer180Degrees = stepsPerRevolution / 2; // Half rotation (180 degrees)

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

unsigned long pauseTime = 500;

// -----------------------
// Motor Control Functions
// -----------------------
void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  analogWrite(leftMotorSpeedPin, leftMotorSpeed);
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);
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
  int steps = stepsPer180Degrees * rotationDegrees / 180;
	myStepper.moveTo(steps);
	// Move the motor one step
	myStepper.run();
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

  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(50.0);
  myStepper.setSpeed(200);
  // delay of 4 seconds for testing if the code is working or not
  delay(4000);

  // First stop
  Serial.println(": Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Second Stop
  Serial.println(": Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Third Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Fourth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Fifth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Sixth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Seventh Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Eighth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Ninth Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);

  // Final Stop
  Serial.println("Car moving forward...");
  moveForward();
  delay(1250);
  stopCar();
  delay(500);
  Serial.println("Car stopped. Rotating stepper motor...");
  rotateStepperMotor(180);
  delay(500);
}

void loop() {
  // Do nothing, as all actions are in the setup() function
}

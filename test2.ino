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

// Movement time and rotation degrees for each stop
unsigned long movementTimes[10] = {1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250};
// Change the travel time according to overshoot and undershoot of the robot
int stepperRotationDegrees[10] = {180, 180, 180, 180, 180, 180, 180, 180, 180, 180};
// change the stepper rotation according to overshoot and undershoot of the stepper

// Pause time after each stop
unsigned long pauseTime = 500;

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

  // Perform 10 Stops
  for (int i = 0; i < 10; i++) {
    Serial.print("Stop ");
    Serial.print(i + 1);
    Serial.println(": Car moving forward...");

    moveForward(leftMotorSpeed, rightMotorSpeed);
    delay(movementTimes[i]);
    
    stopCar();
    Serial.println("Car stopped. Rotating stepper motor...");

    rotateStepperMotor(stepperRotationDegrees[i]);

    Serial.print("Pausing for ");
    Serial.print(pauseTime);
    Serial.println(" ms before next stop.");
    delay(pauseTime);
  }

  stopCar();
  Serial.println("All stops completed. System halted.");
}

void loop() {
  // Do nothing, as all actions are in the setup() function
}

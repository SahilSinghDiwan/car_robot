#include <NewPing.h>
#include <AccelStepper.h>

// Define motor driver pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
 
// Define PWM pins for speed control
const int motor1SpeedPin = 3; // PWM pin for motor1 speed (left motor)
const int motor2SpeedPin = 11; // PWM pin for motor2 speed (right motor)

// Ultrasonic sensor pins
const int trigPin = 12;
const int echoPin = 13;

// Initialize ultrasonic sensor
NewPing sonar(trigPin, echoPin, 200);

// Stepper motor setup
const int stepperPin1 = 2;
const int stepperPin2 = 4;
const int stepperPin3 = 7;
const int stepperPin4 = 8;
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

// Adjustable parameters
int leftMotorSpeed = 200;  // Speed for the left motor (0-255)
int rightMotorSpeed = 150; // Speed for the right motor (0-255)
int initialStopDistance = 6; // Initial stop distance in inches
int sequentialStopDistance = 12; // Distance after first stop in inches
int numberOfStops = 9; // Number of sequential stops after the first stop
int stepperRotationAngle = 180; // Stepper motor rotation in degrees

void setup() {
  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Set PWM speed pins as outputs
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  
  // Initialize stepper motor
  stepper.setMaxSpeed(1000); // Set maximum speed for stepper
  stepper.setAcceleration(500); // Set stepper acceleration
}

void moveForward(int leftSpeed, int rightSpeed) {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}

void moveBackward(int leftSpeed, int rightSpeed) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 0);
}

long readDistance() {
  long duration = sonar.ping();
  long distance = sonar.convert_cm(duration);
  return distance;
}

void rotateStepperMotor() {
  // Rotate stepper motor 180 degrees
  stepper.moveTo(stepper.currentPosition() + stepperRotationAngle);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
}

void loop() {
  for (int stopCount = 0; stopCount < numberOfStops; stopCount++) {
    // Measure distance
    long distance = readDistance();

    // Move forward until the desired distance is reached
    while (distance > initialStopDistance) {
      moveForward(leftMotorSpeed, rightMotorSpeed);
      distance = readDistance();
    }

    // Stop car at the desired distance
    stopCar();
    delay(500); // Pause before rotating stepper motor

    // Rotate stepper motor 180 degrees
    rotateStepperMotor();

    // Adjust the stop distance after the first stop
    if (stopCount < numberOfStops - 1) {
      initialStopDistance = sequentialStopDistance; // Update stop distance for subsequent stops
    }

    // Pause before moving again
    delay(1000); // Wait before moving to next stop
  }

  // Stop the car after all stops
  stopCar();
  while (true); // Stop the loop after completing all stops
}

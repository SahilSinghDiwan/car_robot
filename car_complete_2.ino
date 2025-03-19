#include <AccelStepper.h>

// -----------------------
// DC Motor Connections
// -----------------------
// Left motor pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor1SpeedPin = 3;  // PWM pin for left motor speed

// Right motor pins
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
const int motor2SpeedPin = 11; // PWM pin for right motor speed

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
int leftMotorSpeed = 200;         // Speed for left motor (0-255)
int rightMotorSpeed = 150;        // Speed for right motor (0-255)
unsigned long travelTime = 3000;  // Time (in ms) the car moves before stopping
unsigned long pauseTime = 1000;   // Pause delay (in ms) after stepper rotation
int numberOfCycles = 9;           // Number of cycles to run

// Define the number of steps required for a 180° rotation.
// For example, if your stepper motor has 200 steps per revolution, 180° = 100 steps.
// Adjust this value based on your motor's specifications.
const int stepsPer180Degrees = 100;

// -----------------------
// Motor Control Functions
// -----------------------
void moveForward(int leftSpeed, int rightSpeed) {
  Serial.print("Moving forward. Left speed: ");
  Serial.print(leftSpeed);
  Serial.print(" | Right speed: ");
  Serial.println(rightSpeed);
  
  // Set left motor forward direction:
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  
  // Set right motor forward direction:
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  
  // Set speeds via PWM:
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}

void stopCar() {
  Serial.println("Stopping car.");
  // Turn off motor directions
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  // Stop PWM outputs
  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 0);
}

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
  
  // Run the stepper until it reaches the target position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
    Serial.print("Stepper remaining steps: ");
    Serial.println(stepper.distanceToGo());
    delay(50); // Short delay for readability
  }
  
  Serial.println("Stepper motor rotation complete.");
}

// -----------------------
// Setup Function
// -----------------------
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing system...");
  
  // Initialize motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  
  // Initialize stepper motor parameters
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  
  Serial.println("Setup complete.");
}

// -----------------------
// Main Loop
// -----------------------
void loop() {
  for (int cycle = 0; cycle < numberOfCycles; cycle++) {
    Serial.print("Cycle ");
    Serial.print(cycle + 1);
    Serial.println(": Car moving forward...");
    
    // Move the car forward with specified speeds
    moveForward(leftMotorSpeed, rightMotorSpeed);
    
    // Let the car move for a specified time (simulate distance traveled)
    Serial.print("Car moving for ");
    Serial.print(travelTime);
    Serial.println(" ms.");
    delay(travelTime);
    
    // Stop the car
    stopCar();
    Serial.println("Car stopped. Preparing to rotate stepper motor...");
    delay(500);  // Short pause before stepper rotation
    
    // Rotate the stepper motor 180°
    rotateStepperMotor();
    
    // Pause before starting the next cycle
    Serial.print("Pausing for ");
    Serial.print(pauseTime);
    Serial.println(" ms before next move.");
    delay(pauseTime);
  }
  
  // After completing all cycles, stop the car and halt further execution
  stopCar();
  Serial.println("All cycles completed. System halting.");
  while (true);  // Halt the program
}

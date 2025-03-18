#include <NewPing.h>
#include <AccelStepper.h>

// Define motor driver pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;

// Define PWM pins for speed control
const int motor1SpeedPin = 3;  // PWM pin for motor1 speed (left motor)
const int motor2SpeedPin = 11; // PWM pin for motor2 speed (right motor)

// Ultrasonic sensor pins
const int trigPin = 12;
const int echoPin = 13;

// Initialize ultrasonic sensor (maximum distance in cm)
NewPing sonar(trigPin, echoPin, 200);

// Stepper motor setup
const int stepperPin1 = 2;
const int stepperPin2 = 4;
const int stepperPin3 = 7;
const int stepperPin4 = 8;
AccelStepper stepper(AccelStepper::FULL4WIRE, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

// Adjustable parameters
int leftMotorSpeed = 200;       // Speed for the left motor (0-255)
int rightMotorSpeed = 150;      // Speed for the right motor (0-255)
int initialStopDistance = 6;    // Initial stop distance in inches
int sequentialStopDistance = 12; // Distance after first stop in inches
int numberOfStops = 9;          // Number of sequential stops after the first stop

// Define the number of steps needed for 180° rotation.
// For example, if your stepper has 200 steps per revolution, 180° = 100 steps.
// Adjust this value if you are using microstepping or a different motor.
const int stepsPer180Degrees = 100;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Initializing setup...");

  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set PWM speed pins as outputs
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);

  // Initialize stepper motor parameters
  stepper.setMaxSpeed(1000);   // Set maximum speed for stepper
  stepper.setAcceleration(500); // Set stepper acceleration

  Serial.println("Setup complete.");
}

void moveForward(int leftSpeed, int rightSpeed) {
  Serial.print("Moving forward with Left Speed: ");
  Serial.print(leftSpeed);
  Serial.print(" | Right Speed: ");
  Serial.println(rightSpeed);

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}

void moveBackward(int leftSpeed, int rightSpeed) {
  Serial.print("Moving backward with Left Speed: ");
  Serial.print(leftSpeed);
  Serial.print(" | Right Speed: ");
  Serial.println(rightSpeed);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}

void stopCar() {
  Serial.println("Stopping car...");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 0);
}

long readDistance() {
  delay(50); // Allow sensor to settle
  unsigned int uS = sonar.ping(); // Get ping time in microseconds
  // Convert microseconds to inches using NewPing's constant US_ROUNDTRIP_IN
  long distanceInches = uS / US_ROUNDTRIP_IN;
  Serial.print("Distance: ");
  Serial.print(distanceInches);
  Serial.println(" inches");
  return distanceInches;
}

void rotateStepperMotor() {
  Serial.println("Rotating stepper motor 180 degrees...");
  // Calculate target position using the predefined steps for 180 degrees.
  long targetPosition = stepper.currentPosition() + stepsPer180Degrees;
  stepper.moveTo(targetPosition);
  // Run the stepper until the target is reached.
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  Serial.println("Stepper motor rotation complete.");
}

void loop() {
  for (int stopCount = 0; stopCount < numberOfStops; stopCount++) {
    Serial.print("Stop count: ");
    Serial.println(stopCount + 1);

    // Measure distance before moving
    long distance = readDistance();

    // Move forward until the car reaches the specified stop distance.
    while (distance > initialStopDistance) {
      moveForward(leftMotorSpeed, rightMotorSpeed);
      delay(100); // Allow some time for the movement
      distance = readDistance();
    }

    // Stop the car once the desired distance is reached.
    stopCar();
    delay(500); // Short pause before stepper rotation

    // Rotate the stepper motor 180 degrees.
    rotateStepperMotor();

    // Update stop distance after the first stop for subsequent stops.
    if (stopCount < numberOfStops - 1) {
      initialStopDistance = sequentialStopDistance;
      Serial.print("Updated stop distance: ");
      Serial.print(initialStopDistance);
      Serial.println(" inches");
    }
    
    // Pause before the car moves to the next stop.
    delay(1000);
  }

  // Final stop after completing all stops.
  stopCar();
  Serial.println("All stops completed. Car stopped.");
  while (true); // End the loop.
}

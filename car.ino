// Define motor driver pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
 
// Define PWM pins for speed control
const int motor1SpeedPin = 3; // PWM pin for motor1 speed (left motor)
const int motor2SpeedPin = 11; // PWM pin for motor2 speed (right motor)

 
void setup() {
  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Set PWM speed pins as outputs
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
}
 
// Function to move forward with independent speed control for left and right motors
void moveForward(int leftSpeed, int rightSpeed) {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  
  // Control speed with PWM
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}
 
// Function to move backward with independent speed control for left and right motors
void moveBackward(int leftSpeed, int rightSpeed) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  
  // Control speed with PWM
  analogWrite(motor1SpeedPin, leftSpeed);
  analogWrite(motor2SpeedPin, rightSpeed);
}
 
// Function to stop the motors
void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  // Stop motors by setting PWM to 0
  analogWrite(motor1SpeedPin, 0);
  analogWrite(motor2SpeedPin, 0);
}
 
void loop() {
  // Set desired speeds for the left and right motors
  leftMotorSpeed = 200;  // Speed for the left motor (0-255)
  rightMotorSpeed = 150; // Speed for the right motor (0-255)
  
  moveForward(leftMotorSpeed, rightMotorSpeed); // Move forward with different speeds
  delay(2000);
  stopCar();
  delay(1000);
  
  moveBackward(leftMotorSpeed, rightMotorSpeed); // Move backward with different speeds
  delay(2000);
  stopCar();
  delay(1000);
}

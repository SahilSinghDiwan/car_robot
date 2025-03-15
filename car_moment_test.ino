// Define motor driver pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
 
// Define PWM pins for speed control
const int motor1SpeedPin = 3; 
const int motor2SpeedPin = 11; 

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

void loop() {
  moveForward(200, 150); // Move forward with speeds (left, right)
  delay(2000);
  stopCar();
  delay(1000);
  
  moveBackward(200, 150); // Move backward with speeds (left, right)
  delay(2000);
  stopCar();
  delay(1000);
}

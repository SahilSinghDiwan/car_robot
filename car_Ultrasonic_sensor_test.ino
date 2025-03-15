#include <NewPing.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

// Initialize the ultrasonic sensor
NewPing sonar(trigPin, echoPin, 200);

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Get the distance in cm
  long distance = sonar.ping_cm();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait for a moment before the next reading
}

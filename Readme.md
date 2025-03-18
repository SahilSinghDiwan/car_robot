Here’s a simple and easy-to-understand connection chart for an Arduino Uno with all the components like motors, motor drivers, ultrasonic sensor, stepper motor, and the battery. The format will be "Arduino Pin >> Component Pin," which should make it easy to follow:

### **Connection Chart for Arduino Uno and Components**

---

#### **Motor Driver Connections:**

- **Arduino Pin 5** >> **IN1 on Motor Driver (Motor 1 - Forward Direction)**
- **Arduino Pin 6** >> **IN2 on Motor Driver (Motor 1 - Reverse Direction)**
- **Arduino Pin 9** >> **IN1 on Motor Driver (Motor 2 - Forward Direction)**
- **Arduino Pin 10** >> **IN2 on Motor Driver (Motor 2 - Reverse Direction)**

  These control the direction of the motors connected to the motor driver.

#### **PWM Speed Control for Motors:**

- **Arduino Pin 3** >> **Motor Driver (Motor 1 - Speed Control)**
- **Arduino Pin 11** >> **Motor Driver (Motor 2 - Speed Control)**

  These control the speed of the motors using Pulse Width Modulation (PWM).

#### **Ultrasonic Sensor Connections:**

- **Arduino Pin 12** >> **Trig Pin on Ultrasonic Sensor**
- **Arduino Pin 13** >> **Echo Pin on Ultrasonic Sensor**

  These pins help the Arduino send and receive signals to measure distance.

#### **Stepper Motor Connections:**

- **Arduino Pin 2** >> **IN1 on Stepper Motor**
- **Arduino Pin 4** >> **IN2 on Stepper Motor**
- **Arduino Pin 7** >> **IN3 on Stepper Motor**
- **Arduino Pin 8** >> **IN4 on Stepper Motor**

  These pins control the stepper motor's movement.

#### **Battery Connections:**

- **Battery Positive (+)** >> **Motor Driver VCC Pin (or 5V Pin on Arduino if you are powering Arduino from the same battery)**
- **Battery Negative (−)** >> **Motor Driver GND Pin (and also connect to Arduino GND)**
- **Barrel Connector** >> **Arduino**

  The battery powers both the Arduino and the motor driver, as well as other components.

---

### **Summary of Components and Their Connections:**

| **Component**             | **Arduino Pin** | **Component Pin**                    |
| ------------------------- | --------------- | ------------------------------------ |
| **Motor 1 (Left Motor)**  | Pin 5 (IN1)     | Motor Driver Pin IN1 (Motor 1)       |
|                           | Pin 6 (IN2)     | Motor Driver Pin IN2 (Motor 1)       |
| **Motor 2 (Right Motor)** | Pin 9 (IN1)     | Motor Driver Pin IN1 (Motor 2)       |
|                           | Pin 10 (IN2)    | Motor Driver Pin IN2 (Motor 2)       |
| **Motor Speed Control**   | Pin 3           | Motor Driver Pin for Speed (Motor 1) |
|                           | Pin 11          | Motor Driver Pin for Speed (Motor 2) |
| **Ultrasonic Sensor**     | Pin 12          | Trig Pin                             |
|                           | Pin 13          | Echo Pin                             |
| **Stepper Motor**         | Pin 2           | IN1 on Stepper Motor                 |
|                           | Pin 4           | IN2 on Stepper Motor                 |
|                           | Pin 7           | IN3 on Stepper Motor                 |
|                           | Pin 8           | IN4 on Stepper Motor                 |
| **Battery**               | (+)             | VCC (Motor Driver or Arduino)        |
|                           | (−)             | GND (Motor Driver and Arduino)       |

---

### **How to Power the Components:**

- The **battery** (e.g., 12V DC battery) powers both the **Arduino Uno** and the **motor driver**.
- Connect the **positive terminal (+)** of the battery to the **VCC** pin on the motor driver and **5V** on the Arduino (if you use a 5V Arduino power supply).
- Connect the **negative terminal (−)** of the battery to the **GND** pin on the motor driver and **GND** on the Arduino.

---

### **Important Notes:**

- Ensure that the **GND** of the battery, motor driver, and Arduino are connected to each other to form a common ground. This is important for proper communication between components.
- The **motor driver** should be powered by the battery, as it requires more power to drive the motors.

This should make it very clear for you, and feel free to refer to the pins directly for easier understanding!

# Debugging Document

## 1. Overview

This code rotates a 4-wire stepper motor 180° using the AccelStepper library. The added debugging statements help track:

- The current position of the motor.
- The target position (which is current + 180).
- The remaining steps needed to reach the target position.

## 2. Debugging Features

### Serial Communication Initialization:

- `Serial.begin(9600);` initializes communication at a 9600 baud rate.
- A message "Stepper motor initialized." confirms the setup.

### Position Tracking:

- Before moving, the code prints the current position and target position.
- This helps verify that the motor calculates the target correctly.

### Monitoring Movement:

- Inside the while loop, the code prints the distance to go (i.e., the remaining steps until the target is reached).
- A short delay (`delay(100);`) slows the debug output to make it readable.

### Completion Notification:

- Once the target is reached, the code prints "Target reached. Pausing before next rotation."
- A 2-second delay allows you to observe the final state before the next rotation begins.

## 3. Debugging Steps

### Open the Serial Monitor:

- In the Arduino IDE, go to `Tools → Serial Monitor` and set the baud rate to 9600.

### Observe Initialization:

- Check for the message "Stepper motor initialized." to confirm that the board is set up correctly.

### Monitor Rotation:

- When the loop starts, note the Current Position and Target Position.
- Watch the Distance to go values. They should steadily decrease until they reach zero.
- If the distance value does not decrease as expected, verify the wiring and configuration of your stepper motor.

### Final Rotation Check:

- When "Target reached. Pausing before next rotation." appears, ensure that the motor has indeed rotated 180°.
- If it does not, adjust the target calculation or the number of steps per rotation according to your motor’s specifications.

## 4. Troubleshooting Tips

### Inconsistent Position Values:

- Verify that your stepper motor and driver are properly connected.
- Check for mechanical resistance or binding in the motor mechanism.

### Unexpected Behavior:

- If the stepper reverses direction or stops prematurely, double-check the target position calculation.
- Ensure that your power supply provides sufficient current to the stepper motor.

### Debug Output Overload:

- If too many debug messages make it hard to follow, consider increasing the delay inside the while loop or only printing when significant changes occur.

# Debugging Document

## 1. Overview

This project involves a mobile car controlled by an Arduino Uno, which includes:

- DC motors for driving the car.
- An ultrasonic sensor for distance measurements (in inches).
- A stepper motor that rotates 180° at each stop.
- Debugging messages printed to the Serial Monitor to track operations and sensor readings.

## 2. Code Explanation

### Motor Control Functions:

- **moveForward() / moveBackward():**  
  These functions set the digital pins to control motor direction and use PWM to set speed. Debug messages print the action and speed values.

- **stopCar():**  
  Stops the motors and prints a message indicating the car has stopped.

### Sensor Reading:

- **readDistance():**  
  Uses the NewPing library to measure the distance. The time (in microseconds) is converted into inches using the constant `US_ROUNDTRIP_IN`. The measured distance is printed to the Serial Monitor.

### Stepper Motor Rotation:

- **rotateStepperMotor():**  
  Moves the stepper motor by a number of steps defined by `stepsPer180Degrees`. The target position is calculated by adding the step count to the current position. It prints messages before and after rotation.

### Main Loop (`loop()`):

- The car moves forward until the measured distance is less than or equal to the stop distance.
- After stopping, the stepper motor rotates 180°.
- The process repeats for the defined number of stops.
- Debug messages print the stop count, distance readings, and updated stop distance.

## 3. Debugging Steps

### Serial Monitor Setup:

1. Open the Serial Monitor in the Arduino IDE (Tools → Serial Monitor).
2. Set the baud rate to 9600.

### Observe Initialization:

- Look for "Initializing setup..." followed by "Setup complete." to confirm the board is starting correctly.

### Monitor Motor Actions:

- Check for messages like "Moving forward with Left Speed: ... | Right Speed: ...".
- When the car reaches the set distance, ensure that "Stopping car..." appears.

### Verify Sensor Readings:

- Each call to `readDistance()` should print a distance value in inches.
- Confirm that the distance decreases as the car moves.

### Check Stepper Rotation:

- The Serial Monitor should display "Rotating stepper motor 180 degrees..." and later "Stepper motor rotation complete."
- If the motor rotates less than 180° or reverses, verify that `stepsPer180Degrees` is set correctly based on your motor’s specification.
- If microstepping is used, adjust the step count accordingly.

### Final Stop Verification:

- After the final stop, the message "All stops completed. Car stopped." confirms the loop has ended.

## 4. Troubleshooting Tips

### Stepper Motor Not Rotating as Expected:

- Double-check the value of `stepsPer180Degrees`. For a 200-step motor, 180° typically equals 100 steps.
- Ensure your wiring to the stepper motor matches the pin assignments in the code.
- If using microstepping, multiply the step count by the microstepping factor.

### Car Not Moving:

- Verify that the power supply meets the motor's current and voltage requirements.
- Check that all motor driver connections are secure.
- Use the debug messages to confirm that commands to move forward are being executed.

### Inconsistent Sensor Readings:

- Ensure the ultrasonic sensor is positioned correctly and that there are no obstructions.
- Confirm that the sensor is connected to the correct pins.

## 5. Additional Considerations

### Adjustable Parameters:

You can modify `leftMotorSpeed`, `rightMotorSpeed`, `initialStopDistance`, and `sequentialStopDistance` to fit your project's needs.

### Fine-Tuning:

- Use the Serial Monitor to fine-tune motor speeds and step counts.
- If necessary, add additional debug messages to further isolate issues.

## 6. Conclusion

This document and the accompanying code should provide you with the necessary tools to debug and adjust your Arduino car project. By following the debugging steps, you’ll be able to pinpoint issues—whether they lie with motor control, sensor readings, or stepper rotation—and make the appropriate adjustments for a smoothly operating system.

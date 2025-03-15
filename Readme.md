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

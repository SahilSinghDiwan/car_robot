# Stepper Motor Control for Car Movement

This project controls a small car using four BO motors and a stepper motor for precise rotations. The L298N motor driver is used to control the BO motors, and a 28BYJ-48 stepper motor is used for rotating the car.

## Components Needed

- 4x **BO Motors**
- 1x **L298N Motor Driver**
- 1x **28BYJ-48 Stepper Motor**
- 1x **ULN2003 Stepper Motor Driver**
- 1x **Arduino**
- Jumper wires
- Power Supply (9vV for motors)

---

## Wiring Connections

### **L298N Motor Driver to Arduino**

- IN1 → Pin **5** (Left Motor Control)
- IN2 → Pin **6** (Left Motor Control)
- IN3 → Pin **9** (Right Motor Control)
- IN4 → Pin **10** (Right Motor Control)
- ENA → Pin **3** (Left Motor Speed)
- ENB → Pin **11** (Right Motor Speed)
- GND → Arduino **GND**
- 9V → External Power Supply (9V)

### **28BYJ-48 Stepper Motor to ULN2003 Driver**

- Connect the stepper motor to the ULN2003 driver using its connector.
- IN1 → Pin **2** (Stepper Control)
- IN2 → Pin **7** (Stepper Control)
- IN3 → Pin **4** (Stepper Control)
- IN4 → Pin **8** (Stepper Control)
- GND → Motor Driver Ground **GND**
- VCC → Motor Driver 5V **5V**

---

## How It Works

1. The car moves forward using the four BO motors controlled by the L298N motor driver.
2. After reaching a set time, the car stops.
3. The 28BYJ-48 stepper motor then rotates the car by 180 degrees.
4. The car moves forward again, repeating the process for 10 stops.
5. All the actions happen in the `setup()` function, so the car follows the sequence without using the `loop()` function.

---

## Code Explanation

- **moveForward()**: Turns on the motors to move the car forward.
- **stopCar()**: Stops the car by cutting off the motor power.
- **rotateStepperMotor()**: Rotates the car using the stepper motor.

You can adjust the following parameters for better performance:

- `leftMotorSpeed` and `rightMotorSpeed` to change the speed.
- `travelTime` to change how long the car moves before stopping.
- `pauseTime` to add a delay after each stop.

---

## Safety Tips

- Make sure the connections are correct to avoid damaging the components.
- Do not run the motors for too long without breaks to prevent overheating.
- Keep the stepper motor’s driver board cool by providing proper ventilation.

---

## Final Note

Once everything is connected, upload the code to your Arduino and power up the system. The car will move forward, stop, rotate using the stepper motor, and repeat the process 10 times. Happy building!

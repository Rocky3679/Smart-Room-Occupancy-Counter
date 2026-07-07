# Installation Guide

## 1. Introduction

This guide explains how to assemble the hardware, install the required software, upload the program to the Arduino UNO, and verify the operation of the Smart Room Occupancy Counter.

---

# 2. Software Requirements

Install the following software before starting:

- Arduino IDE (Version 2.x or later)
- Visual Studio Code (Optional)
- Arduino Extension for VS Code (Optional)

Install these libraries using the Arduino Library Manager:

- Adafruit GFX
- Adafruit SSD1306
- Wire

---

# 3. Hardware Requirements

- Arduino UNO
- 2 × IR Sensor Modules
- SSD1306 OLED Display
- Single Channel Relay Module
- COB LED
- Breadboard
- Jumper Wires
- USB Cable

---

# 4. Hardware Connections

| Arduino Pin | Device |
|-------------|--------|
| D2 | IR Sensor A |
| D3 | IR Sensor B |
| D8 | Relay Module |
| A4 | OLED SDA |
| A5 | OLED SCL |
| 5V | Power Supply |
| GND | Common Ground |

---

# 5. Software Installation

1. Install Arduino IDE.
2. Open the Arduino IDE.
3. Install the required libraries.
4. Open `Smart_Occupancy_Counter.ino`.
5. Select **Tools → Board → Arduino UNO**.
6. Select the correct COM Port.

---

# 6. Upload Procedure

1. Connect the Arduino UNO using a USB cable.
2. Verify the program.
3. Upload the program.
4. Wait until the upload completes successfully.
5. Open the Serial Monitor if debugging is required.

---

# 7. System Testing

After uploading the program:

- Power ON the Arduino.
- Verify that the OLED display initializes correctly.
- Move an object through Sensor A followed by Sensor B.
- Confirm that the occupancy count increases.
- Move through Sensor B followed by Sensor A.
- Confirm that the occupancy count decreases.
- Verify that the relay switches ON when occupancy is greater than zero.
- Verify that the relay switches OFF when occupancy becomes zero.

---

# 8. Installation Tips

- Keep both IR sensors aligned properly.
- Maintain approximately 5–10 cm spacing between the sensors.
- Ensure all modules share a common ground.
- Secure loose jumper wire connections.
- Verify the OLED I2C address (commonly 0x3C).

---

# 9. Deployment Notes

The project is intended as a prototype for indoor occupancy monitoring. For permanent installations, a custom PCB, protective enclosure, and regulated power supply are recommended.

---

# 10. Conclusion

Following the above procedure ensures successful installation and operation of the Smart Room Occupancy Counter. Proper wiring, sensor alignment, and software configuration are essential for accurate occupancy detection and reliable automatic lighting control.
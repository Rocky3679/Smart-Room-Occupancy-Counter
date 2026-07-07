# Project Specification

## 1. Project Title

**Smart Room Occupancy Counter with OLED Display and Automatic Light Control**

---

# 2. Problem Statement

In many homes, classrooms, laboratories, offices, and meeting rooms, lights are often left ON even when the room is empty. This results in unnecessary electricity consumption and increased operating costs.

The objective of this project is to develop an embedded system capable of automatically detecting room occupancy and controlling the lighting system without human intervention.

---

# 3. Project Objectives

- Detect people entering and leaving a room.
- Maintain an accurate occupancy count.
- Display the occupancy count on an OLED display.
- Automatically switch the room light ON when occupied.
- Automatically switch the room light OFF when the room becomes empty.
- Demonstrate embedded programming using Arduino.

---

# 4. Scope of the Project

This project is intended for small indoor environments where automatic occupancy monitoring and basic energy saving are required.

Typical applications include:

- Classrooms
- Laboratories
- Offices
- Conference Rooms
- Libraries
- Smart Homes

---

# 5. Functional Requirements

The system shall:

- Detect entry using two IR sensors.
- Detect exit using two IR sensors.
- Increase occupancy count for every valid entry.
- Decrease occupancy count for every valid exit.
- Prevent negative occupancy values.
- Display the current occupancy count.
- Turn ON the relay when occupancy is greater than zero.
- Turn OFF the relay when occupancy becomes zero.
- Continuously monitor sensor inputs.

---

# 6. Non-Functional Requirements

- Low power consumption
- Low hardware cost
- Easy installation
- Simple maintenance
- Reliable operation
- Modular software structure
- Fast response time

---

# 7. Hardware Requirements

| Component | Specification |
|-----------|---------------|
| Microcontroller | Arduino UNO |
| Sensor | IR Sensor Module ×2 |
| Display | SSD1306 OLED Display (128×64) |
| Output | Single Channel Relay Module |
| Light | COB LED |
| Resistors | 220 Ω, 10 kΩ |
| Accessories | Breadboard, Jumper Wires |

---

# 8. Software Requirements

- Arduino IDE
- Visual Studio Code
- Embedded C/C++
- Wire Library
- Adafruit GFX Library
- Adafruit SSD1306 Library

---

# 9. System Inputs

| Input | Description |
|--------|-------------|
| IR Sensor A | Detects first beam interruption |
| IR Sensor B | Detects second beam interruption |

---

# 10. System Outputs

| Output | Description |
|---------|-------------|
| OLED Display | Displays occupancy count |
| Relay Module | Controls room lighting |
| COB LED | Represents room light |

---

# 11. Operating Principle

The system determines movement direction based on the sequence in which the two IR sensors are triggered.

- Sensor A → Sensor B = Entry
- Sensor B → Sensor A = Exit

The occupancy count is updated accordingly.

If the occupancy count is greater than zero, the relay turns ON the room light.

If the occupancy count becomes zero, the relay turns OFF the room light.

---

# 12. Design Constraints

- Suitable for single-door entry systems.
- Requires proper alignment of IR sensors.
- Simultaneous multiple-person entry may affect counting accuracy.
- Performance depends on sensor placement and ambient conditions.

---

# 13. Assumptions

- People pass through the doorway one at a time.
- Sensors remain properly aligned.
- Stable 5 V power supply is available.
- Hardware connections are secure.

---

# 14. Applications

- Smart Homes
- Offices
- Educational Institutions
- Laboratories
- Conference Rooms
- Libraries
- Energy Management Systems

---

# 15. Advantages

- Reduces energy wastage.
- Fully automatic operation.
- Low-cost implementation.
- Easy to install.
- Expandable for IoT applications.
- Demonstrates practical embedded system concepts.

---

# 16. Limitations

- Designed for a single entrance.
- Sensor misalignment may reduce accuracy.
- Cannot identify individual persons.
- Does not support remote monitoring in the current version.

---

# 17. Future Scope

Future enhancements may include:

- ESP32-based wireless connectivity
- MQTT communication
- Mobile application integration
- Cloud-based data logging
- Real-Time Clock (RTC)
- PCB implementation
- Camera-based people detection
- AI-powered occupancy analytics

---

# 18. Conclusion

The Smart Room Occupancy Counter demonstrates a practical embedded system that combines sensor interfacing, occupancy monitoring, display control, and automatic lighting. The project provides a simple and effective solution for improving energy efficiency while serving as a foundation for more advanced smart building and IoT applications.
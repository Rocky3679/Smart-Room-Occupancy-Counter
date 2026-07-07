# Smart Room Occupancy Counter with OLED Display and Automatic Light Control

**Author:** Janaki Raman K

**Technology:** Embedded Systems | Arduino | Automation | Electronics

---

# Abstract

The Smart Room Occupancy Counter is an embedded automation project developed to demonstrate automatic occupancy monitoring and intelligent lighting control using an Arduino UNO. The system detects the direction of movement through two infrared (IR) sensors placed at a doorway, maintains the number of people inside a room, displays the occupancy count on an OLED display, and controls room lighting through a relay module.

The project demonstrates practical concepts in embedded systems including sensor interfacing, finite state machine (FSM) logic, relay control, display interfacing, and non-blocking programming. It also highlights the application of automation for reducing unnecessary electrical energy consumption.

---

# 1. Introduction

Automation has become an essential part of modern buildings, industries, and smart homes. One common problem is unnecessary power consumption caused by lights remaining ON even when a room is unoccupied.

This project addresses that problem by automatically monitoring room occupancy and controlling the lighting system accordingly. Using two IR sensors positioned at the entrance, the system determines whether a person is entering or leaving the room. The occupancy count is continuously updated and displayed on an OLED display while a relay module switches the lighting load automatically.

The project provides a simple, low-cost, and scalable solution that can be expanded into larger smart building systems.

---

# 2. Problem Statement

Manual operation of lighting systems often results in energy wastage because users forget to switch OFF lights after leaving a room.

The objective of this project is to develop an embedded system capable of:

- Detecting entry and exit movements.
- Maintaining an accurate occupancy count.
- Automatically controlling room lighting.
- Providing real-time occupancy information.

---

# 3. Objectives

The primary objectives are:

- Detect room entry and exit using two IR sensors.
- Count the number of occupants inside the room.
- Display occupancy information on an OLED display.
- Automatically control room lighting using a relay module.
- Demonstrate embedded programming and sensor interfacing.

---

# 4. System Overview

The system consists of five major hardware modules:

- Arduino UNO
- Two IR Sensors
- OLED Display
- Relay Module
- COB LED

The Arduino continuously monitors both sensors. Based on the order in which they are activated, the controller determines whether a person has entered or exited the room. The occupancy count is updated, displayed, and used to control the relay.

---

# 5. Hardware Used

| Component | Purpose |
|-----------|---------|
| Arduino UNO | Main controller |
| IR Sensor A | Entry detection |
| IR Sensor B | Exit detection |
| SSD1306 OLED | Occupancy display |
| Relay Module | Light switching |
| COB LED | Simulated room light |
| Breadboard | Circuit assembly |
| Jumper Wires | Connections |

---

# 6. Software Used

- Arduino IDE
- Visual Studio Code
- Embedded C/C++
- Wire Library
- Adafruit GFX Library
- Adafruit SSD1306 Library

---

# 7. System Architecture

```text
Person Movement
       │
       ▼
+-----------------+
|  IR Sensor A    |
+-----------------+
       │
       ▼
+-----------------+
|  IR Sensor B    |
+-----------------+
       │
       ▼
+-----------------+
| Arduino UNO     |
| Occupancy Logic |
+-----------------+
     │       │
     ▼       ▼
 OLED      Relay
             │
             ▼
          COB LED
```

---

# 8. Working Principle

The Arduino continuously monitors both infrared sensors.

If Sensor A is triggered before Sensor B, the movement is considered an entry and the occupancy count is increased.

If Sensor B is triggered before Sensor A, the movement is considered an exit and the occupancy count is decreased.

The OLED display updates the occupancy count after every valid event.

Whenever the occupancy count is greater than zero, the relay switches ON the light.

When the occupancy count reaches zero, the relay automatically switches OFF the light.

---

# 9. Software Algorithm

1. Initialize all hardware modules.
2. Read both IR sensors continuously.
3. Determine the order of sensor activation.
4. Identify entry or exit.
5. Update occupancy count.
6. Prevent negative occupancy values.
7. Update OLED display.
8. Control relay output.
9. Repeat continuously.

---

# 10. Testing and Results

The system was tested by simulating multiple entry and exit events.

The following observations were recorded:

- Correct entry detection.
- Correct exit detection.
- Accurate occupancy counting.
- Relay switched ON when occupancy was greater than zero.
- Relay switched OFF when occupancy reached zero.
- OLED displayed the correct occupancy count throughout testing.

The project successfully met its intended objectives.

---

# 11. Advantages

- Automatic operation.
- Low-cost implementation.
- Energy-efficient lighting control.
- Simple hardware.
- Easy maintenance.
- Expandable for IoT applications.
- Suitable for educational demonstrations.

---

# 12. Limitations

- Designed for a single entrance.
- Simultaneous movement of multiple people may reduce accuracy.
- Sensor alignment is important for reliable operation.
- Does not provide remote monitoring in the current version.

---

# 13. Future Improvements

Future enhancements include:

- ESP32-based wireless communication.
- IoT cloud connectivity.
- MQTT integration.
- Mobile application.
- Real-time clock (RTC).
- Data logging.
- Custom PCB.
- Camera or AI-based people detection.

---

# 14. Skills Demonstrated

This project demonstrates practical knowledge in:

- Embedded Systems
- Arduino Programming
- Sensor Interfacing
- Digital Electronics
- Finite State Machine (FSM)
- Relay Control
- OLED Display Interfacing
- Embedded Debugging
- System Integration
- Technical Documentation

---

# 15. Conclusion

The Smart Room Occupancy Counter successfully demonstrates an embedded automation system capable of monitoring occupancy and automatically controlling room lighting. The project integrates hardware and software to provide a practical energy-saving solution while showcasing core embedded engineering concepts. Its modular design allows future expansion into IoT-enabled smart building applications, making it a strong demonstration project for embedded systems and automation engineering.
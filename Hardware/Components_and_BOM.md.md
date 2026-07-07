# Components and Bill of Materials

## 1. Overview

This document lists the hardware components used in the Smart Room Occupancy Counter project along with their purpose and approximate quantity.

---

# 2. Hardware Components

| Sl. No. | Component | Quantity | Purpose |
|---------:|-----------|:--------:|---------|
| 1 | Arduino UNO | 1 | Main controller |
| 2 | IR Sensor Module | 2 | Detect entry and exit |
| 3 | SSD1306 OLED Display (0.96" I2C) | 1 | Display occupancy count |
| 4 | Single Channel Relay Module | 1 | Control room light |
| 5 | COB LED | 1 | Simulated room light |
| 6 | 220 Ω Resistor | 1 | Current limiting |
| 7 | 10 kΩ Resistor | 1 | Pull-up resistor (if required) |
| 8 | Breadboard | 1 | Circuit assembly |
| 9 | Jumper Wires | As Required | Electrical connections |
| 10 | USB Cable | 1 | Arduino programming |

---

# 3. Component Description

## Arduino UNO

The Arduino UNO serves as the main processing unit. It reads the sensor inputs, processes the occupancy logic, updates the OLED display, and controls the relay.

---

## IR Sensor Modules

Two IR sensors are placed at the doorway.

- Sensor A detects movement first during entry.
- Sensor B detects movement first during exit.

Their activation sequence determines the direction of movement.

---

## OLED Display

A 0.96-inch SSD1306 OLED display connected through the I2C interface displays:

- Current occupancy count
- Light status

---

## Relay Module

The relay acts as an electronic switch.

When occupancy is greater than zero, the relay energizes and turns ON the connected light.

When occupancy becomes zero, the relay switches OFF automatically.

---

## COB LED

The COB LED represents the room lighting load controlled by the relay.

---

## Resistors

The project uses:

- 220 Ω resistor for LED protection
- 10 kΩ resistor where pull-up resistance is required

---

## Breadboard and Jumper Wires

Used for prototype construction and hardware interconnections.

---

# 4. Estimated Bill of Materials

| Component | Quantity |
|-----------|:--------:|
| Arduino UNO | 1 |
| IR Sensor | 2 |
| OLED Display | 1 |
| Relay Module | 1 |
| COB LED | 1 |
| 220 Ω Resistor | 1 |
| 10 kΩ Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# 5. Future Hardware Improvements

- Custom PCB
- Industrial sensors
- DIN-rail enclosure
- ESP32 controller
- Industrial relay module
- Protective casing

---

# 6. Conclusion

The selected hardware provides a low-cost, reliable, and modular platform for implementing an automatic room occupancy monitoring system. The components are readily available, easy to interface with Arduino, and suitable for educational as well as prototype-level smart automation projects.
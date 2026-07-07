# Hardware Connections

## 1. Overview

This document describes the electrical connections used in the Smart Room Occupancy Counter project.

The system consists of an Arduino UNO, two IR sensors, an SSD1306 OLED display, a relay module, and a COB LED.

---

# 2. Pin Connection Table

| Arduino Pin | Connected Device | Function |
|-------------|------------------|----------|
| D2 | IR Sensor A (OUT) | Entry Detection |
| D3 | IR Sensor B (OUT) | Exit Detection |
| D8 | Relay Module (IN) | Light Control |
| A4 | OLED Display (SDA) | I2C Data |
| A5 | OLED Display (SCL) | I2C Clock |
| 5V | IR Sensors, OLED, Relay | Power Supply |
| GND | All Components | Common Ground |

---

# 3. IR Sensor Connections

## IR Sensor A

| Pin | Connection |
|------|------------|
| VCC | Arduino 5V |
| GND | Arduino GND |
| OUT | Arduino D2 |

---

## IR Sensor B

| Pin | Connection |
|------|------------|
| VCC | Arduino 5V |
| GND | Arduino GND |
| OUT | Arduino D3 |

---

# 4. OLED Display Connections

| OLED Pin | Arduino Pin |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

# 5. Relay Module Connections

| Relay Pin | Arduino Pin |
|------------|-------------|
| VCC | 5V |
| GND | GND |
| IN | D8 |

---

# 6. COB LED Connections

The COB LED is connected through the relay module.

When the relay is energized, the LED turns ON.

When the relay is de-energized, the LED turns OFF.

---

# 7. Power Supply

The complete system operates from the Arduino UNO 5 V supply.

Ensure all modules share a common ground for reliable operation.

---

# 8. Wiring Notes

- Verify all wiring before powering the system.
- Keep sensor wires short to minimize electrical noise.
- Align both IR sensors correctly for accurate detection.
- Check the I2C address of the OLED display (typically 0x3C).
- Ensure the relay module is compatible with 5 V logic.

---

# 9. Summary

Proper wiring is essential for reliable occupancy detection and automatic lighting control. Incorrect sensor connections or poor alignment may result in inaccurate occupancy counting.
# Hardware Connections

## Components

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| IR Sensor | 2 |
| OLED Display (SSD1306 I2C) | 1 |
| Relay Module | 1 |
| COB LED | 1 |
| 220 Ω Resistor | 1 |
| 10 kΩ Resistor | 1 |

---

# Pin Connections

## IR Sensor 1 (Entry)

| IR Sensor | Arduino UNO |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| OUT | D2 |

---

## IR Sensor 2 (Exit)

| IR Sensor | Arduino UNO |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| OUT | D3 |

---

## OLED Display (I2C)

| OLED | Arduino UNO |
|------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Relay Module

| Relay | Arduino UNO |
|-------|-------------|
| VCC | 5V |
| GND | GND |
| IN | D8 |

---

## COB LED

The COB LED is powered through the relay module using an external supply.

The Arduino controls only the relay input.

---

# Pin Summary

| Arduino Pin | Connected Device |
|-------------|------------------|
| D2 | IR Sensor A |
| D3 | IR Sensor B |
| D8 | Relay Module |
| A4 | OLED SDA |
| A5 | OLED SCL |

---

# System Flow

IR Sensors

↓

Arduino UNO

↓

Occupancy Logic

↓

OLED Display + Relay

↓

Room Light
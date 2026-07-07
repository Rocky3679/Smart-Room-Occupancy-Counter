# Smart Room Occupancy Counter

## Objective

Design and develop an Arduino-based Smart Room Occupancy Counter capable of detecting entry and exit using two infrared sensors, displaying the number of occupants on an OLED display, and automatically controlling room lighting based on occupancy.

---

## Functional Requirements

### Input Devices

- IR Sensor A
- IR Sensor B

### Processing Unit

- Arduino UNO

### Output Devices

- OLED Display (SSD1306 I2C)
- Relay Module
- COB LED

---

## Functional Logic

### Entry Detection

IF

Sensor A → Sensor B

within the specified timing window

THEN

Increase Occupancy Count by 1

---

### Exit Detection

IF

Sensor B → Sensor A

within the specified timing window

THEN

Decrease Occupancy Count by 1

---

### Occupancy Protection

Occupancy Count shall never become negative.

---

### Display

OLED shall display

People Inside : X

Light : ON/OFF

---

### Light Control

IF Occupancy > 0

Relay ON

ELSE

Relay OFF

---

## System Constraints

- Ignore invalid trigger sequence.
- Ignore repeated sensor bounce.
- Maintain accurate occupancy count.
- Refresh OLED after every valid event.

---

## Future Scope

- ESP32 Upgrade
- Wi-Fi Dashboard
- MQTT
- Blynk
- Mobile Application
- Cloud Monitoring
# Working Principle

## Overview

The Smart Room Occupancy Counter automatically monitors the number of people inside a room using two infrared (IR) sensors positioned at the entrance. Based on the occupancy count, the system controls the room lighting through a relay module and displays the current status on an OLED display.

---

# System Operation

The system continuously monitors the output of two IR sensors.

- Sensor A is placed first.
- Sensor B is placed second.

The sequence in which these sensors are triggered determines whether a person is entering or leaving the room.

---

# Entry Detection

When a person enters the room, the expected trigger sequence is:

Sensor A → Sensor B

The Arduino interprets this as a valid entry event and:

- Increases the occupancy count by one.
- Updates the OLED display.
- Checks the lighting condition.

---

# Exit Detection

When a person leaves the room, the expected trigger sequence is:

Sensor B → Sensor A

The Arduino interprets this as a valid exit event and:

- Decreases the occupancy count by one.
- Prevents the count from becoming negative.
- Updates the OLED display.
- Re-evaluates the lighting condition.

---

# Occupancy Counter

The Arduino maintains an internal occupancy counter.

Rules:

- Entry increases the count.
- Exit decreases the count.
- Count can never become negative.
- Invalid sensor sequences are ignored.

---

# OLED Display

The OLED display provides real-time information.

Example:

People Inside : 3

Light : ON

The display refreshes after every valid entry or exit event.

---

# Automatic Light Control

The relay module controls the room light.

If:

Occupancy > 0

Relay = ON

If:

Occupancy = 0

Relay = OFF

This ensures that electrical energy is not wasted when the room is empty.

---

# Advantages

- Automatic energy saving
- Low-cost implementation
- Real-time occupancy monitoring
- Easy to install
- Expandable for IoT applications

---

# Future Enhancements

- ESP32 with Wi-Fi connectivity
- Mobile application monitoring
- Cloud dashboard
- MQTT communication
- Data logging
- AI-based occupancy prediction
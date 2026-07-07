# Working Principle

## 1. Introduction

The Smart Room Occupancy Counter is an embedded automation system that monitors the number of people inside a room using two infrared (IR) sensors. Based on the occupancy count, the system automatically controls the room lighting through a relay module and displays the current count on an OLED display.

The project demonstrates sensor interfacing, embedded programming, finite state machine (FSM) logic, and basic energy-saving automation.

---

# 2. System Overview

The system consists of:

- Arduino UNO
- Two IR sensors
- SSD1306 OLED Display
- Relay Module
- COB LED (Room Light)

The Arduino continuously monitors both IR sensors to determine the direction of movement and updates the occupancy count accordingly.

---

# 3. Block Diagram

```text
          Person Movement
                 │
                 ▼
      ┌────────────────────┐
      │   IR Sensor A      │
      └────────────────────┘
                 │
                 ▼
      ┌────────────────────┐
      │   IR Sensor B      │
      └────────────────────┘
                 │
                 ▼
      ┌────────────────────┐
      │   Arduino UNO      │
      │  Occupancy Logic   │
      └────────────────────┘
          │            │
          ▼            ▼
   OLED Display    Relay Module
                        │
                        ▼
                  COB LED Light
```

---

# 4. Entry Detection

When a person enters the room:

1. Sensor A detects the person first.
2. Sensor B detects the person next.
3. The Arduino recognizes this sequence as an entry.
4. The occupancy count increases by one.
5. The updated count is displayed on the OLED.
6. If the count becomes greater than zero, the relay turns ON the room light.

---

# 5. Exit Detection

When a person leaves the room:

1. Sensor B detects the person first.
2. Sensor A detects the person next.
3. The Arduino recognizes this sequence as an exit.
4. The occupancy count decreases by one.
5. The updated count is displayed on the OLED.
6. If the occupancy count reaches zero, the relay turns OFF the room light.

---

# 6. Occupancy Counter Logic

The Arduino maintains an internal occupancy counter.

- Entry → Count + 1
- Exit → Count − 1

The program prevents the counter from becoming negative.

---

# 7. Automatic Light Control

The relay module is controlled using the occupancy count.

| Occupancy Count | Relay | Light |
|----------------:|:-----:|:-----:|
| 0 | OFF | OFF |
| Greater than 0 | ON | ON |

This helps reduce unnecessary electricity consumption.

---

# 8. OLED Display

The SSD1306 OLED display continuously shows:

- Number of people inside the room
- Light status (ON/OFF)

The display updates automatically whenever the occupancy count changes.

---

# 9. Software Logic

The Arduino program performs the following tasks continuously:

1. Read both IR sensors.
2. Detect the order of sensor activation.
3. Determine whether the movement is an entry or exit.
4. Update the occupancy count.
5. Control the relay.
6. Refresh the OLED display.

---

# 10. Flow of Operation

```text
Start
   │
   ▼
Initialize Arduino
   │
   ▼
Read IR Sensors
   │
   ▼
Determine Entry or Exit
   │
   ▼
Update Occupancy Count
   │
   ▼
Update OLED Display
   │
   ▼
Control Relay
   │
   ▼
Repeat Continuously
```

---

# 11. Advantages

- Automatic room monitoring
- Energy-efficient lighting control
- Real-time occupancy display
- Simple and low-cost implementation
- Easy to expand for IoT applications

---

# 12. Limitations

- Supports only a single entrance.
- Requires proper sensor alignment.
- Multiple people entering simultaneously may affect counting accuracy.

---

# 13. Conclusion

The Smart Room Occupancy Counter provides an efficient and practical solution for automatic occupancy monitoring and lighting control. By combining IR sensors, Arduino, an OLED display, and a relay module, the system demonstrates essential embedded system concepts while promoting energy conservation. The project can be further enhanced with IoT connectivity, cloud monitoring, and advanced sensing technologies.
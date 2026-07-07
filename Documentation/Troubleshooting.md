# Troubleshooting Guide

## 1. Introduction

This document lists common issues that may occur during the assembly, programming, and operation of the Smart Room Occupancy Counter, along with their possible causes and recommended solutions.

---

# 2. Common Issues

| Problem | Possible Cause | Solution |
|----------|----------------|----------|
| Arduino not detected | Faulty USB cable or incorrect COM port | Check the USB cable and select the correct COM port in the Arduino IDE |
| Program upload failed | Incorrect board selection | Select **Arduino UNO** under Tools → Board |
| OLED display remains blank | Incorrect wiring or wrong I2C address | Verify SDA, SCL, VCC, GND connections and confirm the I2C address (usually 0x3C) |
| Relay does not switch | Incorrect wiring or faulty relay module | Verify relay connections and test the relay independently |
| COB LED does not turn ON | Incorrect relay wiring or power supply issue | Check the LED wiring and relay output connections |
| Occupancy count increases incorrectly | Improper sensor alignment | Align both IR sensors correctly and maintain proper spacing |
| Occupancy count decreases incorrectly | Incorrect sensor sequence | Verify that Sensor A detects entry first and Sensor B detects exit first |
| Occupancy count becomes inaccurate | Multiple people crossing simultaneously | Allow one person to pass through the doorway at a time |
| Sensor triggers continuously | Ambient light interference or sensor sensitivity | Adjust the IR sensor sensitivity using the onboard potentiometer |
| Arduino resets unexpectedly | Insufficient power supply | Use a stable 5 V power source |

---

# 3. Debugging Procedure

If the system is not operating correctly:

1. Verify all hardware connections.
2. Check the Arduino power LED.
3. Confirm that the correct board and COM port are selected.
4. Upload the program again.
5. Open the Serial Monitor for debugging messages.
6. Test each IR sensor individually.
7. Verify OLED initialization.
8. Test relay operation separately.
9. Recheck sensor alignment.
10. Repeat the complete system test.

---

# 4. Sensor Calibration

For reliable operation:

- Position both IR sensors at the same height.
- Maintain a spacing of approximately **5–10 cm**.
- Adjust sensor sensitivity using the onboard potentiometer.
- Avoid direct sunlight or strong external infrared sources.
- Ensure the doorway allows only one person to pass at a time.

---

# 5. Relay Testing

To verify relay operation:

- Apply power to the Arduino.
- Trigger an entry event.
- Listen for the relay click.
- Confirm that the LED turns ON.
- Trigger exit events until the occupancy count reaches zero.
- Verify that the relay switches OFF.

---

# 6. OLED Display Testing

Check the following:

- OLED powers ON.
- Display initializes correctly.
- Occupancy count updates after every valid entry and exit.
- No display flickering occurs during operation.

---

# 7. Maintenance

To maintain reliable operation:

- Clean the IR sensor lenses periodically.
- Inspect jumper wire connections.
- Secure loose components.
- Re-upload firmware if required.
- Replace damaged hardware modules when necessary.

---

# 8. Frequently Asked Questions (FAQ)

### Q1. Why is the occupancy count incorrect?

The most common reasons are improper sensor alignment, incorrect wiring, or multiple people crossing simultaneously.

---

### Q2. Why does the relay not switch?

Check the relay wiring, Arduino pin assignment, and ensure the occupancy count is greater than zero.

---

### Q3. Why is the OLED display blank?

Verify the power connections, SDA/SCL wiring, and confirm the OLED I2C address.

---

### Q4. Can this project be expanded for IoT?

Yes. The Arduino UNO can be replaced with an ESP32 to enable Wi-Fi connectivity, cloud monitoring, MQTT communication, and mobile application integration.

---

# 9. Conclusion

Most issues encountered during development can be resolved by checking wiring, verifying software configuration, and properly calibrating the IR sensors. Following the installation and testing procedures ensures reliable occupancy detection and automatic lighting control.# Troubleshooting Guide

## 1. Introduction

This document lists common issues that may occur during the assembly, programming, and operation of the Smart Room Occupancy Counter, along with their possible causes and recommended solutions.

---

# 2. Common Issues

| Problem | Possible Cause | Solution |
|----------|----------------|----------|
| Arduino not detected | Faulty USB cable or incorrect COM port | Check the USB cable and select the correct COM port in the Arduino IDE |
| Program upload failed | Incorrect board selection | Select **Arduino UNO** under Tools → Board |
| OLED display remains blank | Incorrect wiring or wrong I2C address | Verify SDA, SCL, VCC, GND connections and confirm the I2C address (usually 0x3C) |
| Relay does not switch | Incorrect wiring or faulty relay module | Verify relay connections and test the relay independently |
| COB LED does not turn ON | Incorrect relay wiring or power supply issue | Check the LED wiring and relay output connections |
| Occupancy count increases incorrectly | Improper sensor alignment | Align both IR sensors correctly and maintain proper spacing |
| Occupancy count decreases incorrectly | Incorrect sensor sequence | Verify that Sensor A detects entry first and Sensor B detects exit first |
| Occupancy count becomes inaccurate | Multiple people crossing simultaneously | Allow one person to pass through the doorway at a time |
| Sensor triggers continuously | Ambient light interference or sensor sensitivity | Adjust the IR sensor sensitivity using the onboard potentiometer |
| Arduino resets unexpectedly | Insufficient power supply | Use a stable 5 V power source |

---

# 3. Debugging Procedure

If the system is not operating correctly:

1. Verify all hardware connections.
2. Check the Arduino power LED.
3. Confirm that the correct board and COM port are selected.
4. Upload the program again.
5. Open the Serial Monitor for debugging messages.
6. Test each IR sensor individually.
7. Verify OLED initialization.
8. Test relay operation separately.
9. Recheck sensor alignment.
10. Repeat the complete system test.

---

# 4. Sensor Calibration

For reliable operation:

- Position both IR sensors at the same height.
- Maintain a spacing of approximately **5–10 cm**.
- Adjust sensor sensitivity using the onboard potentiometer.
- Avoid direct sunlight or strong external infrared sources.
- Ensure the doorway allows only one person to pass at a time.

---

# 5. Relay Testing

To verify relay operation:

- Apply power to the Arduino.
- Trigger an entry event.
- Listen for the relay click.
- Confirm that the LED turns ON.
- Trigger exit events until the occupancy count reaches zero.
- Verify that the relay switches OFF.

---

# 6. OLED Display Testing

Check the following:

- OLED powers ON.
- Display initializes correctly.
- Occupancy count updates after every valid entry and exit.
- No display flickering occurs during operation.

---

# 7. Maintenance

To maintain reliable operation:

- Clean the IR sensor lenses periodically.
- Inspect jumper wire connections.
- Secure loose components.
- Re-upload firmware if required.
- Replace damaged hardware modules when necessary.

---

# 8. Frequently Asked Questions (FAQ)

### Q1. Why is the occupancy count incorrect?

The most common reasons are improper sensor alignment, incorrect wiring, or multiple people crossing simultaneously.

---

### Q2. Why does the relay not switch?

Check the relay wiring, Arduino pin assignment, and ensure the occupancy count is greater than zero.

---

### Q3. Why is the OLED display blank?

Verify the power connections, SDA/SCL wiring, and confirm the OLED I2C address.

---

### Q4. Can this project be expanded for IoT?

Yes. The Arduino UNO can be replaced with an ESP32 to enable Wi-Fi connectivity, cloud monitoring, MQTT communication, and mobile application integration.

---

# 9. Conclusion

Most issues encountered during development can be resolved by checking wiring, verifying software configuration, and properly calibrating the IR sensors. Following the installation and testing procedures ensures reliable occupancy detection and automatic lighting control.
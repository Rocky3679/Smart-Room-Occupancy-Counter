# Installation & Deployment Guide

This document outlines the step-by-step procedure required to configure, compile, and physically deploy the Smart Room Occupancy Counter and Energy Management System.

---

## 1. Software Environment Prerequisites

Before compiling the firmware, ensure your development workspace is configured with the following toolchains:

1. [cite_start]**IDE Platform:** VS Code with the Arduino Extension, or the Arduino IDE (v2.x or higher)[cite: 39].
2. **Board Manager Core:** Install the `Arduino AVR Boards` or `ESP32 by Expressif` core depending on your targeted hardware profile deployment.
3. **Required Library Dependencies:** Open your library manager and install the exact versions listed below:
   * [cite_start]`Adafruit GFX Library` (v1.11.9 or higher) [cite: 4]
   * [cite_start]`Adafruit SSD1306` (v2.5.9 or higher) [cite: 4]

---

## 2. Firmware Compilation & Flashing Procedure

1. Connect the development microcontroller to your workstation using a high-quality USB data cable.
2. Open the file `Code/Smart_Occupancy_Counter.ino` within your IDE workspace environment.
3. [cite_start]Select your designated hardware profile targets (e.g., *Arduino Uno*, *Arduino Nano*, or *ESP32 Dev Module*) under the **Tools > Board** configuration index[cite: 4, 44].
4. Select the matching virtual communication node under **Tools > Port**.
5. Change the standard compiler optimization flags to maximum throughput efficiency if utilizing advanced IDE engines.
6. Click the **Verify** icon to execute a pre-compilation syntax check.
7. Once checked cleanly, execute the **Upload** instruction sequence to flash the compiled binary image onto the microcontroller's internal memory chips.

---

## 3. Physical Field Deployment Checklist

* **Sensor Alignment Spacing:** Mount the two infrared boundary modules sequentially across the targeted zone passageway entryway frame. [cite_start]The physical distance between Sensor A and Sensor B must be maintained within **5 cm to 10 cm** to prevent tracking logic overlap errors while matching standard human movement velocities[cite: 15, 52].
* **Optical Axis Isolation:** Ensure that neither sensor's infrared transmitter field is bleeding over into the adjacent receiver element's detection cone, which could cause immediate echo loop degradation.
* [cite_start]**Relay Interlock Verification:** Before switching live AC building line inputs through the relay contact poles, run a low-voltage DC loop continuity pass to confirm that the Normally Open (NO) state changes match your expectations[cite: 46].
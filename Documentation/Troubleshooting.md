# Field Engineering Troubleshooting Manual

This diagnostic runtime runbook is designed to help commissioning and maintenance technicians rapidly identify and resolve anomalies on the Smart Room Occupancy Counter deployment.

---

## 1. Diagnostic Matrix (Fault Isolation)

| Symptom / Fault Observed | Root Cause Analysis (RCA) | Corrective Action Protocol |
| :--- | :--- | :--- |
| **OLED Panel Remains Blank / No HMI Graphics Output** | 1. Missing or loose physical I2C connection wires.<br>2. Incorrect peripheral I2C hardware address configured in software. | 1. Verify terminal tight-points on SCL/SDA lines.<br>2. Run an I2C address scanner utility to confirm if the address matches `0x3C`. |
| **System Repeatedly Fails to Log Entry / Exit Movements** | 1. Sensor cross-distance spacing exceeds the normal step velocity profiling bounds.<br>2. Hardware jitter or optical bounce breaking logic. | 1. [cite_start]Readjust the physical hardware distance between Sensor A and Sensor B to exactly 5 cm apart[cite: 52].<br>2. Increase the internal software variable `T_DEBOUNCE_MS` marginally. |
| **The Population Count Increments on Exit (Reverse Logic)** | [cite_start]The directional field placement orientation of Sensor A and Sensor B has been swapped relative to the entry frame profile[cite: 15]. | Swap the software input pin mappings for `PIN_SENSOR_A` and `PIN_SENSOR_B` inside the firmware source configuration header. |
| **Count Sticks at 1 or Stalls Indefinitely in Loop** | An object blocked one sensor axis and backed out, or a sensor lens is dirty, triggering a partial sequence hang. | Wait 3000 ms for the automated internal sequencer watchdog timer to run down, which will flush the registers back to IDLE automatically. |
| **The Load Relay Module Chills / Does Not Switch On** | 1. Control loop logic output signal tracking line failure.<br>2. Insufficient driver current output on the microcontroller pin. | 1. Check if the onboard system indicator LED matches the status change logic.<br>2. Power the relay coil module from an isolated, external auxiliary power supply rail. |

---

## 2. Serial Telemetry System Auditing

Technicians can monitor performance directly by opening a terminal monitor at a baud rate of `115200 bps`. The system outputs standard JSON formatted data packets every 200 ms:

```json
{"telemetry":{"occupancy":3,"relay_state":1,"fsm_code":0}}
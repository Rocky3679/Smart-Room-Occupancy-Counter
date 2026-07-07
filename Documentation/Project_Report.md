# Comprehensive Engineering Project Report

## 1. Executive Summary
[cite_start]This report presents an industrial-grade Building Energy Management System (BEMS) designed to optimize zone power consumption through real-time, non-blocking room occupancy calculation[cite: 1, 8]. [cite_start]Built upon an asynchronous Finite State Machine (FSM) architecture, the system coordinates sequential optical break-beam signals to achieve dynamic power-line interlocking, eliminating human intervention in commercial lighting grids[cite: 15, 31, 32].

---

## 2. Engineering Objectives & Problem Statement
Traditional commercial automation systems suffer from high energy waste due to lighting networks left active in unoccupied zones. Standard solutions rely on basic motion detectors that turn off power lines if occupants sit completely still. 

This architecture addresses that operational bottleneck by achieving four core objectives:
* [cite_start]**Vector-Driven Traversal Identification:** Differentiating and validating entry vs. exit maneuvers sequentially[cite: 9, 15].
* [cite_start]**Deterministic Register Tracking:** Maintaining a robust, real-time integer register of active occupants within the zone bounds[cite: 20, 21].
* [cite_start]**Isolated HMI Visualization:** Streaming real-time population metrics to an isolated, non-blocking I2C graphic interface display panel[cite: 10, 24].
* [cite_start]**Automatic Relay Load Interlocking:** Automating lighting network isolation via a discrete dry-contact relay module immediately when zone occupancy drops to absolute zero[cite: 11, 31, 32].

---

## 3. System Architecture & Core Modules

```text
[Field Sensor A] ---> (Signal Conditioning / Filter) ---\
                                                         +---> [Asynchronous FSM] ---> [Load Relay Interlock]
[Field Sensor B] ---> (Signal Conditioning / Filter) ---/              |
                                                                       v
                                                            [Non-Blocking I2C HMI]
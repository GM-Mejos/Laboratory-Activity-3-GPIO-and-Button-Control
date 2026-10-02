# Laboratory Activity 3: GPIO and Button Control

An introductory embedded systems firmware implementation on the DOIT ESP32 DEVKIT V1 demonstrating general-purpose input/output (GPIO) interfacing, internal pull-up resistor configuration, active-LOW button sensing, and complementary LED output states.

---

## Overview

This project explores fundamental digital I/O concepts on the ESP32:
- **Active-LOW Digital Input:** Uses a momentary pushbutton tied to ground, leveraging the ESP32 internal pull-up resistor (`INPUT_PULLUP`) to eliminate the need for external pull-up/down resistors.
- **Complementary Dual LED Control:** Drives two output LEDs in alternating states:
  - **Status LED (`led1Pin`):** Reflects the direct active state of the button (turns ON when pressed).
  - **Opposite State LED (`led2Pin`):** Operates in complementary logic (turns ON when released, turns OFF when pressed).

---

## Hardware Specifications & Pin Mapping

| Component | ESP32 GPIO Pin | Mode | Description |
| :--- | :--- | :--- | :--- |
| **Pushbutton** | GPIO 4 (D4) | `INPUT_PULLUP` | Momentary switch with internal pull-up; reads `LOW` when pressed, `HIGH` when released |
| **Status LED** | GPIO 18 (D18) | `OUTPUT` | Active-high status indicator |
| **Opposite State LED** | GPIO 19 (D19) | `OUTPUT` | Complementary indicator |

---

## Circuit Schematic & Wiring Guide

- **Pushbutton:**
  - Connect Terminal A to **GPIO 4**.
  - Connect Terminal B to **GND**.
  - *(No external pull-up resistor required; handled internally by the ESP32).*
- **Status LED (`led1Pin`):**
  - Anode (+) $\rightarrow$ 220Ω / 330Ω resistor $\rightarrow$ **GPIO 18**.
  - Cathode (–) $\rightarrow$ **GND**.
- **Opposite State LED (`led2Pin`):**
  - Anode (+) $\rightarrow$ 220Ω / 330Ω resistor $\rightarrow$ **GPIO 19**.
  - Cathode (–) $\rightarrow$ **GND**.

---

## Logic Behavior

| Button Physical State | Logic Reading at GPIO 4 | Status LED (GPIO 18) | Opposite LED (GPIO 19) |
| :--- | :--- | :--- | :--- |
| **Released** (Default) | `HIGH` (3.3V via internal pull-up) | `LOW` (OFF) | `HIGH` (ON) |
| **Pressed / Held** | `LOW` (GND) | `HIGH` (ON) | `LOW` (OFF) |

---

## Build & Upload Instructions (PlatformIO)

1. Open this repository in **Visual Studio Code** with the PlatformIO extension installed.
2. Verify board configuration in `platformio.ini`:
   ```ini
   [env:esp32doit-devkit-v1]
   platform = espressif32
   board = esp32doit-devkit-v1
   framework = arduino
   monitor_speed = 115200

---

## Lab Demonstrations
https://drive.google.com/drive/folders/1wrWAnmnJ7MWS8m70YYQ9kyIzV3OJyWDB?usp=sharing

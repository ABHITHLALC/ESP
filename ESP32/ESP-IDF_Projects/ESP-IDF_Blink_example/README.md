# ESP32 Blink Example using ESP-IDF

## Overview

This repository contains a simple "Blink" example for ESP32 using ESP-IDF. The project demonstrates how to blink an LED connected to a GPIO pin using the ESP-IDF framework. The LED blinks with a 2-second interval.

## Requirements

- ESP-IDF development environment

## Project Details

- **File**: blink_example.c
- **ESP-IDF**: Version: 5.2
- **Author**: ABHITHLAL C
- **MCU**: ESP32
- **GPIO Pin**: 2 (configurable)

## Usage

To use this project:

1. Set up the ESP-IDF development environment.
2. Clone this repository to your local machine.
3. Compile the project using the ESP-IDF build system.
4. Flash the compiled firmware to your ESP32.
5. Observe the LED connected to GPIO pin 2 blinking with a 2-second interval.

## File Structure

- `blink.c`: Main source code file containing the "Blink" example.
- `CMakeLists.txt`: CMake configuration file for building the project.
- `sdkconfig`: Configuration settings for the ESP-IDF SDK.

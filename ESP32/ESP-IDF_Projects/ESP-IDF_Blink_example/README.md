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

- `main/`: Folder containing the source code files.
    - `blink.c`: Main source code file containing the blink example.
    - `CMakeLists.txt`: CMake configuration file for building the project.
  - `CMakeLists.txt`: Outer CMake configuration file for building the entire project.
  - `sdkconfig`: Configuration settings for the ESP-IDF SDK..

## Terminal Log
```plaintext
I (29) boot: ESP-IDF v5.2 2nd stage bootloader
I (29) boot: compile time Apr  5 2024 00:28:25
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (37) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (67) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (74) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (81) boot:  2 factory          factory app      00 00 00010000 00100000
I (89) boot: End of partition table
I (93) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=098e4h ( 39140) map
I (115) esp_image: segment 1: paddr=0001990c vaddr=3ffb0000 size=02254h (  8788) load
I (119) esp_image: segment 2: paddr=0001bb68 vaddr=40080000 size=044b0h ( 17584) load
I (128) esp_image: segment 3: paddr=00020020 vaddr=400d0020 size=13a30h ( 80432) map
I (157) esp_image: segment 4: paddr=00033a58 vaddr=400844b0 size=0826ch ( 33388) load
I (177) boot: Loaded app from partition at offset 0x10000
I (177) boot: Disabling RNG early entropy source...
I (188) cpu_start: Multicore app
I (197) cpu_start: Pro cpu start user code
I (197) cpu_start: cpu freq: 160000000 Hz
I (197) cpu_start: Application information:
I (200) cpu_start: Project name:     ESP-IDF_Blink_example
I (206) cpu_start: App version:      b182d30-dirty
I (212) cpu_start: Compile time:     Apr  5 2024 02:28:22
I (218) cpu_start: ELF file SHA256:  7898ce385...
I (223) cpu_start: ESP-IDF:          v5.2
I (228) cpu_start: Min chip rev:     v0.0
I (232) cpu_start: Max chip rev:     v3.99
I (237) cpu_start: Chip rev:         v1.0
I (242) heap_init: Initializing. RAM available for dynamic allocation:
I (249) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (255) heap_init: At 3FFB2B18 len 0002D4E8 (181 KiB): DRAM
I (261) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (268) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (274) heap_init: At 4008C71C len 000138E4 (78 KiB): IRAM
I (282) spi_flash: detected chip: generic
I (285) spi_flash: flash io: dio
W (289) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (303) main_task: Started on CPU0
I (313) main_task: Calling app_main()
I (313) LED: LED ON!!!
I (2313) LED: LED OFF!!!
I (4313) LED: LED ON!!!
I (6313) LED: LED OFF!!!
I (8313) LED: LED ON!!!
I (10313) LED: LED OFF!!!
I (12313) LED: LED ON!!!
I (14313) LED: LED OFF!!!
```
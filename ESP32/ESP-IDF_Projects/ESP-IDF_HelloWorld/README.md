# ESP32 "Hello World" Example using ESP-IDF

## Overview

This repository contains a simple "Hello World" example for ESP32 using ESP-IDF. The project demonstrates how to print messages to the console, use the ESP-IDF logging library, delay execution using FreeRTOS tasks, and restart the ESP32 after a certain period of time.

## Project Details

- **File**: hello_world.c
- **Author**: ABHITHLAL C
- **ESP-IDF Version**: 5.2
- **MCU**: ESP32 DevKitC v4

## Usage

To use this project:

1. Set up the ESP-IDF development environment with version 5.2.
2. Clone this repository to your local machine.
3. Compile the project using the ESP-IDF build system.
4. Flash the compiled firmware to your ESP32 DevKitC v4.
5. Monitor the output on the console to observe the "Hello World" message and countdown restart.

## File Structure

- `main/`: Folder containing the source code files.
    - `hello_world.c`: Main source code file containing the hello world example.
    - `CMakeLists.txt`: CMake configuration file for building the project.
  - `CMakeLists.txt`: Outer CMake configuration file for building the entire project.
  - `sdkconfig`: Configuration settings for the ESP-IDF SDK..

## Terminal Output
```plaintext

I (29) boot: ESP-IDF v5.2 2nd stage bootloader
I (29) boot: compile time Apr  4 2024 23:44:28
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (37) boot.esp32: SPI Speed      : 40MHz
I (42) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (51) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (60) boot: ## Label            Usage          Type ST Offset   Length
I (67) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (74) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (82) boot:  2 factory          factory app      00 00 00010000 00100000
I (89) boot: End of partition table
I (94) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=095f4h ( 38388) map
I (115) esp_image: segment 1: paddr=0001961c vaddr=3ffb0000 size=0220ch (  8716) load
I (119) esp_image: segment 2: paddr=0001b830 vaddr=40080000 size=047e8h ( 18408) load
I (128) esp_image: segment 3: paddr=00020020 vaddr=400d0020 size=134d4h ( 79060) map
I (157) esp_image: segment 4: paddr=000334fc vaddr=400847e8 size=07f34h ( 32564) load
I (176) boot: Loaded app from partition at offset 0x10000
I (176) boot: Disabling RNG early entropy source...
I (188) cpu_start: Multicore app
I (196) cpu_start: Pro cpu start user code
I (196) cpu_start: cpu freq: 160000000 Hz
I (196) cpu_start: Application information:
I (199) cpu_start: Project name:     ESP-IDF_HelloWorld
I (205) cpu_start: App version:      f908eb6-dirty
I (211) cpu_start: Compile time:     Apr  5 2024 02:23:15
I (217) cpu_start: ELF file SHA256:  4758b052c...
I (222) cpu_start: ESP-IDF:          v5.2
I (227) cpu_start: Min chip rev:     v0.0
I (232) cpu_start: Max chip rev:     v3.99
I (236) cpu_start: Chip rev:         v1.0
I (241) heap_init: Initializing. RAM available for dynamic allocation:
I (249) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (254) heap_init: At 3FFB2AD0 len 0002D530 (181 KiB): DRAM
I (261) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (267) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (274) heap_init: At 4008C71C len 000138E4 (78 KiB): IRAM
I (281) spi_flash: detected chip: generic
I (284) spi_flash: flash io: dio
W (288) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (302) main_task: Started on CPU0
I (312) main_task: Calling app_main()
Hello World!
I (312) INFO: Demonstrating  Info : Hello World!
W (312) WARNING: Demonstrating Warning: Hello World!
E (312) ERROR: Demonstrating Error: Hello World!
Restarting in 10 sec
Restarting in 9 sec 
Restarting in 8 sec 
Restarting in 7 sec 
Restarting in 6 sec 
Restarting in 5 sec 
Restarting in 4 sec 
Restarting in 3 sec 
Restarting in 2 sec 
Restarting in 1 sec 
Restarting in 0 sec 
ets Jun  8 2016 00:22:57

```


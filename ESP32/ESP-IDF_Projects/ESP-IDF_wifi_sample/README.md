# ESP32 WiFi Connectivity Example using ESP-IDF

## Overview

This repository contains a simple WiFi connectivity example for ESP32 using ESP-IDF. The project demonstrates how to connect to a WiFi network and optionally check internet connectivity using the ESP-IDF framework.

## Requirements

- ESP-IDF development environment

## Project Details

- **File**: wifi_connectivity.c
- **Author**: ABHITHLAL C
- **ESP-IDF Version**: 5.2
- **WiFi SSID**: your_ssid (configurable)
- **WiFi Password**: your_password (configurable)
- **WiFi Maximum Retry**: 10 (configurable)
- **Internet Check Interval**: 5000 ms (configurable)

## Usage

To use this project:

1. Set up the ESP-IDF development environment.
2. Clone this repository to your local machine.
3. Compile the project using the ESP-IDF build system.
4. Flash the compiled firmware to your ESP32.
5. Observe the WiFi connection status and internet connectivity status in the console logs.

## Configuration

You can configure the following parameters in the code:

- WiFi SSID: Change the `WIFI_SSID` macro in the code.
- WiFi Password: Change the `WIFI_PASS` macro in the code.
- WiFi Maximum Retry: Change the `WIFI_MAXIMUM_RETRY` macro in the code.
- Internet Check Interval: Change the `INTERNET_CHECK_INTERVAL_MS` macro in the code.

## File Structure

- `main/`: Folder containing the source code files.
    - `wifi_connectivity.c`: Main source code file containing the WiFi connectivity example.
    - `CMakeLists.txt`: CMake configuration file for building the project.
  - `CMakeLists.txt`: Outer CMake configuration file for building the entire project.
  - `sdkconfig`: Configuration settings for the ESP-IDF SDK..

## Internet Connectivity Check

The project optionally checks internet connectivity by sending HTTP requests to a reliable server (default: http://www.google.com). If internet connectivity is available, it logs "Internet connectivity: Connected"; otherwise, it logs "Internet connectivity: Disconnected".

## Terminal Output When connecting to wifi with intenet connection

```plaintext
I (29) boot: ESP-IDF v5.2 2nd stage bootloader
I (29) boot: compile time Apr  5 2024 01:45:48
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (36) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (66) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (74) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (81) boot:  2 factory          factory app      00 00 00010000 00100000
I (89) boot: End of partition table
I (93) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=2686ch (157804) map
I (156) esp_image: segment 1: paddr=00036894 vaddr=3ffb0000 size=03c04h ( 15364) load
I (162) esp_image: segment 2: paddr=0003a4a0 vaddr=40080000 size=05b78h ( 23416) load
I (171) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=99cfch (630012) map
I (387) esp_image: segment 4: paddr=000d9d24 vaddr=40085b78 size=10b08h ( 68360) load
I (425) boot: Loaded app from partition at offset 0x10000
I (425) boot: Disabling RNG early entropy source...
I (437) cpu_start: Multicore app
I (446) cpu_start: Pro cpu start user code
I (446) cpu_start: cpu freq: 160000000 Hz
I (446) cpu_start: Application information:
I (449) cpu_start: Project name:     example_wifi
I (454) cpu_start: App version:      b7e9265-dirty
I (460) cpu_start: Compile time:     Apr  5 2024 01:45:00
I (466) cpu_start: ELF file SHA256:  2db690f24...
I (471) cpu_start: ESP-IDF:          v5.2
I (476) cpu_start: Min chip rev:     v0.0
I (480) cpu_start: Max chip rev:     v3.99 
I (485) cpu_start: Chip rev:         v1.0
I (490) heap_init: Initializing. RAM available for dynamic allocation:
I (497) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (503) heap_init: At 3FFB8300 len 00027D00 (159 KiB): DRAM
I (510) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (516) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (522) heap_init: At 40096680 len 00009980 (38 KiB): IRAM
I (530) spi_flash: detected chip: generic
I (533) spi_flash: flash io: dio
W (537) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (551) main_task: Started on CPU0
I (561) main_task: Calling app_main()
I (611) wifi:wifi driver task: 3ffc03a8, prio:23, stack:6656, core=0
I (631) wifi:wifi firmware version: cc1dd81
I (631) wifi:wifi certification version: v7.0
I (631) wifi:config NVS flash: enabled
I (631) wifi:config nano formating: disabled
I (641) wifi:Init data frame dynamic rx buffer num: 32
I (641) wifi:Init static rx mgmt buffer num: 5
I (641) wifi:Init management short buffer num: 32
I (651) wifi:Init dynamic tx buffer num: 32
I (651) wifi:Init static rx buffer size: 1600
I (661) wifi:Init static rx buffer num: 10
I (661) wifi:Init dynamic rx buffer num: 32
I (671) wifi_init: rx ba win: 6
I (671) wifi_init: tcpip mbox: 32
I (671) wifi_init: udp mbox: 6
I (681) wifi_init: tcp mbox: 6
I (681) wifi_init: tcp tx win: 5760
I (681) wifi_init: tcp rx win: 5760
I (691) wifi_init: tcp mss: 1440
I (691) wifi_init: WiFi IRAM OP enabled
I (701) wifi_init: WiFi RX IRAM OP enabled
I (701) phy_init: phy_version 4791,2c4672b,Dec 20 2023,16:06:06
I (781) wifi:mode : sta (78:e3:6d:de:96:34)
I (791) wifi:enable tsf
I (801) wifi:new:<1,0>, old:<1,0>, ap:<255,255>, sta:<1,0>, prof:1
I (801) wifi:state: init -> auth (b0)
I (1801) wifi:state: auth -> init (200)
I (1801) wifi:new:<1,0>, old:<1,0>, ap:<255,255>, sta:<1,0>, prof:1
I (1801) wifi_station: retry to connect to the AP (retry left 9 )
I (4221) wifi_station: retry to connect to the AP (retry left 8 )
I (4221) wifi:new:<1,0>, old:<1,0>, ap:<255,255>, sta:<1,0>, prof:1
I (4231) wifi:state: init -> auth (b0)
I (4241) wifi:state: auth -> assoc (0)
I (4271) wifi:state: assoc -> run (10)
I (4301) wifi:connected with SOLO, aid = 5, channel 1, BW20, bssid = 06:ca:c9:2c:b1:59
I (4301) wifi:security: WPA2-PSK, phy: bgn, rssi: -39
I (4301) wifi:pm start, type: 1
I (4311) wifi:dp: 1, bi: 102400, li: 3, scale listen interval from 307200 us to 307200 us
I (4331) wifi:<ba-add>idx:0 (ifx:0, 06:ca:c9:2c:b1:59), tid:0, ssn:0, winSize:64
I (4391) wifi:dp: 2, bi: 102400, li: 4, scale listen interval from 307200 us to 409600 us
I (4391) wifi:AP's beacon interval = 102400 us, DTIM period = 2
I (5311) esp_netif_handlers: sta ip: 192.168.67.112, mask: 255.255.255.0, gw: 192.168.67.39
I (5311) wifi_station: Connected to WiFi network
I (5321) main_task: Returned from app_main()
I (6601) wifi_station: Internet connectivity: Connected
I (11971) wifi:<ba-add>idx:1 (ifx:0, 06:ca:c9:2c:b1:59), tid:4, ssn:0, winSize:64
I (13311) wifi_station: Internet connectivity: Connected
I (19661) wifi_station: Internet connectivity: Connected
```
## Terminal Output: Trying to connect to wifi with wrong credentials

```plaintext
I (29) boot: ESP-IDF v5.2 2nd stage bootloader
I (29) boot: compile time Apr  5 2024 01:45:48
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (36) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (66) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (74) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (81) boot:  2 factory          factory app      00 00 00010000 00100000
I (89) boot: End of partition table
I (93) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=2686ch (157804) map
I (156) esp_image: segment 1: paddr=00036894 vaddr=3ffb0000 size=03c04h ( 15364) load
I (162) esp_image: segment 2: paddr=0003a4a0 vaddr=40080000 size=05b78h ( 23416) load
I (171) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=99cfch (630012) map
I (387) esp_image: segment 4: paddr=000d9d24 vaddr=40085b78 size=10b08h ( 68360) load
I (425) boot: Loaded app from partition at offset 0x10000
I (425) boot: Disabling RNG early entropy source...
I (437) cpu_start: Multicore app
I (446) cpu_start: Pro cpu start user code
I (446) cpu_start: cpu freq: 160000000 Hz
I (446) cpu_start: Application information:
I (449) cpu_start: Project name:     example_wifi
I (454) cpu_start: App version:      b7e9265-dirty
I (460) cpu_start: Compile time:     Apr  5 2024 01:45:00
I (466) cpu_start: ELF file SHA256:  2db690f24...
I (471) cpu_start: ESP-IDF:          v5.2
I (476) cpu_start: Min chip rev:     v0.0
I (480) cpu_start: Max chip rev:     v3.99
I (485) cpu_start: Chip rev:         v1.0
I (490) heap_init: Initializing. RAM available for dynamic allocation:
I (497) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (503) heap_init: At 3FFB8300 len 00027D00 (159 KiB): DRAM
I (510) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (516) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (522) heap_init: At 40096680 len 00009980 (38 KiB): IRAM
I (530) spi_flash: detected chip: generic
I (533) spi_flash: flash io: dio
W (537) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (551) main_task: Started on CPU0
I (561) main_task: Calling app_main()
I (611) wifi:wifi driver task: 3ffc03a8, prio:23, stack:6656, core=0
I (631) wifi:wifi firmware version: cc1dd81
I (631) wifi:wifi certification version: v7.0
I (631) wifi:config NVS flash: enabled
I (631) wifi:config nano formating: disabled
I (641) wifi:Init data frame dynamic rx buffer num: 32
I (641) wifi:Init static rx mgmt buffer num: 5
I (641) wifi:Init management short buffer num: 32
I (651) wifi:Init dynamic tx buffer num: 32
I (651) wifi:Init static rx buffer size: 1600
I (661) wifi:Init static rx buffer num: 10
I (661) wifi:Init dynamic rx buffer num: 32
I (671) wifi_init: rx ba win: 6
I (671) wifi_init: tcpip mbox: 32
I (671) wifi_init: udp mbox: 6
I (681) wifi_init: tcp mbox: 6
I (681) wifi_init: tcp tx win: 5760
I (681) wifi_init: tcp rx win: 5760
I (691) wifi_init: tcp mss: 1440
I (691) wifi_init: WiFi IRAM OP enabled
I (701) wifi_init: WiFi RX IRAM OP enabled
I (701) phy_init: phy_version 4791,2c4672b,Dec 20 2023,16:06:06
I (781) wifi:mode : sta (78:e3:6d:de:96:34)
I (781) wifi:enable tsf
I (3201) wifi_station: retry to connect to the AP (retry left 9 )
I (5621) wifi_station: retry to connect to the AP (retry left 8 )
I (8031) wifi_station: retry to connect to the AP (retry left 7 )
I (10441) wifi_station: retry to connect to the AP (retry left 6 )
I (12851) wifi_station: retry to connect to the AP (retry left 5 )
I (15271) wifi_station: retry to connect to the AP (retry left 4 )
I (17681) wifi_station: retry to connect to the AP (retry left 3 )
I (20091) wifi_station: retry to connect to the AP (retry left 2 )
I (22511) wifi_station: retry to connect to the AP (retry left 1 )
I (24921) wifi_station: retry to connect to the AP (retry left 0 )
E (27331) wifi_station: Failed to connect to the AP after maximum retries
```
## Terminal Output When connecting to wifi without intenet connection

```plaintext
I (29) boot: ESP-IDF v5.2 2nd stage bootloader
I (29) boot: compile time Apr  5 2024 02:01:41
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (36) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (67) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (74) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (81) boot:  2 factory          factory app      00 00 00010000 00100000
I (89) boot: End of partition table
I (93) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=2686ch (157804) map
I (156) esp_image: segment 1: paddr=00036894 vaddr=3ffb0000 size=03c04h ( 15364) load
I (162) esp_image: segment 2: paddr=0003a4a0 vaddr=40080000 size=05b78h ( 23416) load
I (171) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=99cfch (630012) map
I (387) esp_image: segment 4: paddr=000d9d24 vaddr=40085b78 size=10b08h ( 68360) load
I (425) boot: Loaded app from partition at offset 0x10000
I (425) boot: Disabling RNG early entropy source...
I (437) cpu_start: Multicore app
I (446) cpu_start: Pro cpu start user code
I (446) cpu_start: cpu freq: 160000000 Hz
I (446) cpu_start: Application information:
I (449) cpu_start: Project name:     example_wifi
I (454) cpu_start: App version:      b456515-dirty
I (460) cpu_start: Compile time:     Apr  5 2024 02:10:28
I (466) cpu_start: ELF file SHA256:  969d2d8a2...
I (471) cpu_start: ESP-IDF:          v5.2
I (476) cpu_start: Min chip rev:     v0.0
I (481) cpu_start: Max chip rev:     v3.99
I (485) cpu_start: Chip rev:         v1.0
I (490) heap_init: Initializing. RAM available for dynamic allocation:
I (497) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (503) heap_init: At 3FFB8300 len 00027D00 (159 KiB): DRAM
I (510) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (516) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (522) heap_init: At 40096680 len 00009980 (38 KiB): IRAM
I (530) spi_flash: detected chip: generic
I (533) spi_flash: flash io: dio
W (537) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (551) main_task: Started on CPU0
I (561) main_task: Calling app_main()
I (611) wifi:wifi driver task: 3ffc0324, prio:23, stack:6656, core=0
I (631) wifi:wifi firmware version: cc1dd81
I (631) wifi:wifi certification version: v7.0
I (631) wifi:config NVS flash: enabled
I (631) wifi:config nano formating: disabled
I (641) wifi:Init data frame dynamic rx buffer num: 32
I (641) wifi:Init static rx mgmt buffer num: 5
I (641) wifi:Init management short buffer num: 32
I (651) wifi:Init dynamic tx buffer num: 32
I (651) wifi:Init static rx buffer size: 1600
I (661) wifi:Init static rx buffer num: 10
I (661) wifi:Init dynamic rx buffer num: 32
I (671) wifi_init: rx ba win: 6
I (671) wifi_init: tcpip mbox: 32
I (671) wifi_init: udp mbox: 6
I (681) wifi_init: tcp mbox: 6
I (681) wifi_init: tcp tx win: 5760
I (681) wifi_init: tcp rx win: 5760
I (691) wifi_init: tcp mss: 1440
I (691) wifi_init: WiFi IRAM OP enabled
I (701) wifi_init: WiFi RX IRAM OP enabled
I (701) phy_init: phy_version 4791,2c4672b,Dec 20 2023,16:06:06
I (781) wifi:mode : sta (78:e3:6d:de:96:34)
I (781) wifi:enable tsf
I (801) wifi:new:<11,0>, old:<1,0>, ap:<255,255>, sta:<11,0>, prof:1
I (801) wifi:state: init -> auth (b0)
I (1801) wifi:state: auth -> init (200)
I (1801) wifi:new:<11,0>, old:<11,0>, ap:<255,255>, sta:<11,0>, prof:1
I (1811) wifi_station: retry to connect to the AP (retry left 9 )
I (4221) wifi_station: retry to connect to the AP (retry left 8 )
I (4231) wifi:new:<11,0>, old:<11,0>, ap:<255,255>, sta:<11,0>, prof:1
I (4231) wifi:state: init -> auth (b0)
I (4231) wifi:state: auth -> assoc (0)
I (4281) wifi:state: assoc -> run (10)
I (4301) wifi:connected with SOLO, aid = 4, channel 11, BW20, bssid = 06:ca:c9:2c:b1:59
I (4301) wifi:security: WPA2-PSK, phy: bgn, rssi: -35
I (4311) wifi:pm start, type: 1

I (4311) wifi:dp: 1, bi: 102400, li: 3, scale listen interval from 307200 us to 307200 us
I (4331) wifi:<ba-add>idx:0 (ifx:0, 06:ca:c9:2c:b1:59), tid:0, ssn:0, winSize:64
I (4391) wifi:dp: 2, bi: 102400, li: 4, scale listen interval from 307200 us to 409600 us
I (4391) wifi:AP's beacon interval = 102400 us, DTIM period = 2
I (5321) esp_netif_handlers: sta ip: 192.168.67.112, mask: 255.255.255.0, gw: 192.168.67.39
I (5321) wifi_station: Connected to WiFi network
I (5331) main_task: Returned from app_main()
I (5351) wifi:<ba-add>idx:1 (ifx:0, 06:ca:c9:2c:b1:59), tid:7, ssn:0, winSize:64
E (10351) esp-tls: [sock=54] select() timeout
E (10351) transport_base: Failed to open a new connection: 32774
E (10351) HTTP_CLIENT: Connection failed, sock < 0
E (10351) wifi_station: Internet connectivity: Disconnected
E (20371) esp-tls: [sock=54] select() timeout
E (20371) transport_base: Failed to open a new connection: 32774
E (20371) HTTP_CLIENT: Connection failed, sock < 0
E (20371) wifi_station: Internet connectivity: Disconnected
E (30391) esp-tls: [sock=54] select() timeout
E (30391) transport_base: Failed to open a new connection: 32774
E (30391) HTTP_CLIENT: Connection failed, sock < 0
E (30391) wifi_station: Internet connectivity: Disconnected
```
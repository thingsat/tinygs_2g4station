# Basic tests of SX1280 modules

The test are based on the Arduino library for SX12XX https://github.com/StuartsProjects/SX12XX-LoRa

## Instructions

### Toolchain

Add the Espressif toolchain into Preferences > URL of Board manager `https://dl.espressif.com/dl/package_esp32_index.json`

Select the ESP32 board into Tools > Board type > ESP32 Arduino > ESP32 Dev Module

### Basic example

Download the lib `https://codeload.github.com/StuartsProjects/SX12XX-LoRa/zip/refs/heads/master`

Install the lib with `Sketch > Include Lib > Add Zip Lib`

Open the sketch `File > Examples > SX12XX-LoRa-master > examples > SX128x_examples > ESP32 > Basics > 103_LoRa_Transmitter_Detailed_Setup_ESP32`

Replace the default Settings.h by [Settings.h](./Settings.h)

TBC 
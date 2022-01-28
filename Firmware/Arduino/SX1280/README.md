# Basic tests of SX1280 modules with the TinyGS 2G4 station

The test are based on the Arduino library for SX12XX https://github.com/StuartsProjects/SX12XX-LoRa

## Instructions

### Toolchain and SX128x Libraries

Add the Espressif toolchain `https://dl.espressif.com/dl/package_esp32_index.json` into `Preferences > URL of Board manager` 

Select the ESP32 board into `Tools > Board type > ESP32 Arduino > ESP32 Dev Module`

Download the lib `https://codeload.github.com/StuartsProjects/SX12XX-LoRa/zip/refs/heads/master`

Install the lib with `Sketch > Include Lib > Add Zip Lib`

Set the serial console to `115200 8N1`.


### Check the module definition

```c
#define MIKROBUS0_LAMBDA80
//#define MIKROBUS0_E28
//#define MIKROBUS1_LAMBDA80
//#define MIKROBUS1_E28

#include "Settings.h"                            //include the setiings file, frequencies, LoRa settings etc   
...
```

### Configure the `SettingsModulation.h` file

By default, the `SettingsModulation.h` file is compatible with the Multitech 2G4 MCard parameters.

### Transmitter

Open the sketch `TinyGS_2G4_LoRa_Transmitter_Detailed_Setup`

Build and download on the TinyGS 2G4 station which play the role of transmitter.

Open the Arduino console.

The trace is:
```
20:07:41.392 -> LoRa_Transmitter_Detailed_Setup Starting
20:07:41.428 -> LoRa Device found
20:07:42.934 -> 
20:07:42.934 -> SX1280,2421999872hz,SF12,BW812500,CR4:11,IQNormal,Preamble_8
20:07:43.006 -> SX1280,PacketMode_LORA,Explicit,LNAgain_LowPowerRX
20:07:43.077 -> 
20:07:43.077 -> Reg    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
20:07:43.115 -> 0x900  80 FF C9 4F 20 FA BA 4E D4 80 00 00 00 00 00 61 
20:07:43.188 -> 0x910  9C 44 00 00 00 19 00 00 00 19 87 65 43 21 7F FF 
20:07:43.260 -> 0x920  FF FF FF 00 70 50 0A 50 C0 80 00 C0 5F D2 8F 0A 
20:07:43.298 -> 0x930  00 C0 00 00 00 24 00 21 68 B0 30 0D 1B 52 C6 08 
20:07:43.373 -> 0x940  58 0B 32 0A 14 24 6A 96 00 18 00 00 00 00 00 00 
20:07:43.411 -> 0x950  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:07:43.482 -> 0x960  00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF 
20:07:43.555 -> 0x970  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 04 
20:07:43.589 -> 0x980  00 0B 18 70 00 00 00 4C 00 F0 64 00 00 00 00 00 
20:07:43.660 -> 0x990  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:07:43.732 -> 0x9A0  00 08 EC B8 9D 8A E6 66 06 00 00 00 00 00 00 00 
20:07:43.768 -> 0x9B0  00 08 EC B8 9D 8A E6 66 06 00 00 00 00 00 00 00 
20:07:43.844 -> 0x9C0  00 16 00 3F E8 01 FF FF FF FF 5E 4D 25 10 55 55 
20:07:43.914 -> 0x9D0  55 55 55 55 55 55 55 55 55 55 55 55 55 00 00 00 
20:07:43.949 -> 0x9E0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:07:44.025 -> 0x9F0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:07:44.060 -> 
20:07:44.096 -> 
20:07:44.096 -> Transmitter ready
20:07:44.096 -> 10dBm Packet> Hello World 1234567890*  BytesSent,23  CRC,DAAB  TransmitTime,295mS  PacketsSent,1
20:07:45.401 -> 10dBm Packet> Hello World 1234567890*  BytesSent,23  CRC,DAAB  TransmitTime,295mS  PacketsSent,2
20:07:46.730 -> 10dBm Packet> Hello World 1234567890*  BytesSent,23  CRC,DAAB  TransmitTime,295mS  PacketsSent,3
```

Close the console

### Receiver

Open the sketch `TinyGS_2G4_LoRa_Receiver_Detailed_Setup`

Build and download on the TinyGS 2G4 station which play the role of receiver.

Open the Arduino console.

The trace is:
```
20:08:01.874 -> LoRa_Receiver_Detailed_Setup Starting
20:08:01.907 -> 
20:08:01.907 -> LoRa Device found
20:08:03.432 -> 
20:08:03.432 -> SX1280,2421999872hz,SF12,BW812500,CR4:11,IQNormal,Preamble_8
20:08:03.498 -> SX1280,PacketMode_LORA,Explicit,LNAgain_LowPowerRX
20:08:03.531 -> 
20:08:03.565 -> Reg    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
20:08:03.602 -> 0x900  80 FF C9 4F 20 FA BA 4E D4 80 00 00 00 00 00 61 
20:08:03.674 -> 0x910  9C 44 00 00 00 19 00 00 00 19 87 65 43 21 7F FF 
20:08:03.711 -> 0x920  FF FF FF 00 70 50 0A 50 C0 80 00 C0 5F D2 8F 0A 
20:08:03.782 -> 0x930  00 C0 00 00 00 24 00 21 68 B0 30 0D 1B 52 C6 0C 
20:08:03.853 -> 0x940  58 0B 32 0A 14 24 6A 96 00 18 00 00 00 00 00 00 
20:08:03.890 -> 0x950  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:08:03.964 -> 0x960  00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF 
20:08:04.037 -> 0x970  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 04 
20:08:04.075 -> 0x980  00 0B 18 70 00 00 00 4C 00 F0 64 00 00 00 00 00 
20:08:04.148 -> 0x990  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:08:04.186 -> 0x9A0  00 08 EC B8 9D 8A E6 66 06 00 00 00 00 00 00 00 
20:08:04.258 -> 0x9B0  00 08 EC B8 9D 8A E6 66 06 00 00 00 00 00 00 00 
20:08:04.329 -> 0x9C0  00 16 00 3F E8 01 FF FF FF FF 5E 4D 25 10 55 55 
20:08:04.364 -> 0x9D0  55 55 55 55 55 55 55 55 55 55 55 55 55 00 00 00 
20:08:04.437 -> 0x9E0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:08:04.513 -> 0x9F0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20:08:04.548 -> 
20:08:04.548 -> 
20:08:04.548 -> Receiver ready - RXBUFFER_SIZE 32
```

Power the transmitter station with an USB cable.

The trace is:
```
20:08:04.584 -> 
20:09:03.773 -> 62s  Hello World 1234567890*,CRC,DAAB,RSSI,-81dBm,SNR,6dB,Length,23,Packets,1,Errors,0,IRQreg,8012
20:09:05.086 -> 63s  Hello World 1234567890*,CRC,DAAB,RSSI,-92dBm,SNR,5dB,Length,23,Packets,2,Errors,0,IRQreg,8012
20:09:06.390 -> 65s  Hello World 1234567890*,CRC,DAAB,RSSI,-94dBm,SNR,4dB,Length,23,Packets,3,Errors,0,IRQreg,8012
20:09:07.724 -> 66s  Hello World 1234567890*,CRC,DAAB,RSSI,-93dBm,SNR,5dB,Length,23,Packets,4,Errors,0,IRQreg,8012
```


## TodoList
* add a frame counter instead of 1234567890
* Test other examples from https://github.com/StuartsProjects/SX12XX-LoRa/tree/master/examples/SX128x_examples
* Test SX1280 examples from TinyGS [RadioLib](https://github.com/jgromes/RadioLib/tree/master/examples/SX128x)

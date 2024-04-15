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
MAC Address: 44E399A4AE30

18:18:15 Apr 15 2024
V1.1

TinyGS 2G4 :: LoRa_Transmitter_Detailed_Setup Starting
LoRa Device found

SX1280
SX1280,PACKET_TYPE_LORA,2483499776hz,SF12,BW812500,CR4:9
SX1280,PACKET_TYPE_LORA,Preamble_8,Explicit,PayloadL_255,CRC_ON,IQ_NORMAL,LNAgain_LowPowerRX

Reg    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0x900  80 FF C9 4D 20 FA BF 09 E8 80 00 00 00 00 00 61 
0x910  9C 44 00 00 00 19 00 00 00 19 87 65 43 21 7F FF 
0x920  FF FF FF 00 70 32 0A 50 C0 80 00 C0 5F D2 8F 0A 
0x930  00 C0 00 00 00 24 00 21 68 B0 30 0D 01 52 C6 08 
0x940  58 0B 32 0A 14 24 6A 96 00 18 00 00 00 00 00 00 
0x950  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x960  00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF 
0x970  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 04 
0x980  00 0B 18 70 00 00 00 4C 00 F0 64 00 00 00 00 00 
0x990  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x9A0  00 08 EC B8 9D 8A E6 66 04 00 00 00 00 00 00 00 
0x9B0  00 08 EC B8 9D 8A E6 66 04 00 00 00 00 00 00 00 
0x9C0  00 16 00 3F E8 01 FF FF FF FF 5E 4D 25 10 55 55 
0x9D0  55 55 55 55 55 55 55 55 55 55 55 55 55 00 00 00 
0x9E0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x9F0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 


Transmitter ready
0dBm Packet> 44E399A4AE30;fcnt:0,pow:0  BytesSent,25  CRC,2710  TransmitTime,229mS  PacketsSent,1
1dBm Packet> 44E399A4AE30;fcnt:1,pow:1  BytesSent,25  CRC,8F50  TransmitTime,228mS  PacketsSent,2
2dBm Packet> 44E399A4AE30;fcnt:2,pow:2  BytesSent,25  CRC,67B1  TransmitTime,228mS  PacketsSent,3
3dBm Packet> 44E399A4AE30;fcnt:3,pow:3  BytesSent,25  CRC,CFF1  TransmitTime,228mS  PacketsSent,4
4dBm Packet> 44E399A4AE30;fcnt:4,pow:4  BytesSent,25  CRC,A652  TransmitTime,228mS  PacketsSent,5
5dBm Packet> 44E399A4AE30;fcnt:5,pow:5  BytesSent,25  CRC,E12  TransmitTime,228mS  PacketsSent,6
6dBm Packet> 44E399A4AE30;fcnt:6,pow:6  BytesSent,25  CRC,E6F3  TransmitTime,228mS  PacketsSent,7
7dBm Packet> 44E399A4AE30;fcnt:7,pow:7  BytesSent,25  CRC,4EB3  TransmitTime,228mS  PacketsSent,8
8dBm Packet> 44E399A4AE30;fcnt:8,pow:8  BytesSent,25  CRC,35B5  TransmitTime,228mS  PacketsSent,9
9dBm Packet> 44E399A4AE30;fcnt:9,pow:9  BytesSent,25  CRC,9DF5  TransmitTime,228mS  PacketsSent,10
10dBm Packet> 44E399A4AE30;fcnt:10,pow:10  BytesSent,27  CRC,BB40  TransmitTime,239mS  PacketsSent,11
0dBm Packet> 44E399A4AE30;fcnt:11,pow:0  BytesSent,26  CRC,DCF3  TransmitTime,233mS  PacketsSent,12
1dBm Packet> 44E399A4AE30;fcnt:12,pow:1  BytesSent,26  CRC,1450  TransmitTime,233mS  PacketsSent,13
2dBm Packet> 44E399A4AE30;fcnt:13,pow:2  BytesSent,26  CRC,9C52  TransmitTime,233mS  PacketsSent,14
```

Close the console

### Receiver

Open the sketch `TinyGS_2G4_LoRa_Receiver_Detailed_Setup`

Build and download on the TinyGS 2G4 station which play the role of receiver.

Open the Arduino console.

Power the transmitter station with an USB cable.

The trace is:
```
MAC Address: 80B825FB0BAC

TinyGS 2G4 :: LoRa_Receiver_Detailed_Setup Starting

LoRa Device found

SX1280,PACKET_TYPE_LORA,2483499776hz,SF12,BW812500,CR4:9
SX1280,PACKET_TYPE_LORA,Preamble_8,Explicit,PayloadL_255,CRC_ON,IQ_NORMAL,LNAgain_LowPowerRX

Reg    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0x900  80 FF C9 4D 20 FA BF 09 E8 80 00 00 00 00 00 61 
0x910  9C 44 00 00 00 19 00 00 00 19 87 65 43 21 7F FF 
0x920  FF FF FF 00 70 32 0A 50 C0 80 00 C0 5F D2 8F 0A 
0x930  00 C0 00 00 00 24 00 21 68 B0 30 0D 01 52 C6 08 
0x940  58 0B 32 0A 14 24 6A 96 00 18 00 00 00 00 00 00 
0x950  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x960  00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF 
0x970  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 04 
0x980  00 0B 18 70 00 00 00 4C 00 F0 64 00 00 00 00 00 
0x990  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x9A0  00 08 EC B8 9D 8A E6 66 04 00 00 00 00 00 00 00 
0x9B0  00 08 EC B8 9D 8A E6 66 04 00 00 00 00 00 00 00 
0x9C0  00 16 00 3F E8 01 FF FF FF FF 5E 4D 25 10 55 55 
0x9D0  55 55 55 55 55 55 55 55 55 55 55 55 55 00 00 00 
0x9E0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
0x9F0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 


Receiver ready - RXBUFFER_SIZE 255

4s  44E399A4AE30;fcnt:0,pow:0,CRC,2710,RSSI,-53dBm,SNR,7dB,Length,25,Packets,1,Errors,0,IRQreg,8012
5s  44E399A4AE30;fcnt:1,pow:1,CRC,8F50,RSSI,-52dBm,SNR,7dB,Length,25,Packets,2,Errors,0,IRQreg,8012
7s  44E399A4AE30;fcnt:2,pow:2,CRC,67B1,RSSI,-51dBm,SNR,6dB,Length,25,Packets,3,Errors,0,IRQreg,8012
8s  44E399A4AE30;fcnt:3,pow:3,CRC,CFF1,RSSI,-49dBm,SNR,7dB,Length,25,Packets,4,Errors,0,IRQreg,8012
9s  44E399A4AE30;fcnt:4,pow:4,CRC,A652,RSSI,-49dBm,SNR,6dB,Length,25,Packets,5,Errors,0,IRQreg,8012
10s  44E399A4AE30;fcnt:5,pow:5,CRC,E12,RSSI,-49dBm,SNR,7dB,Length,25,Packets,6,Errors,0,IRQreg,8012
12s  44E399A4AE30;fcnt:6,pow:6,CRC,E6F3,RSSI,-47dBm,SNR,5dB,Length,25,Packets,7,Errors,0,IRQreg,8012
13s  44E399A4AE30;fcnt:7,pow:7,CRC,4EB3,RSSI,-46dBm,SNR,6dB,Length,25,Packets,8,Errors,0,IRQreg,8012
14s  44E399A4AE30;fcnt:8,pow:8,CRC,35B5,RSSI,-46dBm,SNR,6dB,Length,25,Packets,9,Errors,0,IRQreg,8012
15s  44E399A4AE30;fcnt:9,pow:9,CRC,9DF5,RSSI,-45dBm,SNR,6dB,Length,25,Packets,10,Errors,0,IRQreg,8012
16s  44E399A4AE30;fcnt:10,pow:10,CRC,BB40,RSSI,-44dBm,SNR,5dB,Length,27,Packets,11,Errors,0,IRQreg,8012
18s  44E399A4AE30;fcnt:11,pow:0,CRC,DCF3,RSSI,-52dBm,SNR,7dB,Length,26,Packets,12,Errors,0,IRQreg,8012
19s  44E399A4AE30;fcnt:12,pow:1,CRC,1450,RSSI,-56dBm,SNR,6dB,Length,26,Packets,13,Errors,0,IRQreg,8012
20s  44E399A4AE30;fcnt:13,pow:2,CRC,9C52,RSSI,-55dBm,SNR,6dB,Length,26,Packets,14,Errors,0,IRQreg,8012
21s  44E399A4AE30;fcnt:14,pow:3,CRC,9537,RSSI,-60dBm,SNR,5dB,Length,26,Packets,15,Errors,0,IRQreg,8012
23s  44E399A4AE30;fcnt:15,pow:4,CRC,5DB1,RSSI,-57dBm,SNR,6dB,Length,26,Packets,16,Errors,0,IRQreg,8012
```

## Two transmitters

Build and download `TinyGS_2G4_LoRa_Transmitter_Detailed_Setup` on a third TinyGS 2G4 station which play the role of transmitter.

Observe the frame collisions between the two boards `44E399A4AE30` and `84156DC63C94`.

```
2s  44E399A4AE30;fcnt:20,pow:9,CRC,3DCE,RSSI,-32dBm,SNR,6dB,Length,26,Packets,1,Errors,0,IRQreg,8012
3s  44E399A4AE30;fcnt:21,pow:10,CRC,D1D7,RSSI,-31dBm,SNR,6dB,Length,27,Packets,2,Errors,0,IRQreg,8012
4s PacketError,RSSI,-39dBm,SNR,0dB,Length,27,Packets,2,Errors,1,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
6s  44E399A4AE30;fcnt:23,pow:1,CRC,6444,RSSI,-39dBm,SNR,6dB,Length,26,Packets,3,Errors,1,IRQreg,8012
7s  44E399A4AE30;fcnt:24,pow:2,CRC,4D63,RSSI,-38dBm,SNR,7dB,Length,26,Packets,4,Errors,1,IRQreg,8012
8s  44E399A4AE30;fcnt:25,pow:3,CRC,E523,RSSI,-37dBm,SNR,7dB,Length,26,Packets,5,Errors,1,IRQreg,8012
9s  44E399A4AE30;fcnt:26,pow:4,CRC,4D46,RSSI,-37dBm,SNR,7dB,Length,26,Packets,6,Errors,1,IRQreg,8012
11s PacketError,RSSI,-35dBm,SNR,0dB,Length,26,Packets,6,Errors,2,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
12s PacketError,RSSI,-34dBm,SNR,2dB,Length,26,Packets,6,Errors,3,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
13s  84156DC63C94;fcnt:72,pow:6,CRC,CCBE,RSSI,-29dBm,SNR,2dB,Length,26,Packets,7,Errors,3,IRQreg,8012
14s  84156DC63C94;fcnt:73,pow:7,CRC,64FE,RSSI,-28dBm,SNR,0dB,Length,26,Packets,8,Errors,3,IRQreg,8012
16s PacketError,RSSI,-52dBm,SNR,-2dB,Length,26,Packets,8,Errors,4,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
17s PacketError,RSSI,-51dBm,SNR,-1dB,Length,26,Packets,8,Errors,5,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
18s  84156DC63C94;fcnt:76,pow:10,CRC,669,RSSI,-49dBm,SNR,5dB,Length,27,Packets,9,Errors,5,IRQreg,8012
19s PacketError,RSSI,-51dBm,SNR,-1dB,Length,26,Packets,9,Errors,6,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
21s PacketError,RSSI,-51dBm,SNR,-1dB,Length,26,Packets,9,Errors,7,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
22s PacketError,RSSI,-36dBm,SNR,0dB,Length,26,Packets,9,Errors,8,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
23s PacketError,RSSI,-35dBm,SNR,0dB,Length,26,Packets,9,Errors,9,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
24s PacketError,RSSI,-35dBm,SNR,-1dB,Length,26,Packets,9,Errors,10,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
25s PacketError,RSSI,-52dBm,SNR,-2dB,Length,26,Packets,9,Errors,11,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
27s PacketError,RSSI,-31dBm,SNR,0dB,Length,26,Packets,9,Errors,12,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
28s PacketError,RSSI,-31dBm,SNR,-1dB,Length,26,Packets,9,Errors,13,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
29s  84156DC63C94;fcnt:85,pow:8,CRC,EDF6,RSSI,-50dBm,SNR,0dB,Length,26,Packets,10,Errors,13,IRQreg,8012
30s PacketError,RSSI,-50dBm,SNR,0dB,Length,26,Packets,10,Errors,14,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
32s  84156DC63C94;fcnt:87,pow:10,CRC,D9EE,RSSI,-29dBm,SNR,5dB,Length,27,Packets,11,Errors,14,IRQreg,8012
33s PacketError,RSSI,-39dBm,SNR,-1dB,Length,26,Packets,11,Errors,15,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
34s PacketError,RSSI,-37dBm,SNR,-1dB,Length,26,Packets,11,Errors,16,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
35s PacketError,RSSI,-36dBm,SNR,-1dB,Length,26,Packets,11,Errors,17,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
37s  84156DC63C94;fcnt:91,pow:3,CRC,DA88,RSSI,-33dBm,SNR,3dB,Length,26,Packets,12,Errors,17,IRQreg,8012
38s PacketError,RSSI,-35dBm,SNR,-1dB,Length,26,Packets,12,Errors,18,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
39s  84156DC63C94;fcnt:93,pow:5,CRC,DAAD,RSSI,-31dBm,SNR,4dB,Length,26,Packets,13,Errors,18,IRQreg,8012
40s  84156DC63C94;fcnt:94,pow:6,CRC,F38A,RSSI,-51dBm,SNR,-1dB,Length,26,Packets,14,Errors,18,IRQreg,8012
42s  84156DC63C94;fcnt:95,pow:7,CRC,5BCA,RSSI,-29dBm,SNR,0dB,Length,26,Packets,15,Errors,18,IRQreg,8012
43s PacketError,RSSI,-31dBm,SNR,-1dB,Length,26,Packets,15,Errors,19,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
44s  84156DC63C94;fcnt:97,pow:9,CRC,DAE7,RSSI,-27dBm,SNR,3dB,Length,26,Packets,16,Errors,19,IRQreg,8012
45s  84156DC63C94;fcnt:98,pow:10,CRC,EB0F,RSSI,-29dBm,SNR,4dB,Length,27,Packets,17,Errors,19,IRQreg,8012
46s PacketError,RSSI,-40dBm,SNR,3dB,Length,26,Packets,17,Errors,20,IRQreg,8052,IRQ_RX_DONE,IRQ_HEADER_VALID,IRQ_CRC_ERROR,IRQ_PREAMBLE_DETECTED
48s  84156DC63C94;fcnt:100,pow:1,CRC,AEAD,RSSI,-37dBm,SNR,0dB,Length,27,Packets,18,Errors,20,IRQreg,8012
49s  44E399A4AE30;fcnt:58,pow:3,CRC,C831,RSSI,-37dBm,SNR,7dB,Length,26,Packets,19,Errors,20,IRQreg,8012
50s  44E399A4AE30;fcnt:59,pow:4,CRC,B7,RSSI,-36dBm,SNR,7dB,Length,26,Packets,20,Errors,20,IRQreg,8012
51s  84156DC63C94;fcnt:0,pow:0,CRC,AD08,RSSI,-42dBm,SNR,5dB,Length,25,Packets,21,Errors,20,IRQreg,8012
51s  44E399A4AE30;fcnt:60,pow:5,CRC,F32F,RSSI,-34dBm,SNR,6dB,Length,26,Packets,22,Errors,20,IRQreg,8012
52s  84156DC63C94;fcnt:1,pow:1,CRC,548,RSSI,-42dBm,SNR,5dB,Length,25,Packets,23,Errors,20,IRQreg,8012
53s  44E399A4AE30;fcnt:61,pow:6,CRC,7B2D,RSSI,-34dBm,SNR,6dB,Length,26,Packets,24,Errors,20,IRQreg,8012
54s  84156DC63C94;fcnt:2,pow:2,CRC,EDA9,RSSI,-40dBm,SNR,7dB,Length,25,Packets,25,Errors,20,IRQreg,8012
54s  44E399A4AE30;fcnt:62,pow:7,CRC,B38E,RSSI,-33dBm,SNR,7dB,Length,26,Packets,26,Errors,20,IRQreg,8012
```

## Exercice

Add a true random delay into the `TinyGS_2G4_LoRa_Transmitter_Detailed_Setup` at line 87: `delay(packet_delay);`

Observe the LoRa frame collisions.

## TodoList
* [x] add a frame counter instead of 1234567890
* [ ] Test other examples from https://github.com/StuartsProjects/SX12XX-LoRa/tree/master/examples/SX128x_examples
* [ ] Test SX1280 examples from TinyGS [RadioLib](https://github.com/jgromes/RadioLib/tree/master/examples/SX128x)
* [ ] Add LoRaWAN-like frame
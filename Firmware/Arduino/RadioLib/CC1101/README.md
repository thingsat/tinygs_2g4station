# CC1101

## C1101

Wire the ESP32 Dev Module to the [CC1101 module](https://github.com/CampusIoT/tutorial/tree/master/cc1101)

| ESP32 Pin on Mikrobus #1 | Function | CC1101 Pin |
| --------- | -------- | ---------- |
| GND  | GND  | 1 |
| 3V3  | 3V3  | 2 |
| 23   | MOSI | 6 |
| 19   | MISO | 7 |
| 18   | SCK  | 5 |
| 15   | CS   | 4 |
| 27   | GDO0 | 3 |
| 4    | GDO2 | 8 |

Select board `ESP32 > ESP32 Dev Module`

Replace the following line into `File > Examples > RadioLib > C1101` 
```c
#include "SettingsModule.h"

// Work with Mikrobus 1 only (transmit fails on Mikrobus 0)
#define CC1101_MIKROBUS_1   1

// CC1101 has the following connections on ESP32 Dev Module

#define CC1101_CS_PIN           NSS_1
#define CC1101_GDO0_PIN         AN_1
#define CC1101_GDO2_PIN         PWM_1
#define CC1101_RST_PIN          RADIOLIB_NC

CC1101 radio = new Module(CC1101_CS_PIN, CC1101_GDO0_PIN, CC1101_RST_PIN, CC1101_GDO2_PIN);
```

# CC1101

## C1101

Wire the ESP32 Dev Module to the [CC1101 module](https://github.com/CampusIoT/tutorial/tree/master/cc1101)

| ESP32 Pin | Function | CC1101 Pin |
| --------- | -------- | ---------- |
| GND | GND  | 1 |
| 3V3 | 3V3  | 2 |
| 23  | MOSI | 6 |
| 19  | MISO | 7 |
| 18  | SCK  | 5 |
| 5   | CS   | 4 |
| 2   | GDO0 | 3 |
| 3   | GDO2 | 8 |


Replace the following line into `File > Examples > RadioLib > C1101` 
```c
// CC1101 has the following connections on ESP32 Dev Module
// CS pin:    5
// GDO0 pin:  2
// RST pin:   unused
// GDO2 pin:  3 (optional)
CC1101 radio = new Module(5, 2, RADIOLIB_NC, 3);
```

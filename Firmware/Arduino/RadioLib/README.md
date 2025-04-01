# RadioLib

[RadioLib](https://github.com/jgromes/RadioLib) for Arduino allows to integrate all sorts of different wireless communication modules, protocols and even digital modes into a single consistent system.

### Supported modules:
* __CC1101__ FSK radio module
* __LLCC68__ LoRa module
* __LR11x0__ series LoRa/GFSK modules (LR1110, LR1120, LR1121)
* __nRF24L01__ 2.4 GHz module
* __RF69__ FSK/OOK radio module
* __RFM2x__ series FSK modules (RFM22, RM23)
* __RFM9x__ series LoRa modules (RFM95, RM96, RFM97, RFM98)
* __Si443x__ series FSK modules (Si4430, Si4431, Si4432)
* __STM32WL__ integrated microcontroller/LoRa module
* __SX126x__ series LoRa modules (SX1261, SX1262, SX1268)
* __SX127x__ series LoRa modules (SX1272, SX1273, SX1276, SX1277, SX1278, SX1279)
* __SX128x__ series LoRa/GFSK/BLE/FLRC modules (SX1280, SX1281, SX1282)
* __SX123x__ FSK/OOK radio modules (SX1231, SX1233)

### Supported protocols and digital modes:
* [__AX.25__](https://www.sigidwiki.com/wiki/PACKET) using 2-FSK or AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, RFM2x, Si443x, LR11x0 and SX128x
* [__RTTY__](https://www.sigidwiki.com/wiki/RTTY) using 2-FSK or AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, nRF24L01, RFM2x, Si443x, LR11x0 and SX128x
* [__Morse Code__](https://www.sigidwiki.com/wiki/Morse_Code_(CW)) using 2-FSK or AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, nRF24L01, RFM2x, Si443x, LR11x0 and SX128x
* [__SSTV__](https://www.sigidwiki.com/wiki/SSTV) using 2-FSK or AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, RFM2x and Si443x
* [__Hellschreiber__](https://www.sigidwiki.com/wiki/Hellschreiber) using 2-FSK or AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, nRF24L01, RFM2x, Si443x, LR11x0 and SX128x
* [__APRS__](https://www.sigidwiki.com/wiki/APRS) using AFSK for modules:  
SX127x, RFM9x, SX126x, RF69, SX1231, CC1101, nRF24L01, RFM2x, Si443x and SX128x
* [__POCSAG__](https://www.sigidwiki.com/wiki/POCSAG) using 2-FSK for modules:  
SX127x, RFM9x, RF69, SX1231, CC1101, nRF24L01, RFM2x and Si443x
* [__LoRaWAN__](https://lora-alliance.org/) using LoRa and FSK for modules:  
SX127x, RFM9x, SX126x, LR11x0 and SX128x  



## Install

Install `RadioLib` using the library manager (`Sketch > Include Libraty > Manage Libraries...`)

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


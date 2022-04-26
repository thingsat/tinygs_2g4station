# TinyGS 2G4 :: SDCard breakout

Read https://randomnerdtutorials.com/esp32-microsd-card-arduino/

Import library https://github.com/espressif/arduino-esp32/tree/master/libraries/SD as a Zip file

Connect the SD card breakout to the following pins of the ESP32 Wroon 32U's double row headers


| SD Card | ESP32 Wroom 32U | Header |
|---------|-----------------|--------|
| D2       | - | - |
| D3/CS       | SS (IO5) | Pin29|
| CMD/MOSI      | MOSI (IO23)| Pin21|
| VSS/GND      | GND (GND3)| Pin20|
| VDD/3V3      | 3.3V (3V3)| Pin1|
| CLK     | SCK (IO12)| Pin13|
| VSS/GND      | - | - |
| D0/MISO       | MISO (IO19)| Pin27|
| D1       | - | - |


Build and flash the sketch SDCard_Test
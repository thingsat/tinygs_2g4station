# TinyGS 2G4 :: Firmware :: Arduino

### Toolchain and SX128x Libraries

Add the Espressif toolchain `https://dl.espressif.com/dl/package_esp32_index.json` into `Preferences > URL of Board manager` 

Select the ESP32 board into `Tools > Board type > ESP32 Arduino > ESP32 Dev Module`

Download the lib `https://codeload.github.com/StuartsProjects/SX12XX-LoRa/zip/refs/heads/master`

Install the lib with `Sketch > Include Lib > Add Zip Lib`

Set the serial console to `115200 8N1`.

## Examples

### LoRa SX1280

* [SX1280](./SX1280) for StuartsProjects - SX12XX

### Networks

* [MQTT](./MQTT) : simple MQTT publisher. Scan of Wifi SSID for searching the Wifi hotspot
* [UDP Dataframe (Semtech UDP Packet Forwarder)](https://github.com/dragino/Arduino-Profile-Examples/tree/master/libraries/Dragino/examples/LoRa/LoRaWAN/LoRaWAN_packet_forwarder)
* [OpenMQTTGateway](https://docs.openmqttgateway.com/)

### Sensors

* [23_GPS_Tracker_Transmitter](./23_GPS_Tracker_Transmitter) with [Grove GPS](https://wiki.seeedstudio.com/Grove-GPS/)
* [Analog_Input_Joystick](./Analog_Input_Joystick) : with [Grove Thumb Joystick](https://wiki.seeedstudio.com/Grove-Thumb_Joystick/)
* [TinyGPSPlus_FullExample](./TinyGPSPlus_FullExample)
* [Grove_LSM6DS3_Accelerometer_Gyroscope](./Grove_LSM6DS3_Accelerometer_Gyroscope) with [Grove  LSM6DS3 Accelerometer Gyroscope](https://wiki.seeedstudio.com/Grove-6-Axis_AccelerometerAndGyroscope/)

Seeedstudio proposes other boards with [various accelerometers](https://wiki.seeedstudio.com/Sensor_accelerometer/).

### Misc

* [TinyGPSPlus_SatelliteTracker](./TinyGPSPlus_SatelliteTracker)
* [ArduinoP13 TLE](https://github.com/TNeutron/ArduinoP13)
* [JSON](https://arduinojson.org/)
* [Sat Tracker](https://github.com/alexchang0229/SatelliteTracker)

## Arduino external libraries

### tinyGS RadioLib
The firmware [RadioLib](https://github.com/thingsat/tinygs_2g4station/tree/main/Firmware/Exemple/Transceiver_modules-RadioLib) is provided by the [tinyGS](https://github.com/G4lile0/tinyGS) community. TinyGS is an open network of Ground Stations distributed around the world to receive and operate LoRa satellites, using cheap and versatile modules. [RadioLib by TinyGS](https://github.com/G4lile0/tinyGS/tree/master/lib/RadioLib) allows its users to integrate all sorts of different wireless communication modules, protocols and even digital modes into a single consistent system. This Lib allow to use a large number of different transceiver modules, protocols and platforms on Arduino IDE.

### StuartsProjects - SX12XX 	
The firmware [SX12XX](https://github.com/thingsat/tinygs_2g4station/tree/main/Firmware/Exemple/Transceiver_modules-SX12XX) is provided by [StuartsProjects](https://github.com/StuartsProjects). StuartsProjects is a independent user which for the last few years has been mostly to do with exploring the capabilities and applications for devices using Semtech�s LoRa�. Thanks to him, he publish all his work ant test on his GitHub page, with some nice description and explanation. 

StuartsProjects made a lib for Semtechs SX12XX LoRa device.[SX12XX-LoRa](https://github.com/StuartsProjects/SX12XX-LoRa). His library supports the SX126x, SX127x and SX128x Semtech LoRa devices. Therefore, the library does not support LoRa modules with a UART based interface such as those from Ebyte and Microchip. There are examples for sending\receiving a simple character buffer ("Hello World") using the SX1280 LoRa module with a ESP32.

StuartsProjects publish a ranging test unsing the G-NiceRF LoRa1280 devices: [SX1280_Testing](https://github.com/StuartsProjects/SX1280_Testing). He uses the SX1280 ranging mode that can measure distance by recording the time of flight of a special packet exchange between two SX1280s. However, the code seems not be published. 

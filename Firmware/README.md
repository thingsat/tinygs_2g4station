# Firmware

You will find here all the firmware that you need for your 2.4GHz ground station using SX128x module.

## Arduino IDE basic tests
Example contains
* [Grove Thumb Joystick](https://wiki.seeedstudio.com/Grove-Thumb_Joystick/)
* [Grove  LSM6DS3 Accelerometer Gyroscope](https://wiki.seeedstudio.com/Grove-6-Axis_AccelerometerAndGyroscope/)
* [Grove GPS](https://wiki.seeedstudio.com/Grove-GPS/)
* SX128x SPI module on Mikrobus adapter 

Seeedstudio proposes boards with [various accelerometers](https://wiki.seeedstudio.com/Sensor_accelerometer/).


###TinyGS - RadioLib
The firmware [RadioLib](https://github.com/thingsat/tinygs_2g4station/tree/main/Firmware/Exemple/Transceiver_modules-RadioLib) is provided by the [tinyGS](https://github.com/G4lile0/tinyGS) community. TinyGS is an open network of Ground Stations distributed around the world to receive and operate LoRa satellites, using cheap and versatile modules. [RadioLib by TinyGS](https://github.com/G4lile0/tinyGS/tree/master/lib/RadioLib) allows its users to integrate all sorts of different wireless communication modules, protocols and even digital modes into a single consistent system. This Lib allow to use a large number of different transceiver modules, protocols and platforms on Arduino IDE.

###StuartsProjects - SX12XX 	
The firmware [SX12XX](https://github.com/thingsat/tinygs_2g4station/tree/main/Firmware/Exemple/Transceiver_modules-SX12XX) is provided by [StuartsProjects](https://github.com/StuartsProjects). StuartsProjects is a independent user which for the last few years has been mostly to do with exploring the capabilities and applications for devices using Semtech’s LoRa®. Thanks to him, he publish all his work ant test on his GitHub page, with some nice description and explanation. 

StuartsProjects made a lib for Semtechs SX12XX LoRa device.[SX12XX-LoRa](https://github.com/StuartsProjects/SX12XX-LoRa). His library supports the SX126x, SX127x and SX128x Semtech LoRa devices. Therefore, the library does not support LoRa modules with a UART based interface such as those from Ebyte and Microchip. There are examples for sending\receiving a simple character buffer ("Hello World") using the SX1280 LoRa module with a ESP32.

StuartsProjects publish a ranging test unsing the G-NiceRF LoRa1280 devices: [SX1280_Testing](https://github.com/StuartsProjects/SX1280_Testing). He uses the SX1280 ranging mode that can measure distance by recording the time of flight of a special packet exchange between two SX1280s. However, the code seems not be published. 

## RIOT OS basic tests
TODO

## RIOT OS cubesat endpoint
TODO


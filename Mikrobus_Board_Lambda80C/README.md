# Mikrobus Adapter for Lambda80-24S SX1280 Module

This is a board to support a lambda80C 2.4GHz LORA transceiver RF module, adapted to Mikrobus standard pinout specification.

Lambda Module used: [Lambda80-24S](https://fr.farnell.com/rf-solutions/lambda80-24s/transceiver-2mbps-2-5ghz/dp/2988571). The LAMBDA80 is a 2.4GHz LoRa transceiver using the Semtech SX1280 technology, providing ultra-long range, spread spectrum communication and high interference immunity within minimal current. For more information on [SX1280](https://github.com/thingsat/tinygs_2g4station/blob/main/Datasheet_SEMTECH_SX1280.PDF).

Some Specification:
* Transmit power +12.5 dBm
* High sensitivity: down to -132 dBm
* RF Data Rate: FSK upto 2.02Mbps - LoRa upto 476bps

Programing of the module is via SPI interface. This module has as pin BUSY, RESET, SPI, 3 DIO (Digital I/O software configured) and a Antenna connection “C” Versions. Antenna  is connectable with a connector UFL female.


Here the connection between the Mikrobus standard pin and the Lambda80 module pin

	AN	<->	DIO1
	RST	<->	RESET
	CS	<->	NSEL
	SCK	<->	SCLK
	MISO	<->	SDO
	MOSI	<->	SDI
	PWM	<->	DIO2
	INT	<->	BUSY

![Lambda_80_Schematic](https://github.com/thingsat/tinygs_2g4station/blob/main/Mikrobus_Board_Lambda80C/Picture/Lambda_80_Schematic.PNG)

Lambda80 is supplied with 3.3V, by the +3.3V Mikrobus pin.

The Ebyte E28 module has no PCB antenna, so a external antenna is needed. A UFL male connector is available on the module to plug a external antenna with a UFL female connector.

### Kicad Project
The project was made on Kikad, which is a free software for electronics circuit board design, developed by IUT of Grenoble.

For the mikrobus lib and footprint, I use the [MIKROE-924](https://componentsearchengine.com/part-view/MIKROE-924/MIKROELEKTRONIKA) model available on [component search engine](https://componentsearchengine.com/).
For the Lambda80, I use the [Lambda80](https://componentsearchengine.com/part-view/LAMBDA80-24S/RF%20SOLUTIONS) model.

All the schematic and footprint are in the "Lib & Fp" folder. For the Mikrobus and Lambda80 lib, you have to choose the KiCad folder when adding the lib to the project.

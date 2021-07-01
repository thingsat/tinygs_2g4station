# TinyGS :: 2.4 GHz LoRa ground station
HW and FW of a TinyGS 2.4 GHz LoRa ground station https://tinygs.com/


## Todolist
* [ ] PCB for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C)
* [ ] PCB for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C) + H-Bridges for driving stepper + Power supply
* [ ] TinyGS firmware for ESP32 Vroom + E28 module
* [ ] TinyGS firmware for ESP32 Vroom + Lambda80 module
* [ ] Power consumption study with [X-NUCLEO-LPM01A](https://www.st.com/en/evaluation-tools/x-nucleo-lpm01a.html)
* [ ] RIOTOS firmware for ESP32 Vroom + Lambda80 module (cubesat emulator)


## PCB for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C)
This PCB is designed to support a ESP32 devkit board and 2 MiKroBus modules.

The purpose of this board is to control mikrobus modules including SX1280 technology that will transmit and receive messages on a 2.4GHz radio frequency. Each module are connected to a ESP32 which will be connected to the wifi.

Mikrobus board is an add-on board socket standard made by [mikroe](https://www.mikroe.com/mikrobus)
 ![MiKroBus module](https://github.com/thingsat/tinygs_2g4station/blob/main/MiKroBus_module%20-%20Pinout_specification.PNG) 

Both Mikrobus boards are connected to the ESP 32 by SPI:


	MiKroBus 1: SPI_0			MiKroBus 2 :SPI_1
	CLK     IO18				CLK	IO14
	MISO	IO19				MISO	IO12
	MOSI  	IO23				MOSI  	IO13
	NSS     IO5				NSS     IO15
	


Mikrobus 1 is also connected to the ESP32 by a RESET (IO27) and a BUSY(IO27) line.

Connector grove available on board :


	I2C:					UART serial link (Rx/Tx):
	SDA   IO21				CLK	IO14
	SCL   IO22				MISO	IO12



Two UFL connected to a SMA mount edge connector are available to plug an antenna. They’re disconnected from the rest of the board, which allows to connect the module that you want to the antenna, with a UFL -UFL connector.


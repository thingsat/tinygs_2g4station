# Board_Tinysgs_2.4GHz_V1

This board is the firts version of the 2.4GHz gateway
Contain Schematic and PCB file for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C).

This Board is designed to support a ESP32 devkitC-V4 and 2 MiKroBus modules. This board is the firts version of the 2.4GHz tinygs ground station gateway and named Board_V1

The purpose of this board is to control mikrobus modules including SX1280 technology that will transmit and receive messages on a 2.4GHz radio frequency. Each module are connected to a ESP32 which will be connected to the wifi.

Mikrobus board is an add-on board socket standard made by [mikroe](https://www.mikroe.com/mikrobus)

Both Mikrobus boards are connected to the ESP 32 by SPI:


	MiKroBus 1: SPI_0			MiKroBus 2 : SPI_1
	CLK     IO18				CLK	IO14
	MISO	IO19				MISO	IO12
	MOSI  	IO23				MOSI  	IO13
	NSS     IO5				NSS     IO15
	


Mikrobus 1 is also connected to the ESP32 by a RESET (IO27) and a BUSY(IO25) line.

Connector grove available on board :


	I2C:					UART serial link (Rx/Tx):
	SDA   IO21				CLK	IO14
	SCL   IO22				MISO	IO12



Two UFL connected to a SMA mount edge connector are available to plug an antenna. They’re disconnected from the rest of the board, which allows to connect the module that you want to the antenna, with a SMA -UFL connector.



#### Library and footprint

Lib & empreinte folder contains all necessary symbol and footprint for the project:
* ESP32 symbol and footprint. Footprint has been changed to match with our ESP32-devkitC-V4
* Mikrobus (mikroe-2439) symbol and footprint
* Grove connector for I2C and RxTx connection
* SMA and UFL connector



#### Files
* .pro: File containing the parameters of the project.
* .sch: Schema files.
* .kicad_pcb: Printed circuit board files.
* sym-info-cache: Library list file (symbol library table): declaration of component symbol libraries available for the schema editor.
* fp-lib-table: Library list file (footprint library table): declaration of component footprint libraries available for the PCB editor.


### Rendered

![Schematic](https://github.com/thingsat/tinygs_2g4station/blob/main/Board_Tinysgs_2.4GHz_V1/Picture/Schematic_board_V1.PNG) 
![Printing_feedback_top](https://github.com/thingsat/tinygs_2g4station/blob/main/Board_Tinysgs_2.4GHz_V1/Picture/Printing_feedback_top.PNG) 
![Printing_feedback_bellow](https://github.com/thingsat/tinygs_2g4station/blob/main/Board_Tinysgs_2.4GHz_V1/Picture/Printing_feedback_bellow.PNG) 

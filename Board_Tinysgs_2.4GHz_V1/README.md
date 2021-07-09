# Board_Tinysgs_2.4GHz

This board is the firts version of the 2.4GHz gateway
Contain Schematic and PCB file for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C).

This Board is designed to support a ESP32 devkitC-V4 and 2 MiKroBus modules. This board is the firts version of the 2.4GHz tinygs ground station gateway and named Board_V1

The purpose of this board is to control mikrobus modules including SX1280 technology that will transmit and receive messages on a 2.4GHz radio frequency. Each module are connected to a ESP32 which will be connected to the wifi.

Mikrobus board is an add-on board socket standard made by [mikroe](https://www.mikroe.com/mikrobus)

Both Mikrobus boards are connected to ESP 32 by SPI, UART Rx/Tx and by a Reset + Busy line :


	MiKroBus 1: 				MiKroBus 2 : 
	
	SPI_0					SPI_1
	CLK 	IO18				CLK	IO14
	MISO	IO19				MISO	IO12
	MOSI	IO23				MOSI	IO13
	NSS 	IO5				NSS	IO15
	
	UART_0					UART_2
	Tx	IO23				Tx	IO30
	Rx	IO24				Rx	IO31
	
	RESET_0 IO27				RESET_1	IO34
	BUSY_0	IO25				BUSY_1	IO35



Connector grove available on board :


	I2C:			UART_2(Rx/Tx):		GPIO:
	SDA   IO21		Tx	IO30		IO32
	SCL   IO22		Rx	IO31		IO33


UART_2 can be connected to module MiKroBus 2 or to grove connector. A jumper need to be plug to choose beetween grove output or the mikrobus module.


Two UFL connected to a SMA mount edge connector are available to plug an antenna. They are disconnected from the rest of the board, which allows to connect the module that you want to the antenna, with a SMA -UFL connector.

A powerbank can be plug under the board to supply the 3V. The [powerbank](https://www.amazon.com/Diymore-Lithium-Battery-Charging-Arduino/dp/B07SZKNST4) is design for ESP32 and is purchasable on amazon. 



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

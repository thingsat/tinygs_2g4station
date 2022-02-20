# Main Board for TinyGS 2.4GHz Station

This board is the firts version of the 2.4GHz gateway for [TinyGS](https://tinygs.com/).

Contain Schematic and PCB file for ESP32 Vroom + 2 Mikrobus modules + 2 groves connectors (RXTX,I2C).

This Board is designed to support a ESP32 devkitC-V4 and 2 MiKroBus modules. This board is the firts version of the 2.4GHz tinygs ground station gateway and named Board_V1

The purpose of this board is to control mikrobus modules including SX1280 technology that will transmit and receive messages on a 2.4GHz radio frequency. Each module are connected to a ESP32 which will be connected to the wifi.

Mikrobus board is an add-on board socket standard made by [mikroe](https://www.mikroe.com/mikrobus)

Connection between ESP32 - ESP32-DevKitC V4 and Mikrobus modules

MiKroBus 0:
	 				 
	SPI_0:
	CLK 	IO18
	MISO	IO19
	MOSI	IO23
	NSS(CS)	IO05
	
	UART_0	:
	Tx	IO01
	Rx	IO03
	
	I2C:
	SDA	IO21
	SCL	IO22
	
	AN_0	IO33
	RESET_0 IO32
	PWM_0	IO25
	INT_0	IO26



MiKroBus 1: 				 
	
	SPI_0
	CLK 	IO18
	MISO	IO19
	MOSI	IO23
	NSS 	IO15
	
	UART_2
	Tx	IO17
	Rx	IO16
	
	I2C:
	SDA	IO21
	SCL	IO22
	
	AN_1	IO27
	RESET_1 IO14
	PWM_1	IO04
	INT_1	IO13



Grove connector available on board :


	I2C:			UART_2(Rx/Tx):		GPIO(INPUT Only):
	SDA   IO21		Tx	IO17		IO34
	SCL   IO22		Rx	IO16		IO35


UART_2 can be connected to module MiKroBus 2 or to grove connector. A jumper need to be plug to choose beetween grove output or the mikrobus module.



Two UFL connected to a SMA mount edge connector are available to plug an antenna. They are disconnected from the rest of the board, which allows to connect the module that you want to the antenna, with a SMA -UFL connector.

A powerbank can be plug under the board to supply the 3V. The [powerbank](https://www.amazon.com/Diymore-Lithium-Battery-Charging-Arduino/dp/B07SZKNST4) is design for ESP32 and is purchasable on amazon. 
5V is only available on the Mikrobus 1 module. 


Careful:
* UART0 is used for flashing and debuging. Be very careful to its use.
* GPIO grove connector are INPUT only, ESP32wroom cannot write on this connection.
* Both Chip selec (NSS) for the SPI communication are Pulled HIGH (IO05 & IO15).
* No 5V on Mikrobus 0. 

## Library and footprint

Lib & empreinte folder contains all necessary symbol and footprint for the project:
* ESP32 symbol and footprint. Footprint has been changed to match with our ESP32-devkitC-V4
* Mikrobus (mikroe-2439) symbol and footprint
* Grove connector for I2C and RxTx connection
* SMA and UFL connector



## Files
* .pro: File containing the parameters of the project.
* .sch: Schema files.
* .kicad_pcb: Printed circuit board files.
* sym-info-cache: Library list file (symbol library table): declaration of component symbol libraries available for the schema editor.
* fp-lib-table: Library list file (footprint library table): declaration of component footprint libraries available for the PCB editor.

## Rendered

![Printing_feedback_top](https://github.com/thingsat/tinygs_2g4station/blob/main/Board_Tinysgs_2.4GHz_V1/Picture/Printing_feedback_top.PNG) 
![Printing_feedback_bellow](https://github.com/thingsat/tinygs_2g4station/blob/main/Board_Tinysgs_2.4GHz_V1/Picture/Printing_feedback_bottom.PNG) 

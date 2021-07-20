# Ebyte_E28

This is a board to support a Ebyte E28 2.4GHz transceiver module, adapted to Mikrobus standard pinout specification. This board will allow you to use your Ebyte E28 module with a standard 0.1” matrix breadboard or a Mikrobus Standard.

This board can support E28_2G4M12S and E28_2G4M20S. This Ebyte E28 Board is inspired by the [Breadboard Friendly Ebyte E28 Board](https://github.com/StuartsProjects/Devices/tree/master/Breadboard%20Friendly%20EbyteE28%20Board) made by StuartsProjects.

Ebyte E28 module usable: [Ebyte E28-2G4M12S](https://www.amazon.fr/Ebyte-%C3%89metteur-r%C3%A9cepteur-Bluetooth-E28-2G4M12S-%C3%A9metteur/dp/B07P2BZW5C) / [Ebyte E28-2G4M20S](https://www.amazon.fr/EBYTE-E28-2G4M20S-SX1280-%C3%89metteur-R%C3%A9cepteur/dp/B07R77CKFK). They are the same module, exept that the E28-2G4M20S as 2 more Pins which are Rx/Tx connection for PA and LNA control.


Here the connection between the Mikrobus standard pin and the E28 module pin

	AN	<->	Busy
	RST	<->	NRESET
	CS	<->	NSS_CTS
	SCK	<->	SCK_RTS
	MISO	<->	MISO_TX
	MOSI	<->	MOSI_RX
	PWM	<->	DIO2
	INT	<->	DIO1
	
	for M20S
	Rx	<->	TX_EN
	Tx	<->	RX_EN

Ebyte E28 is supplied with 3.3V, by the +3.3V Mikrobus pin.

The Ebyte E28 module has a PCB antenna, so no external antenna is needed, but the here also a SMA connector to use a external antenna.

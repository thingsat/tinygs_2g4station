# TinyGPS++ :: Full Example

The purpose of this example is the test of the communication of the ESP32 Wroom with a GPS module using the NMEA 0183 protocol.

This example requires the importation of two libraries into the Arduino IDE
* https://codeload.github.com/plerup/espsoftwareserial/zip/refs/heads/main
* https://codeload.github.com/mikalhart/TinyGPSPlus/zip/refs/heads/master

The example has been tested with the [Grove-GPS](https://wiki.seeedstudio.com/Grove-GPS/) plugged into the UART Grove connector of the TinyGS 2G4 station.

This module is connected to the UART2 with the following wiring:

	Wellow 	<->	pin 16	(Rx ESP / Tx Module)
	White 	<->	pin 17  (Tx ESP / Rx Module)
	Red 	<->	3.3V
	Black	<->	GRD

The default baudrate for [Grove-GPS](https://wiki.seeedstudio.com/Grove-GPS/) is 4800. Check baudrates for [other GNSS modules](https://github.com/CampusIoT/orbimote/blob/master/gnss_modules.md).

![Grove GPS](Grove_GPS.jpg) 


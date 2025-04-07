# TinyGPS++ :: Full Example

The purpose of this example is the test of the communication of the ESP32 Wroom with a GPS module using the NMEA 0183 protocol.

This example requires the importation of two libraries into the Arduino IDE
* https://codeload.github.com/plerup/espsoftwareserial/zip/refs/heads/main
* https://codeload.github.com/mikalhart/TinyGPSPlus/zip/refs/heads/master

## Wiring

Warning: The default baudrate for [Grove-GPS](https://wiki.seeedstudio.com/Grove-GPS/) SIM28 is 9600. Check baudrates for [other common GNSS modules](https://github.com/CampusIoT/orbimote/blob/master/gnss_modules.md).

### Wiring for Grove GPS
The example has been tested with the [Grove-GPS](https://wiki.seeedstudio.com/Grove-GPS/) plugged into the UART Grove connector of the TinyGS 2G4 station.

This module is connected to the UART2 with the following wiring:

	White	<->	pin 16	(Rx ESP / Tx Module)
	Yellow 	<->	pin 17  (Tx ESP / Rx Module)
	Red 	<->	3.3V
	Black	<->	GND


### Wiring for XA1110 Mikrobus on Mikrobus 1

The example has been tested with the [SparkFun GPS Breakout - XA1110](https://learn.sparkfun.com/tutorials/sparkfun-gps-breakout---xa1110-qwiic-hookup-guide) plugged into the Mikrobus 1 slot of the TinyGS 2G4 station.

This module is connected to the UART2 with the following wiring:

## Build

Set the baudrate of the module

```c
...
static const uint32_t GPSBaud = 9600;
...
```

> For debugging baudrate, you can display the raw NMEA sentences by setting `DISPLAY_NMEA0183_SENTENCES` to `1` into the sketch.

```c
...
#define DISPLAY_NMEA0183_SENTENCES    1
...
```

## Flash and Run

Configure the board `ESP32 Dev Module` and the port in `Tools`.

Compile the sketch `Sketch > Verify/Compile`

Upload the sketch `Sketch > Upload` on the board

Open the serial monitor `Tools > Serial monitor`

```
FullExample.ino
An extensive example of many interesting TinyGPS++ features
Testing TinyGPS++ library v. 1.0.2
by Mikal Hart

Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum
           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ----  to CSUG   ----  RX    RX        Fail
----------------------------------------------------------------------------------------------------------------------------------------
**** ***** ********** *********** **** ********** ******** **** ****** ****** ***** ***   ******** ****** ***   0     0         0        
0    0.0   ********** *********** **** 01/06/2080 00:30:22 394  ****** ****** ***** ***   ******** ****** ***   236   0         0        
...
0    0.0   ********** *********** **** 01/06/2080 00:30:28 400  ****** ****** ***** ***   ******** ****** ***   1688  0         0        
0    0.0   ********** *********** **** 01/06/2080 00:30:29 401  ****** ****** ***** ***   ******** ****** ***   1924  0         0        
0    0.0   ********** *********** **** 01/06/2080 00:30:30 402  ****** ****** ***** ***   ******** ****** ***   2160  0         0        
```


![Grove GPS on the TinyGS 2G4 station](Grove_GPS.jpg) 

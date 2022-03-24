# TinyGS ESP32 and MicroPython

## Installation

Download and flash the latest firmware of micropython for ESP32 boards
* http://micropython.org/download/
* https://micropython.org/download/esp32


```bash
ESPTOOL=~/tools/esptools/esptool.py
PORT=/dev/tty.usbserial-0001
FIRMWARE=~/Downloads/esp32-20220117-v1.18.bin
$ESPTOOL --chip esp32 --port $PORT erase_flash
```

```
esptool.py v2.4.0
Connecting........_____....._____..
Chip is ESP32D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse
MAC: 58:bf:25:92:c7:3c
Uploading stub...
Running stub...
Stub running...
Erasing flash (this may take a while)...
Chip erase completed successfully in 13.2s
Hard resetting via RTS pin...
```

```bash
$ESPTOOL --chip esp32 --port $PORT --baud 460800 write_flash -z 0x1000 $FIRMWARE
```

```
esptool.py v2.4.0
Connecting.....
Chip is ESP32D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse
MAC: 58:bf:25:92:c7:3c
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 460800
Changed.
Configuring flash size...
Auto-detected Flash size: 4MB
Compressed 1555136 bytes to 1022998...
Wrote 1555136 bytes (1022998 compressed) at 0x00001000 in 24.9 seconds (effective 500.2 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
```

## Basic tests

```bash
minicom -D $PORT
```

```
MicroPython v1.18 on 2022-01-17; ESP32 module with ESP32
Type "help()" for more information.
>>> help()
Welcome to MicroPython on the ESP32!

For generic online docs please visit http://docs.micropython.org/

For access to the hardware use the 'machine' module:

import machine
pin12 = machine.Pin(12, machine.Pin.OUT)
pin12.value(1)                                                                 
pin13 = machine.Pin(13, machine.Pin.IN, machine.Pin.PULL_UP)                   
print(pin13.value())                                                           
i2c = machine.I2C(scl=machine.Pin(21), sda=machine.Pin(22))                    
i2c.scan()                                                                     
i2c.writeto(addr, b'1234')                                                     
i2c.readfrom(addr, 4)                                                          
                                                                                
Basic WiFi configuration:                                                      
                                                                                
import network                                                                 
sta_if = network.WLAN(network.STA_IF); sta_if.active(True)                     
sta_if.scan()                             # Scan for available access points    
sta_if.connect("<AP_name>", "<password>") # Connect to an AP                   
sta_if.isconnected()                      # Check for successful connection     
                                                                                
Control commands:                                                              
  CTRL-A        -- on a blank line, enter raw REPL mode                        
  CTRL-B        -- on a blank line, enter normal REPL mode                     
  CTRL-C        -- interrupt a running program                                 
  CTRL-D        -- on a blank line, do a soft reset of the board               
  CTRL-E        -- on a blank line, enter paste mode                           
                                                                                
For further help on a specific object, type help(obj)                          
For a list of available modules, type help('modules')                          
>>> help('modules')                                                            
__main__          gc                ubinascii         upysh                    
_boot             inisetup          ubluetooth        urandom                  
_onewire          machine           ucollections      ure                      
_thread           math              ucryptolib        urequests                
_uasyncio         micropython       uctypes           uselect                  
_webrepl          neopixel          uerrno            usocket                  
apa106            network           uhashlib          ussl                     
btree             ntptime           uheapq            ustruct                  
builtins          onewire           uio               usys                     
cmath             uarray            ujson             utime                    
dht               uasyncio/__init__ umqtt/robust      utimeq                   
ds18x20           uasyncio/core     umqtt/simple      uwebsocket               
esp               uasyncio/event    uos               uzlib                    
esp32             uasyncio/funcs    upip              webrepl                  
flashbdev         uasyncio/lock     upip_utarfile     webrepl_setup            
framebuf          uasyncio/stream   uplatform         websocket_helper         
Plus any modules on the filesystem                                             
>>> 
```

## Blink LED


## Scan Wifi networks

```python
import network
station = network.WLAN(network.STA_IF)
station.active(True)
n = station.scan()
print('Wifi networks around:')
for i in n:
  print(i[0], i[2], i[3], 'dBm')
```

## Connect to a Wifi network

## NTP Time and RTC

## HTTP GET

## MQTT subscriber and publisher

## GPIO

Add a LED on pin 15

```python
import time
from machine import Pin
led=Pin(15,Pin.OUT)
 
while True:
  led.value(1)
  time.sleep(0.5)
  led.value(0)
  time.sleep(0.5)

```
## GPS

## LoRa SX1280



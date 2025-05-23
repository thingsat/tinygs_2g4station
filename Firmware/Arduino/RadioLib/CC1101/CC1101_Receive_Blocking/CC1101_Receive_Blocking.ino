/*
  RadioLib CC1101 Blocking Receive Example

  This example receives packets using CC1101 FSK radio module.
  To successfully receive data, the following settings have to be the same
  on both transmitter and receiver:
  - carrier frequency
  - bit rate
  - frequency deviation
  - sync word

  Using blocking receive is not recommended, as it will lead
  to significant amount of timeouts, inefficient use of processor
  time and can some miss packets!
  Instead, interrupt receive is recommended.

  For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#cc1101

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/

// include the library
#include <RadioLib.h>

// CC1101 has the following connections on ESP32 Dev Module
// CS pin:    5
// GDO0 pin:  2
// RST pin:   unused
// GDO2 pin:  3 (optional)

#include "SettingsModule.h"

// Work with Mikrobus 1 only (receive fails on Mikrobus 0)
#define CC1101_MIKROBUS_1   1

#if CC1101_MIKROBUS_0 == 1
// Microbus 0
#define CC1101_CS_PIN           NSS_0
#define CC1101_GDO0_PIN         AN_0
#define CC1101_GDO2_PIN         PWM_0
#define CC1101_RST_PIN          RADIOLIB_NC

#elif CC1101_MIKROBUS_1 == 1
// Microbus 1
#define CC1101_CS_PIN           NSS_1
#define CC1101_GDO0_PIN         AN_1
#define CC1101_GDO2_PIN         PWM_1
#define CC1101_RST_PIN          RADIOLIB_NC

#else

#error Set pinout for CC1101 module

#endif

CC1101 radio = new Module(CC1101_CS_PIN, CC1101_GDO0_PIN, CC1101_RST_PIN, CC1101_GDO2_PIN);

// or detect the pinout automatically using RadioBoards
// https://github.com/radiolib-org/RadioBoards
/*
#define RADIO_BOARD_AUTO
#include <RadioBoards.h>
Radio radio = new RadioModule();
*/

void setup() {
  Serial.begin(9600);

  // initialize CC1101 with default settings
  Serial.print(F("[CC1101] Initializing ... "));
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) { delay(10); }
  }
}

void loop() {
  Serial.print(F("[CC1101] Waiting for incoming transmission ... "));

  // you can receive data as an Arduino String
  String str;
  int state = radio.receive(str);

  // you can also receive data as byte array
  /*
    byte byteArr[8];
    int state = radio.receive(byteArr, 8);
  */

  if (state == RADIOLIB_ERR_NONE) {
    // packet was successfully received
    Serial.println(F("success!"));

    // print the data of the packet
    Serial.print(F("[CC1101] Data:\t\t"));
    Serial.println(str);

    // print RSSI (Received Signal Strength Indicator)
    // of the last received packet
    Serial.print(F("[CC1101] RSSI:\t\t"));
    Serial.print(radio.getRSSI());
    Serial.println(F(" dBm"));

    // print LQI (Link Quality Indicator)
    // of the last received packet, lower is better
    Serial.print(F("[CC1101] LQI:\t\t"));
    Serial.println(radio.getLQI());

  } else if (state == RADIOLIB_ERR_RX_TIMEOUT) {
    // timeout occurred while waiting for a packet
    Serial.println(F("timeout!"));

  } else if (state == RADIOLIB_ERR_CRC_MISMATCH) {
    // packet was received, but is malformed
    Serial.println(F("CRC error!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }
}

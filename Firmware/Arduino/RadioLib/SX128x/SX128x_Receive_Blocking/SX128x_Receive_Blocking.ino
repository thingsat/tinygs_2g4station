/*
  RadioLib SX128x Blocking Receive Example

  This example listens for LoRa transmissions using SX126x Lora modules.
  To successfully receive data, the following settings have to be the same
  on both transmitter and receiver:
  - carrier frequency
  - bandwidth
  - spreading factor
  - coding rate
  - sync word
  - preamble length

  Other modules from SX128x family can also be used.

  Using blocking receive is not recommended, as it will lead
  to significant amount of timeouts, inefficient use of processor
  time and can some miss packets!
  Instead, interrupt receive is recommended.

   For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#sx128x---lora-modem

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/

#include "RLDebug.h"

// include the library
#include <RadioLib.h>

#define MIKROBUS0_LAMBDA80
#include "Settings.h"

SX1280 radio = new Module(NSS, DIO1, NRESET, RFBUSY);

// or detect the pinout automatically using RadioBoards
// https://github.com/radiolib-org/RadioBoards
/*
#define RADIO_BOARD_AUTO
#include <RadioBoards.h>
Radio radio = new RadioModule();
*/

static uint64_t chipid;
static char ssid[14];

static void _showInfo(void) {
  chipid = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes)
  snprintf(ssid, 14, "%llX", chipid);
  Serial.println(ssid);

  //Serial.println(RADIOLIB_PLATFORM);
  Serial.println(RADIOLIB_INFO);

  Serial.print(F("[RadioLib > SX1280] Reveive Blocking "));
}

static void _initRadio(void){
  // initialize SX1280 with default settings
  Serial.print(F("[SX1280] Initializing ... "));

  // Use default modulation parameters

  int state =  radio.begin(Frequency, Bandwidth, SpreadingFactor, CodeRate, SyncWord, TxPower, PreambleLenInSymb);

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) { delay(10); }
  }

  // some modules have an external RF switch
  // controlled via two pins (RX enable, TX enable)
  // to enable automatic control of the switch,
  // call the following method
  // RX enable:   4
  // TX enable:   5
  /*
    radio.setRfSwitchPins(4, 5);
  */
}

void setup() {
  Serial.begin(9600); // 9600 is compliant with Openlog breakout

  _showInfo();

  _initRadio();
}

void loop() {
  Serial.print(F("[SX1280] Waiting for incoming transmission ... "));

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
    Serial.print(F("[SX1280] Receiver:\t"));
    Serial.println(ssid);

    // print the data of the packet
    Serial.print(F("[SX1280] Data:\t\t"));
    Serial.println(str);

    // print the RSSI (Received Signal Strength Indicator)
    // of the last received packet
    Serial.print(F("[SX1280] RSSI:\t\t"));
    Serial.print(radio.getRSSI());
    Serial.println(F(" dBm"));

    // print the SNR (Signal-to-Noise Ratio)
    // of the last received packet
    Serial.print(F("[SX1280] SNR:\t\t"));
    Serial.print(radio.getSNR());
    Serial.println(F(" dB"));

    // print the Frequency Error
    // of the last received packet
    Serial.print(F("[SX1280] Frequency Error:\t"));
    Serial.print(radio.getFrequencyError());
    Serial.println(F(" Hz"));

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

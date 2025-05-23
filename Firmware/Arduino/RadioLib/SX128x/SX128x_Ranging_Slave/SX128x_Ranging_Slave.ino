/*
  RadioLib SX128x Ranging Example

  This example performs ranging exchange between two
  SX1280 LoRa radio modules. Ranging allows to measure
  distance between the modules using time-of-flight
  measurement.

  Only SX1280 and SX1282 without external RF switch support ranging!

  Note that to get accurate ranging results, calibration is needed!
  The process is described in Semtech SX1280 Application Note AN1200.29

  For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#sx128x---lora-modem

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/

/*
 * Debug output enable.
 * Warning: Debug output will slow down the whole system significantly.
 *          Also, it will result in larger compiled binary.
 * Levels: basic - only main info
 *         protocol - mainly LoRaWAN stuff, but other protocols as well
 *         SPI - full transcript of all SPI communication
 */
#define RADIOLIB_DEBUG_BASIC          (1)
#define RADIOLIB_DEBUG_PROTOCOL       (1)
#define RADIOLIB_DEBUG_SPI            (1)
#define RADIOLIB_VERBOSE_ASSERT       (1)
// #define RADIOLIB_DEBUG_PORT           Serial // Serial /stdout

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

void setup() {
  Serial.begin(9600);

  chipid = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes).
  snprintf(ssid, 14, "%llX", chipid);
  Serial.println(ssid);

  Serial.print(F("[RadioLib > SX1280] Ranging "));

  // initialize SX1280 with default settings
  Serial.print(F("[SX1280] Initializing ... "));

  // Use default modulation parameters 
  int state =  radio.begin(Frequency, Bandwidth, 5, CodeRate, SyncWord, TxPower, PreambleLenInSymb);

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) { delay(10); }
  }
}

void loop() {
  Serial.print(F("[SX1280] Ranging ... "));

  // start ranging exchange
  // range as master:             true
  // slave address:               0x12345678
  //int state = radio.range(true, 0x12345678);

  // the other module must be configured as slave with the same address
    int state = radio.range(false, 0x12345678);
  
  // if ranging calibration is known, it can be provided
  // this should improve the accuracy and precision
  /*
    uint16_t calibration[3][6] = {
      { 10299, 10271, 10244, 10242, 10230, 10246 },
      { 11486, 11474, 11453, 11426, 11417, 11401 },
      { 13308, 13493, 13528, 13515, 13430, 13376 }
    };

    int state = radio.range(true, 0x12345678, calibration);
  */

  if (state == RADIOLIB_ERR_NONE) {
    // ranging finished successfully
    Serial.println(F("success!"));
    Serial.print(F("[SX1280] Distance:\t\t\t"));
    Serial.print(radio.getRangingResult());
    Serial.println(F(" meters (raw)"));

  } else if (state == RADIOLIB_ERR_RANGING_TIMEOUT) {
    // timed out waiting for ranging packet
    Serial.println(F("timed out!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }

  // wait for a second before ranging again
  delay(1000);
}

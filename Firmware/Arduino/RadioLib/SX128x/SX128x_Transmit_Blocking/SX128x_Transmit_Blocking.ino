/*
  RadioLib SX128x Blocking Transmit Example

  This example transmits packets using SX1280 LoRa radio module.
  Each packet contains up to 256 bytes of data, in the form of:
  - Arduino String
  - null-terminated char array (C-string)
  - arbitrary binary data (byte array)

  Other modules from SX128x family can also be used.

  Using blocking transmit is not recommended, as it will lead
  to inefficient use of processor time!
  Instead, interrupt transmit is recommended.

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

  Serial.print(F("[RadioLib > SX1280] Transmit Blocking "));

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

/**
 * TODO: config RSSI level and timeout into ChannelScanConfig_t parameter
 */
static bool _scanChannel(void) {

  bool free = false;

  Serial.print(F("[SX1280] Scan Channel (limit: -90.0 dBm): ... "));

  ChannelScanConfig_t cfg = {
    .cad = {
      .symNum = RADIOLIB_SX128X_CAD_PARAM_DEFAULT,
      .detPeak = 0,
      .detMin = 0,
      .exitMode = 0,
      .timeout = 500, // milliseconds
      .irqFlags = RADIOLIB_IRQ_CAD_DEFAULT_FLAGS,
      .irqMask = RADIOLIB_IRQ_CAD_DEFAULT_MASK,
    },
/*    .rssi = {
      .limit = -90.0,
    },
*/
  };

  cfg.rssi.limit = -90.0;

  int16_t res = radio.scanChannel(cfg);

  if (res == RADIOLIB_ERR_UNKNOWN) {
    // the packet was successfully transmitted
    Serial.println(F("Unknown !"));

  } else if (res == RADIOLIB_LORA_DETECTED) {
    // the supplied packet was longer than 256 bytes
    Serial.println(F("LoRa detected !"));

  } else if (res == RADIOLIB_CHANNEL_FREE) {
    // the supplied packet was longer than 256 bytes
    Serial.println(F("Channel free !"));
    free = true;

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(res);
  }
  return free;
}

// counter to keep track of transmitted packets
static int count = 0;

static void _transmit(void) {

  Serial.print(F("[SX1280] Transmitting packet "));
 
  // you can transmit C-string or Arduino string up to
  // 256 characters long
  String str = String(ssid) + "> Hello World! #" + String(count++);

  // TODO change outputPower from 10 to 0 with int16_t SX128x::setOutputPower(int8_t pwr)

  int state = radio.transmit(str);

  // show timeOnAir (RadioLibTime_t SX128x::getTimeOnAir(size_t len))

  // you can also transmit byte array up to 256 bytes long
  /*
    byte byteArr[] = {0x01, 0x23, 0x45, 0x56, 0x78, 0xAB, 0xCD, 0xEF};
    int state = radio.transmit(byteArr, 8);
  */

  if (state == RADIOLIB_ERR_NONE) {
    // the packet was successfully transmitted
    Serial.println(F("success!"));

  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 256 bytes
    Serial.println(F("too long!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }
}

void loop() {

  (void)_scanChannel(); // if true, channel is free

  _transmit();

  // wait for a second before transmitting again
  delay(1000);
}

/*
  RadioLib CC1101 Blocking Transmit Example

  This example transmits packets using CC1101 FSK radio module.
  Each packet contains up to 64 bytes of data, in the form of:
  - Arduino String
  - null-terminated char array (C-string)
  - arbitrary binary data (byte array)

  Using blocking transmit is not recommended, as it will lead
  to inefficient use of processor time!
  Instead, interrupt transmit is recommended.

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

// Work with Mikrobus 1 only (transmit fails on Mikrobus 0)
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

static uint64_t chipid;
static char ssid[14];


//Find the default SPI pins for your board
//Make sure you have the right board selected in Tools > Boards
static void _show_default_SPI_pins(void) {
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);  
}


static void _showInfo(void) {
  chipid = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes)
  snprintf(ssid, 14, "%llX", chipid);
  Serial.println(ssid);

  //Serial.println(RADIOLIB_PLATFORM);
  Serial.println(RADIOLIB_INFO);

  Serial.print(F("[RadioLib > CC1101] Transmit Blocking "));

}

static void _initRadio(void){

    // initialize CC1101 with default settings
  Serial.print(F("[CC1101] Initializing ... "));

    /*!
      \brief Initialization method.
      \param freq Carrier frequency in MHz. Defaults to 434 MHz.
      \param br Bit rate to be used in kbps. Defaults to 4.8 kbps.
      \param freqDev Frequency deviation from carrier frequency in kHz Defaults to 5.0 kHz.
      \param rxBw Receiver bandwidth in kHz. Defaults to 135.0 kHz.
      \param pwr Output power in dBm. Defaults to 10 dBm.
      \param preambleLength Preamble Length in bits. Defaults to 16 bits.
      \returns \ref status_codes

// RadioLib defaults
#define RADIOLIB_CC1101_DEFAULT_FREQ                            434.0
#define RADIOLIB_CC1101_DEFAULT_BR                              4.8
#define RADIOLIB_CC1101_DEFAULT_FREQDEV                         5.0
#define RADIOLIB_CC1101_DEFAULT_RXBW                            58.0
#define RADIOLIB_CC1101_DEFAULT_POWER                           10
#define RADIOLIB_CC1101_DEFAULT_PREAMBLELEN                     16
#define RADIOLIB_CC1101_DEFAULT_SW                              {0x12, 0xAD}
#define RADIOLIB_CC1101_DEFAULT_SW_LEN                          2


    int16_t begin(
      float freq = RADIOLIB_CC1101_DEFAULT_FREQ,
      float br = RADIOLIB_CC1101_DEFAULT_BR,
      float freqDev = RADIOLIB_CC1101_DEFAULT_FREQDEV,
      float rxBw = RADIOLIB_CC1101_DEFAULT_RXBW,
      int8_t pwr = RADIOLIB_CC1101_DEFAULT_POWER,
      uint8_t preambleLength = RADIOLIB_CC1101_DEFAULT_PREAMBLELEN);
    */



  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) { delay(10); }
  }
}

void setup() {
  Serial.begin(9600);

  _show_default_SPI_pins();

  _showInfo();

  _initRadio();

}

// counter to keep track of transmitted packets
int count = 0;


static void _transmit(void) {

  Serial.print(F("[CC1101] Transmitting packet ... "));

  // you can transmit C-string or Arduino string up to 64 characters long
  String str = "Hello World! #" + String(count++);
  int state = radio.transmit(str);

  // you can also transmit byte array up to 64 bytes long
  /*
    byte byteArr[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    int state = radio.transmit(byteArr, 8);
  */

  if (state == RADIOLIB_ERR_NONE) {
    // the packet was successfully transmitted
    Serial.println(F("success!"));

  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 64 bytes
    Serial.println(F("too long!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);
  }

  // wait for a second before transmitting again
  delay(1000);
}

void loop() {
  _transmit();

  // wait for a second before transmitting again
  delay(1000);
}

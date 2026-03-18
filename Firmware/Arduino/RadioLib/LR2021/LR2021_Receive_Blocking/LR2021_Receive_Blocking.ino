/*
  RadioLib LR2021 Blocking Receive Example

  This example listens for LoRa transmissions using LR2021 Lora modules.
  To successfully receive data, the following settings have to be the same
  on both transmitter and receiver:
  - carrier frequency
  - bandwidth
  - spreading factor
  - coding rate
  - sync word
  - preamble length

  Using blocking receive is not recommended, as it will lead
  to significant amount of timeouts, inefficient use of processor
  time and can some miss packets!
  Instead, interrupt receive is recommended.

  For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#lr2021---lora-modem

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/



//These are the pin definitions for TinyGS 2G4 mikrobus modules
// https://github.com/thingsat/tinygs_2g4station/tree/main/Board_Tinysgs_2.4GHz_V1

#define SCK       18                                  //SCK on SPI3
#define MISO      19                                  //MISO on SPI3 
#define MOSI      23                                  //MOSI on SPI3 

#define NSS_0     5                                   //select pin on LoRa device
#define NSS_1     15                                   //select pin on LoRa device

#define AN_0      33
#define RESET_0   32
#define PWM_0     25
#define INT_0     26

#define AN_1      27
#define RESET_1   14
#define PWM_1     04
#define INT_1     13

// https://gricad-gitlab.univ-grenoble-alpes.fr/thingsat/seed/-/tree/main/mikrobus_nicerf_lr2021?ref_type=heads
#define NiceRF_LR2021_at_Slot0
// #define NiceRF_LR2021_at_Slot1

#if defined(NiceRF_LR2021_at_Slot0)
// Mikrobus NiceRF LR2021 @ Slot 0
//#define DIO8    AN_0 ; UNUSED
#define NSS     NSS_0
#define DIO9    PWM_0                     // IRQ
#define RFBUSY  INT_0                     // Busy line
#define NRESET  RESET_0                   // Reset pin on LoRa device

#elif defined(NiceRF_LR2021_at_Slot1)
// Mikrobus NiceRF LR2021 @ Slot 1
//#define DIO8    AN_1 ; UNUSED
#define NSS     NSS_1
#define DIO9    PWM_1                     // IRQ
#define RFBUSY  INT_1                     // Busy line
#define NRESET  RESET_1                   // Reset pin on LoRa device

#else

#error Define NiceRF_LR2021_at_Slot0 or NiceRF_LR2021_at_Slot1 !

#endif



// LR2021 has the following connections:
// NSS pin:   10
// IRQ pin:   2
// NRST pin:  3
// BUSY pin:  9
// include the library

#include <RadioLib.h>


LR2021 radio = new Module(NSS, DIO9, NRESET, RFBUSY);

// or detect the pinout automatically using RadioBoards
// https://github.com/radiolib-org/RadioBoards
/*
#define RADIO_BOARD_AUTO
#include <RadioBoards.h>
Radio radio = new RadioModule();
*/

void setup() {
  Serial.begin(115200);

  // LR2021 allows to use any DIO pin as the interrupt
  // as an example, we set DIO10 to be the IRQ
  // this has to be done prior to calling begin()!
  radio.irqDioNum = 10;

  // initialize LR2021 with default settings
  Serial.print(F("[LR2021] Initializing ... "));
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
  Serial.print(F("[LR2021] Waiting for incoming transmission ... "));

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
    Serial.print(F("[LR2021] Data:\t\t"));
    Serial.println(str);

    // print the RSSI (Received Signal Strength Indicator)
    // of the last received packet
    Serial.print(F("[LR2021] RSSI:\t\t"));
    Serial.print(radio.getRSSI());
    Serial.println(F(" dBm"));

    // print the SNR (Signal-to-Noise Ratio)
    // of the last received packet
    Serial.print(F("[LR2021] SNR:\t\t"));
    Serial.print(radio.getSNR());
    Serial.println(F(" dB"));

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

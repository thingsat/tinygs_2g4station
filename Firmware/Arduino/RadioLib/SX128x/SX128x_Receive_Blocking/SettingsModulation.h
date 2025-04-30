/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 02/03/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup LoRa Parameters Here ! ***************

// https://github.com/chirpstack/chirpstack/blob/master/chirpstack/configuration/region_ism2400.toml
#define CHIRPSTACK_ISM2400_CHANNEL_1       2403.000000
#define CHIRPSTACK_ISM2400_CHANNEL_2       2479.000000
#define CHIRPSTACK_ISM2400_CHANNEL_3       2425.000000
#define CHIRPSTACK_ISM2400_CHANNEL_RX2     2423.000000
#define CHIRPSTACK_ISM2400_BANDWITH        812.50
#define CHIRPSTACK_ISM2400_SF              12


#define MULTITECH_ISM2400_CHANNEL_1       2422.000000
#define MULTITECH_ISM2400_CHANNEL_2       2425.000000
#define MULTITECH_ISM2400_CHANNEL_3       2479.000000
#define MULTITECH_ISM2400_BANDWITH        812.50
#define MULTITECH_ISM2400_SF              12
#define MULTITECH_ISM2400_CR              0x08 //LORA_CR_LI_4_8
#define MULTITECH_ISM2400_SYNCWORD_PUBLIC (0x12)
#define MULTITECH_ISM2400_LEN_IN_SYMB     (8)


#define LORA_IQ_UPLINK              LORA_IQ_NORMAL
#define LORA_IQ_DOWNLINK            LORA_IQ_NORMAL


#if BALLOON == 1

//LoRa Modem Parameters
#define Frequency 2483.500000                    //frequency of transmissions
#define Offset    0                             //offset frequency for calibration purposes  
#define Bandwidth 812.50                  //LoRa bandwidth
#define SpreadingFactor 12               //LoRa spreading factor
#define CodeRate 5                 //LoRa coding rate
#define PreambleLenInSymb             (8)                           //Preamble length
/*
Sync_word = 0x21,
*/
#define TxPower               10                                        // dBm
#define SyncWord              0x21

#elif MULTITECH_ISM2400 == 1

//LoRa Modem Parameters
#define Frequency                 MULTITECH_ISM2400_CHANNEL_1   //frequency of transmissions
#define Offset 0                                                //offset frequency for calibration purposes  
#define Bandwidth                 MULTITECH_ISM2400_BANDWITH    //LoRa bandwidth
#define SpreadingFactor           MULTITECH_ISM2400_SF          //LoRa spreading factor
#define CodeRate                  MULTITECH_ISM2400_CR          //LoRa coding rate
#define PreambleLenInSymb         MULTITECH_ISM2400_LEN_IN_SYMB //Preamble length

#define TxPower                   10                                        // dBm
#define SyncWord                  RADIOLIB_SX128X_SYNC_WORD_PRIVATE


#else

// defines in     RadioLib/src/modules/SX128x/SX128x.h

#define Frequency             CHIRPSTACK_ISM2400_CHANNEL_1                //frequency of transmissions
#define Offset                0                                           //offset frequency for calibration purposes  
#define Bandwidth             CHIRPSTACK_ISM2400_BANDWITH                 //LoRa bandwidth
#define SpreadingFactor       CHIRPSTACK_ISM2400_SF                       //LoRa spreading factor
#define CodeRate              7             //LoRa coding rate
#define PreambleLenInSymb     (12)                                     //Preamble length
#define TxPower               10                                        // dBm
#define SyncWord              0x34

#endif

#ifndef PACKET_DELAY
#define PACKET_DELAY 1000                  // msec.
#endif

// TODO change in #define
const uint16_t packet_delay = PACKET_DELAY;           // mS delay between packets

#ifndef TXBUFFER_SIZE
#define TXBUFFER_SIZE 255                        // TX buffer size (LoRa frame maximum size is 255)
#endif

#ifndef RXBUFFER_SIZE
#define RXBUFFER_SIZE 255                        // RX buffer size (LoRa frame maximum size is 255)
#endif
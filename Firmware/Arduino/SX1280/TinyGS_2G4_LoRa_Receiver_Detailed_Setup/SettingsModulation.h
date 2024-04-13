/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 02/03/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup LoRa Parameters Here ! ***************

#define MULTITECH_ISM2400_CHANNEL_1       2422000000
#define MULTITECH_ISM2400_CHANNEL_2       2425000000
#define MULTITECH_ISM2400_CHANNEL_3       2479000000
#define MULTITECH_ISM2400_BANDWITH        LORA_BW_0800
#define MULTITECH_ISM2400_SF              LORA_SF12
#define MULTITECH_ISM2400_CR              LORA_CR_LI_4_8
#define MULTITECH_ISM2400_SYNCWORD_PUBLIC (0x12)
#define MULTITECH_ISM2400_LEN_IN_SYMB     (8)


#define LORA_IQ_UPLINK              LORA_IQ_NORMAL
#define LORA_IQ_DOWNLINK            LORA_IQ_NORMAL


#if BALLOON == 1

//LoRa Modem Parameters
#define Frequency 2483500000                    //frequency of transmissions
#define Offset    0                             //offset frequency for calibration purposes  
#define Bandwidth LORA_BW_0800                  //LoRa bandwidth
#define SpreadingFactor LORA_SF12               //LoRa spreading factor
#define CodeRate LORA_CR_LI_4_5                 //LoRa coding rate
#define LenInSymb (8)                           //Preamble length
/*
Sync_word = 0x21,
*/

#elif MULTITECH_ISM2400 == 1

//LoRa Modem Parameters
#define Frequency         MULTITECH_ISM2400_CHANNEL_1   //frequency of transmissions
#define Offset 0                                        //offset frequency for calibration purposes  
#define Bandwidth         MULTITECH_ISM2400_BANDWITH    //LoRa bandwidth
#define SpreadingFactor   MULTITECH_ISM2400_SF          //LoRa spreading factor
#define CodeRate          MULTITECH_ISM2400_CR          //LoRa coding rate
#define LenInSymb         MULTITECH_ISM2400_LEN_IN_SYMB //Preamble length

#endif

#ifndef TX_POWER
#define TX_POWER 10                        // dBm
#endif

#ifndef PACKET_DELAY
#define PACKET_DELAY 1000                  // msec.
#endif

// TODO change in #define
const int8_t TXpower = TX_POWER;                      // LoRa transmit power in dBm

// TODO change in #define
const uint16_t packet_delay = PACKET_DELAY;           // mS delay between packets

#ifndef TXBUFFER_SIZE
#define TXBUFFER_SIZE 255                        // TX buffer size (LoRa frame maximum size is 255)
#endif

#ifndef RXBUFFER_SIZE
#define RXBUFFER_SIZE 255                        // RX buffer size (LoRa frame maximum size is 255)
#endif
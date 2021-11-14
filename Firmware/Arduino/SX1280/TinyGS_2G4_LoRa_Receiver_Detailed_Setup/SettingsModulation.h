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

//LoRa Modem Parameters
#define Frequency 2422000000                    //frequency of transmissions
#define Offset 0                                //offset frequency for calibration purposes  
#define Bandwidth LORA_BW_0800                  //LoRa bandwidth
#define SpreadingFactor LORA_SF12               //LoRa spreading factor
#define CodeRate LORA_CR_LI_4_8                 //LoRa coding rate
#define LenInSymb (8)                           //Preamble length

const int8_t TXpower = 10;                      //LoRa transmit power in dBm

const uint16_t packet_delay = 1000;             //mS delay between packets

#define RXBUFFER_SIZE 32                        //RX buffer size  

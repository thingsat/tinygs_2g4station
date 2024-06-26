/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 02/03/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup LoRa Parameters Here ! ***************

#define LORA_IQ_UPLINK              LORA_IQ_NORMAL


//LoRa Modem Default Parameters
#define Frequency 2479000000                    //frequency of transmissions
#define Offset    0                             //offset frequency for calibration purposes  
#define Bandwidth LORA_BW_0800                  //LoRa bandwidth
#define SpreadingFactor LORA_SF12               //LoRa spreading factor
#define CodeRate LORA_CR_LI_4_5                 //LoRa coding rate
#define LenInSymb (8)                           //Preamble length

// Messages configurations
typedef struct _msg_config {
  uint32_t sf;
  uint32_t bandwidth;
  uint32_t time_on_air;
} msg_config_t;

#define NB_MSG                  5
static const msg_config_t MSG_CONFIG[NB_MSG] = {
  {LORA_SF11, LORA_BW_0200, 433},
  {LORA_SF10, LORA_BW_0200, 205},
  {LORA_SF12, LORA_BW_0800, 202},
  {LORA_SF8,  LORA_BW_0200, 62},
  {LORA_SF10, LORA_BW_0800, 51},
};


// Messages structure 
typedef struct {
  uint8_t  mhdr;
  uint32_t dev_addr;
  uint8_t  fctrl;
  uint16_t fcount;
  uint8_t  fport;

  uint32_t msg_id;
  uint16_t voltage;
  uint8_t  test_id;

  int16_t  temperature; // x100
  uint8_t  humidity;    // 0-100%

} __attribute__((packed)) test_message_t;


/*
#ifndef TX_POWER
#define TX_POWER 10                        // dBm
#endif

#ifndef PACKET_DELAY
#define PACKET_DELAY 1000                  // msec.
#endif

// TODO change in #define
const uint16_t packet_delay = PACKET_DELAY;           // mS delay between packets

*/

#ifndef TXBUFFER_SIZE
#define TXBUFFER_SIZE 255                        // TX buffer size (LoRa frame maximum size is 255)
#endif

#ifndef RXBUFFER_SIZE
#define RXBUFFER_SIZE 255                        // RX buffer size (LoRa frame maximum size is 255)
#endif

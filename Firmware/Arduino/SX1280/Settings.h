/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 02/03/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup hardware pin definitions here ! ***************

//These are the pin definitions for one of my own boards, a ESP32 shield base with BBF board shield on
//top. Be sure to change the definitions to match your own setup. Some pins such as DIO2, DIO3, BUZZER
//may not be in used by this sketch so they do not need to be connected and should be included and be 
//set to -1.

#define MIKROTIK_0
#define MIKROTIK_0_LAMBDA80C
//#define MIKROTIK_0_E28


// THe values are the GPIO ids of the ESP32-DevKit 38 pins
#define MIKROTIK_AN_0             33
#define MIKROTIK_RESET_0          32
#define MIKROTIK_NSS_0            5
#define MIKROTIK_SCK_0            18
#define MIKROTIK_MISO_0           19
#define MIKROTIK_MOSI_0           23
#define MIKROTIK_PWM_0            25
#define MIKROTIK_INT_0            26

#ifdef MIKROTIK_0

#ifdef MIKROTIK_0_E28


/*
Here the connection between the Mikrobus standard pin and the E28 module pin

AN  <-> Busy
RST <-> NRESET
CS  <-> NSS_CTS
SCK <-> SCK_RTS
MISO  <-> MISO_TX
MOSI  <-> MOSI_RX
PWM <-> DIO2
INT <-> DIO1
*/


#define NSS MIKROTIK_NSS_0                                   //select pin on LoRa device
#define SCK MIKROTIK_SCK_0                                  //SCK on SPI3
#define MISO MIKROTIK_MISO_0                                 //MISO on SPI3 
#define MOSI MIKROTIK_MOSI_0                                 //MOSI on SPI3 

#define NRESET MIKROTIK_RESET_0                               //reset pin on LoRa device
#define RFBUSY MIKROTIK_AN_0                               //busy line

#define LED1 2                                  //on board LED, high for on
#define DIO1 MIKROTIK_INT_0                                 //DIO1 pin on LoRa device, used for RX and TX done 
#define DIO2 MIKROTIK_PWM_0                                 //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO3 -1                                 //DIO3 pin on LoRa device, normally not used so set to -1
#define RX_EN -1                                //pin for RX enable, used on some SX128X devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX128X devices, set to -1 if not used 
#define BUZZER -1                               //pin for buzzer, set to -1 if not used 
#define VCCPOWER -1                             //pin controls power to external devices
#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using

#endif

#ifdef MIKROTIK_0_LAMBDA80C

/*
Here the connection between the Mikrobus standard pin and the Lambda80 module pin

AN  <-> DIO1
RST <-> RESET
CS  <-> NSEL
SCK <-> SCLK
MISO  <-> SDO
MOSI  <-> SDI
PWM <-> DIO2
INT <-> BUSY
 */



#define NSS MIKROTIK_NSS_0                                   //select pin on LoRa device
#define SCK MIKROTIK_SCK_0                                  //SCK on SPI3
#define MISO MIKROTIK_MISO_0                                 //MISO on SPI3 
#define MOSI MIKROTIK_MOSI_0                                 //MOSI on SPI3 

#define NRESET MIKROTIK_RESET_0                               //reset pin on LoRa device
#define RFBUSY MIKROTIK_INT_0                               //busy line

#define LED1 2                                  //on board LED, high for on
#define DIO1 MIKROTIK_AN_0                                 //DIO1 pin on LoRa device, used for RX and TX done 
#define DIO2 MIKROTIK_PWM_0                                 //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO3 -1                                 //DIO3 pin on LoRa device, normally not used so set to -1
#define RX_EN -1                                //pin for RX enable, used on some SX128X devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX128X devices, set to -1 if not used 
#define BUZZER -1                               //pin for buzzer, set to -1 if not used 
#define VCCPOWER -1                             //pin controls power to external devices
#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using

#endif

#else

#define NSS 5                                   //select pin on LoRa device
#define SCK 18                                  //SCK on SPI3
#define MISO 19                                 //MISO on SPI3 
#define MOSI 23                                 //MOSI on SPI3 

#define NRESET 27                               //reset pin on LoRa device
#define RFBUSY 25                               //busy line

#define LED1 2                                  //on board LED, high for on
#define DIO1 35                                 //DIO1 pin on LoRa device, used for RX and TX done 
#define DIO2 -1                                 //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO3 -1                                 //DIO3 pin on LoRa device, normally not used so set to -1
#define RX_EN -1                                //pin for RX enable, used on some SX128X devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX128X devices, set to -1 if not used 
#define BUZZER -1                               //pin for buzzer, set to -1 if not used 
#define VCCPOWER 14                             //pin controls power to external devices
#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using

#endif

//*******  Setup LoRa Parameters Here ! ***************

//LoRa Modem Parameters
const uint32_t Frequency = 2422000000;          //frequency of transmissions
const int32_t Offset = 0;                       //offset frequency for calibration purposes  
const uint8_t Bandwidth = LORA_BW_0800;         //LoRa bandwidth
const uint8_t SpreadingFactor = LORA_SF12;       //LoRa spreading factor
const uint8_t CodeRate = LORA_CR_4_5;           //LoRa coding rate

const int8_t TXpower = 10;                      //LoRa transmit power in dBm

const uint16_t packet_delay = 1000;             //mS delay between packets

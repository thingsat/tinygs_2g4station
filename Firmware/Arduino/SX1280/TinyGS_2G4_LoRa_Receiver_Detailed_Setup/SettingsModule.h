

//*******  Setup hardware pin definitions here ! ***************

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



#if defined(MIKROBUS0_E28) || defined(MIKROBUS0_NICERF)

/*
E28 module
AN  <-> Busy
INT <-> DIO1
PWM <-> DIO2
*/

#define NSS     NSS_0
#define DIO1    INT_0                               //DIO1 pin on LoRa device, used for RX and TX done 
#define RFBUSY  AN_0                                //busy line
#define NRESET  RESET_0                     //reset pin on LoRa device


#elif defined(MIKROBUS1_E28) || defined(MIKROBUS1_NICERF)

/* same mapping but on port 1*/

#define NSS     NSS_1
#define DIO1    INT_1
#define RFBUSY  AN_1
#define NRESET  RESET_1


/* ********************* */

#elif defined(MIKROBUS0_LAMBDA80)

/*
Lambda80C module
AN  <-> DIO1
INT <-> Busy
PWM <-> DIO2
*/

#define NSS     NSS_0
#define DIO1    AN_0                                //DIO1 pin on LoRa device, used for RX and TX done 
#define RFBUSY  INT_0                               //busy line
#define NRESET  RESET_0                     //reset pin on LoRa device


#elif defined(MIKROBUS1_LAMBDA80)

/* same mapping but on port 1*/

#define NSS     NSS_1
#define DIO1    AN_1
#define RFBUSY  INT_1
#define NRESET  RESET_1



#else

#error Unknown module

#endif


#define LED1 2                                  //on board LED, high for on

#define DIO2  -1                                //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO3 -1                                 //DIO3 pin on LoRa device, normally not used so set to -1
#define RX_EN -1                                //pin for RX enable, used on some SX128X devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX128X devices, set to -1 if not used 
#define BUZZER -1                               //pin for buzzer, set to -1 if not used 
#define VCCPOWER 14                             //pin controls power to external devices

#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using

/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 02/03/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

#ifndef MIKROBUS0_LAMBDA80
#define MIKROBUS0_LAMBDA80    1
#endif

//*******  Setup hardware pin definitions here ! ***************

//These are the pin definitions for TinyGS 2G4 mikrobus modules
// https://github.com/thingsat/tinygs_2g4station/tree/main/Board_Tinysgs_2.4GHz_V1

#define NSS       5                                   //select pin on LoRa device
#define SCK       18                                  //SCK on SPI3
#define MISO      19                                  //MISO on SPI3 
#define MOSI      23                                  //MOSI on SPI3 

#define AN_0      33
#define RESET_0   32
#define PWM_0     25
#define INT_0     26

#define AN_1      27
#define RESET_1   14
#define PWM_1     04
#define INT_1     13

#if defined(MIKROBUS0_E28)

/*
E28 module
AN  <-> Busy
INT <-> DIO1
PWM <-> DIO2
*/

#define DIO1  INT_0                               //DIO1 pin on LoRa device, used for RX and TX done 
//#define DIO2  PWM_0                               //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO2  -1                                //DIO2 pin on LoRa device, normally not used so set to -1 
#define RFBUSY  AN_0                                //busy line
#define NRESET  RESET_0                     //reset pin on LoRa device

#elif defined(MIKROBUS0_LAMBDA80)
/*
Lambda80C module
AN  <-> DIO1
INT <-> Busy
PWM <-> DIO2
*/
#define DIO1  AN_0                                //DIO1 pin on LoRa device, used for RX and TX done 
//#define DIO2  PWM_0                               //DIO2 pin on LoRa device, normally not used so set to -1 
#define DIO2  -1                                //DIO2 pin on LoRa device, normally not used so set to -1 
#define RFBUSY  INT_0                               //busy line
#define NRESET  RESET_0                     //reset pin on LoRa device

#else

// TODO MIKROBUS1_E28 MIKROBUS1_LAMBDA80

#error Unknown module

#endif

#define LED1 2                                  //on board LED, high for on

#define DIO3 -1                                 //DIO3 pin on LoRa device, normally not used so set to -1
#define RX_EN -1                                //pin for RX enable, used on some SX128X devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX128X devices, set to -1 if not used 
#define BUZZER -1                               //pin for buzzer, set to -1 if not used 
#define VCCPOWER 14                             //pin controls power to external devices

#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using

/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 16/12/19

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup hardware pin definitions here ! ***************

//These are the pin definitions for one of my own boards, the Easy Pro Mini,
//be sure to change the definitiosn to match your own setup. 


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


#define RX_EN -1                                //pin for RX enable, used on some SX1280 devices, set to -1 if not used
#define TX_EN -1                                //pin for TX enable, used on some SX1280 devices, set to -1 if not used 

//#define GPSPOWER 4                              //Pin that controls power to GPS, set to -1 if not used
#define GPSONSTATE HIGH                         //logic level to turn GPS on via pin GPSPOWER 
#define GPSOFFSTATE LOW                         //logic level to turn GPS off via pin GPSPOWER 

#define LORA_DEVICE DEVICE_SX1280    //we need to define the device we are using 



//*******  Setup LoRa Parameters Here ! ***************

//LoRa Modem Parameters
const uint32_t Frequency = 2445000000;           //frequency of transmissions
const int32_t Offset = 0;                        //offset frequency for calibration purposes
const uint8_t Bandwidth = LORA_BW_0200;          //LoRa bandwidth
const uint8_t SpreadingFactor = LORA_SF12;       //LoRa spreading factor
const uint8_t CodeRate = LORA_CR_4_5;            //LoRa coding rate

const int8_t TXpower = 10;                       //Power for transmissions in dBm

#define ThisNode '2'                             //a character that identifies this tracker

//**************************************************************************************************
// GPS Settings
//**************************************************************************************************

//#define USE_SOFTSERIAL_GPS                       //need to include this if we are using softserial for GPS     
#define HardwareSerialPort Serial1             //if using hardware serial enable this define for hardware serial port 

#define GPSBaud 9600                             //GPS Baud rate   

#define WaitGPSFixSeconds 30                     //time in seconds to wait for a new GPS fix 
#define WaitFirstGPSFixSeconds 1800              //time to seconds to wait for the first GPS fix at startup
#define Sleepsecs 5                              //seconds between transmissions, this delay is used to set overall transmission cycle time

#define echomS 2000                              //number of mS to run GPS echo at startup    

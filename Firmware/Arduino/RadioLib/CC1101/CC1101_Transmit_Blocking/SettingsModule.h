//*******  Setup hardware pin definitions here ! ***************

//These are the pin definitions for TinyGS 2G4 mikrobus modules
// https://github.com/thingsat/tinygs_2g4station/tree/main/Board_Tinysgs_2.4GHz_V1


#define SCK       18                                  // SCK on SPI3
#define MISO      19                                  // MISO on SPI3 
#define MOSI      23                                  // MOSI on SPI3 

// Mikrobus slot #0
#define NSS_0     5                                   // SPI chip select pin on Mikrobus 0
#define AN_0      33
#define RESET_0   32
#define PWM_0     25
#define INT_0     26

// TODO I2C and UART

// Mikrobus slot #1
#define NSS_1     15                                  // SPI chip select pin on Mikrobus 1
#define AN_1      27
#define RESET_1   14
#define PWM_1     04
#define INT_1     13

// TODO I2C and UART

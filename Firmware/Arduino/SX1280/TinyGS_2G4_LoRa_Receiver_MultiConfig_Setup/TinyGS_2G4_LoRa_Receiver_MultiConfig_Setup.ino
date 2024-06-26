/*******************************************************************************************************
  Programs for Arduino

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors. 
*******************************************************************************************************/

/*******************************************************************************************************
  Program Operation - This is a program that demonstrates the setup of a LoRa test receiver, when the
  transmistter changes the configuration for each packet.

  Serial monitor baud rate is set at 115200.
*******************************************************************************************************/

#define Program_Version "V1.0"

#include <SPI.h>                                 //the lora device is SPI based so load the SPI library
#include "SX128XLT_SW.h"                            //include the appropriate library   


// Define here the S1280 Mikrobus you have plugged on the TinyGS 2G4 station
//#define MIKROBUS0_LAMBDA80
//#define MIKROBUS0_E28
//#define MIKROBUS1_LAMBDA80
//#define MIKROBUS0_E28
//#define MIKROBUS1_E28
//#define MIKROBUS0_NICERF
#define MIKROBUS1_NICERF


#include "Settings.h"                            //include the setiings file, frequencies, LoRa settings etc   

SX128XLT_SW LT;                                     //create a library class instance called LT

uint32_t RXpacketCount;
uint32_t errors;

uint8_t RXBUFFER[RXBUFFER_SIZE];                 //create the buffer that received packets are copied into

uint8_t RXPacketL;                               //stores length of packet received
int8_t  PacketRSSI;                              //stores RSSI of received packet
int8_t  PacketSNR;                               //stores signal to noise ratio (SNR) of received packet

uint64_t devEUI;


uint8_t current_msg;
bool    synced = false;
uint8_t lost_messages;
#define LOST_MESSAGES_MAX       (60 * NB_MSG)

int timeout_ms;
uint32_t rx_start_ts;


/* ************************ */

void setConfig(uint8_t config)
{
  if (config >= NB_MSG) {
    config = 0;
  }
  current_msg = config;
  
  printElapsedTime();
  Serial.print(F("Set config "));
  Serial.println(config);

  LT.setModulationParams(MSG_CONFIG[config].sf, MSG_CONFIG[config].bandwidth, CodeRate);
}


void loop()
{
  if (!synced) {
    // Sync on a 800KHz message in case we don't have TCXO
    Serial.println(F("Wait Sync message"));
    setConfig(2);
    rx_start_ts = millis();
    RXPacketL = LT.receive(RXBUFFER, RXBUFFER_SIZE, 65000, WAIT_RX); //wait for a packet to arrive with 65 seconds timeout
    if (process() == 0) {
      synced = true;
    }
 
  } else {
    setConfig(current_msg+1);
  
    rx_start_ts = millis();
    timeout_ms = 2000;
    do {
      RXPacketL = LT.receive(RXBUFFER, RXBUFFER_SIZE, timeout_ms, WAIT_RX);
      timeout_ms = process();
    } while (timeout_ms > 10);

    if (current_msg == (NB_MSG-1)) {
      Serial.println(F("Waiting while endpoint is sleeping..."));
      delay(61000);
    }
  }
}


int process() 
{
  int res = 0; 

  PacketRSSI = LT.readPacketRSSI();              //read the recived RSSI value
  PacketSNR = LT.readPacketSNR();                //read the received SNR value

  if ((RXPacketL != sizeof(test_message_t)))
  {
    bool real_error = packet_is_Error();

    lost_messages++;
    if (lost_messages >= LOST_MESSAGES_MAX) {
      synced = false;
      res = -1;
      Serial.println(F("Synchronisation is probably lost"));

    } else if (real_error) {
      // contine RX
      Serial.println(F("Still waiting for the message"));
      return 2000 - (millis() - rx_start_ts);

    } else {
      // timeout
      res = -1;
    }
  }
  else
  {
    lost_messages = 0;
    packet_is_OK();
    
    /* synchronize rx timing now */
    uint16_t wait_ms = 1500 - MSG_CONFIG[current_msg].time_on_air;
    delay(wait_ms);
  }
  Serial.println();

  return res;
}

void packet_is_OK()
{
  RXpacketCount++;

  printElapsedTime();                             //print elapsed time to Serial Monitor
  const test_message_t * msg = (test_message_t *) RXBUFFER;
  Serial.printf("RSSI=%ddBm,SNR=%ddB,MSG=%lu,VOLT=%umV,TEMP=%d°,HUM=%u%%",
      PacketRSSI, PacketSNR, msg->msg_id, msg->voltage, msg->temperature/100, msg->humidity);
  Serial.println();
}


bool packet_is_Error()
{
  uint16_t IRQStatus;
  IRQStatus = LT.readIrqStatus();                   //read the LoRa device IRQ status register

  printElapsedTime();                               //print elapsed time to Serial Monitor

  if (IRQStatus & IRQ_RX_TIMEOUT)                   //check for an RX timeout
  {
    Serial.println(F("RXTimeout"));
    return false;
  }
  else
  {
    errors++;
    Serial.print(F("PacketError"));
    Serial.print(F(",RSSI,"));
    Serial.print(PacketRSSI);
    Serial.print(F("dBm,SNR,"));
    Serial.print(PacketSNR);
    Serial.print(F("dB,Length,"));
    Serial.print(LT.readRXPacketL());               //get the device packet length
    Serial.print(F(",IRQreg,"));
    Serial.print(IRQStatus, HEX);
    LT.printIrqStatus();                            //print the names of the IRQ registers set
    Serial.println();
    return true;
  }
  
}


void printElapsedTime()
{
  uint32_t now = millis();

  uint8_t  ms = now % 1000;
  now = now / 1000;
  uint8_t  secs = now % 60;
  now = now / 60;
  uint8_t  mns = now % 60;
  now = now / 60;
  uint8_t  hours = now % 24;
  now = now / 24;
  uint32_t days = now;

  Serial.printf("%uj, %02u:%02u:%02u.%03u > ", days, hours, mns, secs, ms);
}


void setup()
{
#ifdef ARDUINO_ARCH_ESP32  
  devEUI = ESP.getEfuseMac();
  printf("DevEUI: %llX\n", devEUI);
#else
  devEUI = 0x0102030405060708;
#endif

  Serial.begin(115200);
  Serial.println();
  Serial.print(F(__TIME__));
  Serial.print(F(" "));
  Serial.println(F(__DATE__));
  Serial.println(F(Program_Version));
  Serial.println();
  Serial.println(F("TinyGS 2G4 :: LoRa_Receiver_Detailed_Setup Starting"));
  Serial.println();

  SPI.begin();

  //SPI beginTranscation is normally part of library routines, but if it is disabled in the library
  //a single instance is needed here, so uncomment the program line below
  //SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));

  //setup hardware pins used by device, then check if device is found
  if (LT.begin(NSS, NRESET, RFBUSY, DIO1, DIO2, DIO3, RX_EN, TX_EN, LORA_DEVICE))
  {
    Serial.println(F("LoRa Device found"));
    delay(1000);
  }
  else
  {
    Serial.println(F("No device responding"));
    while (1)
    {
    }
  }


  //***************************************************************************************************
  //Setup LoRa device
  //***************************************************************************************************
  LT.setMode(MODE_STDBY_RC);
  LT.setRegulatorMode(USE_LDO);
  LT.setPacketType(PACKET_TYPE_LORA);
  LT.setSyncWord(LORA_MAC_PUBLIC_SYNCWORD);
  LT.setRfFrequency(Frequency, Offset);
  LT.setBufferBaseAddress(0, 0);
  LT.setModulationParams(SpreadingFactor, Bandwidth, CodeRate);
  LT.setPacketParams(LenInSymb, LORA_PACKET_VARIABLE_LENGTH, 255, LORA_CRC_ON, LORA_IQ_UPLINK, 0, 0);
  LT.setDioIrqParams(IRQ_RADIO_ALL, (IRQ_TX_DONE + IRQ_RX_TX_TIMEOUT), 0, 0);
  LT.setHighSensitivity();
  //***************************************************************************************************


  Serial.println();
  LT.printModemSettingsSW();                                     //reads and prints the configured LoRa settings, useful check
  Serial.println();
  LT.printOperatingSettings();                                 //reads and prints the configured operting settings, useful check
  Serial.println();
  Serial.println();


  Serial.print(F("Receiver ready - RXBUFFER_SIZE "));
  Serial.println(RXBUFFER_SIZE);
  Serial.println();
}

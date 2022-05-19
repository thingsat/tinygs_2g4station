/*
 * Author: Didier DONSEZ (adapted of JP Meijers example)
 * Date: 2016-09-07
 *
 * This program is meant to be used on a The Things Uno board.
 *
 * Transmit several bytes packet via a LoRaWAN network (TTN, Helium, Chripstack on premise).
 * 
 *
 * CHANGE ADDRESS!
 * Change the device address, network (session) key, and app (session) key to
 * the values that are registered via the TTN dashboard.
 * The appropriate line is "myLora.initABP(XXX);" or "myLora.initOTAA(XXX);"
 * When using ABP, it is advised to enable "relax frame count" on the dashboard.
 *
 */
#include <rn2xx3.h>

// On ESP32 Wroon 32, Serial2 pins are 16 for RX and 17 for TX.
// Pin 16 (RX) should be plugged on TX pin of the RN2XX3 modem.
// Pin 17 (TX) should be plugged on RX pin of the RN2XX3 modem.
// Pin 4 should be plugged on RST pin of the RN2XX3 modem.

// Uncomment if ABP
//#define ABP               1

#define RN2XX3_RST_PIN   (4U)
#define TX_PERIOD        (10U)

//create an instance of the rn2483 library, using the given Serial port
rn2xx3 myLora(Serial2);

void reset_rn2xx3()
{
  pinMode(RN2XX3_RST_PIN, OUTPUT);
  digitalWrite(RN2XX3_RST_PIN, LOW);
  delay(100);
  digitalWrite(RN2XX3_RST_PIN, HIGH);
}

// the setup routine runs once when you press reset:
void setup()
{ 
  reset_rn2xx3();

  // Open serial communications and wait for port to open:
  Serial.begin(57600); //serial port to computer
  Serial2.begin(57600); //serial port to radio

  // make sure usb serial connection is available,
  // or after 10s go on anyway for 'headless' use of the
  // node.
  while ((!Serial) && (millis() < 10000));

  Serial.println("Startup");

  initialize_radio();

  //transmit a startup message
  myLora.tx("Startup");

  delay(2000);
}

void initialize_radio()
{
  delay(1000); //wait for the RN2xx3's startup message
  Serial2.flush();

  //print out the HWEUI so that we can register it via ttnctl
  String hweui = myLora.hweui();
  while(hweui.length() != 16)
  {
    Serial.println("Communication with RN2xx3 unsuccessful.");
    delay(10000);
    hweui = myLora.hweui();
  }
  
#ifndef ABP  
  Serial.print("DevEUI: ");
  Serial.println(hweui);
#endif

  Serial.print("VBat: ");
  Serial.println(myLora.getVbat());
  
  //configure your keys and join the network
  Serial.println("Trying to join the network");
  bool join_result = false;

#ifdef ABP
  //ABP: initABP(String addr, String AppSKey, String NwkSKey);
  join_result = myLora.initABP("12345678", "8D7FFEF938589D95AAD928C2E2E7E48F", "AE17E567AECC8787F749A62F5541D522");
#else
  //OTAA: initOTAA(String AppEUI, String AppKey);
  join_result = myLora.initOTAA("70B3D57ED0000000", "1234567890ABCDEF1234567890ABCDEF");
#endif

  while(!join_result)
  {
    Serial.println("Unable to join. Are your keys correct, and do you have a LoRaWAN network coverage?");
    delay(60000); //delay a minute before retry
    join_result = myLora.init();
  }
  Serial.println("Successfully joined a LoRaWAN network");

  Serial.print("DevAddr: ");
  Serial.println(myLora.sendRawCommand(F("mac get devaddr")));
}

// the loop routine runs over and over again forever:
void loop()
{
    // TODO read the sensors values (GPS, ADC, ...) and build a LPP payload
    // See https://github.com/jpmeijers/RN2483-Arduino-Library/blob/master/examples/TheThingsUno-GPSshield-TTN-Mapper-binary/TheThingsUno-GPSshield-TTN-Mapper-binary.ino

    Serial.println("TXing");

    switch(myLora.txCnf("Hello World")) // blocking function
    {
      case TX_FAIL:
      {
        Serial.println("TX unsuccessful or not acknowledged");
        break;
      }
      case TX_SUCCESS:
      {
        Serial.println("TX successful and acknowledged");
        break;
      }
      case TX_WITH_RX:
      {
        String received = myLora.getRx();
        //received = myLora.base16decode(received);
        Serial.print("Received downlink: ");
        Serial.print(received);
        Serial.print(" with SNR=");
        Serial.println(myLora.getSNR());        
        break;
      }
      default:
      {
        Serial.println("Unknown response from TX function");
      }
    }

    delay(TX_PERIOD * 1000);
}

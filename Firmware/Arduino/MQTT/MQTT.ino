#include <WiFi.h>
#include <PubSubClient.h>
#include "time.h"


// Update these with values suitable for your network.
const char* ssid       = "MySSID";
const char* password   = "MYSSID-Password";

const char* mqtt_server = "test.mosquitto.org";
#define mqtt_port 1883


// TODO add chipId into the topics
#define MQTT_SERIAL_PUBLISH_CH "/esp32/9897656/serialdata/tx"
#define MQTT_SERIAL_RECEIVER_CH "/esp32/9897656/serialdata/rx"

WiFiClient wifiClient;

PubSubClient client(wifiClient);

/*
The true ESP32 chip ID is essentially its MAC address.
This function provides an alternate chip ID that matches 
the output of the ESP.getChipId() function on ESP8266 
(i.e. a 32-bit integer matching the last 3 bytes of 
the MAC address. This is less unique than the 
MAC address chip ID, but is helpful when you need 
an identifier that can be no more than a 32-bit integer 
(like for switch...case).
*/
uint32_t get_chipid() {
    uint32_t chipId = 0;
    for(int i=0; i<17; i=i+8) {
	  chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}
    return chipId;
}

void print_local_time(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

void config_time() {
  //init and get the time with NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  print_local_time();
}

void scan_wifi() {
  Serial.println("Scanning WiFi Networks...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  int n = WiFi.scanNetworks();
  for (int i=0; i<n; i++) {
    Serial.printf("%2d SSID=%-20s RSSI=%d\n", i+1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
  }
  WiFi.scanDelete();
}

void setup_wifi() {
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      // After 60 sec, stop and scan the available wifi SSIDs with scan_wifi()
    }
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if (client.connect(clientId.c_str(),MQTT_USER,MQTT_PASSWORD)) {
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish("/esp32/9897656/hello/", "hello world");
      // ... and resubscribe
      client.subscribe(MQTT_SERIAL_RECEIVER_CH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");  
    Serial.write(payload, length);
    Serial.println();
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(500);// Set time out for 
  scan_wifi();
  setup_wifi();
  config_time();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();
}

void publishSerialData(char *serialData){
  if (!client.connected()) {
    reconnect();
  }
  client.publish(MQTT_SERIAL_PUBLISH_CH, serialData);
}
void loop() {
   client.loop();
   if (Serial.available() > 0) {
     char mun[501];
     memset(mun,0, 501);
     Serial.readBytesUntil( '\n',mun,500);
     publishSerialData(mun);
   }
 }

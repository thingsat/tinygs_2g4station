// From https://github.com/smolbun/CC1101-Frequency-Analyzer/blob/main/CC1101_Frequency_Analyzer/CC1101_Frequency_Analyzer.ino


#include <Arduino.h>
#include <RadioLib.h>
#include <SPI.h>

#define RADIOLIB_CHECK_PARAMS (0)

#include "SettingsModule.h"

// Work with Mikrobus 1 only (receive fails on Mikrobus 0)
#define CC1101_MIKROBUS_1   1

#if CC1101_MIKROBUS_0 == 1
// Microbus 0
#define CC1101_CS_PIN           NSS_0
#define CC1101_GDO0_PIN         AN_0
#define CC1101_GDO2_PIN         PWM_0
#define CC1101_RST_PIN          RADIOLIB_NC

#elif CC1101_MIKROBUS_1 == 1
// Microbus 1
#define CC1101_CS_PIN           NSS_1
#define CC1101_GDO0_PIN         AN_1
#define CC1101_GDO2_PIN         PWM_1
#define CC1101_RST_PIN          RADIOLIB_NC

#else

#error Set pinout for CC1101 module

#endif

CC1101 radio = new Module(CC1101_CS_PIN, CC1101_GDO0_PIN, CC1101_RST_PIN, CC1101_GDO2_PIN);

static const uint32_t subghz_frequency_list[] = {
  /* 300 - 348 */
  300000000,
  302757000,
  303875000,
  303900000,
  304250000,
  307000000,
  307500000,
  307800000,
  309000000,
  310000000,
  312000000,
  312100000,
  312200000,
  313000000,
  313850000,
  314000000,
  314350000,
  314980000,
  315000000,
  318000000,
  330000000,
  345000000,
  348000000,
  350000000,

  /* 387 - 464 */
  387000000,
  390000000,
  418000000,
  430000000,
  430500000,
  431000000,
  431500000,
  433075000, /* LPD433 first */
  433220000,
  433420000,
  433657070,
  433889000,
  433920000, /* LPD433 mid */
  434075000,
  434176948,
  434190000,
  434390000,
  434420000,
  434620000,
  434775000, /* LPD433 last channels */
  438900000,
  440175000,
  464000000,
  467750000,

  /* 779 - 928 */
  779000000,
  868350000,
  868400000,
  868800000,
  868950000,
  906400000,
  915000000,
  925000000,
  928000000,
};

typedef struct
{
  uint32_t frequency_coarse;
  int rssi_coarse;
  uint32_t frequency_fine;
  int rssi_fine;
} FrequencyRSSI;

const int rssi_threshold = -75;

void setup() {
  Serial.begin(115200);
  while (!Serial) {};
  radio.begin();
  Serial.println("Frequency Analayzer Started!");
}

void loop() {
  int rssi;
  FrequencyRSSI frequency_rssi = {
    .frequency_coarse = 0, .rssi_coarse = -100, .frequency_fine = 0, .rssi_fine = -100
  };

  // First stage: coarse scan
  radio.setRxBandwidth(650); // 58, 68, 81, 102, 116, 135, 162, 203, 232, 270, 325, 406, 464, 541, 650 and 812 kHz    (81kHz seems to work best for me)
  size_t array_size = sizeof(subghz_frequency_list) / sizeof(subghz_frequency_list[0]);
  for (size_t i = 0; i < array_size; i++) {
    uint32_t frequency = subghz_frequency_list[i];
    if (frequency != 467750000 && frequency != 464000000 && frequency != 390000000 && frequency != 312000000 && frequency != 312100000 && frequency != 312200000 && frequency != 440175000) {
      radio.setFrequency((float)frequency / 1000000.0);
      radio.receiveDirect();
      delay(2);
      rssi = radio.getRSSI();

      if (frequency_rssi.rssi_coarse < rssi) {
        frequency_rssi.rssi_coarse = rssi;
        frequency_rssi.frequency_coarse = frequency;
      }
    }
  }

  // Second stage: fine scan
  if (frequency_rssi.rssi_coarse > rssi_threshold) {
    // for example -0.3 ... 433.92 ... +0.3 step 20KHz
    radio.setRxBandwidth(58);
    for (uint32_t i = frequency_rssi.frequency_coarse - 300000; i < frequency_rssi.frequency_coarse + 300000; i += 20000) {
      uint32_t frequency = i;
      radio.setFrequency((float)frequency / 1000000.0);
      radio.receiveDirect();
      delay(2);
      rssi = radio.getRSSI();

      if (frequency_rssi.rssi_fine < rssi) {
        frequency_rssi.rssi_fine = rssi;
        frequency_rssi.frequency_fine = frequency;
      }
    }
  }

  // Deliver results fine
  if (frequency_rssi.rssi_fine > rssi_threshold) {
    Serial.printf("FINE        Frequency: %.2f  RSSI: %d\n", (float)frequency_rssi.frequency_fine / 1000000.0, frequency_rssi.rssi_fine);
  }

  // Deliver results coarse
  else if (frequency_rssi.rssi_coarse > rssi_threshold) {
    Serial.printf("COARSE      Frequency: %.2f  RSSI: %d\n", (float)frequency_rssi.frequency_coarse / 1000000.0, frequency_rssi.rssi_coarse);
  }
  
  delay(10);
}

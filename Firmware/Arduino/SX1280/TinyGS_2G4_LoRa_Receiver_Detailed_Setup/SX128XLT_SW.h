#ifndef SX128XLT_SW_h
#define SX128XLT_SW_h

//#include "Arduino.h"
#include <SX128XLT.h> //include the appropriate library

#define LORA_MAC_PRIVATE_SYNCWORD 0x1424
#define LORA_MAC_PUBLIC_SYNCWORD 0x2414

#define REG_LR_SYNCWORD 0x0944

// SX128XLT with undocumented LoRa Sync Word

class SX128XLT_SW : public SX128XLT {
public:
    SX128XLT_SW();

    void setSyncWord(uint16_t syncword);

    uint16_t getSyncWord();

    void printModemSettingsSW();
};

#endif

// SX128XLT with undocumented LoRa Sync Word

#include "SX128XLT_SW.h"

SX128XLT_SW::SX128XLT_SW() : SX128XLT(){};

void SX128XLT_SW::setSyncWord(uint16_t syncword) {
#ifdef SX128XDEBUG
    Serial.println(F("setSyncWord()"));
#endif
    writeRegister(REG_LR_SYNCWORD, (syncword >> 8) & 0xFF);
    writeRegister(REG_LR_SYNCWORD + 1, syncword & 0xFF);
};

uint16_t SX128XLT_SW::getSyncWord() {
#ifdef SX128XDEBUG
    Serial.println(F("getSyncWord"));
#endif

    uint8_t msb, lsb;
    uint16_t syncword;
    msb = readRegister(REG_LR_SYNCWORD);
    lsb = readRegister(REG_LR_SYNCWORD + 1);
    syncword = (msb << 8) + lsb;

    return syncword;
};

void SX128XLT_SW::printModemSettingsSW() {
    SX128XLT::printModemSettings();
    Serial.print(F(",SyncWord_0x"));
    Serial.print(getSyncWord(), HEX);
};

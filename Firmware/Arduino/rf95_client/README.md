# Grove RFM95 LoRa Module



On error /home/user/Arduino/libraries/Grove_LoRa_433MHz_and_915MHz_RF-master/RadioHead.h:817:27: fatal error: util/atomic.h: No such file or directory

Go down into /home/user/Arduino/libraries/Grove_LoRa_433MHz_and_915MHz_RF-master/RadioHead.h

and replace `<util/atomic.h>` with `<RHutil/atomic.h>`


Add into ``
```c
#include <SoftwareSerial.h>
template class RHUartDriver<SoftwareSerial>;
``` 


```c
#include <SoftwareSerial.h>
template class RH_RF95<SoftwareSerial>;
``` 


```c
#define  RH_RF95_REG_33_INVERT_IQ                              0x33
#define  RH_RF95_REG_3B_INVERT_IQ2                             0x3b
#define  RH_RF95_REG_39_SYNC_WORD                              0x39
``` 


template <typename T>
bool RH_RF95<T>::init() {
    RHUartDriver<T>::init();

    //Set LoRa sync word
    this->write(RH_RF95_REG_39_SYNC_WORD, 0x34);
}



template <typename T>
void RH_RF95<T>::setModeRx() {
    if (this->_mode != RHGenericDriver::RHModeRx) {
        this->write(RH_RF95_REG_01_OP_MODE, RH_RF95_MODE_RXCONTINUOUS);
        this->write(RH_RF95_REG_40_DIO_MAPPING1, 0x00); // Interrupt on RxDone

        // Invert IQ Back
        this->write(RH_RF95_REG_33_INVERT_IQ, 0x67);
        this->write(RH_RF95_REG_3B_INVERT_IQ2, 0x19);

        this->_mode = RHGenericDriver::RHModeRx;
    }
}


template <typename T>
void RH_RF95<T>::setModeTx() {
    if (this->_mode != RHGenericDriver::RHModeTx) {
        this->write(RH_RF95_REG_01_OP_MODE, RH_RF95_MODE_TX);
        this->write(RH_RF95_REG_40_DIO_MAPPING1, 0x40); // Interrupt on TxDone

        // Set IQ to normal values
        this->write(RH_RF95_REG_33_INVERT_IQ, 0x27);
        this->write(RH_RF95_REG_3B_INVERT_IQ2, 0x1D);

        this->_mode = RHGenericDriver::RHModeTx;
    }
}


https://github.com/BeelanMX/Beelan-LoRaWAN/blob/aff67a8a6a818f105fab0fa29b0eca5f078cd810/src/arduino-rfm/RFM95.cpp
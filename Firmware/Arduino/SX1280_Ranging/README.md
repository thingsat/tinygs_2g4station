# Basic ranging tests with SX1280 modules of the TinyGS 2G4 station

The test are based on the Arduino library for SX12XX https://github.com/StuartsProjects/SX12XX-LoRa

Read [ranging.md](ranging.md)

## Instructions

Build and flash `54_Ranging_Slave.ino` on the first board.

```
451 Response sent
452 Response sent
453 Response sent
454 Response sent
455 Response sent
```


Build and flash `55_Ranging_Master.ino` on the second board.

```
TEST #74
Start Ranging ...
Valid,Register=528,Distance=23.8m,RSSIReg=109dBm,RSSI=-41dBm
Start Ranging ...
Valid,Register=437,Distance=19.7m,RSSIReg=94dBm,RSSI=-56dBm
Start Ranging ...
Valid,Register=480,Distance=21.6m,RSSIReg=109dBm,RSSI=-41dBm
Start Ranging ...
Valid,Register=529,Distance=23.8m,RSSIReg=92dBm,RSSI=-58dBm
Start Ranging ...
Valid,Register=449,Distance=20.2m,RSSIReg=111dBm,RSSI=-39dBm

Test=74,TotalValid=5,TotalErrors=0,AverageRAWResult=484,AverageDistance=21.8m

```

## References

* [Semtech, Theory and Principle of Operation: Advanced Ranging, Technical Report, February 2021](https://lora-developers.semtech.com/uploads/documents/files/TheoryAndPrinciples_AdvancedRanging_SX1280_v7.pdf)
* [P. Müller, H. Stoll, L. Sarperi and C. Schüpbach, "Outdoor Ranging and Positioning based on LoRa Modulation," 2021 International Conference on Localization and GNSS (ICL-GNSS), 2021, pp. 1-6, doi: 10.1109/ICL-GNSS51451.2021.9452277.](https://digitalcollection.zhaw.ch/bitstream/11475/22769/3/2021_Mueller-etal_Outdoor-ranging-and-positioning-based-on-LoRa-modulation.pdf)

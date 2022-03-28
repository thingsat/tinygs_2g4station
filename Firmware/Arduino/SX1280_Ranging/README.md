# Basic ranging tests with SX1280 modules of the TinyGS 2G4 station

The test are based on the Arduino library for SX12XX https://github.com/StuartsProjects/SX12XX-LoRa

## Instructions

TODO


Slave

```
451 Response sent
452 Response sent
453 Response sent
454 Response sent
455 Response sent
```


Master

```
Valid,Register,513,Distance,23.1,RSSIReg,103,RSSI,-47dBm
Start Ranging
Valid,Register,514,Distance,23.2,RSSIReg,103,RSSI,-47dBm
Start Ranging
Valid,Register,499,Distance,22.5,RSSIReg,103,RSSI,-47dBm
Start Ranging
Valid,Register,446,Distance,20.1,RSSIReg,104,RSSI,-46dBm
Start Ranging
Valid,Register,392,Distance,17.7,RSSIReg,98,RSSI,-52dBm,TotalValid,15,TotalErrors,0,AverageRAWResult,472,AverageDistance,21.3
```





## References

* [Semtech, Theory and Principle of Operation: Advanced Ranging, Technical Report, February 2021](https://lora-developers.semtech.com/uploads/documents/files/TheoryAndPrinciples_AdvancedRanging_SX1280_v7.pdf)
* [P. Müller, H. Stoll, L. Sarperi and C. Schüpbach, "Outdoor Ranging and Positioning based on LoRa Modulation," 2021 International Conference on Localization and GNSS (ICL-GNSS), 2021, pp. 1-6, doi: 10.1109/ICL-GNSS51451.2021.9452277.](https://digitalcollection.zhaw.ch/bitstream/11475/22769/3/2021_Mueller-etal_Outdoor-ranging-and-positioning-based-on-LoRa-modulation.pdf)

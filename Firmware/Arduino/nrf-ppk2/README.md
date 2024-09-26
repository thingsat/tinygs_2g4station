# ESP32 Power monitoring with Nordic PPK2

Load your sketch first and then unplug the USB cable.

Follow the [tutorial](https://github.com/CampusIoT/tutorial/tree/master/nrf-ppk2#readme) : select 3.3V from the supply voltage.

> Warning: The ESP32 must power only by one supply (PPK2 or USB) !!!

> For showing the console, a FTDI can be wired to `GND`, `RX` and `TX` (but not `3V3`).  

## Pinout

| PPK2 | ESP32 |
| ---- | ----- |
| `VOUT`| `3V3`|
| `GND` | `GND`|
| `D0`  | `D0` |


## References

* Towards Online Machine Learning Libraries for Embedded Systems, 2024 IEEE 10th World Forum on Internet of Things (WF-IoT) - https://hal.science/hal-04680048/document
* https://github.com/CampusIoT/tutorial/tree/master/nrf-ppk2#readme

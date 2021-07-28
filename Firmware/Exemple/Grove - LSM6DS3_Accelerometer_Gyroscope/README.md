# LSM6DS3_Accelerometer_Gyroscope

Software for reading a LSM6DS3, which is a Accelerometer, Gyroscope and thermometer provided by seedstudio. This component is a [Grove-6-Axis_AccelerometerAndGyroscope](https://wiki.seeedstudio.com/Grove-6-Axis_AccelerometerAndGyroscope/),the sensor has a combination of 3-axis digital accelerometer and 3-axis digital gyroscope. 
Communication is by I2C, if you use the Board_Tinygs_2.4GHz_V1, this module can be directly plug to I2C grove connector.


This firmware is made for arduino IDE and is available on: [github.com/Seeed-Studio/Accelerometer_And_Gyroscope_LSM6DS3](https://github.com/Seeed-Studio/Accelerometer_And_Gyroscope_LSM6DS3)


Codes may not work. A error saying that MSBFIRTS was not declared in this scope can be resolved by adding <Arduino.h> into SparkFunLSM6DS3.cpp and .h. [Source](https://github.com/sparkfun/SparkFun_LSM6DS3_Arduino_Library/issues/6)

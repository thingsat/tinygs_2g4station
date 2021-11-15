# MQTT	

The purpose of this simple example is the test of the MQTT Pub-Sub message exchange from and to the ESP32 Wroom.

## Publish a message from a Linux host

```bash
nvm use stable
npm install mqtt -g
mqtt pub -t '/esp32/9897656/serialdata/rx' -h 'test.mosquitto.org' -v -m 'This is a test'
```

The serial console of the ESP32 is
```
16:25:12.030 -> Attempting MQTT connection...connected
16:29:59.422 -> -------new message from broker-----
16:29:59.422 -> channel:/esp32/9897656/serialdata/rx
16:29:59.422 -> data:This is a test
```

## Publish a message from the ESP32 serial console

 : `This is a message from the ESP32 console`

```bash
mqtt sub -t '/esp32/9897656/serialdata/tx' -h 'test.mosquitto.org' -v
```
```
/esp32/9897656/serialdata/tx This is a message from the ESP32 console
```

## TodoList

* [ ] Secure the MQTT connection with TLS (ie MQTTS)

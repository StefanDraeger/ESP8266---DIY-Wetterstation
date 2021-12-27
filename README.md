## DIY Wetterstation v2.0

![DIY Wetterstation v2.0](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/diy_wetterstation_v2_0.jpg)

### Bibliotheken
- [Bounce2](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/Bounce2)
   - als ZIP-Datei vom Repository [thomasfredericks / Bounce2](https://github.com/thomasfredericks/Bounce2) kopiert

### Beispiele
- Button
  - [Taster & LED](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/button/button_led)
  - [Taster & Piezo Buzzer](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/button/button_buzzer)

### Pinout der Sensoren / Aktoren

![Pinout der DIY Wetterstation v2.0](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/diy_wetterstation_v2_0_pinout.jpg)

|Sensor / Aktor|Wemos D1 Mini  ||Sensor / Aktor|Wemos D1 Mini  |
|--|--|--|--|--|
|**Buzzer**|||**Switch** |
|GND|GND||Pin 1|5V|
|+|D8||Pin 2|D5|
||||||
|**LED** |  ||**DHT11** |  |
|Anode (+)|D4||Data|D6|
|Kathode (-)|GND||VCC|5V|
||||GND|GND|
||||||
|**OLED Display** |||**BMP280** |  |
|GND|GND||VCC|3.3V|
|VCC|3.3V||GND|GND|
|SDA|D1||SCL|D2|
|SCL|D2||SDA|D1|
||||3.3|--|
||||||
|**UV-Sensor** |  |
|VIN|--|
|VCC|3.3V|
|GND|GND|
|DATA|A0|
|EN|--|







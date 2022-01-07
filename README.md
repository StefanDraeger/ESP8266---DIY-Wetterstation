
## DIY Wetterstation v2.0

![DIY Wetterstation v2.0](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/diy_wetterstation_v2_0.jpg)

### Bibliotheken
Nachfolgend nun die benötigten Bibliotheken für die Programmierung in der [Arduino IDE](https://www.arduino.cc/en/software). Ich habe die Bibliotheken heruntergeladen und in mein Repository als ZIP-Datei übernommen. Das garantiert, dass die Version der Bibliothek funktioniert und nicht durch ein eventuelles Update durch den Entwickler einen Fehler aufweißt.
- [Bounce2](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/Bounce2)
   - als ZIP-Datei vom Repository [thomasfredericks / Bounce2](https://github.com/thomasfredericks/Bounce2) kopiert
 - [Adafruit SSD1306 OLED Display](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/OLED)
	 - als ZIP-Dateien von Repositories [adafruit / Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) & [stblassitude / Adafruit_SSD1306_Wemos_OLED](https://github.com/stblassitude/Adafruit_SSD1306_Wemos_OLED)
 - [DHTesp](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/DHT11)
	 - als ZIP-Datei vom Respository [beegee-tokyo / DHTesp](https://github.com/beegee-tokyo/DHTesp)

### Programm
Das Programm für die DIY Wetterstation in der Version 2 findest du auf diesem Respository im Ordner [DIY-Weatherstation-V2](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/DIY-Weatherstation-V2/diyWeatherstationV2). Dieses Programm  ist in der Arduino IDE entwickelt und zeigt per Knopfdruck auf dem OLED Display die verschiedenen Sensorwerte an.

### Beispiele
Hier nun einpaar Beispiele wie du die einzelnen Sensoren / Aktoren auf der Platine programmieren kannst. Und somit Stück für Stück die Funktionen der DIY Wetterstation V2 kennenlernst.

- Buzzer
	- [Sirene](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/buzzer/buzzer_simple_sound)
- Button
  - [Taster & LED](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/button/button_led)
  - [Taster & Piezo Buzzer](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/button/button_buzzer)
- OLED Display
	- [Schleife von 0 bis 9999](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/oled_display/oled_display_numbers)
	- [Taster zum hochzählen](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/oled_display/oled_display_button)
-  DHT11 Sensor
	- [Sensordaten auf dem OLED Display anzeigen](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/dht11/dht11_oled_display)
 


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







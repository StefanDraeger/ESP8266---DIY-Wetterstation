

## DIY Wetterstation v2.0

![DIY Wetterstation v2.0](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/diy_wetterstation_v2_0.jpg)

### Programm
Das Programm für die DIY Wetterstation in der Version 2 findest du auf diesem Respository im Ordner [DIY-Weatherstation-V2](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/DIY-Weatherstation-V2/diyWeatherstationV2). Dieses Programm  ist in der Arduino IDE entwickelt und zeigt per Knopfdruck auf dem OLED Display die verschiedenen Sensorwerte an.

### Bibliotheken
Nachfolgend nun die benötigten Bibliotheken für die Programmierung in der [Arduino IDE](https://www.arduino.cc/en/software). Ich habe die Bibliotheken heruntergeladen und in mein Repository als ZIP-Datei übernommen. Das garantiert, dass die Version der Bibliothek funktioniert und nicht durch ein eventuelles Update durch den Entwickler einen Fehler aufweißt.
- [Bounce2](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/Bounce2)
   - als ZIP-Datei vom Repository [thomasfredericks / Bounce2](https://github.com/thomasfredericks/Bounce2) kopiert
 - [Adafruit SSD1306 OLED Display](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/OLED)
	 - als ZIP-Dateien von Repositories [adafruit / Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) & [stblassitude / Adafruit_SSD1306_Wemos_OLED](https://github.com/stblassitude/Adafruit_SSD1306_Wemos_OLED) kopiert
 - [DHTesp](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/DHT11)
	 - als ZIP-Datei vom Respository [beegee-tokyo / DHTesp](https://github.com/beegee-tokyo/DHTesp) kopiert
 - [Adafruit BMP085](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/libs/BMP180)
	 - als ZIP-Datei vom Repository [adafruit / Adafruit-BMP085-Library](https://github.com/adafruit/Adafruit-BMP085-Library) kopiert

### Beispiele
Hier nun ein paar Beispiele, wie du die einzelnen Sensoren / Aktoren auf der Platine programmieren kannst. Und somit Stück für Stück die Funktionen der DIY Wetterstation V2 zu programmieren.

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
- UV-Sensor
	- [Ausgabe auf der seriellen Schnittstelle](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/uv_sensor/uv_sensor_serial)
	- [Ausgabe auf dem OLED Display](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/uv_sensor/uv_sensor_oled_display)
- BMP180
	- [auslesen der Werte](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/bmp180/simple_bmp180_program)
- WiFi
	- [Aufbau einer WiFi Verbindung](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/wifi/esp8266_simple_wifi_connection)
	- [erstellen einer einfachen Webseite für Sensordaten](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/wifi/esp8266_webpage_sensor_data)
	- [senden von Sensordaten an ThingSpeak](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/tree/main/examples/wifi/esp8266_thingspeak_sensor_data)

### Mikrocontroller ESP8266 
![Wemos D1 Mini - ESP8266](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/esp8266.jpg)
#### Technische Daten
|Bezeichnung|Wert  |
|--|--|
|Taktgeschwindigkeit|80 MHz / 160 MHz|
|Betriebsspannung|3.3 V|
|max. Stromstärke pro I/O Pin|20 mA|
|max. Stromstärke 3.3V|50 mA|
|Flash Speicher|4 Mbyte|
|digitale Eingänge / Ausgänge|11|
|digitale PWM Ausgänge|11|
|analoge Eingänge / Ausgänge|1|
### Sensoren
Auf der DIY Weatherstation V2 sind folgende Sensoren / Aktoren verbaut:

#### OLED Display
![0,49 Zoll OLED Display](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/oled_display.jpg)
##### Technische Daten
|Bezeichnung|Wert  |
|--|--|
|Abmaße  |0,49 Zoll  |
|Auflösung|64x32|
|Betriebsspannung  |3.0 V bis 5 V|
|Anschluss  |I2C |

##### Pinout
#### DHT11 Sensor
![DHT11](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/dht11.jpg)
##### Technische Daten
|Bezeichnung|Wert  |
|--|--|
|Abmaße  |0,49 Zoll  |
|Auflösung|64x32|
|Betriebsspannung  |3.0 V bis 5 V|
|Anschluss  |I2C |

##### Pinout
|Bezeichnung|Pin  |
|--|--|
|Data|D6|
|VCC|5 V|
|GND|GND|
#### BMP180 Sensor
![BMP180](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/bmp180.jpg)
##### Technische Daten
|Bezeichnung|Wert  |
|--|--|
|Betriebsspannung|1.8 V bis 3.6 V|
|Leistungsaufnahme|0,5µA bei 1Hz|
|Genauigkeit|0.02 hPa|
|Messbereich|300 hPa bis 1100 hPa|
##### Pinout
|Bezeichnung|Pin  |
|--|--|
|VCC|3.3 V|
|GND|GND|
|SCL|D2|
|SDA|D1|
|3.3|--|
#### UV-Sensor
![UV Sensor](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/uv_sensor.jpg)
##### Technische Daten
|Bezeichnung|Wert  |
|--|--|
|Betriebsspannung|3.3 V|
|max. Stromaufnahme|0,1µA |
##### Pinout
|Bezeichnung|Pin  |
|--|--|
|VIN|--|
|VCC|3.3 V|
|GND|GND|
|DATA|A0|
|EN|--|

#### Piezo Buzzer
![Piezo Buzzer](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/piezo_buzzer.jpg)
##### Pinout
|Bezeichnung|Pin  |
|--|--|
|+|D8|
|-|GND|
#### Taster
![Taster](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/taster_pulldown.jpg)
##### Pinout
|Bezeichnung|Pin  |
|--|--|
|Pin 1|5V|
|Pin 2|D5|
#### LED
![Leuchtdiode](https://github.com/StefanDraeger/ESP8266---DIY-Wetterstation/blob/main/images/led_vorwiderstand.jpg)
##### Pinout
|Bezeichnung|Pin  |
|--|--|
|Anode (+)|D4|
|Kathode (-)|GND|



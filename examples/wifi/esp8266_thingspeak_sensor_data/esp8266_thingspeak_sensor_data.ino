#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"
#include <Adafruit_BMP085.h>

#include "uvsensor.h"
#include "dht11.h"
#include "bmp180.h"

const char* ssid = ""; //SSID aus dem Router
const char* password = ""; //Passwort für den Zugang zum WLAN

ESP8266WiFiMulti WiFiMulti;
WiFiClient client;
HTTPClient http;

String API_KEY = "";
String thingSpeakAPIUrl = "http://api.thingspeak.com/update?api_key="+API_KEY+"&";

//5min Pause
const int PAUSE = 300000;

void setup() {
  Serial.begin(115200); //Baudrate für die Serielle Geschwindigkeit.
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  Serial.print("Aufbau der Verbindung zu: "); //Ausgabe der SSID auf der Seriellen Schnittstelle.
  Serial.println(ssid);

  WiFiMulti.addAP(ssid, password);

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // PIN des UV Sensors als Eingang definieren
  pinMode(uvSensorIn, INPUT);

  setupBmp180();
}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    String url = thingSpeakAPIUrl;
    url = url + "field1=" + getDht11TempValue();
    url = url + "&field2=" + getDht11HumidityValue();
    url = url + "&field3=" + getBmp180Pressure();
    url = url + "&field4=" + getUvSensorValue();
    http.begin(client, url);

    int httpCode = http.GET();
    Serial.println("HTTP Code:"+httpCode);
    Serial.println("URL:"+url);

    delay(PAUSE);
  }
}

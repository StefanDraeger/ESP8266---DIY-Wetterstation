#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"

#include <Adafruit_BMP085.h>

int uvSensorIn = A0; //Analoger Eingang A0

const float inMin = 0.99;
const float inMax = 2.9;
const float outMin = 0.0;
const float outMax = 15.0;

const byte numberOfReadings = 8;


DHTesp dht;
Adafruit_BMP085 bmp;

const char* ssid = "FRITZBox7590GI_EXT";
const char* password = "22894580214767401850";

ESP8266WebServer server(80);

float readTemp() {
  Serial.println("Temperatur");
  return dht.getTemperature();
}

float readLuftfeuchtigkeit() {
  Serial.println("Luftfeuchtigkeit");
  return dht.getHumidity();
}

float readLuftdruck() {
  Serial.println("Luftdruck");
  return bmp.readPressure() / 1000;
}

//Ließt den PIN x mal und berechnet aus der Anzahl der gelesenen Werte den
//Durchschnittswert und liefert diesen zurück.
int averageAnalogRead(int pinToRead){
  unsigned int runningValue = 0; 
  for(int x = 0 ; x < numberOfReadings ; x++){
    runningValue += analogRead(pinToRead);
  }
  return(runningValue / numberOfReadings);  
}

//Arduino map Funktion unterstützt kein Float daher wurde diese neu implementiert 
//(eine Kopie aus dem Arduino Forum)
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float readUvIntensitaet() {
  int uvLevel = averageAnalogRead(uvSensorIn);

  float outputVoltage = 3.3 * uvLevel / 1024;
  float uvIntensity = mapfloat(outputVoltage, inMin, inMax, outMin, outMax);

  return uvIntensity;
}

void handleRoot() {
  delay(dht.getMinimumSamplingPeriod());
  float temperatur = readTemp();
  float luftfeuchtigkeit = readLuftfeuchtigkeit();
  float luftdruck = readLuftdruck();
  float uvIntensitaet = readUvIntensitaet();

  String webseite = "<html><body><h1>DIY - Wetterstation v2</h1><p>Temperatur: " + String(temperatur, 2) + " &deg;C</p><p>rel. Luftfeuchtigkeit " + String(luftfeuchtigkeit, 2) + " &#x25;</p><p>Luftdruck " + String(luftdruck, 2) + " hPa</p><p>UV-Intensit&auml;t " + String(uvIntensitaet, 2) + " mW/cm&sup2;</p></body></html>";
  server.send(200, "text/html", webseite);
}

void setup(void) {
  Serial.begin(115200); //Baudrate für die Serielle Geschwindigkeit.
  pinMode(uvSensorIn, INPUT);
  dht.setup(12, DHTesp::DHT11);
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  Serial.println("");
  Serial.print("Aufbau der Verbindung zu: "); //Ausgabe der SSID auf der Seriellen Schnittstelle.
  Serial.println(ssid);
  Serial.println("");
  WiFi.begin(ssid, password); //Initialisieren der Wifi Verbindung.
  while (WiFi.status() != WL_CONNECTED) { //Warten bis die Verbindung aufgebaut wurde.
    delay(500);
    //Einen Punkt auf der Seriellen Schnittstelle ausgeben so das der Benutzer erkennt dass, das Sketch noch läuft.
    Serial.print(".");
  }
  Serial.println("");
  //Bei erfolgreicher Verbindung wird der folgende Text ausgeben.
  Serial.println("Mit " + String(ssid) + " erfolgreich verbunden!");
  server.begin(); // Starten des Servers.

  // Ausgabe der IP Adresse
  Serial.print("Adresse : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}

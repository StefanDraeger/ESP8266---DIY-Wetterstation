#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"
#include <Adafruit_BMP085.h>

#include "uvsensor.h"
#include "dht11.h"
#include "bmp180.h"

//5min Pause
const int PAUSE = 300000;

float temperatur = 0.0f;
float luftfeuchtigkeit = 0.0f;
float luftdruck = 0.0f;
float uvlicht = 0.0f;

void setup() {
  Serial.begin(9600); //Baudrate für die Serielle Geschwindigkeit.
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  
  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // PIN des UV Sensors als Eingang definieren
  pinMode(uvSensorIn, INPUT);

  setupBmp180();
}

void loop() {
  temperatur = getDht11TempValue();
  luftfeuchtigkeit = getDht11HumidityValue();
  luftdruck = getBmp180Pressure();
  uvlicht = getUvSensorValue();

  Serial.print("Temperatur: ");
  Serial.println(temperatur);

  Serial.print("rel. Luftfeuchtigkeit: ");
  Serial.println(luftfeuchtigkeit);

  Serial.print("Luftdruck: ");
  Serial.println(luftdruck);

  Serial.print("UV-Intensität: ");
  Serial.println(uvlicht);

  delay(1500);
}
  

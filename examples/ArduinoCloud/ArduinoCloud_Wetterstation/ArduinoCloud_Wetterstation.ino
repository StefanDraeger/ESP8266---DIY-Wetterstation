#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"
#include <Adafruit_BMP085.h>

#include "uvsensor.h"
#include "dht11.h"
#include "bmp180.h"

#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // PIN des UV Sensors als Eingang definieren
  pinMode(uvSensorIn, INPUT);

  setupBmp180();
}

void loop() {
  ArduinoCloud.update();
  
  temperatur = getDht11TempValue();
  luftfeuchtigkeit = getDht11HumidityValue();
  luftdruck = getBmp180Pressure();
  uvlicht = getUvSensorValue();
}

void onValueChange() {
  // bleibt leer
}
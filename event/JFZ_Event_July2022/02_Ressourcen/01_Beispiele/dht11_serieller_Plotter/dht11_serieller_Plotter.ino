#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"

DHTesp dht;

void setup()   {
  Serial.begin(9600);
  dht.setup(12, DHTesp::DHT11);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float luftfeuchtigkeit = dht.getHumidity();
  float temperatur = dht.getTemperature();
  String line1 = "rel.Luftfeuchtigkeit Temperatur";
  String line2 = String(luftfeuchtigkeit, DEC)+ " " + String(temperatur, DEC);
  Serial.println(line1);
  Serial.println(line2);
  delay(1500);
}

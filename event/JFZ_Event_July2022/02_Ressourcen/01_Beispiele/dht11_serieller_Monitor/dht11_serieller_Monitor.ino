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

  Serial.println("Humidity:" + String(luftfeuchtigkeit, 2) + "%");
  Serial.println("Temp.:" + String(temperatur, 2) + "C");
  delay(1500);
}

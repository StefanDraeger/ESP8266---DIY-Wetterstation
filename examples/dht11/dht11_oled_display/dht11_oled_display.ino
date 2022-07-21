#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHTesp.h"

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

DHTesp dht;

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float luftfeuchtigkeit = dht.getHumidity();
  float temperatur = dht.getTemperature();

  displayDht11Value("Humidity:",String(luftfeuchtigkeit, 2) + "%");
  delay(1500);
  displayDht11Value("Temp.:", String(temperatur, 2) + "C");
  delay(1500);
}

void displayDht11Value(String text, String value) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 15);
  display.println(text);
  display.setCursor(60, 30);
  display.println(value);
  display.display();
}

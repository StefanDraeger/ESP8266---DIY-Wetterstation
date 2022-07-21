#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  display.clearDisplay();
  display.drawRect(0,20,25,25, WHITE);
  display.drawCircle(23,30,10, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,25);
  display.println("Test");
  display.display();
}

void loop() {
  //bleibt leer
}

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

int uvSensorIn = A0; //Analoger Eingang A0
 
const float inMin = 0.99;
const float inMax = 2.9;
const float outMin = 0.0;
const float outMax = 15.0;

const byte numberOfReadings = 8;

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  
  pinMode(uvSensorIn, INPUT);
  Serial.begin(9600); //Starten der Seriellen Kommunikation mit 9600 baud
}
 
void loop(){
  int uvLevel = averageAnalogRead(uvSensorIn);
 
  float outputVoltage = 3.3 * uvLevel/1024;
  float uvIntensity = mapfloat(outputVoltage, inMin, inMax, outMin, outMax);

  displayValue("UV Sensor:", String(uvIntensity,2)+" mW");
  delay(200); //Pause von 200ms.
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

void displayValue(String text, String value) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 15);
  display.println(text);
  display.setCursor(60, 30);
  display.println(value);
  display.display();
}

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHTesp.h"
#include <Bounce2.h>

#include "uvsensor.h"
#include "dht11.h"

// Taster auf D5 - GPIO14
#define btnPin D5

// erstellen einer Instanz eines Bounce2 Objektes
// um den Taster zu entprellen
Bounce2::Button button = Bounce2::Button();

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

const int DHT11_HUMIDITY = 1;
const int DHT11_TEMP = 2;
const int UV_SENSOR = 3;

const int MAX_SENSOR_VALUES = 3;

int sensorValueIndex = 0;

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // PIN des UV Sensors als Eingang definieren
  pinMode(uvSensorIn, INPUT);

  // "verbinden" des Tasters"
  button.attach( btnPin, INPUT );
  // entprellen mit 5ms
  button.interval(5);
  // wenn der Taster gedrück wurde ist das Signal "LOW"
  button.setPressedState(LOW);
  displayValue("click me", "");
}

void loop() {
  // aktualisieren des Status des Tasters
  button.update();

  // Wenn der Taster gedrück wurde, dann mache...
  if ( button.pressed() ) {
    
    if (sensorValueIndex >= MAX_SENSOR_VALUES) {
      sensorValueIndex = 1;
    } else {
      sensorValueIndex++;
    }

    Serial.println("Taster gedrückt.");
    Serial.println(sensorValueIndex);

    switch (sensorValueIndex) {
      case DHT11_HUMIDITY:
        displayValue("Humidity:", getDht11HumidityValue());
        break;
      case DHT11_TEMP:
        displayValue("Temp.:", getDht11TempValue());
        break;
      case UV_SENSOR:
        displayValue("UV Sensor:", getUvSensorValue());
        break;
      default:
        Serial.println("switch default");
        break;
    }
  }
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

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHTesp.h"
#include <Bounce2.h>

// Taster auf D5 - GPIO14
#define btnPin D5

// erstellen einer Instanz eines Bounce2 Objektes
// um den Taster zu entprellen
Bounce2::Button button = Bounce2::Button();

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

DHTesp dht;

const int DHT11_HUMIDITY = 1;
const int DHT11_TEMP = 2;

const int MAX_SENSOR_VALUES = 2;

int sensorValueIndex = 1;

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // "verbinden" des Tasters"
  button.attach( btnPin, INPUT );
  // entprellen mit 5ms
  button.interval(5);
  // wenn der Taster gedrück wurde ist das Signal "LOW"
  button.setPressedState(LOW);
  displayDht11Value("click me", "");
}

void loop() {
  // aktualisieren des Status des Tasters
  button.update();

  // Wenn der Taster gedrück wurde, dann mache...
  if ( button.pressed() ) {
    delay(dht.getMinimumSamplingPeriod());
    float luftfeuchtigkeit = dht.getHumidity();
    float temperatur = dht.getTemperature();
    
    if (sensorValueIndex >= MAX_SENSOR_VALUES) {
      sensorValueIndex = 1;
    } else {
      sensorValueIndex++;
    }

    Serial.println("Taster gedrückt.");
    Serial.println(sensorValueIndex);

    switch (sensorValueIndex) {
      case DHT11_HUMIDITY:
        displayDht11Value("Humidity:", String(luftfeuchtigkeit, 2) + "%");
        break;
      case DHT11_TEMP:
        displayDht11Value("Temp.:", String(temperatur, 2) + "C");
        break;
      default:
        Serial.println("switch default");
        break;
    }
  }
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

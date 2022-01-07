#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Bounce2.h>

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

// Taster auf D5 - GPIO14
#define btnPin D5

// erstellen einer Instanz eines Bounce2 Objektes
// um den Taster zu entprellen
Bounce2::Button button = Bounce2::Button();

int counter = 0;

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  // "verbinden" des Tasters"
  button.attach( btnPin, INPUT );
  // entprellen mit 5ms
  button.interval(5);
  // wenn der Taster gedrück wurde ist das Signal "LOW"
  button.setPressedState(LOW);
}

void loop() {
  // aktualisieren des Status des Tasters
  button.update();
  // Wenn der Taster gedrück wurde, dann mache...
  if ( button.pressed() ) {
    counter++;
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(60, 5);
    display.println(counter);
    display.display();
  }
}

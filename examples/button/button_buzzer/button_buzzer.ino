#include <Bounce2.h>

// Taster auf D5 - GPIO14
#define btnPin D5
// Piezo Buzzer auf D8 - GPIO15
#define buzzerPin D8

// erstellen einer Instanz eines Bounce2 Objektes 
// um den Taster zu entprellen
Bounce2::Button button = Bounce2::Button();

void setup() {
  Serial.begin(9600);
  // "verbinden" des Tasters"
  button.attach( btnPin, INPUT );
  // entprellen mit 5ms
  button.interval(5);
  // wenn der Taster gedrück wurde ist das Signal "LOW"
  button.setPressedState(LOW);

  // LED Pin als Ausgang definieren
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // aktualisieren des Status des Tasters
  button.update();
  // Wenn der Taster gedrück wurde, dann mache...
  if ( button.pressed() ) {
    Serial.println("pressed");
    tone(buzzerPin, 500, 250);
  }
}

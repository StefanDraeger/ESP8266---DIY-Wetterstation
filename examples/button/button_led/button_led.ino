#include <Bounce2.h>

// Taster auf D5 - GPIO14
#define btnPin D5
// Leuchtdiode auf D4 - GPIO2 
#define ledPin D4

// erstellen einer Instanz eines Bounce2 Objektes 
// um den Taster zu entprellen
Bounce2::Button button = Bounce2::Button();

// Variable zum speichern des Status der LED 
int ledStatus = LOW;

void setup() {
  // "verbinden" des Tasters"
  button.attach( btnPin, INPUT );
  // entprellen mit 5ms
  button.interval(5);
  // wenn der Taster gedrück wurde ist das Signal "LOW"
  button.setPressedState(LOW);

  // LED Pin als Ausgang definieren
  pinMode(ledPin, OUTPUT);
  // deaktivieren der LED
  digitalWrite(ledPin, ledStatus);
}

void loop() {
  // aktualisieren des Status des Tasters
  button.update();
  // Wenn der Taster gedrück wurde, dann mache...
  if ( button.pressed() ) {
    // LED Status umkehren
    ledStatus = !ledStatus;
    // setzen des aktuellen LED Status
    digitalWrite(ledPin, ledStatus);

  }
}

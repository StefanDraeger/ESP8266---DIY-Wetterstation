// Piezo Buzzer auf D8 - GPIO15
#define buzzerPin D8

void setup() {
  // Pin des Piezo Buzzers als Ausgang definieren
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Frequenzen von 450 bis 1500 mit einer dauer von 50ms. ausgeben
  for (int i = 450; i < 1500; i++){
    tone(buzzerPin, i, 50);
  }
}

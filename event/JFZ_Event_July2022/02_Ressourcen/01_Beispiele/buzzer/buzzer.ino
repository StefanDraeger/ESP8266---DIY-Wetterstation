//Piezo Buzzer am 
//digitalen Pin D8 angeschlossen
#define buzzer D8

void setup() {
  //Pin des Buzzers als Ausgang definieren
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Ausgabe von einem Ton mit 750 Hertz
  tone(buzzer, 750);
  //eine kleine Pause von 500ms.
  delay(500);
  //den Ton deaktivieren
  noTone(buzzer);
}

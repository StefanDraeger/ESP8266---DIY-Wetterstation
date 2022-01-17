#define led D4

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Aktivieren der LEd am digitalen Pin D4
  digitalWrite(led, HIGH);
  // eine kleine Pause von 250ms.
  delay(250);
  // Deaktivieren der LEd am digitalen Pin D4
  digitalWrite(led, LOW);
  // eine kleine Pause von 250ms.
  delay(250);
}

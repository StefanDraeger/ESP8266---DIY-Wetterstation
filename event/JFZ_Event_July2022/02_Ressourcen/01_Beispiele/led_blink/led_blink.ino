//LED am digitalen Pin D4 / GPIO01 angeschlossen
#define led D4
//alternativ kann die Konstante LED_BUILTIN
//verwendet werden
//#define led LED_BUILTIN

void setup() {
  //festlegen das der Pin als Ausgang dient
  pinMode(led, OUTPUT);
}

void loop() {
  //LED aktivieren, Ausgang auf HIGH setzen
  digitalWrite(led, HIGH);
  //eine kleine Pause von 500 Millisekunden
  delay(500);
  //LED deaktivieren, Ausgang auf LOW setzen
  digitalWrite(led, LOW);
  //eine kleine Pause von 500 Millisekunden
  delay(500);
}

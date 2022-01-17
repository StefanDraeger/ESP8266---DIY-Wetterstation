#define led D4

#define taster D5

void setup() {
  pinMode(led, OUTPUT);
  pinMode(taster, INPUT);
}

void loop() {
  // Wenn der Taster betätigt wird, dann...
  if(digitalRead(taster)==LOW){
    // LED aktivieren
    digitalWrite(led, HIGH);
  } else {
    // LED deaktivieren
    digitalWrite(led, LOW);
  }
}

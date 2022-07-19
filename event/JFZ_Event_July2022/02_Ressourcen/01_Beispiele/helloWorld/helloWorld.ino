void setup() {
  //beginn der seriellen Kommunikation mit
  //9600 baud
  Serial.begin(9600);
}

void loop() {
  //Ausgabe der Textzeile "Hello World!" auf
  //der seriellen Schnittstelle
  Serial.println("Hello World!");
  //eine kleine Pause von einer Sekunde (1000ms)
  delay(1000);
}

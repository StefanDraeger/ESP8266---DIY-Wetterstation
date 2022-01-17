#define led D4

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Eine Schleife von 0 bis 255
  for(int i=0;i<255;i++){
    // schreiben des analogen Wertes an die LED
    analogWrite(led, i);
    // eine Pause von 25ms.
    delay(25);
  }

  // eine Pause von 250ms.
  delay(250);
}

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
  //eine Schleife von 0 bis 255
  for(int i=0;i<255;i++){
    //schreibe den analogen Wert auf den Pin der LED
    analogWrite(led, i);
    //eine kleine Pause von 125ms.
    delay(15);
  }
}

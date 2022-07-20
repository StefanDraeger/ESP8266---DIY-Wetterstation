#include <Bounce2.h>

#define button D5

Bounce btn = Bounce(button, 50);

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  btn.update();

  if(btn.rose()){
    Serial.println("Taster gedrückt");  
  }

  if(btn.fell()){
    Serial.println("Taster losgelassen");  
  }
}

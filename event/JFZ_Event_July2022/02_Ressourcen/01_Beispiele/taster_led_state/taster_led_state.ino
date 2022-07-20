#include <Bounce2.h>

#define button D5
#define led D4

boolean ledActive = false;

Bounce btn = Bounce(button, 50);

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  btn.update();
  if(btn.rose()){
    if(ledActive == false){
      ledActive = true;
      digitalWrite(led, HIGH);
    } else if(ledActive == true){
      ledActive = false;
      digitalWrite(led, LOW);
    }
  }
}

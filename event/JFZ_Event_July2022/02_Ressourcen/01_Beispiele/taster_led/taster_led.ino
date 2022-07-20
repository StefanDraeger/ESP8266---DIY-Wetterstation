#include <Bounce2.h>

#define button D5
#define led D4

Bounce btn = Bounce(button, 50);

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  btn.update();
  if(btn.rose()){
    digitalWrite(led, HIGH);
  }

  if(btn.fell()){
    digitalWrite(led, LOW);
  }
  
}

#include <Joystick.h>

Joystick joystick(A0, A1, 13);


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (A1==HIGH){
     Serial.println(A1);
  }
}

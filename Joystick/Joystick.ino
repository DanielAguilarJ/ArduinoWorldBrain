#include <Servo.h>
Servo UpDown;
Servo LeftRight;
int JoyX=3;
int JoyY=4;

int ValorX;
int ValorY;

int ValorMaxX = 1023;
int ValorMinX = 0;
int ValorMaxY = 1023;
int ValorMinY = 0;
void setup() {
  UpDown.attach(1);
  LeftRight.attach(2);
}

void loop() {
  ValorX = analogRead(JoyX);
  ValorY = analogRead(JoyY);
  if (ValorX > 511){// Si es mayor a 511 que es casi el valor max del eje X
    ValorMaxX = 1023-ValorX+511;
    ValorMinX = 0;
  }
  else if(ValorX <511){
    ValorMaxX = 1023;
    ValorMinX = 511-ValorX;
  }
  if(ValorY > 511){
    ValorMaxY = 1023 - ValorY + 511;
    ValorMinY = 0;
  }
  else if (ValorY < 511){
    ValorMaxY = 1023;
    ValorMinY = 511 -ValorY;
  }
  ValorX = map (ValorX, ValorMinX,ValorMaxX, 0, 180);
  LeftRight.write(ValorX);
  ValorY = map (ValorY, ValorMinY, ValorMaxY, 0, 180);
  UpDown.write(ValorY);
  delay(50);
}

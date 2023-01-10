#include <SPI.h>;
int S;
int LED = 0;
int LASER = 1;
int CHOQUE = 2;
void setup() {
  S = 0;
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(0,OUTPUT);
  digitalWrite(0,LOW);
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);
  pinMode(2,INPUT);
}

void loop() {
  S = analogRead(A0);
  if (S > 4000){
    digitalWrite(0,HIGH);  
  }
  else{
    digitalWrite(0,LOW);
  }
  if (S>2900 && S<3100){
    digitalWrite(1,HIGH);
  }
 else{
  digitalWrite(1,LOW);
 }
 Serial.println(S);
 delay(2000);
}

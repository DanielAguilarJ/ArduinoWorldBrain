#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define ECHO 11
#define TRIG 10
#define LASER 24
long d;
long t;
int BUZZER = 12;
int INFRAROJO = 14;
int valor;
int MOTOR1 = 3;
int MOTOR2 = 5;
int i;
int CHOQUE = 4;
int value;
Servo servoMotor;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  Serial.begin(9600);
  servoMotor.attach(19);
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
  digitalWrite(TRIG,LOW);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,LOW);
  pinMode(INFRAROJO,INPUT);
  pinMode(LASER,OUTPUT);
  digitalWrite(LASER,LOW);
  pinMode(MOTOR1,OUTPUT);
  analogWrite(MOTOR1,0);
  pinMode(MOTOR2, OUTPUT);
  analogWrite(MOTOR2,0);
  pinMode(CHOQUE,INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  t = pulseIn(ECHO,HIGH);
  d = t/58;
  digitalWrite(TRIG,HIGH);
  delay(1000); 
  digitalWrite(TRIG,LOW);
  
  while(d > 20){
    servoMotor.write(0);
    delay(1000);
    servoMotor.write(90);
    delay(1000);
    servoMotor.write(180);
    delay(1000);
    servoMotor.write(90);
    delay(1000);
    servoMotor.write(0);
    delay(1000);
  }
  if (d<=20){
    digitalWrite(BUZZER,HIGH);
    delay(3000);
  }
  else {
    digitalWrite(BUZZER,LOW);
  }
  valor = 0;
  valor = digitalRead(INFRAROJO);
  if (valor == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Objetivo cerca");
    delay(2000);
    digitalWrite(LASER,HIGH);
    delay(2000);
  }
    i = 255;
    analogWrite(MOTOR1, i);
    analogWrite(MOTOR2, i);  
    value = digitalRead(CHOQUE);
    if(value == HIGH){
      analogWrite(MOTOR1, 0);
      analogWrite(MOTOR2,0);
      delay(2000);
  }
  else{
    analogWrite(MOTOR1, i);
    analogWrite(MOTOR2, i);
  }

}

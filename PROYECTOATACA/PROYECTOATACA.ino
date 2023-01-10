#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define LASER 1
#define BUZZER 2
int sensor = 4;


void setup() {
  pinMode(LASER,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(sensor,INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if(digitalRead(4)==HIGH){
    lcd.setCursor(1,1);
    lcd.print("ATACA");
    digitalWrite(BUZZER,HIGH);
    digitalWrite(LASER,HIGH);
  }
  else{
    lcd.setCursor(1,1);
    lcd.print("NO HAY PELIGRO");
    digitalWrite(BUZZER,LOW);
    digitalWrite(LASER,LOW);
  }
  
}

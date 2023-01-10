#include <LiquidCrystal_I2C.h>;
#include <analogWrite.h>;
LiquidCrystal_I2C lcd(0x27,16,2);
int MOTOR = 24;
int i;
void setup() {
  pinMode(MOTOR,OUTPUT);
  analogWrite(MOTOR,0);
  lcd.init();
  lcd.backlight();
}
void loop() {
  for(i=0; i<=255; i++){
    analogWrite(MOTOR,i);
    lcd.setCursor(0,0);
    lcd.write(i);
    delay(500);
  }
  for(i=255; i<=0; i--){
    analogWrite(MOTOR,i);
    lcd.setCursor(0,0);
    lcd.write(i);
    delay(500);
  }
}

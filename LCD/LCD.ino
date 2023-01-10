int D = 26; 
int A = 39; 
int ValueD; 
int ValueA; 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup ()
{
  pinMode (D, INPUT); 
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop ()
{
  ValueD = digitalRead(D) ; 
  if (ValueD == HIGH) 
  {
    lcd.setCursor(1,0);
    lcd.print ("Campo magnetico");
    delay(2000);
  }
  else
  {
    lcd.setCursor(1,0);
    lcd.print ("No campo magnetico");
    delay(2000);
  }  
  lcd.setCursor(0,0);
  ValueA = analogRead(A);
  lcd.print(ValueA); 
  delay(1000);
}

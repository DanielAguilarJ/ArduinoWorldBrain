int S;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte sonrisa[8] = {
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00010001,
    0b00010001,
    0b00001110,
    0b00000000,
  };
byte sad[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00001110,
  0b00010001,
  0b00010001,
  0b00000000,
};

void setup() {
  Serial.begin(9600);
  pinMode(36,INPUT);
 
  lcd.init();
  lcd.backlight(); 
 
  }

void loop() {  
  S = analogRead(36);
  if (S > 4000){
    
    lcd.createChar(0,sonrisa);
    lcd.setCursor(0,0);
    lcd.write((byte)0);
    delay(1000);
    
    
   
  }
  
  if (S < 4000 && S > 3500){
    lcd.setCursor(0,0);
    lcd.createChar(0,sad);
    lcd.write((byte)0);
    delay(1000);
    
  }

}

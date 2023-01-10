#include <LiquidCrystal_I2C.h>
#include <Wire.h>

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
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,sonrisa);
  lcd.setCursor(0,0);
  lcd.write((byte)0);
 }
void loop() {
  
}

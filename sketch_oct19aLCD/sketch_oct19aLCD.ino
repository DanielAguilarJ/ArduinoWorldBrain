#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD1(0x3F,20,4);
byte sonrisa[8]={
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
  LCD1.init();
  LCD1.backlight(); 
}

void loop() {
  LCD1.createChar(0,sonrisa);
  LCD1.setCursor(0,1);
  LCD1.write((byte)0);
  LCD1.setCursor(3,0);
  LCD1.print("Hola");
}

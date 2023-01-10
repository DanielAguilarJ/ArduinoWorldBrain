#include <time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,16,2);
int S;
int numUno, numDos, numTres;
byte carro[8] = {
  0b00000000,
  0b00010001,
  0b00001110,
  0b00001010,
  0b00001010,
  0b00001110,
  0b00010001,
  0b00000000,
};

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(S,INPUT);
  S = 0;
  S = analogRead(36);
  lcd.createChar(0,carro);
  srand((unsigned int)time(NULL));
}

void loop() {
  lcd.setCursor(7,1);
  lcd.write((byte)0);
  
  if(S>4000){
    lcd.setCursor(6,1);
    lcd.write((byte)0);
    lcd.setCursor(7,1);
    lcd.print(" ");
    delay(2000);
  } 
  if(S>100 && S<300){
    lcd.setCursor(8,1);
    lcd.write((byte)0);
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(6,1);
    lcd.print(" ");
    delay(2000);
  }
  
  numUno = rand()%10;
  lcd.setCursor(7,0);
  lcd.print(numUno);
  numDos = rand()%10;
  lcd.setCursor(3,0);
  lcd.print(numDos);
  numTres = rand()%10;
  lcd.setCursor(11,0);
  lcd.print(numTres);
  delay(5000);
  lcd.clear();
  delay(2000);
  Serial.println(S);
  delay(2000);
  
}

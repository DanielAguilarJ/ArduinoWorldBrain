#include <time.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int numero=0;
int numUno, numDos, numTres;
int i, j, k;
void setup() {
  srand((unsigned int)time(NULL));
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop() {
  numUno = rand()%20;
  lcd.setCursor(7,0);
  lcd.print(numUno);
  numDos = rand()%20;
  lcd.setCursor(3,0);
  lcd.print(numDos);
  numTres = rand()%20;
  lcd.setCursor(11,0);
  lcd.print(numTres);
  delay(3000);
  lcd.clear();
  delay(2000);  
}

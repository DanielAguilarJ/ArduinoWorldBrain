#include <DHT.h>

#define DHTPin 2
#define DHTTipo DHT11
DHT sensor(DHTPin, DHTTipo);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

float h;
float t;

void setup() {
  
  sensor.begin();
  h = sensor.readHumidity();
  t= sensor.readTemperature();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("OBTENIENDO DATOS...");
  delay(2000);
  lcd.clear();
}

void loop() {
 lcd.setCursor(0,0); 
 lcd.print("HUMEDAD: ");
 lcd.print(h);
 lcd.setCursor(0,1);
 lcd.print("TEMPERATURA:");
 lcd.print(t);
 lcd.print("°C");
 delay(5000);
 

}

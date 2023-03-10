
//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the LCD i2c screen
//This code is a modified version of the code provided in virtuabotixRTC library
//Refer to https://Surtrtech.com for more information
 
#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal_I2C.h>
 
#define I2C_ADDR 0x27 //LCD i2c stuff
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
 
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8
 
virtuabotixRTC myRTC(6, 7, 8); //If you change the wiring change the pins here also
 
 
void setup() {
 Serial.begin(9600);
 lcd.begin (16,2); //Initialize the LCD
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home ();
 myRTC.setDS1302Time(15, 31, 15, 5, 12, 1, 2018); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done as I did
 //The setup is done only one time and the module will continue counting it automatically
 
}
 
void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
}

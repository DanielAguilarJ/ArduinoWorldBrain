#include <virtuabotixRTC.h>
virtuabotixRTC CLOCK(6, 7, 8);
void setup() {
  Serial.begin(9600);
  CLOCK.setDS1302Time(0, 25,11,2,29,11,2022);

}

void loop() {
  CLOCK.updateTime();
  Serial.print("Fecha/Hora: ");
  Serial.print(CLOCK.dayofmonth);
  Serial.print("/");
  Serial.print(CLOCK.month);
  Serial.print("/");
  Serial.print(CLOCK.year);
  Serial.print(" ");
  Serial.print(CLOCK.hours);
  Serial.print(":");
  Serial.print(CLOCK.minutes);
  Serial.print(":");
  Serial.print(CLOCK.seconds);
  delay(1000);
 
}

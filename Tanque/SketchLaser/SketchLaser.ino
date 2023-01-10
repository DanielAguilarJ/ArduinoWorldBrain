#include <Servo.h>
Servo servoMotor;

void setup() { 
  Serial.begin(9600);
  servoMotor.attach(19);
}

void loop() {
  servoMotor.write(0);
  delay(2000);
  servoMotor.write(90);
  delay(2000);
  servoMotor.write(180);
  delay(2000);
}

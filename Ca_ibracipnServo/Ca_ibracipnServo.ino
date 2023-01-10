#include <Servo.h>
Servo myservo1;   // Create a servo object to control the servo
int pos = 0;
void setup() {
 myservo1.attach(9);   //attaches the servo object to PWM pin 9
}
void loop() {
 myservo1.write(pos);}


 //0
 //180

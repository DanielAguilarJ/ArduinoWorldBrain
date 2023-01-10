#include <Stepper.h>
#define STEPS 200
Stepper stepper(STEPS, 2,3,4,5);
void setup() {
  stepper.setSpeed(1000);
}

void loop() {
  stepper.step(200);
  delay(1000);
  stepper.step(-200);
  delay(1000);
}

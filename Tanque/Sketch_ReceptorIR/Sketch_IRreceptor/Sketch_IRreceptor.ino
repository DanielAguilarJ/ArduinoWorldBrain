#include   <IRremote.h>
const byte IR_RECEIVE_PIN = 34;
int value = IrReceiver.decodedIRData.command;
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  
  if (IrReceiver.decode()){
    Serial.println(value, DEC);
    IrReceiver.resume();
  }
}

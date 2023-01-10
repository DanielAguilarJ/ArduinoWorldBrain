#include <IRremote.h>
int SENSOR = 12;
IRrecv irrecv(SENSOR);
decode_results codigo;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&codigo)){
    Serial.println(codigo.value,HEX);
    irrecv.resume();
  }
  delay(100);
}
// Buton 1 FF807F
// Boton 2 FF40BF
// Boton 3 FFC03F

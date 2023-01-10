int RED = 9;
int GREEN = 6;
int valor;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  for (valor=100; valor>0; valor--){
    analogWrite(RED,valor);
    analogWrite(GREEN, 100 - valor);
    delay(500);
  }
  for (valor=0; valor<100; valor++){
    analogWrite(GREEN,valor);
    analogWrite(RED, 100 - valor);
    delay(500);
  }
}

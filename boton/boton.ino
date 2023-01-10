int BUTON = 25;
void setup() {
  pinMode(BUTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(BUTON));
  delay(2000);
  if (digitalRead(BUTON) == LOW){
    Serial.println("Presionado");
  }
  else{
    Serial.println("No presionado");
  }
  delay(2000);
}

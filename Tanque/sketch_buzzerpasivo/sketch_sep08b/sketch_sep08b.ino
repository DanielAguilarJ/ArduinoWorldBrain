int BUZZER = 17;
void setup() {
  pinMode(17,OUTPUT);
}

void loop() {
  for (int i = 0; i < 80; i++){
    digitalWrite(BUZZER,HIGH);
    delay(1);
    digitalWrite(BUZZER,LOW);
    delay(1);
  }
  delay(2000);
  for (int j = 0; j < 80; j++){
    digitalWrite(BUZZER,HIGH);
    delay(2);
    digitalWrite(BUZZER,LOW);
    delay(2);
  }
  delay(1000);
}

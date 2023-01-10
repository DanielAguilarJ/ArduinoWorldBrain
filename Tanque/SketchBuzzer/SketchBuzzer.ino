#define BUZZER 26;

void setup() {
  pinMode(26,OUTPUT);
  digitalWrite(26,LOW);
}

void loop() {
  digitalWrite(26,HIGH);
  delay(2000);
  digitalWrite(26,LOW);
  delay(3000);
}

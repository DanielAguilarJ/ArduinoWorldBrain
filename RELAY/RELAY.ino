int RELAY = 26;
void setup() {
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY,LOW);
}

void loop() {
  digitalWrite(RELAY,HIGH);
  delay(2000);
  digitalWrite(RELAY,LOW);
  delay(2000);
}

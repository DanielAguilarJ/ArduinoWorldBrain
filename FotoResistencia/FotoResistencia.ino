int fotoresistor = A0;
void setup() {
  Serial.begin(9600);
  pinMode(fotoresistor,INPUT);

}

void loop() {
  Serial.println(analogRead(fotoresistor));
  delay(1000);
}

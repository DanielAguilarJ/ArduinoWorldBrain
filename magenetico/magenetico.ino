int MAG;
void setup() {
  pinMode(MAG,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(39));
  delay(2000);
}

int Joy;

void setup() {
  Joy = 0;
  Serial.begin(9600);
  pinMode(36,INPUT);
}
void loop() {
  Joy = analogRead(39);
  Serial.println(Joy);
  delay(2000);
}

int SENSOR = A0;

void setup() {
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(SENSOR));
  delay(1000);

}

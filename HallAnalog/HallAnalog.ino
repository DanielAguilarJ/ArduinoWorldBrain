int SENSOR;
void setup() {
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(39));
  delay(2000); 
}

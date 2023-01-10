int SENSOR = 34;

void setup() {
  Serial.begin(9600);
  pinMode(34,INPUT);
}

void loop() {
  int value = 0;
  value = digitalRead(34);
  if (value == LOW)
  {
    Serial.println("Obstaculo cerca");
    
  }
  delay(2000);
}

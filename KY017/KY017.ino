int SENSOR = 2;
int inclinacion;
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR,INPUT);
  inclinacion=digitalRead(SENSOR);
}

void loop() {
  Serial.println(inclinacion);
  delay(500);
}

//LEER LAS LECTURAS DEL SENSOR
int SensorAgua;
void setup() {
  Serial.begin(9600);
}

void loop() {
  SensorAgua= analogRead(A0);
  Serial.println(SensorAgua);
  delay(1000);
}

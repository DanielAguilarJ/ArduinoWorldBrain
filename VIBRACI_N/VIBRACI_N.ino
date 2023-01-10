int SENSOR = 13;
int LED = 4;
int valor;
void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);
  Serial.begin(9600);
}

void loop() {
  valor = digitalRead(SENSOR);
  if (valor == LOW){
    digitalWrite(LED,HIGH);
    delay(500);
  }
  digitalWrite(LED,LOW);
  Serial.println(digitalRead(SENSOR));
  delay(1000);
}

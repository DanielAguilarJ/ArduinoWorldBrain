int pin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  digitalWrite(pin, HIGH);
  Serial.println("Encendido");
  delay (10000);
  digitalWrite(pin, LOW);
  Serial.println("Apagado");
  delay (1000);
}

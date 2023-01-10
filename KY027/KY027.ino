int SENSOR = 2;
int LED = 3;
int inclinacion;
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
 inclinacion = digitalRead(SENSOR);
 Serial.println(inclinacion);
 delay(1000);
 if (inclinacion == 1){
  digitalWrite(LED,HIGH);
 }
 else {
  digitalWrite(LED,LOW);
 }

}

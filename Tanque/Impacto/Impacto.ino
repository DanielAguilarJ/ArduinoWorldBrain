int SENSOR = 34;
int value;
void setup() {
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);
  value = digitalRead(SENSOR);
}

void loop() {
  
  if (value == HIGH){
    Serial.print("CHOQUE");
  }
 delay(2000);
}

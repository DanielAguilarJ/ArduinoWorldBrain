int MOTOR = 34;
int i;
void setup() {
  pinMode(MOTOR,OUTPUT);
  analogWrite(MOTOR,0);
  Serial.begin(9600);
}
void loop() {
  for(i=0; i<=255; i++){
    analogWrite(MOTOR,i);
    Serial.println(i);
    delay(500);
  }
  for(i=255; i<=0; i--){
    analogWrite(MOTOR,i);
    Serial.println(i);
    delay(500);
  }
  
}

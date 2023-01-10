int RED = 6;
int GREEN = 9;
int SENSOR = 2;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(SENSOR)==HIGH){
    analogWrite(RED,255);
    analogWrite(GREEN,0);
  }
  else{
    analogWrite(RED,0);
    analogWrite(GREEN,255);
  }
  delay(1);
  Serial.println(digitalRead(SENSOR));
  delay(1000);

}

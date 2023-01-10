int RED = 14;
int GREEN = 17;
int BLUE = 25;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
}

void loop() {
  digitalWrite(RED,HIGH);
  delay(1000);
  digitalWrite(RED,LOW);
  delay(1000);
  digitalWrite(GREEN,HIGH);
  delay(1000);
  digitalWrite(GREEN,LOW);
  delay(1000);
  digitalWrite(BLUE,HIGH);
  delay(1000);
  digitalWrite(BLUE,LOW);
  delay(1000);
}

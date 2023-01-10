int LED = 10;
int A = 12;
int D = 13;
int ValorA;
int ValorD;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(D,INPUT);
  Serial.begin(9600);
}

void loop() {
  ValorA = analogRead(A);
  ValorD = digitalRead(D);
  Serial.println(ValorA);
  delay(2000);
  while(ValorD == HIGH){
    digitalWrite(LED,HIGH);
  }
  Serial.println(ValorD);
  delay(1000);
  
}

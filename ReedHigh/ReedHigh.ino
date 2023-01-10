int D = 26;
int A = 25;

int ValorD;
int ValorA;


void setup() {
  
  pinMode(D,INPUT);
 
  Serial.begin(9600);
  ValorD = digitalRead(D);
  
  ValorA = analogRead(A);
}



void loop() {
  
  if (D == LOW){
    Serial.println("CAMPO MAGNETICO DETECTADO");
    
  }
  Serial.println(ValorA);
  delay(2000);
}

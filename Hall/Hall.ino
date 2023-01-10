int D = 26; 
int A = 39; 
int ValueD; 
int ValueA; 
void setup ()
{
  pinMode (D, INPUT); 
  Serial.begin(9600);
}
void loop ()
{
  ValueD = digitalRead(D) ; 
  if (ValueD == HIGH) 
  {
    Serial.println ("Campo magnetico");
  }
  else
  {
    Serial.println ("0");
  }  
  ValueA = analogRead(A);
  Serial.println(ValueA); 
  delay(1000);
}

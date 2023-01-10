int LASER = 25; 
int ky20 = 26;
int inclina; 
void setup() {     
pinMode(LASER,OUTPUT); 
pinMode(ky20, INPUT);     
}
void loop() 
{
  inclina = digitalRead(ky20);                          
if (inclina == HIGH) {
digitalWrite(LASER, HIGH);
}
else{
digitalWrite(LASER, LOW);
}
}   

#define E 13
#define T 12
#define LASER 13;
void setup() {
  pinMode(E,INPUT);
  pinMode(T,OUTPUT);
  digitalWrite(T,LOW);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  long t;
  long d;
  t = pulseIn(E,HIGH);
  d = t/58;
  digitalWrite(T,HIGH);
  delay(2000);
  digitalWrite(T,LOW);
  if(d<10){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}

#define sonido 2
#define analogSonido A5
#define relay 4
int valor=0;

void setup() {
 pinMode(sonido,INPUT);
 pinMode(relay,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  if (digitalRead(sonido)==HIGH){
    digitalWrite(relay,HIGH);
    valor= valor +1;
  }
  if (valor==2){
    digitalWrite(relay,LOW);
    valor=0;
  }
 Serial.println(digitalRead(sonido));
 delay(1000);
 Serial.println(analogRead(analogSonido));
 delay(500);
}

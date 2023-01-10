int D = 39;
int valor;


void setup() {
  pinMode(D,INPUT);
  Serial.begin(9600);
}


void loop() {
  valor = digitalRead(D);
  if (valor == HIGH){
    Serial.println("Obstaculo");
    delay(1000);
  }
 else {
  Serial.println("LIBRE");
  delay(1000);
 }
 
 Serial.println(valor);
 delay(1000);
 
}

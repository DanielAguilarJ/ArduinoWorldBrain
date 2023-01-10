int LedRed = 10;
int LedGreen = 9;
int SENSOR = A0;
int valor;

float R1= 10000;
float logR2, R2, TK, TC;
float A= 0.001129148, B= 0.000234125, C=0.0000000876741;
void setup() {
  Serial.begin(9600);
  pinMode (LedRed, OUTPUT);
  pinMode (LedGreen, OUTPUT);
}

void loop() {
  valor = analogRead(SENSOR);
  Serial.print("Valor analógico: ");
  Serial.print(valor);
  valor = map (valor, 0, 650, -55, 125);
  //Conversión de valores analogicos a C
  R2 = R1 * (1023.0/(float)valor-1.0);
  logR2 =log (R2);
  TK= (1.0/ (A+B* logR2 + C *logR2* logR2 * logR2));
  TC= TK-273.15;
  TC = TC *(-1);
  Serial.print("Temperatura es: ");
  Serial.println(TC);
  delay(5000);

  digitalWrite(LedRed,LOW);
  digitalWrite(LedGreen,LOW);
  if(TC >= 23){
    digitalWrite(LedRed,HIGH);
  }
  else {
    digitalWrite(LedGreen,HIGH);
  }
  
  
 

}

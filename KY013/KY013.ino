int LedRed = 10;
int LedGreen = 9;
int SENSOR = A0;
int valor;

//Variables para la ecuación
float R1 = 10000;
// Valor de R1 de la PCB 10k
float logR2, R2, TK, TC;
float A= 0.001129148, B= 0.000234125, C=0.0000000876741;
// Valores constantes considerando NTC de 10K y trabajando a una temp de entre -55°C a +125°C 
void setup() {
  Serial.begin(9600);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  valor = analogRead(SENSOR);
}

void loop() {
  Serial.print("VALOR ANALOGICO: ");
  Serial.print(analogRead(SENSOR));
/* Map necesita 5 elementos:
 *  valor: el numero a mapear (lectura del sensor)
 *  0: el limite inferior del valor leído por el sensor
 *  teniendo en cuenta que va de 0 a 1023
 *  270: el limite superior del valor leido por el sensor, 
 *  este puede variar dependiendo el transmisor
 *  0: el limite inferior de temperatura
 *  50: el limite superior de la temperatura
 */
  valor = map (valor, 0, 270, 0, 50);
  R2 = R1 * (1023.0/ (float)valor - 1.0); //Calcula resistencia del transmisor
  logR2 = log(R2); //Calculo del logaritmo de la resistencia del termisor
  TK = (1.0/ (A+B*logR2 + C*logR2 * logR2 * logR2)); //Temp en K
  TC = TK -273.15;
  TC=TC*(-1);
  Serial.print("La temperatura es: ");
  Serial.println(TK);
  delay(5000);
  digitalWrite(LedRed, LOW);
  digitalWrite(LedGreen,LOW);
  if (TC >= 22){
    digitalWrite(LedRed,HIGH);
  }
  else {
    digitalWrite(LedGreen,HIGH);
    }
  

}

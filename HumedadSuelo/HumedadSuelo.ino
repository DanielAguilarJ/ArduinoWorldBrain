1
2
3
4
5
6
7
8
9
int SensorPin = A0;
 void setup() {
   Serial.begin(9600);
 }
 void loop() {  
   int humedad = analogRead(SensorPin);
   Serial.println(humedad);
   delay(1000);
 }

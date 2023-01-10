#include <DHT.h>
#define DHTPin  2
#define DHTTipo DHT11
DHT sensor(DHTPin, DHTTipo);

float h;
float t;

void setup() {
  Serial.begin(9600);
  sensor.begin();
  h = sensor.readHumidity();
  //La T se lee en grados centigrados
  t = sensor.readTemperature();
}

void loop() {
  Serial.print("Humedad: ");
  Serial.println(h);
  Serial.print("Temperatura: ");
  Serial.println(t);
  delay(5000);
}

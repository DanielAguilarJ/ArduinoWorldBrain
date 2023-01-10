#include <OneWire.h>
/*OneWire es un sistema con el que se consigue enviar y recibir datos
 *por un unico cable 
 */
#include <DallasTemperature.h>
/*Librería que facilita la lectura de la temperatura (análogo
 * a digital). Se usa con conjunto con OneWire. 
 */
#define SENSOR_PIN 2
OneWire oneWire(SENSOR_PIN);
//Conexion oneWire para comunicarnos con el protocolo
DallasTemperature celsius(&oneWire);
//Se anuncia al sensor que se realizara la comunicación usando
//OneWire
float temp;
//variable que guarda los datos leídos de celsius
void setup() {
 celsius.begin();
 //Iniciamos la comunicación del OneWire con celsius
 Serial.begin(9600);

}

void loop() {
  Serial.println("CARGANDO...");
  celsius.requestTemperatures();
  //Permite obtener datos del sensor en variable "celsius"
  Serial.println("CONFIGURANDO...");
  delay(3000);
  Serial.println("La temperatura es: ");
  Serial.print(celsius.getTempCByIndex(0));
  Serial.println("°C");
  delay(1000);
}

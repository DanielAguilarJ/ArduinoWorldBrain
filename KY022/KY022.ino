
/*Con esta librería se puede realizar la programación para 
 * enviar y recibir códigos en diversos protocolos como: 
 * NEC
 * Sony SIRC
 * Philips RC5 Y RC6
 * Protocolos sin formato
 * En este sketch se utilizarán los comando para enviar datos
 * bajo el protocolo NEC, que tiene las siguientes características
 * Longitud de 8 bits de direccipon y 8 bits de comando
 * Tanto la dirección como el comando son enviados dos veces
 * a modo de CRC
 * La primera vez los bits originales y la segunda los mismos
 * pero negados. 
 * Los pulsos son por modulación de amplitud
 * La frecuencia portada es de 38kHz
 * La longitud de un bit "0" es de 1.12ms y la de un "1" es de
 * 2.25ms.
 * En total se transmiten un bit de Start de 9ms+4.5ms=13.5
 * mas 32 bits de datos. 
 */
#include <IRremote.h>
IRsend irsend; //Se trasmiten paquetes remotos
int sensor = 11;
int valor;
void setup() {
  Serial.begin (9600);
  pinMode(sensor,OUTPUT);
  valor = digitalRead(sensor);
}

void loop() {
  if (valor ==HIGH){
    irsend.sendNEC(0x000000,32);
    Serial.println("send");
    delay(100);
  }
  

}

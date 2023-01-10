/* La librería interpreta los códigos que lleguen y nos dará
una salida hexadecimal.
*/

#include <IRremote.h>
int RECEPTOR = 12;
IRrecv irrecv (RECEPTOR);
decode_results resultado; //decodifica codigos
//LIBRERIA Y ARGUMENTOS PARA MATRIZ LEDS
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR1RR0_HW
#define CLK_PIN 4
#define DATA_PIN 2
#define CS_PIN 3
#define NUM_OF_MATRIX 3
MD_MAX72XX matriz = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, NUM_OF_MATRIX);

void translateIR(){
  switch(resultado.value){
    case 0xFF807F: Serial.println ("BOTON 1");
    //prende los LEDS necesarios de acuerdo al numero
    matriz.setRow(1,4,B11111110);
    matriz.setRow(1,3,B00000100);
    matriz.setRow(1,5,B00000100);
    break;
    case 0xFF40BF: Serial.println("BOTON 2");
    matriz.setRow(2,4,B11111110);
    matriz.setRow(2,3,B00000100);
    matriz.setRow(2,5,B00000100);
    break;
    case 0xFFC03F: Serial.println("BOTON 3");
    matriz.setRow(0,4,B11111110);
    matriz.setRow(0,3,B00000100);
    matriz.setRow(0,5,B00000100);
    break;
    
  }
}
//Se debe informar a la librería en donde esta conectado el receptor IR

//variable que guarda el codigo recibido

void setup() {
  Serial.begin(9600);
  //Se informa a la librería que empiece a recibir codigos
  irrecv.enableIRIn();
  Serial.println("INICIANDO PROCESO");
 //Funciones para matriz LEDS
  matriz.begin();
  matriz.control(MD_MAX72XX::UPDATE, false);

}

void loop() {
  
  if (irrecv.decode(&resultado)){
    translateIR(); 
 
      //Reinicia la libreria para recibir nuevos codigos
   irrecv.resume();
  }
  delay(1); //le da estabilidad al programa
  matriz.update();
}

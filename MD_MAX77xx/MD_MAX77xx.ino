//Se incluye la librería
#include <MD_MAX72xx.h>
/*Se declaran las constantes, que son los pines a donde se
 * conectan los puertos y el tipo de HARDWARE, poner este
 */
#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW
#define CLK_PIN 4
#define DATA_PIN 2
#define CS_PIN 3
//Se define el número de matrices utilizadas. 
#define NUM_OF_MATRIX 1
/*Se declará el tipo de objeto utilizando los valores de las
constantes previamente definidas.
*/
MD_MAX72XX matriz = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, NUM_OF_MATRIX);
/* Se utilizan dos variables tipo string
 *  mensaje= donde se almacena el mensaje a mostrar
 *  proximo_mensaje=utilizada como almacenamiento temporal cuando se actualiza el mensaje
 *  desde el puerto serie
 */

void setup() {
//Inicializar el objeto mx
matriz.begin();
//Establecer intencidad a un valor de 5
matriz.control(MD_MAX72XX::INTENSITY,5);
//Comprueba si sirven todos los leds
matriz.control(MD_MAX72XX::TEST,true);
//Desactivar auto-actualización
matriz.control(MD_MAX72XX::UPDATE, false);

}

void loop() {
  
  /* printText():Imprime un texto en las matrices comenzando en la columna indicada
   * slide_text():Muestra el valor de la variable global mensaje desplazandose por la matriz de izquierda a derech
   * actualizar_mensaje():Comprueba el puerto serie y si existe algún mensaje nuevo actualiza el valor de la variable mensaje
   */
//Encender un LED indicando su fila y columna
matriz.setPoint(3, 2, true);
delay(100);
matriz.setRow(0,7,B1111111);
delay(100);

  //Actualiza el contenido de la pantalla
matriz.update();
  
}

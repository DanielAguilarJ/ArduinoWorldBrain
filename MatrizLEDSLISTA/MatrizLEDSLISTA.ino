#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::DR0CR1RR0_HW
#define CLK_PIN 4
#define DATA_PIN 2
#define CS_PIN 3
#define NUM_OF_MATRIX 3
MD_MAX72XX matriz = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, NUM_OF_MATRIX);
void setup() {
matriz.begin();
matriz.control(MD_MAX72XX::UPDATE, false);


}

void loop() {
matriz.setRow(1,4,B11111110);
matriz.setRow(1,3,B00000100);
matriz.setRow(1,5,B00000100);


matriz.setRow(2,4,B11111110);
matriz.setRow(2,3,B00000100);
matriz.setRow(2,5,B00000100);

matriz.setPoint(3,3,true);
matriz.setPoint(2,2,true);
matriz.setPoint(3,1,true);
matriz.setPoint(4,2,true);
matriz.setPoint(3,2,true);
matriz.setPoint(3,4,true);
matriz.setPoint(3,5,true);
matriz.setPoint(3,6,true);
matriz.setPoint(3,7,true);
matriz.update();
}

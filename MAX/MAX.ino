#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX;
#define DIN_PIN 12
#define CS_PIN 13
#define CLK_PIN 14
#define HOLA
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup() {
  M.begin();
  
}

void loop() {
  
}

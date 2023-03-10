
#include <Keyboard.h>
#include <Joystick.h>

Joystick joystick(9,10,11);

void setup() {
  // Initialize Button Pins
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  // Initialize Joystick Library
  joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 9;

// Last state of the button
int lastButtonState[4] = {0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      if (index < 2) {
        joystick.setButton(index, currentButtonState);
        lastButtonState[index] = currentButtonState;
      } else {
        if (currentButtonState) {
          Keyboard.write(47 + index);
          delay(500);
        }
      }
    }
  }

  delay(100);
}

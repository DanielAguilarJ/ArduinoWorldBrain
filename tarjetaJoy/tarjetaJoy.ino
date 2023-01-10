int botonA = 25;
int boton2;
int boton3;
int boton4;
int JoystickX;
int JoystickY;
void setup() {
  pinMode(botonA,INPUT);
  Serial.begin(9600);
}

void loop() {
 Serial.print(digitalRead(botonA));
 delay(1000);

}

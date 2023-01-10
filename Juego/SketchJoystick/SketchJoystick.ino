int JoyX = 36;
int JoyY = 34;
int BUTTON = 25;
int ValueX = 0;
int ValueY = 0;
bool valueButton = false;

void setup() {
  pinMode(25,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  ValueX = analogRead(JoyX);
  delay(1000);
  ValueY = analogRead(JoyY);
  valueButton = digitalRead(BUTTON);
  Serial.print("X: ");
  Serial.println(ValueX);
  Serial.print("Y: ");
  Serial.println(ValueY);
  Serial.print("BUTTON: ");
  Serial.println(valueButton);
  delay(3000);
}

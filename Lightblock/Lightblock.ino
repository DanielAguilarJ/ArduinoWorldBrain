int Block = 2;



void setup() {
  pinMode(Block,INPUT);
  Serial.begin(9600);
}


void loop() {
  if(digitalRead(Block) ==HIGH){
    Serial.println("Bloqueado");
  }
  else{
    Serial.println("libre");
  }
  delay(2000);
}

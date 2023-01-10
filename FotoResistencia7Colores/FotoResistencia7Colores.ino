int ky18 = 2;             //Define Pin2 Analógico para la entrada de datos analógicos del KY-018
int LedR = 11;            //Define PWM P11 para Led Rojo (R)
int LedV = 10;            //Define PWM P10 para Led Verde (G)
int LedA = 9;             //Define PWM P9 para Led Azul (B)
int valor ;               //La variable VALOR, almacenará los datos de KY018 
int luz ;                 //La variable LUZ, almacenará los valores que tendrán los led (0-255)

void setup() {
Serial.begin(9600);        //Iniciamos puerto serial a 9600 baud
pinMode(ky18, INPUT);      //Declaramos a ky18 como pin de entrada
pinMode(LedR, OUTPUT);     //Declaramos a Led Rojo como pin de salida
pinMode(LedA, OUTPUT);     //Declaramos a Led Azul como pin de salida
pinMode(LedV, OUTPUT);     //Declaramos a Led Verde como pin de salida
}

void loop()
{
analogWrite (LedR, 0 );             //Siempre al iniciar la rutina los valores del Led RGB se reiniciaran
analogWrite (LedV, 0);              //Recordando que los valores para cada Led va desde 0 a 255, 0 MENOR intensidad
analogWrite (LedA, 0);              //255 MAYOR intensidad de luz en el led correspondiente
valor = analogRead(ky18);             //Se guarda en la variable valor , los datos de la foto resistencia
Serial.println(valor, DEC);           // Intensidad de Luz, Valores Altos=Obscuridad Valores Bajos==Iluminación Alta

luz = map(valor, 4, 1018, 0, 255);   //Se usara la función map para que asigne valores a LUZ dependiendo el barrido de datos
                                     //que arroje el foto resistor.
Serial.print("luz");                 //Se imprime mensaje de LUZ y 
Serial.println(luz);                 //..el valor registrado por la función map
analogWrite (LedR, luz );           //Los valores que tendrá el LED Rojo serán variables a la información que se obtenga de LUZ
analogWrite (LedV, luz);            //Lo mismo para el Led Verde y Azul, lo cual puede ser configurable a tener una mezcla del RGB
analogWrite (LedA, luz);

delay(500);                          // El proceso durara medio segundo
  
} 

 
#define outCLK 2       //Salida A del codificador un valor constante definido antes de compilar el programa
#define outDT 3        //Salida B del codificador un 
#define boton 4     //Salida del SW/Swich Pulsador del Encoder 
  
int paso = 0;      //Variable entera para realizar el conteo de avance del Encoder
int edoCLK;        //Variable de posición del CLK/A/Pin 2 
int anteriorCLK;   //Variable que guardara el estado anterior de la entrada CLK/A/Pin 2

void setup() { 
  
   Serial.begin (9600);                    //Inicia Puerto Serial a 9600 baudios
   pinMode (outCLK,INPUT);                 // Pin de entrada CLK/A/Pin 2 Arduino
   pinMode (outDT,INPUT);                  // Pin de entrada DT/B/Pin 3 Arduino                             
   pinMode (boton, INPUT_PULLUP);          // El SW/Swich Pulsador del Encoder será entrada con la resistencia Pull-up interna habilitada
   anteriorCLK= digitalRead(outCLK);       // Siempre se leerá el valor de CLK/A/Pin 2 Arduino y se guarda la información en la variable anteriorCLK
 } 

void loop() 
 {
   edoCLK = digitalRead(outCLK);             // Lee el estado de la salida CLK/A/Pin 2 Arduino y se guarda en estadoCLK para tener un valor actualizado
   
   if (edoCLK != anteriorCLK){               // Si el estado previo y el valor actualizado son diferentes, entonces existe un pulso   
     if (digitalRead(outDT) != edoCLK) {     // Si el estado de salidaDT/B/Pin 3 es diferente del estado de salidaCLK/A/Pin 2 el codificador esta girando a la derecha
       paso --;                              //por lo tanto se avanzara un paso en el Encoder
     } else {                                // de lo contrario
       paso ++;                              // se estará girando de lado izquierdo y se retrocederá el paso del Encoder 
     }
     Serial.print("Ubicación: ");            //Se visualizara en el monitor serial la impresión del mensaje que nos dará la posición del ENCODER
     Serial.println(paso); 
   }
   anteriorCLK = edoCLK;                    //actualizaremos el valor anterior

bool Bot = digitalRead(boton);                         //Se compara que el valor obtenido de "boton" que sea diferente de cero
   if (!Bot)                                           // si se pulsa el botón su valor va a BAJO
    { 
      Serial.println("Botón pulsado: Reinicia a 0");   //Se mandara un mensaje en donde se dará aviso que el conteo de pasos se reiniciara
      paso = 0 ;                                      //Se actualiza el valor de paso a 0 
      delay(300);                                     //Se espera .3 segundos para continuar
    }
 
}

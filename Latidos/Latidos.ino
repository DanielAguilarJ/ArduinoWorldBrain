int ky039 = A0;               //Variable entera para la señal del KY039
int latido = 0;               //Variable para almacenar el número de latidos por ciclo
int rangoT;                    //Variable que almacenará los valores recibidos por KY039
int lateMin = 300;            //Constante para calculo del numero de latidos por minuto mínimos

double factor = 0.75;         //Constante para Filtro Paso Bajas
double minval = 0.0;          //Variable para almacenar el valor Mínimo de onda de la señal filtrada
double VFiltrado;             //Variable que recibirá el resultado del calculo del filtro paso bajas
double cambio;                //Variable que tiene la diferencia entre el valor filtrado y anterior

float antes = 512;            //Valor de referencia (mitad de 1023),para el Valor Filtrado Anterior An-1
float maxval = 0.0;           //Variable para almacenar el valor Máximo de onda de la señal filtrada

void setup ()
{
  Serial.begin (9600);      //Inicialización de puerto serial a 9600 bd
}


void loop ()
{
  static unsigned long LPMtime = millis();  //Retorno de # de ms desde que se enciende el Arduino a la variable LMPtime para el calculo de los latidos p/minuto
  static unsigned long LPMQR = millis();    //Retorno de # de ms a la variable LPMQR que servirá para saber el tiempo entre latidos del corazón
  rangoT = analogRead (ky039);              //Se almacenan los valores brutos provenientes del sensor KY-039 (0 a 1023)

  //Acondicionamiento de la señal por medio de un filtro paso bajas (EMA)
  VFiltrado = factor * antes + (1 - factor) * rangoT;         //Expresión para el Filtro paso bajo (EMA)
  cambio = VFiltrado - antes;                                //Diferencia para obtener el valor transcurrido
  antes = VFiltrado;                                         //El valor anterior queda actualizado con la información del valor filtrado
    
  //Condición para poder descartar valores fuera de los latidos "normales" en un tiempo de 300 ms
  //Condición doble: si la diferencia obtenida es mayor al valor máximo y el tiempo millis es mayor que el valor de tiempo ENTRE LATIDOS mas el Valor Mínimo entonces..
 
  if ((cambio >= maxval) && (millis() > LPMQR + minval)) {         //En caso de ser afirmativa la condición...
    maxval = cambio;                                                //se actualiza el valor máximo por el resultado de la diferencia entre valor filtrado y valor anterior
    digitalWrite(13, HIGH);                                         //se encenderá el LED de la placa para confirmar que se esta tomando una lectura dentro de estos rangos
    LPMQR = millis();                                               //se carga a la variable ENTRE LATIDOS el valor actualizado de millis
    latido++;                                                       //incremento de la cuenta de latidos
  }
  else {
    digitalWrite(13, LOW);                                           //si la condición es negativa no encenderá el Led de la Placa
     }
  
  maxval = maxval * 0.97;                            //el valor máximo de la señal se multiplica por 0.97 para que tenga un 3% de decaimiento la señal
 
  //Condición para conteo de latidos del corazón
  if (millis() >= LPMtime + 15000) {        //nuevamente compara el tiempo transcurrido sea mayor a 15s
    int L= latido*4;                        //Caso afirmativo, se multiplicara los latidos por 4 para tener un resultado a los 60s
    
    Serial.print ("Latidos Por Minuto:");                  //Imprime el valor procesado del sensor KY-039
    Serial.println(L); 
              
    latido = 0;                             //Reinicia el valor del contador de latidos
    LPMtime = millis();                     //Actualiza el valor de tiempo de Latidos p/minuto 
    }

  delay(50);                                //con este tiempo actualizamos las funciones para que nuevamente se repita el ciclo
}

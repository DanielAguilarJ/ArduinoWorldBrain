/*
Author: Danny van den brande, Arduinosensors.nl. BlueCore Tech.
In this example we use the KY-036 Touch sensor to turn on a led and buzzer.
 */
int GreenLed = 5;
int BlueLed = 6;
int Buzzer = 7;
int TouchSensor = 3; 
int val;

void setup ()
{
pinMode (GreenLed, OUTPUT);
pinMode (BlueLed, OUTPUT);
pinMode (Buzzer, OUTPUT);
pinMode (TouchSensor, INPUT);
}
void loop ()
{
val = digitalRead (TouchSensor) ;
if (val == HIGH) 
{
digitalWrite (BlueLed, HIGH);
digitalWrite (GreenLed, LOW);
digitalWrite (Buzzer, HIGH);
}
else
{
digitalWrite (BlueLed, LOW);
digitalWrite (GreenLed, HIGH);
digitalWrite (Buzzer, LOW);
}
}

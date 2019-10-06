//Anyi Paola Leon Riscanevo
//Detectar Sombra

#define pEcho 3
#define pTrrig 4

const int LEDPin = 13;
const int LDRPin = A0;
long duracion;
int luz = 0;       
int vSensor = 0;       
int vLimite = 500;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode(pTrrig, OUTPUT);
  pinMode(13, 1);
  pinMode(LEDPin, INPUT);
  pinMode (LDRPin, OUTPUT);
 
}

void loop() {
  
  duracion = pulseIn(pEcho, HIGH);
  vSensor = analogRead(LDRPin); 
  luz = (5 * vSensor * 100)/1024;
  Serial.print(luz);  
  Serial.println(" Luz");             
  
  if (luz <= vLimite)
  {
    digitalWrite (LEDPin, LOW);
    delay(5000);
    Serial.print(duracion);
    digitalWrite (13, 1);
  }
  if (luz > vLimite)   
  {
    digitalWrite (LEDPin, HIGH);
  }
}

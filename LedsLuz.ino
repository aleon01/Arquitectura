//Anyi Paola Leon Riscanevo
//Luz por Leds

#define pTrrig 4
#define pEcho 3

const int LDRPin = A0;
int Led1 = 11;
int Led2 = 10;
int Led3 = 9;
int i,j,k;
int vSensor = 0;       
int vLimite = 500;
int luz = 0;     

  void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode (pTrrig, OUTPUT);
  pinMode (LDRPin, OUTPUT);
  analogWrite(Led1,OUTPUT);
  analogWrite(Led2,OUTPUT);
  analogWrite(Led3,OUTPUT);
  
}


void loop() {

  vSensor = analogRead(LDRPin); 
  luz = (5 * vSensor * 100)/1024;
  Serial.print(luz);  
  Serial.println(" Luz");             
  delay(300);                       
  
  i = Led1;
  j = Led2;
  k = Led3;
  
  if (luz <= vLimite)
    {
      //Led Numero 1
      for  (i=1; i<255; i++){
        analogWrite(Led1,i);
        delay(1000);
      }
      //Led Numero 2
      for  (j=1; j<255; j++){
        analogWrite(Led2,j);
        delay(1000);
      }
      //Led Numero 3
      for  (k=1; k<255; k++){
        analogWrite(Led3,k);
        delay(1000);
      } 
    }

  if (luz > vLimite)
    {
      //Led Numero 1
      for  (i=255; i>0; i--){
          analogWrite(Led1,i);
          delay(1000);
      }
      //Led Numero 2
      for  (j=255; j>0; j--){
          analogWrite(Led2,j);
          delay(1000);
      }
      //Led Numero 3
      for  (k=255; k>0; k--){
          analogWrite(Led3,k);
          delay(1000);
      }
    }
}

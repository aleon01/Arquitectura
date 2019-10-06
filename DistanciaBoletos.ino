//compra de boletos, despues de acercarce a cierta distancia
//Anyi Paola Leon Riscanevo

#define pTrrig 4
#define DEBUG(a) Serial.println(a);
#define pEcho 3

long distancia, contador, duracion;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode(pTrrig, OUTPUT);
  pinMode(13, 1);
}

void loop() {
  digitalWrite(pTrrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrrig, LOW);

  duracion = pulseIn(pEcho, HIGH);  
  distancia = (duracion/2)/29;
  delay(1000);

  if(distancia >= 200 || distancia <= 0){
    if (Serial.available())
   {
      char data = Serial.read();
 
      if (data >= '0' && data <= '9')
      {
         data -= '0';
         DEBUG((int)data);
      }
   }
  }
  
}


 

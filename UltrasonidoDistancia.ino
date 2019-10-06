#define pEcho 3
#define pTrrig 4

long duracion, distancia;

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

  if(distancia >= 500 || distancia <= 0){
    Serial.println("-------");
  }else{
     Serial.print(distancia);
     Serial.println("cm");
     digitalWrite(13, 0);
  }
  if(distancia <=10 && distancia >=1){
    digitalWrite(13, 1);
    Serial.println("Sonido");
  }
  delay(400);
}

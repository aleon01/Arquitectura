//Anyi Paola Leon Riscanevo
//Valor Luminica
#define pTrrig 4
#define pEcho 3

const int LEDPin = 13;
const int LDRPin = A0;
const int threshold = 100;
long duracion;

int valor;

void setup() {
  Serial.begin(9600);
  pinMode(pEcho, INPUT);
  pinMode(pTrrig, OUTPUT);
  pinMode(13, 1);
  pinMode(LEDPin, INPUT);
  pinMode (LDRPin, OUTPUT);
}  

void loop() {
  digitalWrite(pTrrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrrig, LOW);

  duracion = pulseIn(pEcho, HIGH);
  valor = analogRead(LDRPin);
  
  Serial.println(valor); 
  delay(50); 
  
  if (valor > threshold) {
    digitalWrite(LEDPin, HIGH);
    Serial.print(duracion);
    digitalWrite (13, 1);  
  } else {
    digitalWrite(LEDPin, LOW);  
    Serial.print(duracion);
    digitalWrite (13, 1);
  }
}

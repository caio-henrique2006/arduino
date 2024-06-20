#include <Ultrasonic.h>
#define indicadorVermelho 4
#define indicadorAmarelo 3
#define indicadorVerde 2
#define bip A0
int distancia;
unsigned long currentMillis = 0;
unsigned long prevMillis = 0; 
unsigned period;
bool bipHappen = true;

Ultrasonic ultrassom(9, 8);

void setup() {
  Serial.begin(9600);
  pinMode(indicadorVermelho, OUTPUT);
  pinMode(indicadorAmarelo, OUTPUT);
  pinMode(indicadorVerde, OUTPUT);
  pinMode(bip, OUTPUT);
  double timePast = 0;
}

void loop() {

  distancia = ultrassom.Ranging(CM); // Pega a distância atual no ultrassônico

  // currentMillis = millis();
  // if(bipHappen) {
  //   prevMillis = currentMillis;
  //   tone(bip, 600);
  //   bipHappen = false;
  // }

  // if(currentMillis - prevMillis >= distancia*10){
  //   noTone(bip);
  //   bipHappen = true;
  // } 

  Serial.println(distancia);
  if(distancia <= 10) { // Abaixo de tal valor LED vermelha acende
    digitalWrite(indicadorVerde, LOW);
    digitalWrite(indicadorAmarelo, LOW);
    digitalWrite(indicadorVermelho, HIGH);
    tone(bip, 900);
  } else if (distancia <= 20) { // Abaixo de tal valor LED Amarela acende
    digitalWrite(indicadorVerde, LOW);
    digitalWrite(indicadorAmarelo, HIGH);
    digitalWrite(indicadorVermelho, LOW);
    tone(bip, 600);
  } else { // Acima do último valor LED verde acende
    digitalWrite(indicadorVerde, HIGH);
    digitalWrite(indicadorAmarelo, LOW);
    digitalWrite(indicadorVermelho, LOW);
    tone(bip, 300);
  }
}
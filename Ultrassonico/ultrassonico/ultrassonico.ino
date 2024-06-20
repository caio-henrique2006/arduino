// https://portal.vidadesilicio.com.br/hc-sr04-sensor-ultrassonico/

#include <Ultrasonic.h>

Ultrasonic ultrassom(8, 7); // trig, Echo respectivamente

long distancia;


void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
}

void loop() {
  distancia = ultrassom.Ranging(CM);
  if(distancia <= 100){
    int value = map(distancia, 0, 100, 1000, 0);
    Serial.print("Value:");
    Serial.println(value);
    tone(A0, value);
  } else {
    noTone(A0);
  }
  Serial.println(distancia);
  delay(100);

}

#define sensorPin A1

int valorSensor = 0;
float voltage;

void setup() {
  Serial.begin(9600);
  delay(100);

}

void loop() {
  valorSensor = analogRead(sensorPin);
  voltage = valorSensor * (5.0 / 1024);
  Serial.println(valorSensor);
  delay(500);

}

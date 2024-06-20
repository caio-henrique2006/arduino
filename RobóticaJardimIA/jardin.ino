const int ledPin = 12;
const int motorPin = 11; // Pino do motor (conecte o motor a este pino)

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Faz a leitura do sensor
  int leitura = analogRead(A0);
  Serial.println(leitura); // Exibe o valor lido no monitor serial

  if (leitura < 500 && leitura >= 250) {
    digitalWrite(ledPin, HIGH); // Acende o LED se a umidade estiver entre 250 e 499
    digitalWrite(motorPin, HIGH); // Liga o motor quando o LED estiver aceso
  } else {
    digitalWrite(ledPin, LOW); // Mantém o LED apagado se a umidade for maior ou igual a 500 ou menor que 250
    digitalWrite(motorPin, LOW); // Desliga o motor quando o LED estiver apagado
  }

  // Cria um pequeno atraso entre cada medição
  delay(3000);
}

#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 40);
EthernetServer server(80);

int sensorPin = A0;
const int pinLed = 11;
int sensorValue = 0;

void setup() {
    Ethernet.begin(mac, ip);
    server.begin();

    if (!SD.begin(4)) {
        Serial.println("Falha ao inicializar o cartão SD!");
        return;
    }

    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    EthernetClient client = server.available();

    if (client) {
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();

                if (c == '\n' && currentLineIsBlank) {
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();

                    // Lê o valor do sensor
                    sensorValue = analogRead(sensorPin);

                    // Atualiza a página HTML com o valor do sensor
                    File webFile = SD.open("pagina.html");
                    if (webFile) {
                        while (webFile.available()) {
                            String line = webFile.readStringUntil('\n');
                            if (line.indexOf("SENSOR_VALUE") != -1) {
                                // Substitui a variável no HTML pelo valor do sensor
                                line.replace("SENSOR_VALUE", String(sensorValue));
                            }
                            client.println(line);
                        }
                        webFile.close();
                    } else {
                        client.println("<p>Erro ao abrir o arquivo.</p>");
                    }

                    // Controla o motor com base no valor do sensor
                    if (sensorValue < 500 && sensorValue >= 250) {
                        digitalWrite(pinLed, HIGH); // Liga o motor
                    } else {
                        digitalWrite(pinLed, LOW); // Desliga o motor
                    }

                    break;
                }

                if (c == '\n') {
                    currentLineIsBlank = true;
                } else if (c != '\r') {
                    currentLineIsBlank = false;
                }
            }
        }

        delay(1);
        client.stop();
    }
}

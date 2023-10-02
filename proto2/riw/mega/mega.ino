#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200

NewPing sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo testeServo;

bool batendo = false;
void setup() {
    Serial.begin(115200);

    testeServo.attach(4);

    testeServo.write(0);
}

void loop() {
    unsigned long int distancia = sensor.ping_cm();
    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.println("cm");

    String comando = Serial.readStringUntil('\n');

    if (!batendo) {
      if (distancia <= 5 && distancia != 0) {
        batendo = true;
        // Cumprimento
        testeServo.write(90);
        delay(7000);
        testeServo.write(0);

        batendo = false;
      }

      if (comando == "A") {
          // Letra A
      } else if (comando == "botaoriw") {
          // Expressão RIW
      } else if (comando == "PEDRA") {
          // Jogo Pedra
      }
    }
}

#include <Servo.h>

#define H 180
#define AH 0

Servo testeServo;

void setup() {
    Serial.begin(115200);
    
    testeServo.attach(22);
    testeServo.write(0);
}

void loop() {
    String comando = Serial.readStringUntil('\n');

    if (comando == "gira") {
        mover(testeServo, H, 2000);
        delay(2000);
        mover(testeServo, AH, 2000);
    }
}

void mover(Servo servo, int direcao, int duracao) {
  servo.write(direcao);
  delay(duracao);
  servo.write(90);
}

// Exemplo:
// Esse exemplo move o servo na direção horária com velocidade definida por H durante um segundo
// mover(servo, H, 1000);
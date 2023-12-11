#include <Servo.h>

#define H 180
#define AH 0

Servo testeServo;
Servo trapezioE;
Servo trapezioD;
Servo ombroE;
Servo ombroD;
Servo bicepsE;
Servo bicepsD;
Servo cotoveloE;
Servo cotoveloD;
Servo cabeca;

void setup() {
    Serial.begin(115200);
    
    trapezioE.attach(2);
    trapezioD.attach(3);
    ombroE.attach(4);
    ombroD.attach(5);
    bicepsE.attach(6);
    bicepsD.attach(7);
    cotoveloE.attach(8);
    cotoveloD.attach(9);
    cabeca.attach(10);

    testeServo.attach(11);
}

void loop() {
    String comando = Serial.readStringUntil('\n');
    Serial.println(comando);

    if (comando == "gira") {

    } else if (comando == "auditorio") {
      
    } else if (comando == "banheiro") {
      mover(trapezioE, AH, 700);
      mover(trapezioD, H, 700);
      delay(2000);   
    } else if (comando == "secretaria") {
    
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

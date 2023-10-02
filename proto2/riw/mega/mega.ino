#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200

NewPing sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo testeServo;
Servo mindinho;
Servo anelar;
Servo medio;
Servo indicador;
Servo dedao
Servo dedaoPuxo;
servo pulso;
Servo cotovelo;

bool batendo = false;
void setup() {
    Serial.begin(115200);

    testeServo.attach(4);
    mindinho.attach(22);
    anelar.attach(24);
    medio.attach(26);
    indicador.attach(28);
    dedao.attach(30);
    dedaoPuxo.attach(32);
    pulso.attach(34);
    cotovelo.attach(36);

    mindinho.write(0);
    anelar.write(0);
    medio.write(0);
    indicador.write(0);
    dedao.write(0);
    dedaoPuxo.write(0);
    pulso.write(0);
    cotovelo.write(0);

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

      // Letras
      if (comando == "A") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "B") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "C") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "D") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "E") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "F") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "G") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "I") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "L") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "M") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "N") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "O") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "P") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "Q") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "R") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "S") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "T") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "V") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "W") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "Y") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      }
      
      // Expressões
      else if (comando == "botaotail") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "botaoriw") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      }else if (comando == "botaoifrj") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "botaopalmas") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      }
      
      // Jogo
      else if (comando == "PEDRA") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "PAPEL") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      } else if (comando == "TESOURA") {
          mindinho.write();
          anelar.write();
          medio.write();
          indicador.write();
          dedao.write();
          dedaoPuxo.write();
          pulso.write();
          cotovelo.write();
      }
    }
}

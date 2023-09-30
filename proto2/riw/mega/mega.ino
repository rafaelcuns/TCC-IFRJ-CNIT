#include <Servo.h>

void setup() {
    Serial.begin(115200);
}

void loop() {
    String comando = Serial.readStringUntil('\n');

    if (comando == "A") {
        // Letra A
    }

    if (comando == "botaoriw") {
        // Expressão RIW
    }
}
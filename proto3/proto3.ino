#include <Servo.h>

Servo servo1;

void setup() {
    Serial.begin(115200);
    
    servo1.attach(22);
    servo1.write(0);
}

void loop() {
    String comando = Serial.readString();
    comando.trim();

    if (comando == "gira") {
        servo1.write(0);
        delay(1000);
        servo1.write(180);
        delay(1000);
        servo1.write(0);
    }
}
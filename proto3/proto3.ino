#include <Servo.h>

Servo servo1;

void setup() {
    Serial.begin(115200);
    
    servo1.attach(22);
    servo1.write(0);
}

void loop() {
    String comando = Serial.readStringUntil('\n');

    if (comando == "gira") {
        servo1.write(180);
        delay(2000);
        servo1.write(0);
    }
}
#include "pins.h"
#include "encoder.h"
#include <stdio.h>

void setup() {
    Encoder encoder(SERVO_PIN);
    Serial.begin(9600);
}

void loop() {
    int angle = -1;

    // feio
    if (Serial.available() && (angle = Serial.read() - '0') >= 0) {
        encoder.setPosition(angle);
        Serial.println(angle);
    }
}

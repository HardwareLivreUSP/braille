#include "consts.hpp"
#include "encoder.hpp"
#include "carriage.hpp"
#include "parser.hpp"
#include <stdio.h>

Encoder encoder(SERVO_PIN);
Carriage c1(X_AXIS, 0.7, 200);

void setup() {
    Serial.begin(9600);
    pinMode(ENABLE, OUTPUT);
    digitalWrite(ENABLE, LOW);
    pinMode(13, OUTPUT);
}

void loop() {
    if (Serial.available() >= 2) {
        command c;
        c.raw.b1 = Serial.read();
        c.raw.b2 = Serial.read();
        parse_and_execute(c);
    }
}

#include "consts.hpp"
#include "encoder.hpp"
#include "carriage.hpp"
#include <stdio.h>

Encoder encoder(SERVO_PIN);
Carriage c1(Y_AXIS, 0.7, 200);
// Stepper s = Stepper(Y_AXIS);

void setup() {
    Serial.begin(9600);
    pinMode(ENABLE, OUTPUT);
    digitalWrite(ENABLE, LOW);
}

void loop() {
    // debug via serial

    if (Serial.available()){
        int arg = Serial.parseInt();
        // encoder.setPosition(arg);
        c1.move_relative(arg);
        Serial.println(arg);
    }

    c1.move_relative(-100);
    // s.step(CW, 1000);
    delay(2000);

}

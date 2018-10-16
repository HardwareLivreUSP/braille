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

    // test encoder
    // int angle = -1;
    // if (Serial.available() && (angle = Serial.read() - '0') >= 0) {
    //     encoder.setPosition(angle);
    //     Serial.println(angle);
    // }

    c1.move_relative(-100);
    // s.step(CW, 1000);
    delay(2000);

}

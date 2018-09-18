#include "encoder.h"
#include <Arduino.h>

static Servo Encoder::servo;

Encoder::Encoder(int servo_pin) {
    this->servo_pin = servo_pin;
}

void Encoder::rotate(int angle) {
    Encoder::servo.attach(this->servo_pin);
    Encoder::servo.write(angle);
    delay(500);
    Encoder::servo.detach();
}

void Encoder::setPosition(int position) {
    const int begin = 11;
    const int step = 20;

    rotate(begin + position * step);
}

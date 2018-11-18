#include "encoder.hpp"

static Servo Encoder::servo;

Encoder::Encoder(int servo_pin) {
    this->servo_pin = servo_pin;
}

void Encoder::rotate(int angle) {
    Encoder::servo.attach(this->servo_pin);
    Encoder::servo.write(angle);
    delay(700);
    Encoder::servo.detach();
}

void Encoder::setPosition(int position) {
    const float begin = 8.;
    const float step = 20.;

    rotate(begin + position * step);
}


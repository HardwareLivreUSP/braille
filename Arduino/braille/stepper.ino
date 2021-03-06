#include "stepper.hpp"
#include "consts.hpp"

Stepper::Stepper() {}

Stepper::Stepper(axis ax) {
    byte dir_pins[] = {X_DIR, Y_DIR, Z_DIR};
    byte stp_pins[] = {X_STP, Y_STP, Z_STP};
        
    this->dir_pin = dir_pins[ax];
    this->stp_pin = stp_pins[ax];
    pinMode(this->dir_pin, OUTPUT);
    pinMode(this->stp_pin, OUTPUT);

    this->frequency = 3000;
}

void Stepper::step(stpdir dir, int steps) {
    unsigned int T = 1000000 / this->frequency;
    // unsigned int T = 800;
    digitalWrite(ENABLE, LOW);
    digitalWrite (this->dir_pin, dir);
    delay (50);
    for (int i = 0; i < steps; i ++) {
        digitalWrite (this->stp_pin, HIGH);
        delayMicroseconds (T);
        digitalWrite (this->stp_pin, LOW);
        delayMicroseconds (T);
    }
    digitalWrite(ENABLE, HIGH);
}

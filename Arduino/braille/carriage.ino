#include "carriage.hpp"

Carriage::Carriage(axis ax, float pitch, int steps_per_revolution) {
    this->stepper = Stepper(ax);
    this->pitch = pitch;
    this->steps_per_revolution = steps_per_revolution;
}

void Carriage::move_relative(float distance) {
    stpdir dir = distance > 0 ? CW : CCW;
    int steps = (distance > 0 ? 1. : -1.)
        * (distance / this->pitch)
        * this->steps_per_revolution;
    this->stepper.step(dir, steps);
}

#ifndef _CARRIAGE
#define _CARRIAGE

#include "stepper.hpp"

class Carriage {
public:
    Carriage(axis ax, float pitch, int steps_per_revolution);
    void move_relative(float distance);
private:
    Stepper stepper;
    float   pitch;
    int     steps_per_revolution;
};

#endif

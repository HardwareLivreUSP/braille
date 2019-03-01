#ifndef _STEPPER
#define _STEPPER

enum stpdir {CCW, CW};
enum axis {X_AXIS, Y_AXIS, Z_AXIS};

class Stepper {
public:
    Stepper();
    Stepper(axis ax);
    void step(stpdir dir, int steps);
private:
    byte dir_pin;
    byte stp_pin;
    unsigned int frequency;
};

#endif

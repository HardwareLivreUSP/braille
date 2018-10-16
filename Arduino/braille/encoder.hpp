#ifndef _SERVO
#define _SERVO

#include <Servo.h>

void servoRotate(int angle);

class Encoder {
 private:
    int servo_pin;
    void rotate(int angle);
    static Servo servo;
    
 public:
    Encoder(int servo_pin);
    void setPosition(int position);
};

#endif

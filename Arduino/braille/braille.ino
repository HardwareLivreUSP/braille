#include "consts.hpp"
#include "parser.hpp"
#include "globals.hpp"

void setup() {
    Serial.begin(9600);
    pinMode(ENABLE, OUTPUT);
    digitalWrite(ENABLE, LOW);
    pinMode(13, OUTPUT);
}

void loop() {
    if (Serial.available() >= 2) {
        serial_command c;
        c.raw.b1 = Serial.read();
        c.raw.b2 = Serial.read();
        parse_and_execute(c);
    }
}

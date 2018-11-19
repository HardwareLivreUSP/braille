#include "parser.hpp"
#include "globals.hpp"

static void set_encoder_pins(unsigned int arg) {
    encoder.setPosition((int) arg);
}

static void cmd2(unsigned int arg) {
    for (unsigned int i = 0; i < arg; i++) {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
    }
}


void parse_and_execute(serial_command raw) {
    void (*cmds[])(unsigned int) = {set_encoder_pins, cmd2};
    cmds[raw.parsed.cmd](raw.parsed.param);
}

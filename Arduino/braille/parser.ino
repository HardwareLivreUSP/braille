#include "parser.hpp"
#include "globals.hpp"

static void set_encoder_pins(int arg) {
    encoder.setPosition((int) arg);
}

static void move_encoder_carriage_relative(int arg) {
    c1.move_relative((float) arg / 10);
}

static void move_c1(int arg) {
    c1.move_relative((float) arg);
}

// static void cmd2(unsigned int arg) {
//     for (unsigned int i = 0; i < arg; i++) {
//         digitalWrite(13, HIGH);
//         delay(500);
//         digitalWrite(13, LOW);
//         delay(500);
//     }
// }

void parse_and_execute(serial_command raw) {
    void (*cmds[])(int) = {set_encoder_pins,
                           move_encoder_carriage_relative,
                           move_c1};
    cmds[raw.parsed.cmd](raw.parsed.param);
}

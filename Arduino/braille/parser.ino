#include "parser.hpp"

struct serial_command {
    unsigned int param : 12;
    unsigned int cmd : 4;
};

static void cmd1(unsigned int arg) {
    for (unsigned int i = 0; i < arg; i++) {
        digitalWrite(13, HIGH);
        delay(200);
        digitalWrite(13, LOW);
        delay(800);
    }
}

static void cmd2(unsigned int arg) {
    for (unsigned int i = 0; i < arg; i++) {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
    }
}

void parse_and_execute(command raw) {
    void (*cmds[])(unsigned int) = {cmd1, cmd2};
    cmds[raw.parsed.cmd](raw.parsed.param);
}

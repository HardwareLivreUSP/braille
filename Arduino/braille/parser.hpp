#ifndef _PARSER
#define _PARSER

union serial_command {
    struct {
        unsigned int b1 : 8;
        unsigned int b2 : 8;
    } raw;

    struct {
        unsigned int cmd : 4;
        unsigned int param : 12;
    } parsed;
};

void parse_and_execute(serial_command raw);

#endif

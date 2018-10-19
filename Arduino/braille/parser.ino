#include "parser.hpp"

static void cmd1(uint16_t arg) {
    
}

static void cmd2(uint16_t arg) {
    
}

void parse_and_execute(uint16_t raw) {
    void (*funcs[]) (uint16_t) =  {cmd1, cmd2};

    uint8_t  cmd = raw >> 12;
    uint16_t arg = raw & 0x0FFF;
    funcs[cmd](arg);
}

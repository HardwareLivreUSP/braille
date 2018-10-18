#include "parser.hpp"

void parse_and_execute(uint16_t raw) {
    const void (*funcs[]) (uint16_t);
    uint8_t cmd = raw >> 12;
    uint16_t arg = raw & 0x0FFF;
}

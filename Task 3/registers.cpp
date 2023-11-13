#include "registers.h"

void registers::fill() {
    for (int i = 0; i < 16; i++) {
        reg[i] = "00";
    }
}
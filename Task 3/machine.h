#ifndef VOLESIMULATER_MACHINE_H
#define VOLESIMULATER_MACHINE_H

#include "memory.h"
#include "registers.h"
#include "instructions.h"
#include "Hexa.h"

class machine : public Hexa {
public:
    memory mem;
    instructions inst;
    registers regs;

    void run();
};


#endif

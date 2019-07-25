//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_MACHINE_H
#define MIPS_MONOCYCLE_MACHINE_H

#include <cstdio>
#include <curses.h>

#include "Processor.h"

class Machine {
public:
    Machine();

private:
    Processor *processor;


public:
    void clock();

//    Memory memory;
    static void debugInfo(const char *message);
};


#endif // MIPS_MONOCYCLE_MACHINE_H

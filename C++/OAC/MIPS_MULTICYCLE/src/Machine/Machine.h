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
    static unsigned char verbosityLevel;

private:
    Processor *processor;



    // Memory memory;

public:
    Machine();

    void initialize(const char *instructionsFile, unsigned char verbLevel);

    void clock();

    static void debugInfo(const char *message, unsigned char verbLevel);

    static unsigned int getInstructionFromLine(const char str[255]);

};


#endif // MIPS_MONOCYCLE_MACHINE_H

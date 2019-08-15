//
// Created by jarvis on 7/22/19.
//

#include <cstdlib>
#include "Machine.h"

#include <iostream>

using namespace std;

unsigned char Machine::verbosityLevel = 0;

Machine::Machine() {
    this->processor = new Processor();
}

void Machine::clock() {
    debugInfo("================================================", 1);
    Machine::debugInfo("Clocking Machine", 2);
    processor->clock();
    debugInfo("------------------------------------------------", 2);
    Machine::debugInfo("Updating IO", 2);
    processor->updateIO();
    debugInfo("------------------------------------------------", 2);

    Machine::debugInfo("Printing Registers", 1);
    processor->printRegisters();
    debugInfo("------------------------------------------------", 1);
    Machine::debugInfo("Printing Memory", 1);
    processor->printMemory();
    debugInfo("------------------------------------------------", 1);
}


void Machine::debugInfo(const char *message, unsigned char verbLevel) {
    if (Machine::verbosityLevel < verbLevel)
        return;

    switch (verbLevel) {
        case 1:
            cout << "\033[1;32m";
            break;
        case 2:
            cout << "\033[1;34m";
            break;
        case 3:
            cout << "\033[1;33m";
            break;
        default:
            break;
    }

    fprintf(stdout, "%s", message);
    cout << "\033[0m" << endl;
}

void Machine::initialize(const char *instructionsFile, unsigned char verbLevel) {
    FILE *f = fopen(instructionsFile, "r");
    Machine::verbosityLevel = verbLevel;

    if (!f)
        exit(1);

    int i;
    auto *instructionMemory = (unsigned int *) (malloc(255 * sizeof(unsigned int)));
    char buff[255];

    for (i = 0; !feof(f); ++i) {
        fgets(buff, 255, f);
        instructionMemory[i] = getInstructionFromLine(buff);
        if (verbLevel)
            printf("Instruction[%02d] = 0x%08x\n", i * 4, instructionMemory[i]);
    }

    processor->initialize(instructionMemory);
}

unsigned int Machine::getInstructionFromLine(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }

    return res;
}



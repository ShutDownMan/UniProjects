//
// Created by jarvis on 7/22/19.
//

#include "Machine.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

unsigned char Machine::verbosityLevel = 0;

Machine::Machine() {
    this->processor = new Processor();
}

void Machine::clock() {
    debugInfo("================================================", 1);
    Machine::debugInfo("Updating Raising Edge Components", 2);
    processor->raisingEdge();
    debugInfo("------------------------------------------------", 2);
    Machine::debugInfo("Updating Passive Components", 2);
    processor->passive();
    debugInfo("------------------------------------------------", 2);
    Machine::debugInfo("Updating Falling Edge Components", 2);
    processor->fallingEdge();

    Machine::debugInfo("Registers", 1);
    processor->printRegisters();
    debugInfo("------------------------------------------------", 1);
    Machine::debugInfo("Memory", 1);
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
    int aux;

    Machine::debugInfo("Instructions:", 1);

    for (i = 0; !feof(f); ++i) {
        fgets(buff, 255, f);
        aux = (int)getInstructionFromLine(buff);
        memcpy(&instructionMemory[i], &aux, sizeof(int));
        instructionMemory[i] = getInstructionFromLine(buff);
        if (verbLevel) {
            sprintf(buff, "\tInstruction[%03d] = 0x%08x", i * 4, aux);
            debugInfo(buff, 1);
        }
    }

    debugInfo("------------------------------------------------", 1);
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



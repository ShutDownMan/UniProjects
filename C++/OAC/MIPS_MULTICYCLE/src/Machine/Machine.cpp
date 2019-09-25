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
    Machine::debugInfo("Updating Controller:", 2);
    processor->updateController();
    debugInfo("------------------------------------------------", 2);
    Machine::debugInfo("Clocking Components:", 2);
    processor->clock();
    debugInfo("------------------------------------------------", 2);
    Machine::debugInfo("Updating Passive Components:", 2);
    processor->updatePassive();
    debugInfo("------------------------------------------------", 2);

    Machine::debugInfo("Memory:", 1);
    processor->printMemory();
    debugInfo("------------------------------------------------", 1);
    Machine::debugInfo("Registers:", 1);
    processor->printRegisters();
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
    auto *memory = (unsigned char *) (malloc(65536 * sizeof(unsigned char)));
    char buff[255];
    int aux;

    Machine::debugInfo("Instructions:", 1);

    for (i = 0; !feof(f); i += 4) {
        fgets(buff, 255, f);

        aux = getInstructionFromLine(buff);
        memcpy(&memory[i], &aux, sizeof(int));
        memory[i] = getInstructionFromLine(buff);
        if (verbLevel) {
            sprintf(buff, "\tInstruction[%03d] = 0x%08x", i * 4, aux);
            debugInfo(buff, 1);
        }
    }

    debugInfo("------------------------------------------------", 1);
    processor->initialize(memory);
    debugInfo("------------------------------------------------", 1);
}

unsigned int Machine::getInstructionFromLine(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }

    return res;
}

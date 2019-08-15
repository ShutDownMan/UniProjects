//
// Created by jarvis on 7/22/19.
//

#include <cstdlib>
#include "Machine.h"
#include <iostream>
#include <cstring>

using namespace std;

unsigned char Machine::verbosityLevel = 0;

Machine::Machine() {
    this->processor = new Processor();
}

void Machine::clock() {
    debugInfo("================================================\n", 1);
    processor->updateController();
    debugInfo("------------------------------------------------\n", 1);
    processor->clock();
    debugInfo("------------------------------------------------\n", 1);
    processor->updatePassive();
    debugInfo("------------------------------------------------\n", 1);
    processor->updateIO();


    debugInfo("------------------------------------------------\n", 1);
    processor->printMemory();
    debugInfo("------------------------------------------------\n", 1);
    processor->printRegisters();

}


void Machine::debugInfo(const char *message, unsigned char verbLevel) {
    if (Machine::verbosityLevel < verbLevel)
        return;

    switch (verbLevel) {
        case 1:
            cout << "\033[1;31m";
            break;
        case 2:
            cout << "\033[1;37m";
            break;
        case 3:
            cout << "\033[1;35m";
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

    for (i = 0; !feof(f); i += 4) {
        fgets(buff, 255, f);

        aux = getInstructionFromLine(buff);
        memcpy(&memory[i], &aux, sizeof(int));
        memory[i] = getInstructionFromLine(buff);

        sprintf(buff, "Instruction[%d] = %u", i, aux);
        debugInfo(buff, 1);
    }

    processor->initialize(memory);
}

unsigned int Machine::getInstructionFromLine(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }

    return res;
}



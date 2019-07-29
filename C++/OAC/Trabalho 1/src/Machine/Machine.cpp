//
// Created by jarvis on 7/22/19.
//

#include <cstdlib>
#include "Machine.h"

Machine::Machine() {
    this->processor = new Processor();
}

void Machine::clock() {
    char c;
    int i = 0;

    do {
        processor->clock();
        printf("------------------------------------------------\n");
        processor->updateIO();
        printf("------------------------------------------------\n");

        processor->printRegisters();
        printf("------------------------------------------------\n");
        processor->printMemory();
        printf("------------------------------------------------\n");

        c = getchar();
    } while (i++ < 64 && c != 'q');
}


void Machine::debugInfo(const char *message) {
    fprintf(stderr, "%s\n", message);
}

void Machine::initialize(const char *instructionsFile) {
    FILE *f = fopen(instructionsFile, "r");

    if (!f)
        exit(1);

    int i;
    auto *instructionMemory = (unsigned int *) (malloc(255 * sizeof(unsigned int)));
    char buff[255];

    for (i = 0; !feof(f); ++i) {
        fgets(buff, 255, f);
        instructionMemory[i] = getInstructionFromLine(buff);
        printf("Instruction[%d] = %u\n", i, instructionMemory[i]);
    }

    processor->initialize(instructionMemory);
}

unsigned int Machine::getInstructionFromLine(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }
    printf("\n");

    return res;
}



//
// Created by jarvis on 7/22/19.
//

#include "Machine.h"

Machine::Machine() {
    this->processor = new Processor();
}

void Machine::clock() {
    char c;

    processor->initialize();

    do {
        processor->clock();
        processor->updateIO();

        c = getchar_unlocked();
    } while(c != 'q');
}


void Machine::debugInfo(const char *message) {
    fprintf(stderr, "%s\n", message);
}

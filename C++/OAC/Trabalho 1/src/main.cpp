#include <iostream>
#include "Machine/Machine.h"

int main(int argc, char const *argv[]) {
    auto *machine = new Machine();
    unsigned char verbosity = 0;

    Machine::debugInfo("Initializing Machine", 1);

    if(argc >= 3) {
        verbosity = strtol(argv[2], nullptr, 10);
    }

    if(argc < 2) {
        printf("Usage: \n"
               "program assembly.txt [verbosity_level]\n");
        return 1;
    }

    machine->initialize(argv[1], verbosity);

    int i = 0;

    do {
        machine->clock();
        printf("Type any key for the next clock\n"
               "Press 'q' to quit");
    } while (i++ < 128 && getchar_unlocked() != 'q');

    return 0;
}
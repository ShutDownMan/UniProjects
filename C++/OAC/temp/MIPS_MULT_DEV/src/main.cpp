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

    Machine::debugInfo("Reading Instructions", 1);
    machine->initialize(argv[1], verbosity);

    do {
        Machine::debugInfo("Clocking Machine", 1);
        machine->clock();
        printf("Return key for the next clock\n"
               "Use 'q' to quit\n");
    } while (getchar_unlocked() != 'q');

    return 0;
}
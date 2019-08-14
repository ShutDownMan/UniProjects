#include <iostream>
#include "Machine/Machine.h"

int main() {
    auto *machine = new Machine();

    Machine::debugInfo("Initializing Machine", 1);
    machine->initialize("initTest.txt", 3);

    Machine::debugInfo("Clocking Machine", 1);

    int i = 0;

    do {
        machine->clock();
    } while (i++ < 64 && getchar() != 'q');
    return 0;
}
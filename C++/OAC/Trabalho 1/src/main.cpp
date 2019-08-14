#include <iostream>
#include "Machine/Machine.h"

using namespace std;

int main() {
    auto *machine = new Machine();

    Machine::debugInfo("Initializing Machine");
    machine->initialize("fibTeste.txt");

    Machine::debugInfo("Clocking Machine");
    char c;
    int i = 0;

    do {
        machine->clock();
        c = getchar();
    } while (i++ < 64 && c != 'q');

    return 0;
}
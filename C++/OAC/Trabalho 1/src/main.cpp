#include <iostream>
#include "Machine/Machine.h"

using namespace std;

int main() {
    auto *machine = new Machine();

    Machine::debugInfo("Initializing Machine");
    machine->initialize("teste1.txt");

    Machine::debugInfo("Clocking Machine");
    machine->clock();

    return 0;
}
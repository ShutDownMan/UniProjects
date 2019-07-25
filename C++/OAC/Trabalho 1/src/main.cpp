#include <iostream>
#include "Machine/Machine.h"

int main() {
    auto *machine = new Machine();

    machine->initialize("teste1.txt");

    machine->clock();

    return 0;
}


//
// Created by Jedson Gabriel on 7/22/19.
//

#include "INBus.h"
#include "../Machine.h"

#include <string>
#include <iostream>

using namespace std;

INBus::INBus(OUTBus *refBus) : refBus(refBus) {
    this->value = 0;
    this->mask = -1;
    this->fistSetBit = 0;
}

INBus::INBus(unsigned int mask, OUTBus *refBus) : mask(mask), refBus(refBus) {
    this->value = 0;
    this->fistSetBit = ffs(mask) - 1;
}

void INBus::update() {
    this->value = refBus->getValue();
}

unsigned int INBus::getValue() const {
    return (value & mask) >> this->fistSetBit;
}

void INBus::printContents() {
    string str = "INBus:\n";

    str += "\tMask = " + to_string(this->mask) + "\n";
    str += "\trefBus = " + to_string(this->refBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

//
// Created by jarvis on 7/22/19.
//

#include "INBus.h"

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

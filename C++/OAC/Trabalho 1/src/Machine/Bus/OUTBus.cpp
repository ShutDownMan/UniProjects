//
// Created by jarvis on 7/22/19.
//

#include "OUTBus.h"

int OUTBus::getValue() const {
    return value;
}

void OUTBus::setValue(unsigned int newValue) {
    OUTBus::value = newValue;
}

OUTBus::OUTBus() {
    this->value = 0;
}

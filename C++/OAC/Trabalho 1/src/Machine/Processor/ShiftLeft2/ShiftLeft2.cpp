//
// Created by jarvis on 7/22/19.
//

#include "ShiftLeft2.h"

ShiftLeft2::ShiftLeft2() {
    this->inBus = nullptr;
    this->outBus = new OUTBus();
}

void ShiftLeft2::updateIO() {
    this->inBus->update();

    this->outBus->setValue(this->inBus->getValue() << 2u);
}

void ShiftLeft2::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

OUTBus *ShiftLeft2::getOutBus() const {
    return outBus;
}

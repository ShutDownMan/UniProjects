//
// Created by jarvis on 7/22/19.
//

#include "PCRegister.h"

PCRegister::PCRegister() {
    this->inBus = nullptr;
    this->outBus = new OUTBus();
}

void PCRegister::initialize(INBus *refInBus) {
    this->inBus = refInBus;
}

void PCRegister::updateState() {
    this->outBus->setValue(this->inBus->getValue());
}

void PCRegister::updateIO() {
    this->inBus->update();
}

OUTBus *PCRegister::getOutBus() const {
    return outBus;
}


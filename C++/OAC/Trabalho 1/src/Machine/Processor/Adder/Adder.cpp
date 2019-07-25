//
// Created by jarvis on 7/22/19.
//

#include "Adder.h"

Adder::Adder() {
    this->outputBus = new OUTBus();
}

void Adder::updateIO() {
    this->inputBBus->update();
    this->inputBBus->update();

    this->outputBus->setValue(this->inputABus->getValue() + this->inputBBus->getValue());
}

void Adder::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *Adder::getOutputBus() const {
    return outputBus;
}

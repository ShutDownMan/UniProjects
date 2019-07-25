//
// Created by jarvis on 7/22/19.
//

#include "Multiplexer.h"

Multiplexer::Multiplexer() {
    this->inputABus = nullptr;
    this->inputBBus = nullptr;
    this->controlSignal = nullptr;

    this->outBus = new OUTBus();
}

void Multiplexer::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();
    this->controlSignal->update();

    this->outBus->setValue((!this->controlSignal->getValue()) ? this->inputABus->getValue() : this->inputBBus->getValue());
}

void Multiplexer::initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *controlSignalRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
    this->controlSignal = controlSignalRef;
}

OUTBus *Multiplexer::getOutBus() const {
    return outBus;
}

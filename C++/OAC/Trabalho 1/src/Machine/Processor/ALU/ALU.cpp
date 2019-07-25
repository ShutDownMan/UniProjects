//
// Created by jarvis on 7/22/19.
//

#include "ALU.h"

ALU::ALU() {
    this->outBus = new OUTBus();
    this->zeroBus = new OUTBus();
}

void ALU::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();
}

void ALU::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *ALU::getOutBus() const {
    return outBus;
}

OUTBus *ALU::getZeroBus() const {
    return zeroBus;
}

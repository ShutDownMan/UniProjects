//
// Created by jarvis on 7/22/19.
//

#include "And.h"
#include "../../Bus/INBus.h"

void And::updateState() {

}

void And::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();

    this->outBus->setValue(this->inputABus && this->inputBBus);
}

void And::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *And::getOutBus() const {
    return outBus;
}

And::And() {
    this->outBus = new OUTBus();
}

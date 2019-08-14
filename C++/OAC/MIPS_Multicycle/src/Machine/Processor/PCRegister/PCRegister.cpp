//
// Created by jarvis on 7/22/19.
//

#include "PCRegister.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

PCRegister::PCRegister() {
    this->inBus = nullptr;
    this->controlSignal = nullptr;

    this->outBus = new OUTBus();
}

void PCRegister::initialize(INBus *refInBus, INBus *controlSignalRef) {
    this->inBus = refInBus;
    this->controlSignal = controlSignalRef;
}

void PCRegister::updatePassive() {
    this->inBus->update();
    this->controlSignal->update();

    if (this->controlSignal->getValue())
        this->outBus->setValue(this->inBus->getValue());
}

void PCRegister::updateState() {
}

OUTBus *PCRegister::getOutBus() const {
    return outBus;
}

void PCRegister::printContents() {
    string str = "PCRegister:\n";

    str += "\tInBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\tControlSignal: " + to_string(this->controlSignal->getValue()) + "\n";
    str += "\tOutBus: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);
}


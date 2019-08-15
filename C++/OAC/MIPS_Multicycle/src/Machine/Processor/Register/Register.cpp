//
// Created by jarvis on 7/29/19.
//

#include "Register.h"

#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

Register::Register() {
    this->inBus = nullptr;
    this->controlSignal = nullptr;

    this->outBus = new OUTBus();
}

void Register::initialize(INBus *refInBus) {
    this->inBus = refInBus;
}

void Register::initialize(INBus *refInBus, INBus *controlSignalRef) {
    this->inBus = refInBus;
    this->controlSignal = controlSignalRef;
}

void Register::updatePassive() {
    this->inBus->update();
    if (this->controlSignal)
        this->controlSignal->update();

    if (!this->controlSignal || this->controlSignal->getValue())
        this->outBus->setValue(this->inBus->getValue());
}

OUTBus *Register::getOutBus() const {
    return outBus;
}

void Register::printContents() {
    string str = "Register:\n";

    str += "\tInBus = " + to_string(this->inBus->getValue()) + "\n";
    str += "\tOutBus = " + to_string(this->outBus->getValue()) + "\n";
    if (this->controlSignal)
        str += "\tControlSignal = " + to_string(this->controlSignal->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);
}


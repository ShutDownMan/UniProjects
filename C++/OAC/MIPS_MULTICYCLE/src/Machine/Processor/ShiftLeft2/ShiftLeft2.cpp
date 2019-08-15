//
// Created by jarvis on 7/22/19.
//

#include "ShiftLeft2.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

ShiftLeft2::ShiftLeft2() {
    this->inBus = nullptr;

    this->outBus = new OUTBus();
}

void ShiftLeft2::updatePassive() {
    this->inBus->update();

    this->outBus->setValue(this->inBus->getValue() << 2u);
}

void ShiftLeft2::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

OUTBus *ShiftLeft2::getOutBus() const {
    return outBus;
}

void ShiftLeft2::printContents() {
    string str = "ShiftLeft2:\n";

    str += "\tinBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);

}
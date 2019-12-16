//
// Created by Jedson Gabriel on 7/22/19.
//

#include "ALU.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

ALU::ALU() {
    this->inputABus = nullptr;
    this->inputBBus = nullptr;
    this->controlBus = nullptr;

    this->outBus = new OUTBus();
    this->zeroBus = new OUTBus();
}

void ALU::updatePassive() {
    this->inputABus->update();
    this->inputBBus->update();
    this->controlBus->update();

    unsigned int res = 0;

    switch (this->controlBus->getValue()) {
        case AND:
            Machine::debugInfo("A & B", 3);
            res = this->inputABus->getValue() & this->inputBBus->getValue();
            break;
        case OR:
            Machine::debugInfo("A | B", 3);
            res = this->inputABus->getValue() | this->inputBBus->getValue();
            break;
        case SUM:
            Machine::debugInfo("A + B", 3);
            res = this->inputABus->getValue() + this->inputBBus->getValue();
            break;
        case SUB:
            Machine::debugInfo("A - B", 3);
            res = this->inputABus->getValue() - this->inputBBus->getValue();
            break;
        case LST:
            Machine::debugInfo("A < B", 3);
            res = (this->inputABus->getValue() < this->inputBBus->getValue());
            break;
        case NOR:
            Machine::debugInfo("!(A | B)", 3);
            res = ~(this->inputABus->getValue() | this->inputBBus->getValue());
            break;
    }

    this->zeroBus->setValue(res == 0);

    this->outBus->setValue(res);
}

void ALU::initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *aluControlBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
    this->controlBus = aluControlBusRef;
}

OUTBus *ALU::getOutBus() const {
    return outBus;
}

OUTBus *ALU::getZeroBus() const {
    return zeroBus;
}

void ALU::printContents() {
    string str = "ALU:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    str += "\tcontrolBus: " + to_string(this->controlBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";
    str += "\tzeroBus: " + to_string(this->zeroBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}
//
// Created by jarvis on 7/22/19.
//

#include "InstructionRegister.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

InstructionRegister::InstructionRegister() {
    this->inBus = nullptr;
    this->IRWriteSignal = nullptr;

    this->outBus = new OUTBus();
}

void InstructionRegister::initialize(INBus *inBusRef, INBus *IRWriteRef) {
    this->IRWriteSignal = IRWriteRef;
    this->inBus = inBusRef;
}

void InstructionRegister::updatePassive() {
    this->IRWriteSignal->update();

    this->inBus->update();

    if (this->IRWriteSignal->getValue())
        this->outBus->setValue(this->inBus->getValue());
}

OUTBus *InstructionRegister::getOutBus() const {
    return outBus;
}

void InstructionRegister::printContents() {
    string str = "InstructionRegister:\n";

    str += "\tinBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\tIRWriteSignal: " + to_string(this->IRWriteSignal->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);
}


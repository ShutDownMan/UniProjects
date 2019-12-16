//
// Created by Jedson Gabriel on 7/22/19.
//

#include "Multiplexer.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

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

    this->outBus->setValue(
            (!this->controlSignal->getValue()) ? this->inputABus->getValue() : this->inputBBus->getValue());
}

void Multiplexer::initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *controlSignalRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
    this->controlSignal = controlSignalRef;
}

OUTBus *Multiplexer::getOutputBus() const {
    return outBus;
}

void Multiplexer::printContents() {
    string str = "Multiplexer:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    str += "\tcontrolSignal: " + to_string(this->controlSignal->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

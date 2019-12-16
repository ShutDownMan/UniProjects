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
    this->inputCBus = nullptr;
    this->inputDBus = nullptr;
    this->controlSignal = nullptr;

    this->outBus = new OUTBus();
}

void Multiplexer::updatePassive() {
    this->inputABus->update();
    this->inputBBus->update();
    if (this->inputCBus)
        this->inputCBus->update();
    if (this->inputDBus)
        this->inputDBus->update();

    this->controlSignal->update();

    int res = 0;

    switch (this->controlSignal->getValue()) {
        case 0:
            res = this->inputABus->getValue();
            break;
        case 1:
            res = this->inputBBus->getValue();
            break;
        case 2:
            res = this->inputCBus->getValue();
            break;
        case 3:
            res = this->inputDBus->getValue();
            break;
        default:
            break;
    }

    this->outBus->setValue(res);
}

void Multiplexer::initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *controlSignalRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
    this->controlSignal = controlSignalRef;
}

void Multiplexer::initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *inputCBusRef, INBus *inputDBusRef,
                             INBus *controlSignalRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
    this->inputCBus = inputCBusRef;
    this->inputDBus = inputDBusRef;
    this->controlSignal = controlSignalRef;
}

OUTBus *Multiplexer::getOutBus() const {
    return outBus;
}

void Multiplexer::printContents() {
    string str = "Multiplexer:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    if (this->inputCBus)
        str += "\tinputCBus: " + to_string(this->inputCBus->getValue()) + "\n";
    if (this->inputDBus)
        str += "\tinputDBus: " + to_string(this->inputDBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";
    str += "\tcontrolSignal: " + to_string(this->controlSignal->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

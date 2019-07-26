//
// Created by jarvis on 7/22/19.
//

#include "And.h"
#include "../../Bus/INBus.h"
#include <string>
#include <iostream>

using namespace std;


And::And() {
    this->inputABus = nullptr;
    this->inputBBus = nullptr;

    this->outBus = new OUTBus();
}

void And::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();

    this->outBus->setValue(this->inputABus->getValue() && this->inputBBus->getValue());
}

void And::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *And::getOutBus() const {
    return outBus;
}

void And::printContents() {
    string str = "And:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";

    cout << str << endl;
}

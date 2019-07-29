//
// Created by jarvis on 7/26/19.
//

#include "Or.h"
#include "../../Bus/INBus.h"
#include <string>
#include <iostream>

using namespace std;


Or::Or() {
    this->inputABus = nullptr;
    this->inputBBus = nullptr;

    this->outBus = new OUTBus();
}

void Or::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();

    this->outBus->setValue(this->inputABus->getValue() || this->inputBBus->getValue());
}

void Or::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *Or::getOutBus() const {
    return outBus;
}

void Or::printContents() {
    string str = "Or:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";

    cout << str << endl;
}
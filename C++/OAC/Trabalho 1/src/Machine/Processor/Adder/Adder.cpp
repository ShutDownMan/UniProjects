//
// Created by jarvis on 7/22/19.
//

#include "Adder.h"
#include <string>
#include <iostream>

using namespace std;

Adder::Adder() {
    this->inputABus = nullptr;
    this->inputBBus = nullptr;

    this->outputBus = new OUTBus();
}

void Adder::updateIO() {
    this->inputABus->update();
    this->inputBBus->update();

    this->outputBus->setValue(this->inputABus->getValue() + this->inputBBus->getValue());
}

void Adder::initialize(INBus *inputABusRef, INBus *inputBBusRef) {
    this->inputABus = inputABusRef;
    this->inputBBus = inputBBusRef;
}

OUTBus *Adder::getOutputBus() const {
    return outputBus;
}

void Adder::printContents() {
    string str = "Adder:\n";

    str += "\tinputABus: " + to_string(this->inputABus->getValue()) + "\n";
    str += "\tinputBBus: " + to_string(this->inputBBus->getValue()) + "\n";
    str += "\toutputBus: " + to_string(this->outputBus->getValue()) + "\n";

    cout << str << endl;

}

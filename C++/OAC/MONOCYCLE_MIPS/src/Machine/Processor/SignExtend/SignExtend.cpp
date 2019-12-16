//
// Created by Jedson Gabriel on 7/22/19.
//

#include <cstdint>
#include "SignExtend.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

SignExtend::SignExtend() {
    this->inBus = nullptr;

    this->outBus = new OUTBus();
}

void SignExtend::updateIO() {
    this->inBus->update();

    int16_t s = this->inBus->getValue();

    this->outBus->setValue((int32_t) s);
}

void SignExtend::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

OUTBus *SignExtend::getOutputBus() const {
    return outBus;
}

void SignExtend::printContents() {
    string str = "SignExtend:\n";

    str += "\tinBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);

}

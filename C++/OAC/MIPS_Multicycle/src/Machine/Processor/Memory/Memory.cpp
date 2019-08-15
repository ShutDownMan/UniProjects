//
// Created by jarvis on 7/22/19.
//

#include "Memory.h"
#include "../../Machine.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Memory::Memory() {
    this->addressBus = nullptr;
    this->writeDataBus = nullptr;
    this->writeMemControlBus = nullptr;
    this->readMemControlBus = nullptr;
    this->memory = nullptr;

    this->memDataBus = new OUTBus();
}

void Memory::initialize(unsigned char *memoryRef, INBus *addressBusRef, INBus *writeDataRef,
                        INBus *writeMemControlBusRef,
                        INBus *readMemControlBusRef) {
    this->memory = memoryRef;
    this->addressBus = addressBusRef;
    this->writeDataBus = writeDataRef;
    this->readMemControlBus = readMemControlBusRef;
    this->writeMemControlBus = writeMemControlBusRef;
}

void Memory::updateIO() {
    this->addressBus->update();
    this->readMemControlBus->update();
    this->writeMemControlBus->update();
    this->writeDataBus->update();
}

void Memory::writeMem() {
    unsigned int val;

    if (this->writeMemControlBus->getValue())
        memcpy(&this->memory[this->addressBus->getValue()], &(val = this->writeDataBus->getValue()), sizeof(int));
}

void Memory::updateState() {
    unsigned int val;

    if (this->readMemControlBus->getValue()) {
        memcpy(&val, &this->memory[this->addressBus->getValue()], sizeof(int));
        this->memDataBus->setValue(val);
    }

}

OUTBus *Memory::getMemDataBus() const {
    return memDataBus;
}

const unsigned char *Memory::getMemory() const {
    return memory;
}

void Memory::printContents() {
    string str = "Memory:\n";

    str += "\taddressBus: " + to_string(this->addressBus->getValue()) + "\n";
    str += "\twriteDataBus: " + to_string(this->writeDataBus->getValue()) + "\n";
    str += "\treadMemControlBus: " + to_string(this->readMemControlBus->getValue()) + "\n";
    str += "\twriteMemControlBus: " + to_string(this->writeMemControlBus->getValue()) + "\n";
    str += "\treadDataBus: " + to_string(this->memDataBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);
}

//
// Created by jarvis on 7/22/19.
//

#include "DataMemory.h"
#include "../../Machine.h"
#include <string>
#include <cstring>

using namespace std;

DataMemory::DataMemory() {
    this->addressBus = nullptr;
    this->writeDataBus = nullptr;
    this->writeMemControlBus = nullptr;
    this->readMemControlBus = nullptr;

    this->readDataBus = new OUTBus();
}

void DataMemory::updateState() {
    unsigned int val;
    if (this->writeMemControlBus->getValue())
        memcpy(&this->memory[this->addressBus->getValue()], &(val = this->writeDataBus->getValue()), sizeof(unsigned int));
}

void DataMemory::updateIO() {
    this->writeDataBus->update();
    this->addressBus->update();
    this->readMemControlBus->update();
    this->writeMemControlBus->update();

    if (this->readMemControlBus->getValue())
        this->readDataBus->setValue(this->memory[this->addressBus->getValue()]);
}

void DataMemory::initialize(INBus *addressBusRef, INBus *writeDataRef, INBus *writeMemControlBusRef,
                            INBus *readMemControlBusRef) {
    this->addressBus = addressBusRef;
    this->writeDataBus = writeDataRef;
    this->readMemControlBus = readMemControlBusRef;
    this->writeMemControlBus = writeMemControlBusRef;
}

OUTBus *DataMemory::getReadDataBus() const {
    return readDataBus;
}

const unsigned char *DataMemory::getMemory() const {
    return memory;
}

void DataMemory::printContents() {
    string str = "DataMemory:\n";

    str += "\taddressBus: " + to_string(this->addressBus->getValue()) + "\n";
    str += "\twriteDataBus: " + to_string(this->writeDataBus->getValue()) + "\n";
    str += "\treadMemControlBus: " + to_string(this->readMemControlBus->getValue()) + "\n";
    str += "\twriteMemControlBus: " + to_string(this->writeMemControlBus->getValue()) + "\n";
    str += "\treadDataBus: " + to_string(this->readDataBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

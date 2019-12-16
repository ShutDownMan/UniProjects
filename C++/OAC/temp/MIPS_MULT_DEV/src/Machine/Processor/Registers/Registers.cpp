//
// Created by Jedson Gabriel on 7/22/19.
//

#include "Registers.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

Registers::Registers() {
    this->readRegister1Bus = nullptr;
    this->readRegister2Bus = nullptr;
    this->writeDataBus = nullptr;
    this->writeRegisterBus = nullptr;
    this->writeControlBus = nullptr;

    this->readData1Bus = new OUTBus();
    this->readData2Bus = new OUTBus();
}

void Registers::initialize(INBus *readRegister1BusRef, INBus *readRegisterBus2Ref, INBus *writeRegisterBusRef,
                           INBus *writeDataBusRef,
                           INBus *writeControlBusRef) {
    this->readRegister1Bus = readRegister1BusRef;
    this->readRegister2Bus = readRegisterBus2Ref;
    this->writeRegisterBus = writeRegisterBusRef;
    this->writeDataBus = writeDataBusRef;
    this->writeControlBus = writeControlBusRef;
}

void Registers::updateIO() {
    this->readRegister1Bus->update();
    this->readRegister2Bus->update();
    this->writeDataBus->update();
    this->writeRegisterBus->update();
    this->writeControlBus->update();
}

void Registers::readRegisters() {
    this->readData1Bus->setValue(this->memory[this->readRegister1Bus->getValue()]);
    this->readData2Bus->setValue(this->memory[this->readRegister2Bus->getValue()]);
}

void Registers::writeRegisters() {
    if (this->writeControlBus->getValue()) {
        this->memory[this->writeRegisterBus->getValue()] = this->writeDataBus->getValue();
    }
}

OUTBus *Registers::getReadData1() const {
    return readData1Bus;
}

OUTBus *Registers::getReadData2() const {
    return readData2Bus;
}

const unsigned int *Registers::getMemory() const {
    return memory;
}

void Registers::printContents() {
    string str = "Registers:\n";

    str += "\tReadRegister1: " + to_string(this->readRegister1Bus->getValue()) + "\n";
    str += "\tReadRegister2: " + to_string(this->readRegister2Bus->getValue()) + "\n";
    str += "\twriteRegisterBus: " + to_string(this->writeRegisterBus->getValue()) + "\n";
    str += "\twriteDataBus: " + to_string(this->writeDataBus->getValue()) + "\n";
    str += "\twriteControlBus: " + to_string(this->writeControlBus->getValue()) + "\n";
    str += "\treadData1Bus: " + to_string(this->readData1Bus->getValue()) + "\n";
    str += "\treadData2Bus: " + to_string(this->readData2Bus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

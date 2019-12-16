//
// Created by Jedson Gabriel on 7/22/19.
//

#include "InstructionMemory.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

InstructionMemory::InstructionMemory() {
    this->readAddressBus = nullptr;
    this->memory = nullptr;

    this->instructionBus = new OUTBus();
}

void InstructionMemory::initialize(unsigned int *memoryRef, INBus *readAddressBusRef) {
    this->memory = memoryRef;
    this->readAddressBus = readAddressBusRef;
}

void InstructionMemory::updateIO() {
    this->readAddressBus->update();

    this->instructionBus->setValue(this->memory[this->readAddressBus->getValue()/4]);
}

OUTBus *InstructionMemory::getInstructionBus() const {
    return instructionBus;
}

void InstructionMemory::printContents() {
    string str = "InstructionMemory:\n";

    str += "\tReadAddressBus: " + to_string(this->readAddressBus->getValue()) + "\n";
    str += "\tInstructionBus: " + to_string(this->instructionBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}


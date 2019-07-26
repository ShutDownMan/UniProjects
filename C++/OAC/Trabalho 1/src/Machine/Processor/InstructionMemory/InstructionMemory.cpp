//
// Created by jarvis on 7/22/19.
//

#include "InstructionMemory.h"
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

void InstructionMemory::updateState() {
    this->instructionBus->setValue(this->memory[this->readAddressBus->getValue()/4]);
}

void InstructionMemory::updateIO() {
    this->readAddressBus->update();
}

OUTBus *InstructionMemory::getInstructionBus() const {
    return instructionBus;
}

void InstructionMemory::printContents() {
    string str = "InstructionMemory:\n";

    str += "\tReadAddressBus: " + to_string(this->readAddressBus->getValue()) + "\n";
    str += "\tInstructionBus: " + to_string(this->instructionBus->getValue()) + "\n";

    cout << str << endl;
}


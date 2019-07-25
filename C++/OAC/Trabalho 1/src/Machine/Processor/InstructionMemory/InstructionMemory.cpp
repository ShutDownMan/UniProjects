//
// Created by jarvis on 7/22/19.
//

#include "InstructionMemory.h"

InstructionMemory::InstructionMemory() {
    this->readAddressBus = nullptr;
    this->instructionBus = new OUTBus();
}

void InstructionMemory::initialize(unsigned int *memoryRef, INBus *readAddressBusRef) {
    this->memory = memoryRef;
    this->readAddressBus = readAddressBusRef;
}

void InstructionMemory::updateState() {
    this->instructionBus->setValue(this->memory[this->readAddressBus->getValue()]);
}

void InstructionMemory::updateIO() {
    this->readAddressBus->update();
}

OUTBus *InstructionMemory::getInstructionBus() const {
    return instructionBus;
}


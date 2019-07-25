//
// Created by jarvis on 7/22/19.
//

#include "InstructionMemory.h"

InstructionMemory::InstructionMemory() {
    this->readAddressBus = nullptr;
    this->instructionBus = new OUTBus();
}

void InstructionMemory::updateState() {

}

void InstructionMemory::updateIO() {
    this->readAddressBus->update();
}

void InstructionMemory::initialize(INBus *readAddressBusRef) {
    this->readAddressBus = readAddressBusRef;
}

OUTBus *InstructionMemory::getInstructionBus() const {
    return instructionBus;
}


//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_INSTRUCTIONMEMORY_H
#define MIPS_MONOCYCLE_INSTRUCTIONMEMORY_H


#include "../../Bus/OUTBus.h"
#include "../../Bus/INBus.h"

class InstructionMemory {
private:
    unsigned int *memory;

    INBus *readAddressBus;

    OUTBus *instructionBus;

public:
    InstructionMemory();

    void updateState();

    void updateIO();

    void initialize(unsigned int *memoryRef, INBus *readAddressBusRef);

    OUTBus *getInstructionBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_INSTRUCTIONMEMORY_H

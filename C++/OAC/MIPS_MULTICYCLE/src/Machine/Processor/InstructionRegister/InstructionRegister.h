//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_INSTRUCTIONREGISTER_H
#define MIPS_MONOCYCLE_INSTRUCTIONREGISTER_H


#include "../../Bus/OUTBus.h"
#include "../../Bus/INBus.h"

class InstructionRegister {
private:
    INBus *inBus;
    INBus *IRWriteSignal;

    OUTBus *outBus;

public:
    InstructionRegister();

    void updateState();

    void initialize(INBus *inBusRef, INBus *IRWriteRef);

    OUTBus *getOutBus() const;

    void printContents();

    void updateIO();
};


#endif //MIPS_MONOCYCLE_INSTRUCTIONREGISTER_H

//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ADDER_H
#define MIPS_MONOCYCLE_ADDER_H


#include "../../Bus/INBus.h"
#include "../../Bus/OUTBus.h"

class Adder {
private:
    INBus *inputABus;
    INBus *inputBBus;

    OUTBus *outputBus{};

public:
    Adder();

    void updatePassive();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef);

    OUTBus *getOutputBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_ADDER_H

//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALU_H
#define MIPS_MONOCYCLE_ALU_H


#include "../../Bus/INBus.h"

class ALU {
private:
    INBus *inputABus;
    INBus *inputBBus;

    OUTBus *outBus;
    OUTBus *zeroBus;
public:
    ALU();

public:
    void updateIO();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef);

    OUTBus *getOutBus() const;

    OUTBus *getZeroBus() const;
};


#endif //MIPS_MONOCYCLE_ALU_H

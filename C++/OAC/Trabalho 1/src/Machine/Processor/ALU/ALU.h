//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALU_H
#define MIPS_MONOCYCLE_ALU_H

#include "../../Bus/INBus.h"

#define AND 0
#define OR 1
#define SUM 2
#define SUB 6
#define LST 7
#define NOR 12

class ALU {
private:
    INBus *inputABus;
    INBus *inputBBus;
    INBus *controlBus;

    OUTBus *outBus;
    OUTBus *zeroBus;

public:
    ALU();

    void updateIO();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *aluControlBusRef);

    OUTBus *getOutBus() const;

    OUTBus *getZeroBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_ALU_H

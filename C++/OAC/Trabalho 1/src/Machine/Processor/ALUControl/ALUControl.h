//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALUCONTROL_H
#define MIPS_MONOCYCLE_ALUCONTROL_H


#include "../../Bus/INBus.h"

class ALUControl {
private:
    INBus *instructionBus;
    INBus *controlBus;

    OUTBus *outBus;

public:
    ALUControl();

    void updateIO();

    void initialize(INBus *inBusRef, INBus *controlBusRef);

    OUTBus *getOutBus() const;
};


#endif //MIPS_MONOCYCLE_ALUCONTROL_H

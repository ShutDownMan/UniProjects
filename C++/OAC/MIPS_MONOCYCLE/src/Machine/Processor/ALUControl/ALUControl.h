//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALUCONTROL_H
#define MIPS_MONOCYCLE_ALUCONTROL_H

#include "../../Bus/INBus.h"

#define IS_JR_MASK 0x08u

class ALUControl {
private:
    INBus *functBus;
    INBus *controlBus;

    OUTBus *outBus;
    OUTBus *BranchJumpSrcSignal;
public:
    OUTBus *getBranchJumpSrcSignal() const;

public:
    ALUControl();

    void updateIO();

    void initialize(INBus *inBusRef, INBus *controlBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_ALUCONTROL_H

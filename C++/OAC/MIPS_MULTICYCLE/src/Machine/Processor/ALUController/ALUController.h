//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALUCONTROL_H
#define MIPS_MONOCYCLE_ALUCONTROL_H

#include "../../Bus/INBus.h"

#define IS_JR_MASK 0x08u

class ALUController {
private:
    INBus *functBus;
    INBus *controlBus;

    OUTBus *outBus;
    OUTBus *BranchJumpSrcSignal;
public:
    OUTBus *getBranchJumpSrcSignal() const;

public:
    ALUController();

    void updatePassive();

    void initialize(INBus *functBusRef, INBus *controlBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_ALUCONTROL_H

//
// Created by Jedson Gabriel on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_ALUCONTROL_H
#define MIPS_MONOCYCLE_ALUCONTROL_H

#include "../../Bus/INBus.h"

#define IS_JR_MASK 0x08u
#define IS_ADD_MASK 0x20u
#define IS_SUB_MASK 0x22u
#define IS_AND_MASK 0x24u
#define IS_OR_MASK 0x25u
#define IS_SLT_MASK 0x2Au

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

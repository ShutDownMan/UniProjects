//
// Created by jarvis on 7/28/19.
//

#ifndef MIPS_MONOCYCLE_BRANCHCONTROL_H
#define MIPS_MONOCYCLE_BRANCHCONTROL_H


#include "../../Bus/INBus.h"

class BranchController {
private:
    INBus *pcWriteCondBus;
    INBus *zeroSignalBus;
    INBus *pcWriteBus;

    OUTBus *outBus;

public:
    BranchController();

    void initialize(INBus *pcWriteCondRef, INBus *pcWriteRef, INBus *zeroSignalBusRef);

    void updatePassive();

    void printContents();

    OUTBus *getOutBus() const;

};


#endif //MIPS_MONOCYCLE_BRANCHCONTROL_H

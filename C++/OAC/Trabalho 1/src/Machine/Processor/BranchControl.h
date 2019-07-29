//
// Created by jarvis on 7/28/19.
//

#ifndef MIPS_MONOCYCLE_BRANCHCONTROL_H
#define MIPS_MONOCYCLE_BRANCHCONTROL_H


#include "../Bus/INBus.h"

class BranchControl {
private:
    INBus *branchSignalBus;
    INBus *zeroSignalBus;
    INBus *jumpSignalBus;

    OUTBus *outBus;

public:
    BranchControl();

    void initialize(INBus *branchSignalBusRef, INBus *zeroSignalBusRef, INBus *jumpSignalBusRef);

    void updateIO();

    void printContents();

    OUTBus *getOutBus() const;

};


#endif //MIPS_MONOCYCLE_BRANCHCONTROL_H

//
// Created by Jedson Gabriel on 7/28/19.
//

#ifndef MIPS_MONOCYCLE_BRANCHCONTROL_H
#define MIPS_MONOCYCLE_BRANCHCONTROL_H


#include "../../Bus/INBus.h"

class BranchControl {
private:
    INBus *branchSignalBus;
    INBus *zeroSignalBus;

    OUTBus *outBus;

public:
    BranchControl();

    void initialize(INBus *branchSignalBusRef, INBus *zeroSignalBusRef);

    void updateIO();

    void printContents();

    OUTBus *getOutBus() const;

};


#endif //MIPS_MONOCYCLE_BRANCHCONTROL_H

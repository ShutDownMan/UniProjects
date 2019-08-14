//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_PCREGISTER_H
#define MIPS_MONOCYCLE_PCREGISTER_H


#include "../../Bus/INBus.h"

class PCRegister {
private:
    INBus *inBus;
    INBus *controlSignal;

    OUTBus *outBus;

public:
    PCRegister();

    void initialize(INBus *refInBus, INBus *controlSignalRef);

    void updateState();

    OUTBus *getOutBus() const;

    void printContents();

    void updatePassive();
};


#endif //MIPS_MONOCYCLE_PCREGISTER_H

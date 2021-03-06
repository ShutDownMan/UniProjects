//
// Created by Jedson Gabriel on 7/29/19.
//

#ifndef MIPS_MULTICYCLE_REGISTER_H
#define MIPS_MULTICYCLE_REGISTER_H


#include "../../Bus/INBus.h"

class Register {
private:
    INBus *inBus;
    INBus *controlSignal;

    OUTBus *outBus;

public:
    Register();

    void initialize(INBus *refInBus);

    OUTBus *getOutBus() const;

    void updatePassive();

    void initialize(INBus *refInBus, INBus *controlSignalRef);

    void printContents();
};


#endif //MIPS_MULTICYCLE_REGISTER_H

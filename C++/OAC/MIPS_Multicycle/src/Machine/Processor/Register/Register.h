//
// Created by jarvis on 7/29/19.
//

#ifndef MIPS_MULTICYCLE_REGISTER_H
#define MIPS_MULTICYCLE_REGISTER_H


#include "../../Bus/INBus.h"

class Register {
private:
    INBus *inBus;
    OUTBus *outBus;

public:
    Register();

    void initialize(INBus *refInBus);

    OUTBus *getOutBus() const;

    void printContents();

    void updatePassive();
};


#endif //MIPS_MULTICYCLE_REGISTER_H

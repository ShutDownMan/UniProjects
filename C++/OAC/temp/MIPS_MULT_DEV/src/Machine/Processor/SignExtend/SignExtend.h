//
// Created by Jedson Gabriel on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_SIGNEXTEND_H
#define MIPS_MONOCYCLE_SIGNEXTEND_H


#include "../../Bus/INBus.h"
#include "../../Bus/OUTBus.h"

class SignExtend {
private:
    INBus *inBus;
    OUTBus *outBus;

public:
    SignExtend();

    void updatePassive();

    void initialize(INBus *inBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_SIGNEXTEND_H

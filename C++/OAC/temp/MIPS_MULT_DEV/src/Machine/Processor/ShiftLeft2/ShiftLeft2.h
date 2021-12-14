//
// Created by Jedson Gabriel on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_SHIFTLEFT2_H
#define MIPS_MONOCYCLE_SHIFTLEFT2_H


#include "../../Bus/INBus.h"

class ShiftLeft2 {
private:
    INBus *inBus;
    OUTBus *outBus;

public:
    ShiftLeft2();

    void updatePassive();

    void initialize(INBus *inBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_SHIFTLEFT2_H
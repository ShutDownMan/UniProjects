//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_SHIFTLEFT2_H
#define MIPS_MONOCYCLE_SHIFTLEFT2_H


#include "../../Bus/INBus.h"

class ShiftLeft2 {
private:
    INBus *inBus{};
    OUTBus *outBus{};
public:
    OUTBus *getOutBus() const;

public:
    void updateState();

    void updateIO();

    void initialize(INBus *inBusRef);
};


#endif //MIPS_MONOCYCLE_SHIFTLEFT2_H

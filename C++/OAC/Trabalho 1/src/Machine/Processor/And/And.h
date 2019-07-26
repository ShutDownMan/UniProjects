//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_AND_H
#define MIPS_MONOCYCLE_AND_H


#include "../../Bus/INBus.h"

class And {
private:
    INBus *inputABus;
    INBus *inputBBus;

    OUTBus *outBus;

public:
    And();

    void updateIO();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_AND_H

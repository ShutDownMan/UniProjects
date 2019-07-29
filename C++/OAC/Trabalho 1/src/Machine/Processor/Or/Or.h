//
// Created by jarvis on 7/26/19.
//

#ifndef MIPS_MONOCYCLE_OR_H
#define MIPS_MONOCYCLE_OR_H


#include "../../Bus/INBus.h"

class Or {

private:
    INBus *inputABus;
    INBus *inputBBus;

    OUTBus *outBus;

public:
    Or();

    void updateIO();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef);

    OUTBus *getOutBus() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_OR_H

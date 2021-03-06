//
// Created by Jedson Gabriel on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_MULTIPLEXER_H
#define MIPS_MONOCYCLE_MULTIPLEXER_H


#include "../../Bus/INBus.h"

class Multiplexer {
private:
    INBus *inputABus;
    INBus *inputBBus;
    INBus *controlSignal;

    OUTBus *outBus;

public:
    Multiplexer();

    void updateIO();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *controlSignalRef);

    OUTBus *getOutputBus() const;

    void printContents();
};


#endif // MIPS_MONOCYCLE_MULTIPLEXER_H

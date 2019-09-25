//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_MULTIPLEXER_H
#define MIPS_MONOCYCLE_MULTIPLEXER_H


#include "../../Bus/INBus.h"

class Multiplexer {
private:
    INBus *inputABus;
    INBus *inputBBus;
    INBus *inputCBus;
    INBus *inputDBus;
    INBus *controlSignal;

    OUTBus *outBus;

public:
    Multiplexer();

    void updatePassive();

    void initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *controlSignalRef);

    void initialize(INBus *inputABusRef, INBus *inputBBusRef, INBus *inputCBusRef, INBus *inputDBusRef,
                    INBus *controlSignalRef);

    OUTBus *getOutBus() const;

    void printContents();

};


#endif // MIPS_MONOCYCLE_MULTIPLEXER_H

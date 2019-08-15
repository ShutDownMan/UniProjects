//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_DATAMEMORY_H
#define MIPS_MONOCYCLE_DATAMEMORY_H


#include "../../Bus/INBus.h"

class Memory {

private:
    unsigned char *memory;

    INBus *addressBus;
    INBus *writeDataBus;
    INBus *writeMemControlBus;
    INBus *readMemControlBus;

    OUTBus *memDataBus;

public:
    Memory();

    void updateState();

    void initialize(unsigned char *memoryRef, INBus *addressBusRef, INBus *writeDataRef, INBus *writeMemControlBusRef,
                    INBus *readMemControlBusRef);

    OUTBus *getMemDataBus() const;

    const unsigned char *getMemory() const;

    void printContents();

    void updateIO();

    void writeMem();
};


#endif //MIPS_MONOCYCLE_DATAMEMORY_H

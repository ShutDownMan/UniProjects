//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_DATAMEMORY_H
#define MIPS_MONOCYCLE_DATAMEMORY_H


#include "../../Bus/INBus.h"

class DataMemory {

private:
    unsigned char memory[65536] = {0};

    INBus *addressBus;
    INBus *writeDataBus;
    INBus *writeMemControlBus;
    INBus *readMemControlBus;

    OUTBus *readDataBus;

public:
    DataMemory();

    void updateState();

    void updateIO();

    void
    initialize(INBus *addressBusRef, INBus *writeDataRef, INBus *writeMemControlBusRef, INBus *readMemControlBusRef);

    OUTBus *getReadDataBus() const;

    const unsigned char *getMemory() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_DATAMEMORY_H

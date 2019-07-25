//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_DATAMEMORY_H
#define MIPS_MONOCYCLE_DATAMEMORY_H


#include "../../Bus/INBus.h"

class DataMemory {
private:
    INBus *addressBus;
    INBus *writeData = nullptr;

    OUTBus *readDataBus;

public:
    DataMemory();

    void updateState();

    void updateIO();

    void initialize(INBus *addressBusRef, INBus *writeDataRef);

    OUTBus *getReadDataBus() const;
};


#endif //MIPS_MONOCYCLE_DATAMEMORY_H

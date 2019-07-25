//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_REGISTERS_H
#define MIPS_MONOCYCLE_REGISTERS_H


#include "../../Bus/INBus.h"
#include "../../Bus/OUTBus.h"

class Registers {
private:
    INBus *readRegister1Bus;
    INBus *readRegister2Bus;
    INBus *writeRegisterBus;
    INBus *writeDataBus;

    OUTBus *readData1Bus;
    OUTBus *readData2Bus;

public:
    Registers();

    void updateState();

    void updateIO();

    void initialize(INBus *readRegister1BusRef, INBus *readRegisterBus2Ref, INBus *writeRegisterBusRef,
                    INBus *writeDataBusRef);

    OUTBus *getReadData1() const;

    OUTBus *getReadData2() const;
};


#endif //MIPS_MONOCYCLE_REGISTERS_H

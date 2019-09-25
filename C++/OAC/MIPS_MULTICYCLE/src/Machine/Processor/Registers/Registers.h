//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_REGISTERS_H
#define MIPS_MONOCYCLE_REGISTERS_H


#include "../../Bus/INBus.h"
#include "../../Bus/OUTBus.h"

class Registers {
private:
    unsigned int memory[32] = {0};

    INBus *readRegister1Bus;
    INBus *readRegister2Bus;
    INBus *writeRegisterBus;
    INBus *writeDataBus;

    INBus *writeControlBus;

    OUTBus *readData1Bus;
    OUTBus *readData2Bus;

public:
    Registers();

    void writeRegisters();

    void initialize(INBus *readRegister1BusRef, INBus *readRegisterBus2Ref, INBus *writeRegisterBusRef,
                    INBus *writeDataBusRef,
                    INBus *writeControlBusRef);

    const unsigned int *getMemory() const;

    OUTBus *getReadData1() const;

    OUTBus *getReadData2() const;

    void printContents();

    void updateIO();

    void readRegisters();
};


#endif //MIPS_MONOCYCLE_REGISTERS_H

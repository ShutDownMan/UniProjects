//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_PCREGISTER_H
#define MIPS_MONOCYCLE_PCREGISTER_H


#include "../../Bus/INBus.h"

class PCRegister {
private:
    INBus *inBus;
    OUTBus *outBus;

public:
    PCRegister();

    void initialize(INBus *refInBus);

    void updateState();

    void updateIO();

    OUTBus *getOutBus() const;

};


#endif //MIPS_MONOCYCLE_PCREGISTER_H

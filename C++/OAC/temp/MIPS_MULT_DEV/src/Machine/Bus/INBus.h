//
// Created by Jedson Gabriel on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_INBUS_H
#define MIPS_MONOCYCLE_INBUS_H

#include <strings.h>
#include "OUTBus.h"

class INBus {

private:
    unsigned int value;
    unsigned int mask;

    unsigned char fistSetBit;

    OUTBus *refBus;

public:
    explicit INBus(unsigned int mask, OUTBus *refBus);

    explicit INBus(OUTBus *refBus);

    void update();

    unsigned int getValue() const;

    void printContents();
};


#endif //MIPS_MONOCYCLE_INBUS_H

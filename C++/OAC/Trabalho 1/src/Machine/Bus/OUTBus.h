//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_OUTBUS_H
#define MIPS_MONOCYCLE_OUTBUS_H


class OUTBus {
private:
    unsigned int value;

public:
    OUTBus();

    int getValue() const;

    void setValue(unsigned int newValue);

};


#endif //MIPS_MONOCYCLE_OUTBUS_H

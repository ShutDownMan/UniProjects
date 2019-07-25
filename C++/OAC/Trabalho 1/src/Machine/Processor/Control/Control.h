//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_CONTROL_H
#define MIPS_MONOCYCLE_CONTROL_H

#include "../../Bus/OUTBus.h"
#include "../../Bus/INBus.h"

#define IS_RTYPE_INSTRUCTION    0x3F
#define IS_LW_INSTRUCTION       0x23
#define IS_SW_INSTRUCTION       0x2B
#define IS_BEQ_INSTRUCTION      0x04

typedef enum InstructionType {
    RTYPE,
    LW,
    SW,
    BEQ,
    NONE
} InstructionType;

class Control {
private:
    INBus *inBus;

    OUTBus *RegDstSignal;

private:
    OUTBus *BranchSignal;
    OUTBus *MemReadSignal;
    OUTBus *MemToRegSignal;
    OUTBus *ALUOpSignal;
    OUTBus *MemWriteSignal;
    OUTBus *ALUSrcSignal;
    OUTBus *RegWriteSignal;

public:
    Control();

    void updateIO();

    void initialize(INBus *inBusRef);

    OUTBus *getRegDstSignal() const;

    OUTBus *getBranchSignal() const;

    OUTBus *getMemReadSignal() const;

    OUTBus *getMemToRegSignal() const;

    OUTBus *getAluOpSignal() const;

    OUTBus *getMemWriteSignal() const;

    OUTBus *getAluSrcSignal() const;

    OUTBus *getRegWriteSignal() const;


    unsigned int testRegisterDestinationSignal(InstructionType type);

    InstructionType getInstructionType();
};


#endif //MIPS_MONOCYCLE_CONTROL_H

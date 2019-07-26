//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_CONTROL_H
#define MIPS_MONOCYCLE_CONTROL_H

#include "../../Bus/OUTBus.h"
#include "../../Bus/INBus.h"

#define IS_RTYPE_INSTRUCTION    0x00u
#define IS_LW_INSTRUCTION       0x23u
#define IS_SW_INSTRUCTION       0x2Bu
#define IS_BEQ_INSTRUCTION      0x04u
#define IS_LI_INSTRUCTION       0x0Fu

typedef enum InstructionType {
    RTYPE,
    LW,
    SW,
    BEQ,
    LI,
    NONE
} InstructionType;
static const char * InstructionTypeStrings[] = { "RTYPE", "LW", "SW", "BEQ", "LI", "NONE" };

class Control {

private:
    INBus *inBus;

    OUTBus *BranchSignal;
    OUTBus *MemReadSignal;
    OUTBus *MemToRegSignal;
    OUTBus *ALUOpSignal;
    OUTBus *MemWriteSignal;
    OUTBus *ALUSrcSignal;
    OUTBus *RegWriteSignal;
    OUTBus *RegDstSignal;
    OUTBus *RegDataSrcSignal;
public:
    OUTBus *getRegDataSrc() const;

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


    InstructionType getInstructionType();

    void printContents();
};


#endif //MIPS_MONOCYCLE_CONTROL_H

//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MULTICYCLE_PROCESSOR_H
#define MIPS_MULTICYCLE_PROCESSOR_H

#include <cstdio>
#include "Processor/PCRegister/PCRegister.h"
#include "Processor/Multiplexer/Multiplexer.h"
#include "Processor/Memory/Memory.h"
#include "Processor/Register/Register.h"
#include "Processor/Controller/Controller.h"
#include "Processor/BranchController/BranchController.h"
#include "Processor/Registers/Registers.h"
#include "Processor/SignExtend/SignExtend.h"
#include "Processor/ShiftLeft2/ShiftLeft2.h"
#include "Processor/ALUController/ALUController.h"
#include "Processor/ALU/ALU.h"
#include "Processor/InstructionRegister/InstructionRegister.h"


class Processor {
public:
    Register *pc;

    Multiplexer *IorDMux;

    Memory *memory;

    Register *instructionRegister;

    Register *memoryDataRegister;

    Controller *controller;

    BranchController *pcRegisterController;

    Multiplexer *regDstMux;

    Multiplexer *memToRegMux;

    Registers *registers;

    SignExtend *signExtend;

    ShiftLeft2 *aluShiftLeft2;

    Register *registerA;

    Register *registerB;

    Multiplexer *aluSrcAMux;

    OUTBus *num4Const;

    Multiplexer *aluSrcBMux;

    ShiftLeft2 *pcShiftLeft2;

    ALUController *aluController;

    ALU *alu;

    Register *aluOut;

    Multiplexer *pcSourceMux;

public:
    Processor();

    void initialize(unsigned char *memoryRef);

    void clock();

    void updatePassive();

    void printRegisters();

    void printMemory();

    void updateController();
};


#endif //MIPS_MULTICYCLE_PROCESSOR_H

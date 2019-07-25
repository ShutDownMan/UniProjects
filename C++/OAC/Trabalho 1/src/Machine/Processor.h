//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_PROCESSOR_H
#define MIPS_MONOCYCLE_PROCESSOR_H

#include <cstdio>

#include "Processor/PCRegister/PCRegister.h"
#include "Processor/Adder/Adder.h"
#include "Processor/InstructionMemory/InstructionMemory.h"
#include "Processor/Control/Control.h"
#include "Processor/Multiplexer/Multiplexer.h"
#include "Processor/Registers/Registers.h"
#include "Processor/SignExtend/SignExtend.h"
#include "Processor/ShiftLeft2/ShiftLeft2.h"
#include "Processor/ALUControl/ALUControl.h"
#include "Processor/ALU/ALU.h"
#include "Processor/And/And.h"
#include "Processor/DataMemory/DataMemory.h"

class Processor {
public:
    PCRegister *pc = new PCRegister();

    OUTBus *num4Const = new OUTBus();

    Adder *adder_1 = new Adder();

    InstructionMemory *instructionMemory = new InstructionMemory();

    Control *control = new Control();

    Multiplexer *regDstMux = new Multiplexer();

    Registers *registers = new Registers();

    SignExtend *signExtend = new SignExtend();

    ShiftLeft2 *shiftLeft2 = new ShiftLeft2();

    Multiplexer *aluSrcMux = new Multiplexer();

    ALUControl *aluControl = new ALUControl();

    Adder *adder_2 = new Adder();

    ALU *alu = new ALU();

    And *branchZeroAnd = new And();

    Multiplexer *branchZeroMux = new Multiplexer();

    DataMemory *dataMemory = new DataMemory();

    Multiplexer *memToRegMux = new Multiplexer();

public:
    Processor();

    void initialize();

    void clock();

    void updateIO();
};


#endif //MIPS_MONOCYCLE_PROCESSOR_H

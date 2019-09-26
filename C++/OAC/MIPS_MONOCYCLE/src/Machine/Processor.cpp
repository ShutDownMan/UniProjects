//
// Created by jarvis on 7/22/19.
//

#include <cstring>
#include "Processor.h"
#include "Machine.h"

Processor::Processor() = default;

void Processor::initialize(unsigned int *instructionMemoryRef) {
    Machine::debugInfo("Initializing Component: PC Register", 2);
    this->pc->initialize(new INBus(jumpMultiplexer->getOutputBus()));

    Machine::debugInfo("Initializing Component: Number 4 const", 2);
    this->num4Const->setValue(4);

    Machine::debugInfo("Initializing Component: Adder 1", 2);
    this->adder_1->initialize(new INBus(pc->getOutBus()),
                              new INBus(this->num4Const));

    Machine::debugInfo("Initializing Component: Instruction Memory", 2);
    this->instructionMemory->initialize(instructionMemoryRef,
                                        new INBus(pc->getOutBus()));

    Machine::debugInfo("Initializing Component: Controller", 2);
    this->control->initialize(new INBus(0xFC000000, instructionMemory->getInstructionBus()));

    Machine::debugInfo("Initializing Component: Register Destination Multiplexer", 2);
    this->regDstMux->initialize(new INBus(0x001F0000, this->instructionMemory->getInstructionBus()),
                                new INBus(0x0000F800, this->instructionMemory->getInstructionBus()),
                                new INBus(this->control->getRegDstSignal()));

    Machine::debugInfo("Initializing Component: Register Data Source Multiplexer", 2);
    this->regDataSrcMux->initialize(new INBus(this->memToRegMux->getOutputBus()),
                                    new INBus(this->signExtend->getOutputBus()),
                                    new INBus(this->control->getRegDataSrc()));

    Machine::debugInfo("Initializing Component: Register Data Source Multiplexer", 2);
    this->branchMultiplexer->initialize(new INBus(this->signExtend->getOutputBus()),
                                        new INBus(this->registers->getReadData1()),
                                        new INBus(this->aluControl->getBranchJumpSrcSignal()));

    Machine::debugInfo("Initializing Component: Registers", 2);
    this->registers->initialize(new INBus(0x03E00000, this->instructionMemory->getInstructionBus()),
                                new INBus(0x001F0000, this->instructionMemory->getInstructionBus()),
                                new INBus(this->regDstMux->getOutputBus()),
                                new INBus(this->regDataSrcMux->getOutputBus()),
                                new INBus(this->control->getRegWriteSignal()));

    Machine::debugInfo("Initializing Component: Sign Extend", 2);
    this->signExtend->initialize(new INBus(0x0000FFFF, this->instructionMemory->getInstructionBus()));

    Machine::debugInfo("Initializing Component: Shift Left 2", 2);
    this->shiftLeft2->initialize(new INBus(this->signExtend->getOutputBus()));

    Machine::debugInfo("Initializing Component: Alu Source Multiplexer", 2);
    this->aluSrcMux->initialize(new INBus(this->registers->getReadData2()),
                                new INBus(this->signExtend->getOutputBus()),
                                new INBus(this->control->getAluSrcSignal()));

    Machine::debugInfo("Initializing Component: Alu Controller", 2);
    this->aluControl->initialize(new INBus(0x0000002F, this->instructionMemory->getInstructionBus()),
                                 new INBus(0x00000003, this->control->getAluOpSignal()));

    Machine::debugInfo("Initializing Component: Adder 2", 2);
    this->adder_2->initialize(new INBus(this->shiftLeft2->getOutBus()),
                              new INBus(this->adder_1->getOutputBus()));

    Machine::debugInfo("Initializing Component: ALU", 2);
    this->alu->initialize(new INBus(this->registers->getReadData1()),
                          new INBus(this->aluSrcMux->getOutputBus()),
                          new INBus(0x0000000F, this->aluControl->getOutBus()));

    this->branchControl->initialize(new INBus(0x03, this->control->getBranchSignal()),
                                    new INBus(this->alu->getZeroBus()));

    Machine::debugInfo("Initializing Component: Branch Multiplexer", 2);
    this->branchMux->initialize(new INBus(this->adder_1->getOutputBus()),
                                new INBus(this->adder_2->getOutputBus()),
                                new INBus(this->branchControl->getOutBus()));

    Machine::debugInfo("Initializing Component: Jump Multiplexer", 2);
    this->jumpMultiplexer->initialize(new INBus(this->branchMux->getOutputBus()),
                                      new INBus(this->signExtend->getOutputBus()),
                                      new INBus(this->control->getBranchJumpSignal()));


    Machine::debugInfo("Initializing Component: Data Memory", 2);
    this->dataMemory->initialize(new INBus(this->alu->getOutBus()),
                                 new INBus(this->registers->getReadData2()),
                                 new INBus(this->control->getMemWriteSignal()),
                                 new INBus(this->control->getMemReadSignal()));

    Machine::debugInfo("Initializing Component: Memory to Register Multiplexer", 2);
    this->memToRegMux->initialize(new INBus(this->alu->getOutBus()),
                                  new INBus(this->dataMemory->getReadDataBus()),
                                  new INBus(this->control->getMemToRegSignal()));
}

void Processor::raisingEdge() {
    Machine::debugInfo("Clocking Component: PC Register", 2);
    pc->updateState();
    pc->printContents();
}

void Processor::fallingEdge() {
    Machine::debugInfo("Clocking Component: Registers", 2);
    registers->updateState();
    registers->printContents();

    Machine::debugInfo("Clocking Component: Data Memory", 2);
    dataMemory->updateState();
    dataMemory->printContents();
}

void Processor::passive() {
    Machine::debugInfo("Updating Component: PC Register", 2);
    pc->updateIO();
    pc->printContents();

    Machine::debugInfo("Updating Component: Adder 1", 2);
    adder_1->updateIO();
    adder_1->printContents();

    Machine::debugInfo("Updating Component: Instruction Memory", 2);
    instructionMemory->updateIO();
    instructionMemory->printContents();

    Machine::debugInfo("Updating Component: Controller", 2);
    control->updateIO();
    control->printContents();

    Machine::debugInfo("Updating Component: Register Destination Multiplexer", 2);
    regDstMux->updateIO();
    regDstMux->printContents();

    Machine::debugInfo("Updating Component: Register Data Source Multiplexer", 2);
    regDataSrcMux->updateIO();
    regDataSrcMux->printContents();

    Machine::debugInfo("Updating Component: Registers", 2);
    registers->updateIO();
    registers->printContents();

    Machine::debugInfo("Updating Component: Sign Extend", 2);
    signExtend->updateIO();
    signExtend->printContents();

    Machine::debugInfo("Updating Component: Branch Source Multiplexer", 2);
    branchMultiplexer->updateIO();
    branchMultiplexer->printContents();

    Machine::debugInfo("Updating Component: Shift Left 2", 2);
    shiftLeft2->updateIO();
    shiftLeft2->printContents();

    Machine::debugInfo("Updating Component: Alu Source Multiplexer", 2);
    aluSrcMux->updateIO();
    aluSrcMux->printContents();

    Machine::debugInfo("Updating Component: Alu Controller", 2);
    aluControl->updateIO();
    aluControl->printContents();

    Machine::debugInfo("Updating Component: Adder 2", 2);
    adder_2->updateIO();
    adder_2->printContents();

    Machine::debugInfo("Updating Component: ALU", 2);
    alu->updateIO();
    alu->printContents();

    Machine::debugInfo("Updating Component: Branch Control", 2);
    branchControl->updateIO();
    branchControl->printContents();

    Machine::debugInfo("Updating Component: Branch Multiplexer", 2);
    branchMux->updateIO();
    branchMux->printContents();

    Machine::debugInfo("Updating Component: Jump Multiplexer", 2);
    jumpMultiplexer->updateIO();
    jumpMultiplexer->printContents();

    Machine::debugInfo("Updating Component: Data Memory", 2);
    dataMemory->updateIO();
    dataMemory->printContents();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer", 2);
    memToRegMux->updateIO();
    memToRegMux->printContents();

    /// Second update

    Machine::debugInfo("Updating Component: PC Register", 2);
    pc->updateIO();
    pc->printContents();

    Machine::debugInfo("Updating Component: Register Data Source Multiplexer", 2);
    regDataSrcMux->updateIO();
    regDataSrcMux->printContents();

    Machine::debugInfo("Updating Component: Registers", 2);
    registers->updateIO();
    registers->printContents();
}

void Processor::printRegisters() {
    unsigned int const *registersMem = this->registers->getMemory();

    for (int i = 0; i < 32; ++i) {
        if (registersMem[i])
            printf("$%d = %d\n", i, (int) registersMem[i]);
    }
}

void Processor::printMemory() {
    unsigned char const *dataMem = this->dataMemory->getMemory();
    int val;

    for (int i = 0; i < 65536; ++i) {
        memcpy(&val, &dataMem[i], sizeof(int));
        if (dataMem[i])
            printf("MEM[%d] = 0x%x\n", i, val);
    }
}

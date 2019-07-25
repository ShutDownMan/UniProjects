//
// Created by jarvis on 7/22/19.
//

#include "Processor.h"
#include "Machine.h"

Processor::Processor() = default;

void Processor::initialize() {
    Machine::debugInfo("Initializing Component: PC Register");
    this->pc->initialize(new INBus(branchZeroMux->getOutBus()));

    Machine::debugInfo("Initializing Component: Number 4 const");
    this->num4Const->setValue(4);

    Machine::debugInfo("Initializing Component: Adder 1");
    this->adder_1->initialize(new INBus(pc->getOutBus()),
                              new INBus(this->num4Const));

    Machine::debugInfo("Initializing Component: Instruction Memory");
    this->instructionMemory->initialize(new INBus(pc->getOutBus()));

    Machine::debugInfo("Initializing Component: Controller");
    this->control->initialize(new INBus(0xFE000000, instructionMemory->getInstructionBus()));

    Machine::debugInfo("Initializing Component: Register Destination Multiplexer");
    this->regDstMux->initialize(new INBus(0x001F0000, this->instructionMemory->getInstructionBus()),
                                new INBus(0x00007C00, this->instructionMemory->getInstructionBus()),
                                new INBus(0xFE000000, this->control->getRegDstSignal()));

    Machine::debugInfo("Initializing Component: Registers");
    this->registers->initialize(new INBus(0x01F00000, this->instructionMemory->getInstructionBus()),
                                new INBus(0x001F0000, this->instructionMemory->getInstructionBus()),
                                new INBus(this->regDstMux->getOutBus()),
                                new INBus(this->memToRegMux->getOutBus()));

    Machine::debugInfo("Initializing Component: Sign Extend");
    this->signExtend->initialize(new INBus(0x0000FFFF, this->instructionMemory->getInstructionBus()));

    Machine::debugInfo("Initializing Component: Shift Left 2");
    this->shiftLeft2->initialize(new INBus(this->signExtend->getOutBus()));

    Machine::debugInfo("Initializing Component: Alu Source Multiplexer");
    this->aluSrcMux->initialize(new INBus(this->registers->getReadData2()),
                                new INBus(this->signExtend->getOutBus()),
                                new INBus(this->control->getAluSrcSignal()));

    Machine::debugInfo("Initializing Component: Alu Controller");
    this->aluControl->initialize(new INBus(0x0000002F, this->instructionMemory->getInstructionBus()),
                                 new INBus(this->control->getAluOpSignal()));

    Machine::debugInfo("Initializing Component: Adder 2");
    this->adder_2->initialize(new INBus(this->shiftLeft2->getOutBus()),
                              new INBus(this->adder_1->getOutputBus()));

    Machine::debugInfo("Initializing Component: ALU");
    this->alu->initialize(new INBus(this->registers->getReadData1()),
                          new INBus(this->aluSrcMux->getOutBus()));

    Machine::debugInfo("Initializing Component: Branch-Zero And");
    this->branchZeroAnd->initialize(new INBus(this->control->getBranchSignal()),
                                    new INBus(this->alu->getZeroBus()));

    Machine::debugInfo("Initializing Component: Branch-Zero Multiplexer");
    this->branchZeroMux->initialize(new INBus(this->adder_1->getOutputBus()),
                                    new INBus(this->adder_2->getOutputBus()),
                                    new INBus(this->branchZeroAnd->getOutBus()));

    Machine::debugInfo("Initializing Component: Data Memory");
    this->dataMemory->initialize(new INBus(this->alu->getOutBus()),
                                 new INBus(this->registers->getReadData2()));

    Machine::debugInfo("Initializing Component: Memory to Register Multiplexer");
    this->memToRegMux->initialize(new INBus(this->dataMemory->getReadDataBus()),
                                  new INBus(this->alu->getOutBus()),
                                  new INBus(this->control->getMemToRegSignal()));
}

void Processor::clock() {
    Machine::debugInfo("Clocking Component: PC Register");
    pc->updateState();

    Machine::debugInfo("Clocking Component: Instruction Memory");
    instructionMemory->updateState();

    Machine::debugInfo("Clocking Component: Registers");
    registers->updateState();

    Machine::debugInfo("Clocking Component: Data Memory");
    dataMemory->updateState();
}

void Processor::updateIO() {
    Machine::debugInfo("Updating Component: PC Register");
    pc->updateIO();

//    Machine::debugInfo("Initializing Component: Number 4 const");

    Machine::debugInfo("Updating Component: Adder 1");
    adder_1->updateIO();

    Machine::debugInfo("Updating Component: Instruction Memory");
    instructionMemory->updateIO();

    Machine::debugInfo("Updating Component: Controller");
    control->updateIO();

    Machine::debugInfo("Updating Component: Register Destination Multiplexer");
    regDstMux->updateIO();

    Machine::debugInfo("Updating Component: Registers");
    registers->updateIO();

    Machine::debugInfo("Updating Component: Sign Extend");
    signExtend->updateIO();

    Machine::debugInfo("Updating Component: Shift Left 2");
    shiftLeft2->updateIO();

    Machine::debugInfo("Updating Component: Alu Source Multiplexer");
    aluSrcMux->updateIO();

    Machine::debugInfo("Updating Component: Alu Controller");
    aluControl->updateIO();

    Machine::debugInfo("Updating Component: Adder 2");
    adder_2->updateIO();

    Machine::debugInfo("Updating Component: ALU");
    alu->updateIO();

    Machine::debugInfo("Updating Component: Branch-Zero And");
    branchZeroAnd->updateIO();

    Machine::debugInfo("Updating Component: Branch-Zero Multiplexer");
    branchZeroMux->updateIO();

    Machine::debugInfo("Updating Component: Data Memory");
    dataMemory->updateIO();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer");
    memToRegMux->updateIO();
}

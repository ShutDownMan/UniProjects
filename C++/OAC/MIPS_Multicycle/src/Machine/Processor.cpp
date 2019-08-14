//
// Created by jarvis on 7/22/19.
//

#include <cstring>

#include "Processor.h"
#include "Machine.h"

Processor::Processor() {
    this->pc = new PCRegister();

    this->IorDMux = new Multiplexer();

    this->memory = new Memory();

    this->instructionRegister = new InstructionRegister();

    this->memoryDataRegister = new Register();

    this->controller = new Controller();

    this->pcRegisterController = new BranchController();

    this->regDstMux = new Multiplexer();

    this->memToRegMux = new Multiplexer();

    this->registers = new Registers();

    this->signExtend = new SignExtend();

    this->aluShiftLeft2 = new ShiftLeft2();

    this->registerA = new Register();

    this->registerB = new Register();

    this->aluSrcAMux = new Multiplexer();

    this->num4Const = new OUTBus();

    this->aluSrcBMux = new Multiplexer();

    this->pcShiftLeft2 = new ShiftLeft2();

    this->aluController = new ALUController;

    this->alu = new ALU();

    this->aluOut = new Register();

    this->pcSourceMux = new Multiplexer();
}

void Processor::initialize(unsigned char *memoryRef) {
    Machine::debugInfo("Initializing Component: PC Register", 1);
    this->pc->initialize(new INBus(pcSourceMux->getOutBus()),
                         new INBus(this->pcRegisterController->getOutBus()));

    Machine::debugInfo("Initializing Component: IorDMux", 1);
    this->IorDMux->initialize(new INBus(this->pc->getOutBus()),
                              new INBus(this->aluOut->getOutBus()),
                              new INBus(this->controller->getIorDSignal()));


    Machine::debugInfo("Initializing Component: Memory", 1);
    this->memory->initialize(memoryRef, new INBus(this->IorDMux->getOutBus()),
                             new INBus(this->registerB->getOutBus()),
                             new INBus(this->controller->getMemWriteSignal()),
                             new INBus(this->controller->getMemReadSignal()));

    Machine::debugInfo("Initializing Component: Instruction Register", 1);
    this->instructionRegister->initialize(new INBus(this->memory->getMemDataBus()),
                                          new INBus(this->controller->getIRWriteSignal()));

    Machine::debugInfo("Initializing Component: Memory Data Register", 1);
    this->memoryDataRegister->initialize(new INBus(this->memory->getMemDataBus()));

    Machine::debugInfo("Initializing Component: Controller", 1);
    this->controller->initialize(new INBus(0xFC000000, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: PC Register Controller", 1);
    this->pcRegisterController->initialize(new INBus(this->controller->getPCWriteCondSignal()),
                                           new INBus(this->controller->getPCWriteSignal()),
                                           new INBus(this->alu->getZeroBus()));


    Machine::debugInfo("Initializing Component: Register Destination Multiplexer", 1);
    this->regDstMux->initialize(new INBus(0x001F0000, this->instructionRegister->getOutBus()),
                                new INBus(0x0000F800, this->instructionRegister->getOutBus()),
                                new INBus(this->controller->getRegDstSignal()));

    Machine::debugInfo("Initializing Component: Memory to Register Multiplexer", 1);
    this->memToRegMux->initialize(new INBus(this->aluOut->getOutBus()),
                                  new INBus(this->memoryDataRegister->getOutBus()),
                                  new INBus(this->controller->getMemToRegSignal()));

    Machine::debugInfo("Initializing Component: Registers", 1);
    this->registers->initialize(new INBus(0x03E00000, this->instructionRegister->getOutBus()),
                                new INBus(0x001F0000, this->instructionRegister->getOutBus()),
                                new INBus(this->regDstMux->getOutBus()),
                                new INBus(this->memToRegMux->getOutBus()),
                                new INBus(this->controller->getRegWriteSignal()));

    Machine::debugInfo("Initializing Component: Sign Extend", 1);
    this->signExtend->initialize(new INBus(0x0000FFFF, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: ALU Shift Left 2", 1);
    this->aluShiftLeft2->initialize(new INBus(this->signExtend->getOutBus()));

    Machine::debugInfo("Initializing Component: A Register", 1);
    this->registerA->initialize(new INBus(this->registers->getReadData1()));

    Machine::debugInfo("Initializing Component: B Register", 1);
    this->registerB->initialize(new INBus(this->registers->getReadData2()));

    Machine::debugInfo("Initializing Component: Alu Source A Multiplexer", 1);
    this->aluSrcAMux->initialize(new INBus(this->pc->getOutBus()),
                                 new INBus(this->registerA->getOutBus()),
                                 new INBus(this->controller->getAluSrcASignal()));

    Machine::debugInfo("Initializing Component: Number 4 const", 1);
    this->num4Const->setValue(4);

    Machine::debugInfo("Initializing Component: Alu Source B Multiplexer", 1);
    this->aluSrcBMux->initialize(new INBus(this->registerB->getOutBus()),
                                 new INBus(this->num4Const),
                                 new INBus(this->signExtend->getOutBus()),
                                 new INBus(this->aluShiftLeft2->getOutBus()),
                                 new INBus(this->controller->getAluSrcBSignal()));

    Machine::debugInfo("Initializing Component: PC Register Shift Left 2", 1);
    this->pcShiftLeft2->initialize(new INBus(0x3FFFFFF, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: Alu Controller", 1);
    this->aluController->initialize(new INBus(0x0000002F, this->memory->getMemDataBus()),
                                    new INBus(0x00000003, this->controller->getAluOpSignal()));


    Machine::debugInfo("Initializing Component: ALU", 1);
    this->alu->initialize(new INBus(this->aluSrcAMux->getOutBus()),
                          new INBus(this->aluSrcBMux->getOutBus()),
                          new INBus(this->aluController->getOutBus()));

    Machine::debugInfo("Initializing Component: ALUOut Register", 1);
    this->aluOut->initialize(new INBus(this->alu->getOutBus()));

    Machine::debugInfo("Initializing Component: PC Source Multiplexer", 1);
    this->pcSourceMux->initialize(new INBus(this->alu->getOutBus()),
                                  new INBus(this->aluOut->getOutBus()),
                                  new INBus(this->pcShiftLeft2->getOutBus()),
                                  nullptr,
                                  new INBus(this->controller->getPCSourceSignal()));
}

void Processor::updateController() {

    Machine::debugInfo("Updating IO of Component: Controller", 1);
    this->controller->updateIO();

    Machine::debugInfo("Clocking Component: Controller", 1);
    this->controller->updateState();
    this->controller->printContents();
}

void Processor::clock() {
//    Machine::debugInfo("Clocking Component: PC Register");
//    this->pc->updatePassive();
//    this->pc->printContents();

    Machine::debugInfo("Updating IO of Component: Memory", 1);
    this->memory->updateIO();

    Machine::debugInfo("Updating IO of Component: Registers", 1);
    this->registers->updateIO();

    // -- //

    Machine::debugInfo("Clocking Component: Memory", 1);
    this->memory->updateState();
    this->memory->printContents();

//    Machine::debugInfo("Clocking Component: Memory Data Register");
//    this->memoryDataRegister->updatePassive();

    Machine::debugInfo("Clocking Component: Registers", 1);
    this->registers->updateState();
    this->registers->printContents();

//    Machine::debugInfo("Clocking Component: Register A");
//    this->registerA->updatePassive();
//
//    Machine::debugInfo("Clocking Component: Register B");
//    this->registerB->updatePassive();
//
//    Machine::debugInfo("Clocking Component: ALU Out Register");
//    this->aluOut->updatePassive();
}

void Processor::updatePassive() {
    Machine::debugInfo("Updating IO Component: PC Register", 1);
    this->pc->updatePassive();
    this->pc->printContents();

    Machine::debugInfo("Updating Component: IorD Multiplexer", 1);
    this->IorDMux->updatePassive();

    Machine::debugInfo("Updating IO Component: Memory Data Register", 1);
    this->memoryDataRegister->updatePassive();

    Machine::debugInfo("Updating IO Component: Instruction Register", 1);
    this->instructionRegister->updatePassive();
    this->instructionRegister->printContents();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer", 1);
    this->memToRegMux->updatePassive();
//    this->memToRegMux->printContents();

    Machine::debugInfo("Updating Component: Register Destination Multiplexer", 1);
    this->regDstMux->updatePassive();

    Machine::debugInfo("Updating Component: Registers", 1);
    this->registers->updatePassive();

    Machine::debugInfo("Updating Component: Sign Extend", 1);
    this->signExtend->updatePassive();
    this->signExtend->printContents();

    Machine::debugInfo("Updating Component: ALU Shift Left 2", 1);
    this->aluShiftLeft2->updatePassive();
//    this->aluShiftLeft2->printContents();

//    this->registers->printContents();

    Machine::debugInfo("Updating IO Component: Register A", 1);
    this->registerA->updatePassive();
    this->registerA->printContents();

    Machine::debugInfo("Updating IO Component: Register B", 1);
    this->registerB->updatePassive();
    this->registerB->printContents();

    Machine::debugInfo("Updating Component: Alu Source A Multiplexer", 1);
    this->aluSrcAMux->updatePassive();
    this->aluSrcAMux->printContents();

    Machine::debugInfo("Updating Component: Alu Source B Multiplexer", 1);
    this->aluSrcBMux->updatePassive();
    this->aluSrcBMux->printContents();

    Machine::debugInfo("Updating Component: PC Shift Left 2", 1);
    this->pcShiftLeft2->updatePassive();

    Machine::debugInfo("Updating Component: Alu Controller", 1);
    this->aluController->updatePassive();
//    this->aluController->printContents();

    Machine::debugInfo("Updating Component: ALU", 1);
    this->alu->updatePassive();
    this->alu->printContents();

    Machine::debugInfo("Updating Component: PC Source Multiplexer", 1);
    this->pcSourceMux->updatePassive();
//    pcSourceMux->printContents();

    Machine::debugInfo("Updating Component: ALU Out Register", 1);
    this->aluOut->updatePassive();
    this->aluOut->printContents();

    Machine::debugInfo("Updating Component: PC Register Controller", 1);
    this->pcRegisterController->updatePassive();

    /// Second update

    Machine::debugInfo("Updating Component: PC Register", 1);
    this->pc->updatePassive();
    this->pc->printContents();

    Machine::debugInfo("Updating Component: IorD Multiplexer", 1);
    this->IorDMux->updatePassive();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer", 1);
    this->memToRegMux->updatePassive();
//    this->memToRegMux->printContents();
}

void Processor::printRegisters() {
    unsigned int const *registersMem = this->registers->getMemory();

    for (int i = 0; i < 32; ++i) {
        if (registersMem[i])
            printf("$%d = %d\n", i, (int) registersMem[i]);
    }
}

void Processor::printMemory() {
    unsigned char const *dataMem = this->memory->getMemory();
    int val;

    for (int i = 0; i < 65536; i += 4) {
        memcpy(&val, &dataMem[i], sizeof(int));
        if (dataMem[i])
            printf("MEM[%d] = 0x%x\n", i, val);
    }
}

//
// Created by jarvis on 7/22/19.
//

#include <cstring>

#include "Processor.h"
#include "Machine.h"

Processor::Processor() {
    this->pc = new Register();

    this->IorDMux = new Multiplexer();

    this->memory = new Memory();

    this->instructionRegister = new Register();

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
    Machine::debugInfo("Initializing Component: PC Register", 2);
    this->pc->initialize(new INBus(pcSourceMux->getOutBus()),
                         new INBus(this->pcRegisterController->getOutBus()));

    Machine::debugInfo("Initializing Component: IorDMux", 2);
    this->IorDMux->initialize(new INBus(this->pc->getOutBus()),
                              new INBus(this->aluOut->getOutBus()),
                              new INBus(this->controller->getIorDSignal()));

    Machine::debugInfo("Initializing Component: Memory", 2);
    this->memory->initialize(memoryRef, new INBus(this->IorDMux->getOutBus()),
                             new INBus(this->registerB->getOutBus()),
                             new INBus(this->controller->getMemWriteSignal()),
                             new INBus(this->controller->getMemReadSignal()));

    Machine::debugInfo("Initializing Component: Instruction Register", 2);
    this->instructionRegister->initialize(new INBus(this->memory->getMemDataBus()),
                                          new INBus(this->controller->getIRWriteSignal()));

    Machine::debugInfo("Initializing Component: Memory Data Register", 2);
    this->memoryDataRegister->initialize(new INBus(this->memory->getMemDataBus()),
                                         new INBus(this->controller->getMemReadSignal()));

    Machine::debugInfo("Initializing Component: Controller", 2);
    this->controller->initialize(new INBus(0xFC000000, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: PC Register Controller", 2);
    this->pcRegisterController->initialize(new INBus(this->controller->getPCWriteCondSignal()),
                                           new INBus(this->controller->getPCWriteSignal()),
                                           new INBus(this->alu->getZeroBus()));

    Machine::debugInfo("Initializing Component: Register Destination Multiplexer", 2);
    this->regDstMux->initialize(new INBus(0x001F0000, this->instructionRegister->getOutBus()),
                                new INBus(0x0000F800, this->instructionRegister->getOutBus()),
                                new INBus(this->controller->getRegDstSignal()));

    Machine::debugInfo("Initializing Component: Memory to Register Multiplexer", 2);
    this->memToRegMux->initialize(new INBus(this->aluOut->getOutBus()),
                                  new INBus(this->memoryDataRegister->getOutBus()),
                                  new INBus(this->controller->getMemToRegSignal()));

    Machine::debugInfo("Initializing Component: Registers", 2);
    this->registers->initialize(new INBus(0x03E00000, this->instructionRegister->getOutBus()),
                                new INBus(0x001F0000, this->instructionRegister->getOutBus()),
                                new INBus(this->regDstMux->getOutBus()),
                                new INBus(this->memToRegMux->getOutBus()),
                                new INBus(this->controller->getRegWriteSignal()));

    Machine::debugInfo("Initializing Component: Sign Extend", 2);
    this->signExtend->initialize(new INBus(0x0000FFFF, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: ALU Shift Left 2", 2);
    this->aluShiftLeft2->initialize(new INBus(this->signExtend->getOutBus()));

    Machine::debugInfo("Initializing Component: A Register", 2);
    this->registerA->initialize(new INBus(this->registers->getReadData1()));

    Machine::debugInfo("Initializing Component: B Register", 2);
    this->registerB->initialize(new INBus(this->registers->getReadData2()));

    Machine::debugInfo("Initializing Component: Alu Source A Multiplexer", 2);
    this->aluSrcAMux->initialize(new INBus(this->pc->getOutBus()),
                                 new INBus(this->registerA->getOutBus()),
                                 new INBus(this->controller->getAluSrcASignal()));

    Machine::debugInfo("Initializing Component: Number 4 const", 2);
    this->num4Const->setValue(4);

    Machine::debugInfo("Initializing Component: Alu Source B Multiplexer", 2);
    this->aluSrcBMux->initialize(new INBus(this->registerB->getOutBus()),
                                 new INBus(this->num4Const),
                                 new INBus(this->signExtend->getOutBus()),
                                 new INBus(this->aluShiftLeft2->getOutBus()),
                                 new INBus(this->controller->getAluSrcBSignal()));

    Machine::debugInfo("Initializing Component: PC Register Shift Left 2", 2);
    this->pcShiftLeft2->initialize(new INBus(0x3FFFFFF, this->instructionRegister->getOutBus()));

    Machine::debugInfo("Initializing Component: Alu Controller", 2);
    this->aluController->initialize(new INBus(0x0000002F, this->instructionRegister->getOutBus()),
                                    new INBus(0x00000003, this->controller->getAluOpSignal()));

    Machine::debugInfo("Initializing Component: ALU", 2);
    this->alu->initialize(new INBus(this->aluSrcAMux->getOutBus()),
                          new INBus(this->aluSrcBMux->getOutBus()),
                          new INBus(this->aluController->getOutBus()));

    Machine::debugInfo("Initializing Component: ALUOut Register", 2);
    this->aluOut->initialize(new INBus(this->alu->getOutBus()),
                             new INBus(this->controller->getAluOutWriteSignal()));

    Machine::debugInfo("Initializing Component: PC Source Multiplexer", 2);
    this->pcSourceMux->initialize(new INBus(this->alu->getOutBus()),
                                  new INBus(this->aluOut->getOutBus()),
                                  new INBus(this->pcShiftLeft2->getOutBus()),
                                  new INBus(this->signExtend->getOutBus()),
                                  new INBus(this->controller->getPCSourceSignal()));
}

void Processor::updateController() {

    Machine::debugInfo("Updating IO of Component: Controller", 2);
    this->controller->updateIO();

    Machine::debugInfo("Clocking Component: Controller", 2);
    this->controller->updateState();
    this->controller->printContents();
}

void Processor::clock() {

    Machine::debugInfo("Updating Component: IorD Multiplexer", 2);
    this->IorDMux->updatePassive();

    Machine::debugInfo("Updating IO of Component: Memory", 2);
    this->memory->updateIO();

    Machine::debugInfo("Updating IO of Component: Registers", 2);
    this->registers->updateIO();

    Machine::debugInfo("Clocking Component: Memory", 2);
    this->memory->readMem();
    this->memory->printContents();

    Machine::debugInfo("Clocking Component: Registers", 2);
    this->registers->readRegisters();
    this->registers->printContents();
}

void Processor::updatePassive() {
    Machine::debugInfo("Updating IO Component: PC Register", 2);
    this->pc->updatePassive();
    this->pc->printContents();

    Machine::debugInfo("Updating Component: IorD Multiplexer", 2);
    this->IorDMux->updatePassive();
    this->IorDMux->printContents();

    Machine::debugInfo("Updating IO Component: Memory Data Register", 2);
    this->memoryDataRegister->updatePassive();
    this->memoryDataRegister->printContents();

    Machine::debugInfo("Updating IO Component: Instruction Register", 2);
    this->instructionRegister->updatePassive();
    this->instructionRegister->printContents();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer", 2);
    this->memToRegMux->updatePassive();
    this->memToRegMux->printContents();

    Machine::debugInfo("Updating Component: Register Destination Multiplexer", 2);
    this->regDstMux->updatePassive();
    this->regDstMux->printContents();

    Machine::debugInfo("Updating Component: Registers", 2);
    this->registers->readRegisters();
    this->registers->printContents();

    Machine::debugInfo("Updating Component: Sign Extend", 2);
    this->signExtend->updatePassive();
    this->signExtend->printContents();

    Machine::debugInfo("Updating Component: ALU Shift Left 2", 2);
    this->aluShiftLeft2->updatePassive();
    this->aluShiftLeft2->printContents();

    Machine::debugInfo("Updating IO Component: Register A", 2);
    this->registerA->updatePassive();
    this->registerA->printContents();

    Machine::debugInfo("Updating IO Component: Register B", 2);
    this->registerB->updatePassive();
    this->registerB->printContents();

    Machine::debugInfo("Updating Component: Alu Source A Multiplexer", 2);
    this->aluSrcAMux->updatePassive();
    this->aluSrcAMux->printContents();

    Machine::debugInfo("Updating Component: Alu Source B Multiplexer", 2);
    this->aluSrcBMux->updatePassive();
    this->aluSrcBMux->printContents();

    Machine::debugInfo("Updating Component: PC Shift Left 2", 2);
    this->pcShiftLeft2->updatePassive();
    this->pcShiftLeft2->printContents();

    Machine::debugInfo("Updating Component: Alu Controller", 2);
    this->aluController->updatePassive();
    this->aluController->printContents();

    Machine::debugInfo("Updating Component: ALU", 2);
    this->alu->updatePassive();
    this->alu->printContents();

    Machine::debugInfo("Updating Component: PC Source Multiplexer", 2);
    this->pcSourceMux->updatePassive();
    this->pcSourceMux->printContents();

    Machine::debugInfo("Updating Component: ALU Out Register", 2);
    this->aluOut->updatePassive();
    this->aluOut->printContents();

    Machine::debugInfo("Updating Component: PC Register Controller", 2);
    this->pcRegisterController->updatePassive();
    this->pcRegisterController->printContents();

    /// Second update

    Machine::debugInfo("Updating Component: PC Register", 2);
    this->pc->updatePassive();
    this->pc->printContents();

    Machine::debugInfo("Updating Component: IorD Multiplexer", 2);
    this->IorDMux->updatePassive();
    this->IorDMux->printContents();

    Machine::debugInfo("Clocking Component: Memory", 2);
    this->memory->updateIO();
    this->memory->readMem();
    this->memory->writeMem();
    this->memory->printContents();

    Machine::debugInfo("Updating IO Component: Memory Data Register", 2);
    this->memoryDataRegister->updatePassive();
    this->memoryDataRegister->printContents();

    Machine::debugInfo("Updating Component: Memory to Register Multiplexer", 2);
    this->memToRegMux->updatePassive();
    this->memToRegMux->printContents();

    Machine::debugInfo("Updating Component: Register Destination Multiplexer", 2);
    this->regDstMux->updatePassive();
    this->regDstMux->printContents();

    Machine::debugInfo("Updating Component: Registers", 2);
    this->registers->updateIO();
    this->registers->writeRegisters();
    this->registers->printContents();

}

void Processor::printRegisters() {
    unsigned int const *registersMem = this->registers->getMemory();
    char buff[255];

    for (int i = 0; i < 32; ++i) {
        if (registersMem[i]) {
            sprintf(buff, "\t$%d = %d", i, (int) registersMem[i]);
            Machine::debugInfo(buff, 1);
        }
    }
    Machine::debugInfo("", 1);
}

void Processor::printMemory() {
    unsigned char const *dataMem = this->memory->getMemory();
    char buff[255];
    int val;

    for (int i = 0; i < 65536; i += 4) {
        memcpy(&val, &dataMem[i], sizeof(int));
        if (val) {
            sprintf(buff, "\tMEM[%02d] = 0x%08x", i, val);
            Machine::debugInfo(buff, 1);
        }
    }
    Machine::debugInfo("", 1);
}

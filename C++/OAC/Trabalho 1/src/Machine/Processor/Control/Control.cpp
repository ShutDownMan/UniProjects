//
// Created by jarvis on 7/22/19.
//

#include "Control.h"
#include "../../Machine.h"

Control::Control() {
    this->RegDstSignal = new OUTBus();
    this->ALUSrcSignal = new OUTBus();
    this->MemToRegSignal = new OUTBus();
    this->RegWriteSignal = new OUTBus();
    this->MemReadSignal = new OUTBus();
    this->MemWriteSignal = new OUTBus();
    this->BranchSignal = new OUTBus();
    this->ALUOpSignal = new OUTBus();
}

void Control::updateIO() {
    this->inBus->update();

    switch (getInstructionType()) {
        case RTYPE:
            Machine::debugInfo("R Type Instruction detected");
            this->RegDstSignal->setValue(1);
            this->ALUSrcSignal->setValue(0);
            this->MemToRegSignal->setValue(0);
            this->RegWriteSignal->setValue(1);
            this->MemReadSignal->setValue(0);
            this->MemWriteSignal->setValue(0);
            this->BranchSignal->setValue(0);
            this->ALUOpSignal->setValue(2);
            break;
        case LW:
            Machine::debugInfo("LW Instruction detected");
            this->RegDstSignal->setValue(0);
            this->ALUSrcSignal->setValue(1);
            this->MemToRegSignal->setValue(1);
            this->RegWriteSignal->setValue(1);
            this->MemReadSignal->setValue(1);
            this->MemWriteSignal->setValue(0);
            this->BranchSignal->setValue(0);
            this->ALUOpSignal->setValue(0);
            break;
        case SW:
            Machine::debugInfo("SW Instruction detected");
//            this->RegDstSignal->setValue(?);
            this->ALUSrcSignal->setValue(1);
//            this->MemToRegSignal->setValue(?);
            this->RegWriteSignal->setValue(0);
            this->MemReadSignal->setValue(0);
            this->MemWriteSignal->setValue(1);
            this->BranchSignal->setValue(0);
            this->ALUOpSignal->setValue(0);
            break;
        case BEQ:
            Machine::debugInfo("BEQ Instruction detected");
//            this->RegDstSignal->setValue(?);
            this->ALUSrcSignal->setValue(0);
//            this->MemToRegSignal->setValue(?);
            this->RegWriteSignal->setValue(0);
            this->MemReadSignal->setValue(0);
            this->MemWriteSignal->setValue(0);
            this->BranchSignal->setValue(1);
            this->ALUOpSignal->setValue(1);
            break;

        default:
            Machine::debugInfo("INSTRUCTION TYPE NOT DETECTED!");
            break;
    }
}

void Control::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

OUTBus *Control::getRegDstSignal() const {
    return RegDstSignal;
}

OUTBus *Control::getBranchSignal() const {
    return BranchSignal;
}

OUTBus *Control::getMemReadSignal() const {
    return MemReadSignal;
}

OUTBus *Control::getMemToRegSignal() const {
    return MemToRegSignal;
}

OUTBus *Control::getAluOpSignal() const {
    return ALUOpSignal;
}

OUTBus *Control::getMemWriteSignal() const {
    return MemWriteSignal;
}

OUTBus *Control::getAluSrcSignal() const {
    return ALUSrcSignal;
}

OUTBus *Control::getRegWriteSignal() const {
    return RegWriteSignal;
}

unsigned int Control::testRegisterDestinationSignal(InstructionType type) {
    return 0;
}

InstructionType Control::getInstructionType() {
    if ((this->inBus->getValue() & IS_RTYPE_INSTRUCTION) == IS_RTYPE_INSTRUCTION) return RTYPE;

    if ((this->inBus->getValue() & IS_LW_INSTRUCTION) == IS_LW_INSTRUCTION) return LW;

    if ((this->inBus->getValue() & IS_SW_INSTRUCTION) == IS_SW_INSTRUCTION) return SW;

    if ((this->inBus->getValue() & IS_BEQ_INSTRUCTION) == IS_BEQ_INSTRUCTION) return BEQ;

    return NONE;
}

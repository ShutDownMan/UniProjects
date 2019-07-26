//
// Created by jarvis on 7/22/19.
//

#include "Control.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

Control::Control() {
    this->inBus = nullptr;

    this->RegDstSignal = new OUTBus();
    this->ALUSrcSignal = new OUTBus();
    this->MemToRegSignal = new OUTBus();
    this->RegWriteSignal = new OUTBus();
    this->MemReadSignal = new OUTBus();
    this->MemWriteSignal = new OUTBus();
    this->BranchSignal = new OUTBus();
    this->ALUOpSignal = new OUTBus();
    this->RegDataSrcSignal = new OUTBus();
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
            this->ALUOpSignal->setValue(0); // WHY THO?
            this->RegDataSrcSignal->setValue(0);
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
            this->ALUOpSignal->setValue(0); // WHY THO?
            this->RegDataSrcSignal->setValue(0);
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
            this->RegDataSrcSignal->setValue(0);
            break;

        case LI:
            Machine::debugInfo("LI Instruction detected");
            this->RegDstSignal->setValue(0);
//            this->ALUSrcSignal->setValue(0);
//            this->MemToRegSignal->setValue(0);
            this->RegWriteSignal->setValue(1);
            this->MemReadSignal->setValue(0);
            this->MemWriteSignal->setValue(0);
            this->BranchSignal->setValue(0);
//            this->ALUOpSignal->setValue(0);
            this->RegDataSrcSignal->setValue(1);
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

OUTBus *Control::getRegDataSrc() const {
    return RegDataSrcSignal;
}

InstructionType Control::getInstructionType() {
    if (this->inBus->getValue() == IS_RTYPE_INSTRUCTION) return RTYPE;

    if (this->inBus->getValue() == IS_LW_INSTRUCTION) return LW;

    if (this->inBus->getValue() == IS_SW_INSTRUCTION) return SW;

    if (this->inBus->getValue() == IS_BEQ_INSTRUCTION) return BEQ;

    if (this->inBus->getValue() == IS_LI_INSTRUCTION) return LI;

    return NONE;
}

void Control::printContents() {
    string str = "Control:\n";

    str += "\tInBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\tRegDstSignal: " + to_string(this->RegDstSignal->getValue()) + "\n";
    str += "\tALUSrcSignal: " + to_string(this->ALUSrcSignal->getValue()) + "\n";
    str += "\tMemToRegSignal: " + to_string(this->MemToRegSignal->getValue()) + "\n";
    str += "\tRegWriteSignal: " + to_string(this->RegWriteSignal->getValue()) + "\n";
    str += "\tMemReadSignal: " + to_string(this->MemReadSignal->getValue()) + "\n";
    str += "\tMemWriteSignal: " + to_string(this->MemWriteSignal->getValue()) + "\n";
    str += "\tBranchSignal: " + to_string(this->BranchSignal->getValue()) + "\n";
    str += "\tALUOpSignal: " + to_string(this->ALUOpSignal->getValue()) + "\n";
    str += "\tRegDataSrcSignal: " + to_string(this->RegDataSrcSignal->getValue()) + "\n";
    str += "\tInstructionType: " + to_string(this->getInstructionType()) + "\n";

    cout << str << endl;
}

// 001111 00000 10010 0000000000001000
// 001111 00000 11111 0000000000000000
//                       F   F   F   F

// 101011 11100 10010 0000000000000000
// 101011 11100 10010 1111111111111111
// 000000 00000 11111 0000000000000000

// 100011 11100 00111 0000000000000000

// 000000 00111 01000 01001 00000 100000

// 101011 11100 10010 0000000000000000
// 101011 11100 10011 0000000000000100
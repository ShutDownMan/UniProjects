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
    this->BranchJumpSignal = new OUTBus();
}

void Control::updateIO() {
    this->inBus->update();

    this->RegDstSignal->setValue(0);
    this->ALUSrcSignal->setValue(0);
    this->MemToRegSignal->setValue(0);
    this->RegWriteSignal->setValue(0);
    this->MemReadSignal->setValue(0);
    this->MemWriteSignal->setValue(0);
    this->BranchSignal->setValue(0);
    this->ALUOpSignal->setValue(0);
    this->RegDataSrcSignal->setValue(0);
    this->BranchJumpSignal->setValue(0);

    switch (getInstructionType()) {
        case RTYPE:
            Machine::debugInfo("R Type Instruction detected", 3);
            this->RegDstSignal->setValue(1);
            this->RegWriteSignal->setValue(1);
            this->ALUOpSignal->setValue(2);
            break;

        case LW:
            Machine::debugInfo("LW Instruction detected", 3);
            this->ALUSrcSignal->setValue(1);
            this->MemToRegSignal->setValue(1);
            this->RegWriteSignal->setValue(1);
            this->MemReadSignal->setValue(1);
            break;

        case SW:
            Machine::debugInfo("SW Instruction detected", 3);
            this->ALUSrcSignal->setValue(1);
            this->MemWriteSignal->setValue(1);
            break;

        case BEQ:
            Machine::debugInfo("BEQ Instruction detected", 3);
            this->BranchSignal->setValue(1);
            this->ALUOpSignal->setValue(1);
            break;

        case BNE:
            Machine::debugInfo("BNE Instruction detected", 3);
            this->BranchSignal->setValue(2);
            this->ALUOpSignal->setValue(1);
            break;

        case LI:
            Machine::debugInfo("LI Instruction detected", 3);
            this->RegWriteSignal->setValue(1);
            this->RegDataSrcSignal->setValue(1);
            break;

        case J:
            Machine::debugInfo("J Instruction detected", 3);
            this->BranchSignal->setValue(1);
            this->ALUOpSignal->setValue(1);
            this->BranchJumpSignal->setValue(1);
            break;

        default:
            Machine::debugInfo("INSTRUCTION TYPE NOT DETECTED!", 3);
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

OUTBus *Control::getBranchJumpSignal() const {
    return BranchJumpSignal;
}

InstructionType Control::getInstructionType() {
    if (this->inBus->getValue() == IS_RTYPE_INSTRUCTION) return RTYPE;

    if (this->inBus->getValue() == IS_LW_INSTRUCTION) return LW;

    if (this->inBus->getValue() == IS_SW_INSTRUCTION) return SW;

    if (this->inBus->getValue() == IS_BEQ_INSTRUCTION) return BEQ;

    if (this->inBus->getValue() == IS_BNE_INSTRUCTION) return BNE;

    if (this->inBus->getValue() == IS_LI_INSTRUCTION) return LI;

    if (this->inBus->getValue() == IS_J_INSTRUCTION) return J;

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
    str += "\tBranchJumpSignal: " + to_string(this->BranchJumpSignal->getValue()) + "\n";
    str += "\tInstructionType: " + to_string(this->getInstructionType()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
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

// LI $1, 1
// 001111 00000 00001 00000 00000000001
// LI $2, 1
// 001111 00000 00010 00000 00000000001
// ADD $3, $2, $1
// 000000 00001 00010 00011 00000100000
// AND $2, $2, $0
// 000000 00010 00000 00010 00000100100
// ADD $2, $2, $1
// 000000 00010 00001 00010 00000100000
// AND $1, $1, $0
// 000000 00001 00000 00001 00000100100
// ADD $1, $1, $3
// 000000 00001 00011 00001 00000100000
// J -7
// 000010 11111111111111111111111001

// BNE $0, $1, -7
// 000101 00000 00001 1111111111111001
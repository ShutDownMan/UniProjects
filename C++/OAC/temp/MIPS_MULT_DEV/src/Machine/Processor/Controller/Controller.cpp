//
// Created by Jedson Gabriel on 7/22/19.
//

#include "Controller.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

Controller::Controller() {
    this->state = InstructionFetch;

    this->inBus = nullptr;

    this->RegDstSignal = new OUTBus();
    this->MemToRegSignal = new OUTBus();
    this->IRWriteSignal = new OUTBus();
    this->RegWriteSignal = new OUTBus();
    this->MemReadSignal = new OUTBus();
    this->MemWriteSignal = new OUTBus();
    this->BranchSignal = new OUTBus();
    this->ALUOpSignal = new OUTBus();
    this->RegDataSrcSignal = new OUTBus();
    this->BranchJumpSignal = new OUTBus();
    this->IorDSignal = new OUTBus();
    this->PCSourceSignal = new OUTBus();
    this->PCWriteCondSignal = new OUTBus();
    this->PCWriteSignal = new OUTBus();
    this->AluSrcASignal = new OUTBus();
    this->AluSrcBSignal = new OUTBus();
    this->AluOutWriteSignal = new OUTBus();
}

void Controller::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

void Controller::updateIO() {
    this->inBus->update();
}

void Controller::updateState() {
    this->RegDstSignal->setValue(0);
    this->MemToRegSignal->setValue(0);
    this->IRWriteSignal->setValue(0);
    this->RegWriteSignal->setValue(0);
    this->MemReadSignal->setValue(0);
    this->MemWriteSignal->setValue(0);
    this->BranchSignal->setValue(0);
    this->ALUOpSignal->setValue(0);
    this->RegDataSrcSignal->setValue(0);
    this->BranchJumpSignal->setValue(0);
    this->IorDSignal->setValue(0);
    this->PCSourceSignal->setValue(0);
    this->PCWriteCondSignal->setValue(0);
    this->PCWriteSignal->setValue(0);
    this->AluSrcASignal->setValue(0);
    this->AluSrcBSignal->setValue(0);
    this->AluOutWriteSignal->setValue(0);

    switch (this->state) {
        case InstructionFetch:
            this->MemReadSignal->setValue(1);
            this->IRWriteSignal->setValue(1);
            this->AluSrcASignal->setValue(0);
            this->AluSrcBSignal->setValue(1);
            this->IorDSignal->setValue(0);
            this->ALUOpSignal->setValue(0);
            this->PCWriteSignal->setValue(1);
            this->PCSourceSignal->setValue(0);

            this->state = InstructionDecode;
            break;
        case InstructionDecode:
            this->AluSrcASignal->setValue(0);
            this->AluSrcBSignal->setValue(3);
            this->ALUOpSignal->setValue(0);
            this->AluOutWriteSignal->setValue(1);

            switch (this->getInstructionType()) {
                case LW:
                case SW:
                    this->state = MemoryAddressComputation;
                    Machine::debugInfo("LW or SW Instruction detected", 3);
                    break;
                case RTYPE:
                    Machine::debugInfo("RTYPE Instruction detected", 3);
                    this->state = Execution;
                    break;
                case BEQ:
                case BNE:
                    Machine::debugInfo("BEQ or BNE Instruction detected", 3);
                    this->state = BranchCompletion;
                    break;
                case LI:
                    Machine::debugInfo("LI Instruction detected", 3);
                    this->state = LoadImmediate;
                    break;
                case J:
                    Machine::debugInfo("JUMP Instruction detected", 3);
                    this->state = JumpCompletion;
                    break;
                case NONE:
                    break;
            }
            break;
        case MemoryAddressComputation:
            this->AluSrcASignal->setValue(1);
            this->AluSrcBSignal->setValue(2);
            this->ALUOpSignal->setValue(0);
            this->AluOutWriteSignal->setValue(1);

            switch (this->getInstructionType()) {
                case LW:
                    this->state = MemoryAccessLW;
                    break;
                case SW:
                    this->state = MemoryAccessSW;
                    break;
                default:
                    Machine::debugInfo("ERROR ON MemoryAddressComputation STATE", 1);
                    break;
            }
            break;
        case MemoryAccessLW:
            this->MemReadSignal->setValue(1);
            this->IorDSignal->setValue(1);

            this->state = MemoryReadCompletionStep;
            break;
        case MemoryAccessSW:
            this->MemWriteSignal->setValue(1);
            this->IorDSignal->setValue(1);

            this->state = InstructionFetch;
            break;
        case MemoryReadCompletionStep:
            this->RegDstSignal->setValue(0);
            this->RegWriteSignal->setValue(1);
            this->MemToRegSignal->setValue(1);

            this->state = InstructionFetch;
            break;
        case Execution:
            this->AluSrcASignal->setValue(1);
            this->AluSrcBSignal->setValue(0);
            this->ALUOpSignal->setValue(2);
            this->AluOutWriteSignal->setValue(1);

            this->state = RTypeCompletion;
            break;
        case RTypeCompletion:
            this->RegDstSignal->setValue(1);
            this->RegWriteSignal->setValue(1);
            this->MemToRegSignal->setValue(0);

            this->state = InstructionFetch;
            break;
        case BranchCompletion:
            this->AluSrcASignal->setValue(1);
            this->AluSrcBSignal->setValue(0);
            this->ALUOpSignal->setValue(1);
            this->PCSourceSignal->setValue(1);

            switch (this->getInstructionType()) {
                case BEQ:
                    this->PCWriteCondSignal->setValue(1);
                    break;
                case BNE:
                    this->PCWriteCondSignal->setValue(2);
                    break;
                default:
                    Machine::debugInfo("ERROR ON BranchCompletion STATE", 1);
                    break;
            }

                this->state = InstructionFetch;
            break;
        case JumpCompletion:
            this->PCWriteSignal->setValue(1);
            this->PCSourceSignal->setValue(2);

            this->state = InstructionFetch;
            break;
        case LoadImmediate:
            this->RegDataSrcSignal->setValue(1);
            this->AluSrcASignal->setValue(1);
            this->AluSrcBSignal->setValue(2);
            this->AluOutWriteSignal->setValue(1);

            this->state = LoadImmediateCompletion;
            break;
        case LoadImmediateCompletion:
            this->RegWriteSignal->setValue(1);

            this->state = InstructionFetch;
            break;

    }
}

OUTBus *Controller::getRegDstSignal() const {
    return RegDstSignal;
}

OUTBus *Controller::getBranchSignal() const {
    return BranchSignal;
}

OUTBus *Controller::getMemReadSignal() const {
    return MemReadSignal;
}

OUTBus *Controller::getMemToRegSignal() const {
    return MemToRegSignal;
}

OUTBus *Controller::getAluOpSignal() const {
    return ALUOpSignal;
}

OUTBus *Controller::getMemWriteSignal() const {
    return MemWriteSignal;
}

OUTBus *Controller::getRegWriteSignal() const {
    return RegWriteSignal;
}

OUTBus *Controller::getRegDataSrc() const {
    return RegDataSrcSignal;
}

OUTBus *Controller::getBranchJumpSignal() const {
    return BranchJumpSignal;
}

OUTBus *Controller::getIorDSignal() const {
    return IorDSignal;
}

OUTBus *Controller::getPCWriteCondSignal() const {
    return PCWriteCondSignal;
}

OUTBus *Controller::getPCWriteSignal() const {
    return PCWriteSignal;
}

OUTBus *Controller::getAluSrcASignal() const {
    return AluSrcASignal;
}

OUTBus *Controller::getAluSrcBSignal() const {
    return AluSrcBSignal;
}

OUTBus *Controller::getPCSourceSignal() const {
    return PCSourceSignal;
}

OUTBus *Controller::getIRWriteSignal() const {
    return IRWriteSignal;
}

OUTBus *Controller::getAluOutWriteSignal() const {
    return AluOutWriteSignal;
}


InstructionType Controller::getInstructionType() {
    if (this->inBus->getValue() == IS_RTYPE_INSTRUCTION) return RTYPE;

    if (this->inBus->getValue() == IS_LW_INSTRUCTION) return LW;

    if (this->inBus->getValue() == IS_SW_INSTRUCTION) return SW;

    if (this->inBus->getValue() == IS_BEQ_INSTRUCTION) return BEQ;

    if (this->inBus->getValue() == IS_BNE_INSTRUCTION) return BNE;

    if (this->inBus->getValue() == IS_LI_INSTRUCTION) return LI;

    if (this->inBus->getValue() == IS_J_INSTRUCTION) return J;

    return NONE;
}

void Controller::printContents() {
    string str = "Controller:\n";

    str += "\tNext State: " + to_string(this->state) + "\n";
    str += "\tInBus: " + to_string(this->inBus->getValue()) + "\n";
    str += "\tRegDstSignal: " + to_string(this->RegDstSignal->getValue()) + "\n";
    str += "\tMemToRegSignal: " + to_string(this->MemToRegSignal->getValue()) + "\n";
    str += "\tIRWriteSignal: " + to_string(this->IRWriteSignal->getValue()) + "\n";
    str += "\tRegWriteSignal: " + to_string(this->RegWriteSignal->getValue()) + "\n";
    str += "\tMemReadSignal: " + to_string(this->MemReadSignal->getValue()) + "\n";
    str += "\tMemWriteSignal: " + to_string(this->MemWriteSignal->getValue()) + "\n";
    str += "\tBranchSignal: " + to_string(this->BranchSignal->getValue()) + "\n";
    str += "\tALUOpSignal: " + to_string(this->ALUOpSignal->getValue()) + "\n";
    str += "\tRegDataSrcSignal: " + to_string(this->RegDataSrcSignal->getValue()) + "\n";
    str += "\tBranchJumpSignal: " + to_string(this->BranchJumpSignal->getValue()) + "\n";
    str += "\tIorDSignal: " + to_string(this->IorDSignal->getValue()) + "\n";
    str += "\tPCSourceSignal: " + to_string(this->PCSourceSignal->getValue()) + "\n";
    str += "\tPCWriteCondSignal: " + to_string(this->PCWriteCondSignal->getValue()) + "\n";
    str += "\tPCWriteSignal: " + to_string(this->PCWriteSignal->getValue()) + "\n";
    str += "\tAluSrcASignal: " + to_string(this->AluSrcASignal->getValue()) + "\n";
    str += "\tAluSrcBSignal: " + to_string(this->AluSrcBSignal->getValue()) + "\n";
    str += "\tInstructionType: " + to_string(this->getInstructionType()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}
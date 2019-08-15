//
// Created by jarvis on 7/22/19.
//

#include "ALUController.h"
#include "../../Machine.h"

#include <string>
#include <iostream>

using namespace std;

ALUController::ALUController() {
    this->controlBus = nullptr;
    this->functBus = nullptr;

    this->outBus = new OUTBus();
    this->BranchJumpSrcSignal = new OUTBus();
}

void ALUController::updatePassive() {
    this->functBus->update();
    this->controlBus->update();

    this->BranchJumpSrcSignal->setValue(0);

    unsigned int fsignal = this->functBus->getValue();
    unsigned int result = 0;

    switch (this->controlBus->getValue()) {
        case 0:
            result = 2;
            break;

        case 1:
            result = 6;
            break;

        case 2:
            if (this->functBus->getValue() == IS_JR_MASK)
                this->BranchJumpSrcSignal->setValue(1);

            switch (fsignal) {
                case IS_ADD_MASK:
                    result = 2;
                    break;
                case IS_SUB_MASK:
                    result = 6;
                    break;
                case IS_AND_MASK:
                    result = 0;
                    break;
                case IS_OR_MASK:
                    result = 1;
                    break;
                case IS_SLT_MASK:
                    result = 7;
                    break;
                default:
                    break;
            }

            break;
        case 3:
            // XXX?
            if (!(fsignal & 0x09u)) // F0 e F3
                result |= 1ul << 0u;
            else
                result &= ~(1ul << 0u);

            // XX?X
            if ((fsignal & 0x04u)) // F2
                result &= ~(1ul << 1u);
            else
                result |= 1ul << 1u;

            // X1XX
            result |= 1ul << 2u;

            break;

        default:
            break;
    }

    this->outBus->setValue(result);

}

void ALUController::initialize(INBus *functBusRef, INBus *controlBusRef) {
    this->functBus = functBusRef;
    this->controlBus = controlBusRef;
}

OUTBus *ALUController::getOutBus() const {
    return outBus;
}

OUTBus *ALUController::getBranchJumpSrcSignal() const {
    return BranchJumpSrcSignal;
}

void ALUController::printContents() {
    string str = "ALUController:\n";

    str += "\tControlBus: " + to_string(this->controlBus->getValue()) + "\n";
    str += "\tInstructionBus: " + to_string(this->functBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";
    str += "\tBranchJumpSrcSignal: " + to_string(this->BranchJumpSrcSignal->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

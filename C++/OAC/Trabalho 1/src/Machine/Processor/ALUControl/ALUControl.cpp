//
// Created by jarvis on 7/22/19.
//

#include "ALUControl.h"

#include <string>
#include <iostream>

using namespace std;

ALUControl::ALUControl() {
    this->controlBus = nullptr;
    this->functBus = nullptr;

    this->outBus = new OUTBus();
    this->BranchJumpSrcSignal = new OUTBus();
}

void ALUControl::updateIO() {
    this->functBus->update();
    this->controlBus->update();

    this->BranchJumpSrcSignal->setValue(0);

    unsigned int fsignal = this->functBus->getValue();
    unsigned int result = 0;

    switch (this->controlBus->getValue()) {
        case 0:
            // XXX0
            result &= ~(1ul << 0u);

            // XX?X
            result |= 1ul << 1u;

            // X0XX
            result &= ~(1ul << 2u);

            break;

        case 1:
            // XXX0
            result &= ~(1ul << 0u);

            // XX1X
            result |= 1ul << 1u;

            // X1XX
            result |= 1ul << 2u;

            break;

        case 2:
            if(this->functBus->getValue() == IS_JR_MASK)
                this->BranchJumpSrcSignal->setValue(1);

            // XXX?
            if (!(fsignal & 0x09u)) // F0 e F3
                result &= ~(1ul << 0u);
            else
                result |= 1ul << 0u;

            // XX?X
            if ((fsignal & 0x04u)) // F2
                result &= ~(1ul << 1u);
            else
                result |= 1ul << 1u;

            // X?XX
            if (!(fsignal & 0x02u)) // F1
                result &= ~(1ul << 2u);
            else
                result |= 1ul << 2u;

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

void ALUControl::initialize(INBus *inBusRef, INBus *controlBusRef) {
    this->functBus = inBusRef;
    this->controlBus = controlBusRef;
}

OUTBus *ALUControl::getOutBus() const {
    return outBus;
}

OUTBus *ALUControl::getBranchJumpSrcSignal() const {
    return BranchJumpSrcSignal;
}

void ALUControl::printContents() {
    string str = "ALUControl:\n";

    str += "\tControlBus: " + to_string(this->controlBus->getValue()) + "\n";
    str += "\tInstructionBus: " + to_string(this->functBus->getValue()) + "\n";
    str += "\toutBus: " + to_string(this->outBus->getValue()) + "\n";
    str += "\tBranchJumpSrcSignal: " + to_string(this->BranchJumpSrcSignal->getValue()) + "\n";

    cout << str << endl;
}

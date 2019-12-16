//
// Created by Jedson Gabriel on 7/28/19.
//

#include "BranchControl.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

BranchControl::BranchControl() {
    this->branchSignalBus = nullptr;
    this->zeroSignalBus = nullptr;

    this->outBus = new OUTBus();
}

void BranchControl::initialize(INBus *branchSignalBusRef, INBus *zeroSignalBusRef) {
    this->branchSignalBus = branchSignalBusRef;
    this->zeroSignalBus = zeroSignalBusRef;
}

OUTBus *BranchControl::getOutBus() const {
    return outBus;
}

void BranchControl::updateIO() {
    this->branchSignalBus->update();
    this->zeroSignalBus->update();

    this->outBus->setValue(0);

    switch (this->branchSignalBus->getValue()) {
        case 1:
            if(this->branchSignalBus->getValue() && this->zeroSignalBus->getValue())
                this->outBus->setValue(1);
            break;

        case 2:
            if(this->branchSignalBus->getValue() && !this->zeroSignalBus->getValue())
                this->outBus->setValue(1);
            break;

        default:
            break;
    }
}

void BranchControl::printContents() {
    string str = "BranchControl:\n";

    str += "\tbranchSignalBus: " + to_string(this->branchSignalBus->getValue()) + "\n";
    str += "\tzeroSignalBus: " + to_string(this->zeroSignalBus->getValue()) + "\n";
    str += "\tbranchEnable: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

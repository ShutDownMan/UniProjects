//
// Created by jarvis on 7/28/19.
//

#include "BranchControl.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

BranchControl::BranchControl() {
    this->branchSignalBus = nullptr;
    this->zeroSignalBus = nullptr;
    this->jumpSignalBus = nullptr;

    this->outBus = new OUTBus();
}

void BranchControl::initialize(INBus *branchSignalBusRef, INBus *zeroSignalBusRef, INBus *jumpSignalBusRef) {
    this->branchSignalBus = branchSignalBusRef;
    this->zeroSignalBus = zeroSignalBusRef;
    this->jumpSignalBus = jumpSignalBusRef;
}

OUTBus *BranchControl::getOutBus() const {
    return outBus;
}

void BranchControl::updateIO() {
    this->branchSignalBus->update();
    this->zeroSignalBus->update();
    this->jumpSignalBus->update();

    this->outBus->setValue(0);

    if(!this->jumpSignalBus->getValue()) {
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
    } else {
        this->outBus->setValue(1);
    }

}

void BranchControl::printContents() {
    string str = "BranchControl:\n";

    str += "\tbranchSignalBus: " + to_string(this->branchSignalBus->getValue()) + "\n";
    str += "\tzeroSignalBus: " + to_string(this->zeroSignalBus->getValue()) + "\n";
    str += "\tjumpSignalBus: " + to_string(this->jumpSignalBus->getValue()) + "\n";
    str += "\tbranchEnable: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 3);
}

//
// Created by jarvis on 7/28/19.
//

#include "BranchController.h"
#include "../../Machine.h"
#include <string>
#include <iostream>

using namespace std;

BranchController::BranchController() {
    this->pcWriteCondBus = nullptr;
    this->zeroSignalBus = nullptr;
    this->pcWriteBus = nullptr;

    this->outBus = new OUTBus();
}

void BranchController::initialize(INBus *pcWriteCondRef, INBus *pcWriteRef, INBus *zeroSignalBusRef) {
    this->pcWriteCondBus = pcWriteCondRef;
    this->pcWriteBus = pcWriteRef;
    this->zeroSignalBus = zeroSignalBusRef;
}

OUTBus *BranchController::getOutBus() const {
    return outBus;
}

void BranchController::updatePassive() {
    this->pcWriteCondBus->update();
    this->zeroSignalBus->update();
    this->pcWriteBus->update();

    this->outBus->setValue(0);

    if(this->pcWriteBus->getValue()) {
        this->outBus->setValue(1);
    }

    switch (this->pcWriteCondBus->getValue()) {
        case 1:
            if (this->zeroSignalBus->getValue())
                this->outBus->setValue(1);
            break;
        case 2:
            if (!this->zeroSignalBus->getValue())
                this->outBus->setValue(1);
            break;
    }
}

void BranchController::printContents() {
    string str = "BranchController:\n";

    str += "\tpcWriteCondBus: " + to_string(this->pcWriteCondBus->getValue()) + "\n";
    str += "\tpcWriteBus: " + to_string(this->pcWriteBus->getValue()) + "\n";
    str += "\tzeroSignalBus: " + to_string(this->zeroSignalBus->getValue()) + "\n";
    str += "\tbranchEnable: " + to_string(this->outBus->getValue()) + "\n";

    Machine::debugInfo(str.c_str(), 2);

}

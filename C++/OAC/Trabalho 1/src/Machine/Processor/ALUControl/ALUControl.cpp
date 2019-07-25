//
// Created by jarvis on 7/22/19.
//

#include "ALUControl.h"

ALUControl::ALUControl() {
    this->outBus = new OUTBus();
}

void ALUControl::updateIO() {
    this->instructionBus->update();
    this->controlBus->update();


}

void ALUControl::initialize(INBus *inBusRef, INBus *controlBusRef) {
    this->instructionBus = inBusRef;
    this->controlBus = controlBusRef;
}

OUTBus *ALUControl::getOutBus() const {
    return outBus;
}

//
// Created by jarvis on 7/22/19.
//

#include <cstdint>
#include "SignExtend.h"

SignExtend::SignExtend() {
    this->outBus = new OUTBus();
}

void SignExtend::updateIO() {
    this->inBus->update();

    int16_t s = this->inBus->getValue();

    this->outBus->setValue((int32_t)s);
}

void SignExtend::initialize(INBus *inBusRef) {
    this->inBus = inBusRef;
}

OUTBus *SignExtend::getOutBus() const {
    return outBus;
}

//
// Created by jarvis on 7/22/19.
//

#include "Registers.h"

Registers::Registers() {
    this->readData1Bus = new OUTBus();
    this->readData2Bus = new OUTBus();
}

void Registers::updateState() {

}

void Registers::updateIO() {
    this->readRegister1Bus->update();
    this->readRegister2Bus->update();
    this->writeDataBus->update();
    this->writeRegisterBus->update();


}

void Registers::initialize(INBus *readRegister1BusRef, INBus *readRegisterBus2Ref, INBus *writeRegisterBusRef,
                           INBus *writeDataBusRef) {
    this->readRegister1Bus = readRegister1BusRef;
    this->readRegister2Bus = readRegisterBus2Ref;
    this->writeRegisterBus = writeRegisterBusRef;
    this->writeDataBus = writeDataBusRef;
}

OUTBus *Registers::getReadData1() const {
    return readData1Bus;
}

OUTBus *Registers::getReadData2() const {
    return readData2Bus;
}

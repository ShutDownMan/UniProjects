//
// Created by jarvis on 7/22/19.
//

#include "DataMemory.h"

void DataMemory::updateState() {

}

void DataMemory::updateIO() {
    this->writeData->update();
    this->addressBus->update();
}

void DataMemory::initialize(INBus *addressBusRef, INBus *writeDataRef) {
    this->addressBus = addressBusRef;
    this->writeData = writeDataRef;
}

DataMemory::DataMemory() {
    this->readDataBus = new OUTBus();

    this->addressBus = nullptr;
    this->writeData = nullptr;
}

OUTBus *DataMemory::getReadDataBus() const {
    return readDataBus;
}

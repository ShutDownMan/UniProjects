#include "contador.h"

#include <iostream>

using namespace std;

Contador::Contador() {
    this->timer = 0;
}

Contador::~Contador() {
    cout << "(Contador) Liberando memória" << endl;
}

void Contador::increment() {
    this->timer++;
}

int Contador::getTime() {
    return this->timer;
}


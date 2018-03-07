#include "ponto.h"

#include <iostream>

using namespace std;

Ponto::Ponto(double x, double y) {
    this->x = x;
    this->y = y;
}

Ponto::~Ponto(void) {
    cout << "(Ponto) Liberando memória" << endl;
}

void Ponto::setX(double x) {
    this->x = x;
}

void Ponto::setY(double y) {
    this->y = y;
}

double Ponto::getX(void) {
    return this->x;
}

double Ponto::getY(void) {
    return this->y;
}

void Ponto::show() {
    cout << "[" << this->x << " | " << this->y << "]" << endl;
}

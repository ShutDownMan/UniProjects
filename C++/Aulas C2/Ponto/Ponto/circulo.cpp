#include "circulo.h"

#include <iostream>

using namespace std;

Circulo::Circulo(double x, double y, double r) : Ponto(x, y) {
    this->raio = r;
}

Circulo::~Circulo(void) {
    cout << "(Circulo) Liberando memória" << endl;
}

void Circulo::mover(double x, double y) {
    this->setX(x);
    this->setY(y);
}

void Circulo::mover(Ponto p) {
    this->setX(p.getX());
    this->setY(p.getY());
}

void Circulo::aumentar(void) {
    this->raio++;
}

void Circulo::diminuir(void) {
    this->raio--;
}

double Circulo::getRaio(void) {
    return this->raio;
}

void Circulo::show(void) {
    cout << "("
         << this->getX()
         << ","
         << this->getY()
         << ","
         << this->raio
         << ")"
         << endl;
}

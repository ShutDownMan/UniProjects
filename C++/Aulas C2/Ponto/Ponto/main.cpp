#include "ponto.h"
#include "circulo.h"

#include <iostream>
using namespace std;

int main(void) {
    Ponto *ponto1 = new Ponto(10, 2.5);
    //ponto1->setX(1);

    ponto1->show();

    Circulo *circulo1 = new Circulo(15, 11.3, 3.14);

    circulo1->mover(1.5, 1.1);
    circulo1->show();

    circulo1->mover(ponto1);
    circulo1->show();

    circulo1->aumentar();
    circulo1->show();

    circulo1->diminuir();
    circulo1->show();

    cout << circulo1->getRaio() << endl;

    delete circulo1;
    delete ponto1;

    return 0;
}

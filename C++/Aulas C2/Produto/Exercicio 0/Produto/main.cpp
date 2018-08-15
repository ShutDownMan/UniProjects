#include <iostream>
#include "product.h"
#include "chemical.h"

using namespace std;

int main() {
    Chemical *produto = new Chemical(123, 10, new string("Feijaoada"), 5.22);

    cout << *produto->toString() << endl;

    produto->updatePrice(0.15);
    produto->setFlamable(true);

    cout << *produto->toString() << endl;

    return 0;
}

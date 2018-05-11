#include <iostream>
#include "pessoa.h"

using namespace std;

int main() {
    Pessoa *p1 = new Pessoa(0, "Mariazenha");
    Pessoa *p2 = new Pessoa(0, "Joaozenho");

    cout << *p1 << endl;

    cout << ((*p1) > (*p2)) << endl;

    delete p1;

    return 0;
}

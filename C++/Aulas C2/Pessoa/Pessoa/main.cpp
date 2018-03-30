#include <iostream>
#include <pessoa.h>

using namespace std;

int main(int argc, char *argv[]) {
    Pessoa *p = NULL;

    p = new Pessoa();

    p->setar();
    p->mostrar();

    delete p;

    return 0;
}

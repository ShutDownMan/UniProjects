#include "pessoa.h"
#include "funcionario.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    Funcionario *f = new Funcionario();

    f->setar();
    f->mostrar();

    delete f;

    return 0;
}

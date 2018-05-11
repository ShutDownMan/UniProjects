#ifndef PESSOA_H
#define PESSOA_H

#include <stdlib.h>
#include <string.h>

#include <iostream>

using namespace std;

class Pessoa {
protected:
    friend ostream &operator<<(ostream &output, Pessoa &p);
private:
    int idPessoa;
    char *nome;
public:
    Pessoa(int idPessoa, char *nome);

    char *getNome();

    bool operator<(Pessoa &p);
    bool operator>(Pessoa &p);
    bool operator==(Pessoa &p);

    void mostrar();

    ~Pessoa();
};

#endif // PESSOA_H

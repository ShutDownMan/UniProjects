#ifndef PESSOA_H
#define PESSOA_H


class Pessoa {
private:
    char nome[31];
    char endereco[40];
public:
    ~Pessoa();
    void mostrar();
    void setar();
};

#endif // PESSOA_H

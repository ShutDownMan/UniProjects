#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <time.h>

class Funcionario : public Pessoa {
protected:
    int faltas;
    struct tm* data_admissao;
    float salario_base;
public:
    Funcionario();
    void setar();
    void mostrar();
    ~Funcionario();
};

#endif // FUNCIONARIO_H

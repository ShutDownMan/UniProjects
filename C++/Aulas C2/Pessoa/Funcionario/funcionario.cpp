#include "pessoa.h"
#include "funcionario.h"

#include <iostream>
using namespace std;

Funcionario::Funcionario() {
    this->faltas = 0;
}

void Funcionario::setar() {
    time_t rawtime;

    cout << "ENTRADA COM OS DADOS DOS FUNCIONARIOS" << endl;
    Pessoa::setar();
    cout << "Digite o valor do Salario: ";
    cin >> this->salario_base;

    time(&rawtime);
    this->data_admissao = localtime(&rawtime);
}

void Funcionario::mostrar() {
    cout << "\n\n SAIDA DE DAOS DO FUNCIONARIO" << endl;
    Pessoa::mostrar();
    cout << "\nSalario base: " << salario_base << endl;
    cout << "\nFaltas no periodo: " << faltas << endl;
    cout << "\nData de admissão: "
         << (int)data_admissao->tm_mday << "/"
         << (int)data_admissao->tm_mon << "/"
         << (int)data_admissao->tm_year << endl;
}

Funcionario::~Funcionario() {
    cout << "Liberando memória (Funcionario)" << endl;
}

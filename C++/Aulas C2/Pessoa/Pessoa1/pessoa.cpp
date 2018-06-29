#include "pessoa.h"

#include <iostream>

using namespace std;

//Pessoa::Pessoa() {
//}

void Pessoa::mostrar() {
    cout << "\nNome: " << this->nome << endl;
    cout << "\nEndereco: " << this->endereco << endl;
}

void Pessoa::setar() {
    char newline;
    cout << "Digite o nome: ";
    cin.get(this->nome, 30, '\n');
    cin.get(newline);
    cout << "Digite o endereco: ";
    cin.get(this->endereco, 40, '\n');
    cin.get(newline);
}

Pessoa::~Pessoa() {
    cout << "Liberando memoria (pessoa)" << endl;
}

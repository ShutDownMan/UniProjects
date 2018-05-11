#include "pessoa.h"

ostream &operator<<(ostream &output, Pessoa &p) {
    p.mostrar();
    return output;
}

Pessoa::Pessoa(int idPessoa, char *nome) {
    this->idPessoa = idPessoa;
    this->nome = strcpy((char *)malloc(sizeof(strlen(nome))+1), nome);
}

char *Pessoa::getNome() {
    return this->nome;
}

bool Pessoa::operator<(Pessoa &p) {
    return (strcmp(this->getNome(), p.getNome()) < 0);
}

bool Pessoa::operator>(Pessoa &p) {
    return (strcmp(this->getNome(), p.getNome()) > 0);
}

bool Pessoa::operator==(Pessoa &p) {
    return (!strcmp(this->getNome(), p.getNome()));
}

void Pessoa::mostrar() {
    printf("[%04d]:\n", this->idPessoa);
    printf("\t%s\n", this->nome);
}

Pessoa::~Pessoa() {
    printf("(%04d) Liberando memoria.\n", this->idPessoa);
}


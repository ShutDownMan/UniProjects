#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>

#include "pessoa.h"
#include "date.h"

#define MAXLENGTH 10

using namespace std;

class Agenda {
private:
    Person *mContacts[MAXLENGTH];
    int length;
public:
    Agenda();

    void armazenaPessoa(string *nome, Date *birthdate, double heigth);

    void removePessoa(string *nome);

    int buscaPessoa(string *nome);

    void imprimeAgenda();

    void imprimePessoa(int ind);

    ~Agenda();
};

#endif // AGENDA_H

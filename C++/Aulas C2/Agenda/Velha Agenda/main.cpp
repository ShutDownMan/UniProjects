#include <iostream>

#include "pessoa.h"
#include "date.h"
#include "agenda.h"

using namespace std;

int main() {
    Agenda *agenda = new Agenda();

    agenda->armazenaPessoa(new string("Alisson"), new Date(12, 9, 1995), 1.66);
    agenda->armazenaPessoa(new string("notPessoa"), new Date(1, 1, 2015), 1.10);
    agenda->armazenaPessoa(new string("Aleson"), new Date(1, 12, 1975), 2.66);

    agenda->removePessoa(new string("notPessoa"));

    agenda->imprimeAgenda();

    agenda->imprimePessoa(1);

    delete agenda;

    return 0;
}

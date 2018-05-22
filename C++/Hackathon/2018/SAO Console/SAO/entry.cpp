#include "entry.h"

Entry::Entry() {
    this->databaseId = 0;

    this->id = 0;
    this->ano = 0;

    this->tipoId = 0;
    this->tipoDesc = NULL;

    this->setorRmtntId = 0;
    this->setorDestIdQnt = 0;

    this->ant = 0;
    this->resposta = 0;

    this->pendente = 0;
}

void Entry::show() {
    int i;
    printf("%04d/%03d\n\n", this->ano, this->id);

    if(this->tipoId) {
        printf("Tipo: %d\n", this->tipoId);
    } else {
        cout << "Tipo: " << (*this->tipoDesc) << endl;
    }

    printf("Setor remetente: %03d\n", this->setorRmtntId);

    for(i = 0; i < this->setorDestIdQnt; ++i) {
        printf("%d", this->setorDestIds[i]);
        if(i != this->setorDestIdQnt-1) {
            printf(", ");
        } else {
            printf(".");
        }
    }
    printf("\n");

    printf("Pendente?: %c\n", (this->pendente) ? 's' : 'n');

}

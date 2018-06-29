#include "agenda.h"

Agenda::Agenda() {
    this->length = 0;

    for(int i = 0; i < MAXLENGTH; ++i) {
        this->mContacts[i] = NULL;
    }
}

void Agenda::armazenaPessoa(string *nome, Date *birthdate, double heigth) {
    Person *newPerson = new Person(nome, birthdate, heigth);
    int i;

    if(this->length >= MAXLENGTH) {
        cout << "A agenda está cheia!" << endl;
        return;
    }

    for(i = 0; i < MAXLENGTH; ++i) {
        if(!this->mContacts[i]) {
            this->mContacts[i] = newPerson;
            this->length++;
            break;
        }
    }
}

void Agenda::removePessoa(string *nome) {
    int i;

    for(i = 0; i < this->length; ++i) {
        if(this->mContacts[i]) {
            if(!(this->mContacts[i]->getName())->compare(*nome)) {
                delete this->mContacts[i];
                this->mContacts[i] = NULL;
                this->length--;
                break;
            }
        }
    }
}

int Agenda::buscaPessoa(string *nome) {
    int i;

    for(i = 0; i < this->length; ++i) {
        if(this->mContacts[i]) {
            if(!(this->mContacts[i]->getName())->compare(*nome)) {
                return i;
            }
        }
    }

    return -1;
}

void Agenda::imprimeAgenda() {
    int i;

    cout << "Agenda:" << endl;

    for(i = 0; i < this->length; ++i) {
        if(this->mContacts[i]) {
            this->mContacts[i]->show();
        }
    }
    cout << "---------------" << endl;
}

void Agenda::imprimePessoa(int ind) {
    int i = 0, aux = 0;

    for(i = 0; i < MAXLENGTH; i++) {
        if(this->mContacts[i]) {
            if(aux == ind) break;
            aux++;
        }
    }

    this->mContacts[i]->show();
}

Agenda::~Agenda() {
    int i;

    for(i = 0; i < this->length; ++i) {
        if(this->mContacts[i]) {
            delete this->mContacts[i];
        }
    }

    cout << "Destruindo agenda" << endl;
}


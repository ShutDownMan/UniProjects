#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iostream>
using namespace std;

#define SETORDESTMAX 16

class Entry {
public:
    unsigned int databaseId;
    unsigned int id, ano;

    unsigned int tipoId;
    string *tipoDesc;

    unsigned int setorRmtntId;
    unsigned int setorDestIds[SETORDESTMAX];
    int setorDestIdQnt;

    string *imagesPath;

    Entry *ant;
    Entry *resposta;

    bool pendente;

    void show();

    Entry();
};

#endif // ENTRY_H

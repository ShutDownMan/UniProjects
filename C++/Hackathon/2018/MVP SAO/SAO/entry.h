#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

#define SETORDESTMAX 16

class Entry {
private:
    Entry *ant;
    Entry *resposta;

    unsigned int id, ano;

    unsigned int tipoId;
    string tipoDesc;

    unsigned int setorRmtntId;
    unsigned int setorDestId[SETORDESTMAX];

    Image *imagens;

public:
    Entry();
};

#endif // ENTRY_H

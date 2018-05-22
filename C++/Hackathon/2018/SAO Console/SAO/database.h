#ifndef DATABASE_H
#define DATABASE_H

#define MAXENTRIES 128

#include "entry.h"

class Database {
public:
    Entry *entry[MAXENTRIES];
    unsigned int entryQnt;
    Database();

    int saveEntry(Entry *entry);

    Entry *search(unsigned int ano, unsigned int id);

    ~Database();
};

#endif // DATABASE_H

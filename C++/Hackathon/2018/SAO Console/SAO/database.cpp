#include "database.h"

Database::Database() {
    this->entryQnt = 0;
}

Entry *Database::search(unsigned int ano, unsigned int id) {
    Entry *foundEntry = NULL;
    unsigned int i;

    for(i = 0; i < this->entryQnt; ++i) {
        if(this->entry[i]->ano == ano && this->entry[i]->id == id) {
            foundEntry = this->entry[i];
        }
    }

    return foundEntry;
}

int Database::saveEntry(Entry *entry) {
    this->entry[this->entryQnt++] = entry;
    return 1;
}

Database::~Database() {

}

//
// Created by Jedson on 11/2/2018.
//

#ifndef ARQUIVO_INVERSO_REGISTY_H
#define ARQUIVO_INVERSO_REGISTY_H

#include <stdio.h>

typedef struct entry {
    int file, quant, entryPos, nextEntryPos;
} Entry;

typedef struct registryHeader {
    int topPos;
} RegistryHeader;

//- INITIALIZE -//

void createEmptyRegistryFile(FILE *f);

Entry * createEntry();

//- WRITE -//

void writeRegistryHeader(FILE *f, RegistryHeader *header);

int writeEntryToFile(FILE *f, RegistryHeader *header, Entry *entry);

//- READ -//

RegistryHeader *readRegistryHeader(FILE *f);

Entry *readEntryFromFile(FILE *f, int pos);

//- SHOW -//

void printRegistryHeader(RegistryHeader *header);

void printEntry(Entry *entry);

#endif //ARQUIVO_INVERSO_REGISTY_H

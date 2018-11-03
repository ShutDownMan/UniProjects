//
// Created by Jedson on 11/2/2018.
//

#include <stdlib.h>
#include "Registy.h"

//- INITIALIZE -//

void createEmptyRegistryFile(FILE *f) {
    RegistryHeader header = {.topPos = 0};

    writeRegistryHeader(f, &header);
}

Entry *createEntry() {
    Entry *newEntry = (Entry *) malloc(sizeof(Entry));

    newEntry->file = -1;
    newEntry->quant = 0;
    newEntry->entryPos = -1;
    newEntry->nextEntryPos = -1;

    return newEntry;
}

//- WRITE -//


void writeRegistryHeader(FILE *f, RegistryHeader *header) {
    fseek(f, 0, SEEK_SET);

    fwrite(header, sizeof(RegistryHeader), 1, f);
}

int writeEntryToFile(FILE *f, RegistryHeader *header, Entry *entry) {
    int pos;

    if ((pos = entry->entryPos) == -1) {
        pos = header->topPos++;
        writeRegistryHeader(f, header);
    }

    entry->entryPos = pos;

    fseek(f, sizeof(RegistryHeader) + sizeof(Entry) * pos, SEEK_SET);

    fwrite(entry, sizeof(Entry), 1, f);

    return pos;
}

//- READ -//

RegistryHeader *readRegistryHeader(FILE *f) {
    RegistryHeader *header = (RegistryHeader *) malloc(sizeof(RegistryHeader));

    fseek(f, 0, SEEK_SET);

    fread(header, sizeof(RegistryHeader), 1, f);

    return header;
}

Entry *readEntryFromFile(FILE *f, int pos) {
    Entry *entry = (Entry *)malloc(sizeof(Entry));

    if(pos == -1) return NULL;

    fseek(f, sizeof(RegistryHeader) + sizeof(Entry)*pos, SEEK_SET);

    fread(entry, sizeof(Entry), 1, f);

    return entry;
}

//- SHOW -//

void printRegistryHeader(RegistryHeader *header) {
    printf("-----------------\n");
    printf("topPos = %d\n", header->topPos);
    printf("-----------------\n");
}

void printEntry(Entry *entry) {
    printf("-----------------\n");
    printf("fileNumber = %d\n", entry->file);
    printf("Word quantity = %d\n", entry->quant);
    printf("Entry position = %d\n", entry->entryPos);
    printf("Next entry position = %d\n", entry->nextEntryPos);
    printf("-----------------\n");
}


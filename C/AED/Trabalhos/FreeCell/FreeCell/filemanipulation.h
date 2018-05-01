#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

typedef Card ItemType;

typedef struct header {
    int freeCellsHeads[4];
    int homeCellsHeads[4], tableauHeads[8];
    int topPos;
} Header;

typedef struct fileNode {
    ItemType val;
    int next;
} FileNode;

FILE *openBinaryFile(char fileName[], char mode[]);

void createEmptyList(FILE *f);

FileNode *createFileNode(ItemType val);

void writeHeaderToFile(FILE *f, Header *header);

void writeNodeToFile(FILE *f, FileNode *toWrite, int pos);

Header *readHeader(FILE *f);

FileNode *readFileNode(FILE *f, int pos);

void insertNodeOnFreeCell(FILE *f, int index, ItemType val);

void insertNodeOnHomeCell(FILE *f, int index, ItemType val);

void insertNodeOnTableau(FILE *f, int index, ItemType val);

void freeFileNode(FileNode *node);

#endif // FILEMANIPULATION_H

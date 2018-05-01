#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef int ItemType;

typedef struct header {
    int headPos, topPos, freePos;
} Header;

typedef struct node {
    ItemType val;
    int next;
} Node;

FILE *openBinaryFile(char fileName[]);

void createEmptyList(FILE *f);

Node *createNode(ItemType val);

void writeHeaderToFile(FILE *f, Header *header);

void writeNodeToFile(FILE *f, Node *toWrite, int pos);

Header *readHeader(FILE *f);

Node *readNode(FILE *f, int pos);

void insertNodeOnHead(FILE *f, ItemType val);

void printFileList(FILE *f);

void freeNode(Node *node);

#endif

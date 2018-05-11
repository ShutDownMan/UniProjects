#include "filemanipulation.h"

FILE *openBinaryFile(char fileName[], char mode[]) {
    return fopen(fileName, mode);
}

void createEmptyList(FILE *f) {
    Header *newHeader = (Header *) malloc(sizeof(Header));
    int i;

    for(i = 0; i < 4; ++i) {
        newHeader->freeCellsHeads[i] = -1;
        newHeader->homeCellsHeads[i] = -1;
        newHeader->tableauHeads[i] = -1;
        newHeader->tableauHeads[i+4] = -1;
    }

    newHeader->topPos = 0;

    writeHeaderToFile(f, newHeader);
    free(newHeader);
}

FileNode *createFileNode(ItemType val) {
    FileNode *newNode = (FileNode *) malloc(sizeof(FileNode));

    newNode->val = val;
    newNode->next = -1;

    return newNode;
}

void writeHeaderToFile(FILE *f, Header *header) {
    fseek(f, 0, SEEK_SET);
    fwrite(header, sizeof(Header), 1, f);
}

void writeNodeToFile(FILE *f, FileNode *toWrite, int pos) {
    fseek(f, sizeof(Header) + sizeof(FileNode)*pos, SEEK_SET);
    fwrite(toWrite, sizeof(FileNode), 1, f);
}

Header *readHeader(FILE *f) {
    Header *readHeader = (Header *) malloc(sizeof(Header));

    fseek(f, 0, SEEK_SET);
    fread(readHeader, sizeof(Header), 1, f);

    return readHeader;
}

FileNode *readFileNode(FILE *f, int pos) {
    FileNode *toRead = (FileNode *) malloc(sizeof(FileNode));

    fseek(f, sizeof(Header) + sizeof(FileNode)*pos, SEEK_SET);
    fread(toRead, sizeof(FileNode), 1, f);

    return toRead;
}

void insertNodeOnFreeCell(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    toWrite->next = header->freeCellsHeads[index];

    writeNodeToFile(f, toWrite, header->topPos);
    header->freeCellsHeads[index] = header->topPos;
    header->topPos++;

    writeHeaderToFile(f, header);

//    printf("freeCellsHeads[%d] = %d\n", index, header->freeCellsHeads[index]);
    freeFileNode(toWrite);
}

void insertNodeOnHomeCell(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    toWrite->next = header->homeCellsHeads[index];

    writeNodeToFile(f, toWrite, header->topPos);
    header->homeCellsHeads[index] = header->topPos;
    header->topPos++;

    writeHeaderToFile(f, header);

//    printf("homeCellsHeads[%d] = %d\n", index, header->homeCellsHeads[index]);
    freeFileNode(toWrite);
}

void insertNodeOnTableau(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    toWrite->next = header->tableauHeads[index];

    writeNodeToFile(f, toWrite, header->topPos);
    header->tableauHeads[index] = header->topPos;
    header->topPos++;

    writeHeaderToFile(f, header);

//    printf("tableauHeads[%d] = %d\n", index, header->tableauHeads[index]);
    freeFileNode(toWrite);
}

void freeFileNode(FileNode *node) {
    free(node);
}

#include "main.h"

int main(int argc, char const *argv[]) {
    FILE *f = openBinaryFile("test.bin");

    createEmptyList(f);

    insertNodeOnHead(f, 5);
    insertNodeOnHead(f, 6);
    insertNodeOnHead(f, 3);
    insertNodeOnHead(f, 4);
    insertNodeOnHead(f, 0);
    insertNodeOnHead(f, 1);

    printFileList(f);

    fclose(f);

    return 0;
}

FILE *openBinaryFile(char fileName[]) {
    FILE *newFile = NULL;

    newFile = fopen(fileName, "wb+");

    return newFile;
}

void createEmptyList(FILE *f) {
    Header *newHeader = (Header *) malloc(sizeof(Header));

    newHeader->headPos = -1;
    newHeader->topPos = 0;
    newHeader->freePos = -1;

    writeHeaderToFile(f, newHeader);
    free(newHeader);
}

Node *createNode(ItemType val) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->val = val;
    newNode->next = -1;

    return newNode;
}

void writeHeaderToFile(FILE *f, Header *header) {
    fseek(f, 0, SEEK_SET);
    fwrite(header, sizeof(Header), 1, f);
}

void writeNodeToFile(FILE *f, Node *toWrite, int pos) {
    fseek(f, sizeof(Header) + pos*sizeof(Node), SEEK_SET);
    fwrite(toWrite, sizeof(Node), 1, f);
}

Header *readHeader(FILE *f) {
    Header *readHeader = (Header *) malloc(sizeof(Header));

    fseek(f, 0, SEEK_SET);
    fread(readHeader, sizeof(Header), 1, f);

    return readHeader;
}

Node *readNode(FILE *f, int pos) {
    Node *toRead = createNode(0);
    fseek(f, sizeof(Header) + sizeof(Node)*pos, SEEK_SET);
    fread(toRead, sizeof(Node), 1, f);
    return toRead;
}

void insertNodeOnHead(FILE *f, ItemType val) {
    Header *header = readHeader(f);
    Node *toWrite = createNode(val), *freePosNode = NULL;

    toWrite->next = header->headPos;

    if(header->freePos == -1) {
        writeNodeToFile(f, toWrite, header->topPos);
        header->headPos = header->topPos;
        header->topPos++;
    } else {
        freePosNode = readNode(f, header->freePos);
        writeNodeToFile(f, toWrite, header->freePos);
        header->headPos = header->freePos;
        header->freePos = freePosNode->next;
        free(header);
    }

    writeHeaderToFile(f, header);

    free(toWrite);
    free(freePosNode);
}

void printFileList(FILE *f) {
    Header *header = readHeader(f);
    Node *aux = NULL, *next = NULL;

    if(header->headPos != -1) {
        aux = readNode(f, header->headPos);
        printf("(%d)->", aux->val);
        while(aux->next != -1) {
            next = readNode(f, aux->next);
            freeNode(aux);
            printf("(%d)->", next->val);
            aux = next;
        }
        freeNode(aux);
        printf("(!);\n");
    }
}

void freeNode(Node *node) {
    free(node);
}

#ifndef HUFFMAN_CHAR_H
#define HUFFMAN_CHAR_H

#define FALSE 0
#define TRUE 1

#include "symbol_code.h"

typedef struct CharSymbol
{
    unsigned char charactere;
    size_t freq;
} CharSymbol;

typedef struct HuffTreeChar
{
    CharSymbol *symbol;
    char isJoinNode;

    struct HuffTreeChar *leftChild;
    struct HuffTreeChar *rightChild;
} HuffTreeChar;

typedef struct QueueChar
{
    HuffTreeChar *treeSymbol;
    struct QueueChar *next;
} QueueChar;

QueueChar *generateQueueFromCharFreq(size_t *freqs);

void charQuickSortIndex(CharSymbol *vet[], size_t left, size_t right);
int charSeparate(CharSymbol *vet[], size_t left, size_t right);

QueueChar *pushQueueChar(QueueChar *qHead, QueueChar *newNode);

HuffTreeChar *generateHuffTreeFromQueueChar(QueueChar *queue);
QueueChar *popQueueChar(QueueChar **qHead);

void printQueueChar(QueueChar *queue);
void printHuffTreeChar(HuffTreeChar *tree);

void generateHuffCodesChar(HuffTreeChar *huffTree, SymbolCode huffCodes[256]);
void generateHuffCodesCharRec(HuffTreeChar *huffTree, SymbolCode huffCodes[256], SymbolCode symbolCode);

typedef struct HuffmanCharFileHeader
{
    size_t huffTreeCharHeadOffset;
    size_t dataOffset;
} HuffmanCharFileHeader;

typedef struct HuffTreeCharFile
{
    char symbol;

    unsigned int leftChildOffset;
    unsigned int rightChildOffset;
} HuffTreeCharFile;

size_t writeHuffTreeChar(HuffTreeChar *ht, FILE *outputFile);

#endif
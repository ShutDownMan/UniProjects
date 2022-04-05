#ifndef HUFFMAN_H
#define HUFFMAN_H

#define FALSE 0
#define TRUE 1

#include "huffman_char.h"
#include "symbol_code.h"

typedef struct huffmanSettings
{
    char useWords;
    char useLFSS;
    char *filePath;
    char decompress;
    char verbose;
} HuffmanSettings;

HuffmanSettings *settings;

HuffmanSettings *parseSettings(int argc, char const *argv[]);
void printSettings(HuffmanSettings *settings);

int compressFile();
int compressFilebyChar(FILE *inputFile, FILE *outputFile, HuffmanSettings *settings);

void writeSymbolCodeToFile(SymbolCode currentCode, SymbolCode writeBuff, SymbolCode huffCodes[256], FILE *outputFile);

#endif
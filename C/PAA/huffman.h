#ifndef HUFFMAN_H
#define HUFFMAN_H

#define FALSE 0
#define TRUE 1

typedef struct huffmanSettings
{
    char useWords;
    char useLFSS;
    char *filePath;
} HuffmanSettings;

HuffmanSettings *parseSettings(int argc, char const *argv[]);
void printSettings(HuffmanSettings *settings);

int compressFile(HuffmanSettings *settings);
int compressFilebyChar(FILE *inputFile, FILE *outputFile, HuffmanSettings *settings);

typedef struct CharSymbol
{
    unsigned char symbol;
    size_t freq;
} CharSymbol;


typedef struct QueueChar
{
    CharSymbol *symbol;
    struct QueueChar *next;
} QueueChar;

QueueChar *generateQueueFromCharFreq(size_t *freqs);

void charQuickSortIndex(size_t vet[], size_t vetIdx[], size_t left, size_t right);
int charSeparate(size_t vet[], size_t vetIdx[], size_t left, size_t right);

typedef struct HuffTreeChar
{
    CharSymbol *tree;

    struct HuffTreeChar *leftChild;
    struct HuffTreeChar *rightChild;


} HuffTreeChar;

HuffTreeChar *generateHuffTreeFromCharQueue(QueueChar *queue);

#endif
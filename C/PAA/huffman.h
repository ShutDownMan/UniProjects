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

typedef struct HuffTreeChar
{
    HuffTreeCharNode *tree;
} HuffTreeChar;

typedef struct HuffTreeCharNode
{
    unsigned char symbol;
    size_t freq;
} HuffTreeCharNode;

HuffTreeChar *generateHuffTreeFromCharFreq(char *freqs);




#endif
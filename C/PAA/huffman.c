#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"

int main(int argc, char const *argv[])
{
    HuffmanSettings *settings = parseSettings(argc, argv);

    printSettings(settings);

    if (argc == 1 || !settings->filePath)
    {
        printf("Especifique o arquivo de entrada.\n");
        printf("ex:\n");
        printf("./huffman [-w -l] arquivo.txt\n");
        return 1;
    }

    char exitCode = compressFile(settings);

    if (exitCode)
    {
        printf("[%d] Não foi possível comprimir o arquivo\n", exitCode);
    }

    return 0;
}

HuffmanSettings *parseSettings(int argc, char const *argv[])
{
    HuffmanSettings *settings = (HuffmanSettings *)malloc(sizeof(HuffmanSettings));

    settings->useWords = FALSE;
    settings->useLFSS = FALSE;
    settings->filePath = NULL;

    for (size_t i = 1; i < argc; i++)
    {
        size_t argLen = strlen(argv[i]);
        if (argLen >= 2 && argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'w':
                settings->useWords = TRUE;
                break;
            case 'l':
                settings->useLFSS = TRUE;
                break;

            default:
                break;
            }
        }
        else if (argLen >= 1)
        {
            settings->filePath = (char *)malloc(sizeof(char) * argLen + 1);
            strcpy(settings->filePath, argv[i]);
        }
    }

    return settings;
}

void printSettings(HuffmanSettings *settings)
{
    printf("Usando palavras: %s\n", (settings->useWords) ? "Sim" : "Não");
    printf("Usando LFSS: %s\n", (settings->useLFSS) ? "Sim" : "Não");
    printf("Arquivo de Entrada: %s\n", settings->filePath);
}

int compressFile(HuffmanSettings *settings)
{
    FILE *inputFile = fopen(settings->filePath, "r");

    char *outputFileName = "compressed.hff"; // TODO
    FILE *outputFile = fopen(outputFileName, "w");

    if (!inputFile)
    {
        printf("Não foi posssível abrir o arquivo de entrada \"%s\"", settings->filePath);
        return 1;
    }
    if (!outputFile)
    {
        printf("Não foi posssível abrir o arquivo de saida \"%s\"", outputFileName);
        return 1;
    }

    if (settings->useWords)
    {
        printf("Funcionalidade não implementada.");
        return 2;
    }
    else
    {
        int exitCode = compressFilebyChar(inputFile, outputFile, settings);
        return exitCode;
    }
}

int compressFilebyChar(FILE *inputFile, FILE *outputFile, HuffmanSettings *settings)
{
    if (settings->useLFSS)
    {
        printf("Funcionalidade não implementada.");
        return 2;
    }
    else
    {
        char c;
        char freqs[256] = {0};
        while ((c = fgetc(inputFile)) != EOF)
        {
            freqs[(unsigned char)c]++;
        }

        for (size_t i = 0; i < 256; i++)
        {
            if (freqs[i])
            {
                printf("[%c] - %d\n", (char)i, freqs[i]);
            }
        }

        HuffTreeChar *huffTree = generateHuffTreeFromCharFreq(freqs);
    }
}

HuffTreeChar *generateHuffTreeFromCharFreq(char *freqs)
{
    HuffTreeChar *htChar = (HuffTreeChar *)malloc(sizeof(HuffTreeChar));

    htChar->tree = (HuffTreeCharNode *)malloc(sizeof(HuffTreeCharNode) * 2);

    

}
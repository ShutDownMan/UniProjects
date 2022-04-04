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
        size_t freqs[256] = {0};
        while ((c = fgetc(inputFile)) != EOF)
        {
            freqs[(size_t)c]++;
        }

        // print freqs
        for (size_t i = 0; i < 256; i++)
        {
            if (freqs[i])
            {
                printf("[%c] - %d\n", (char)i, freqs[i]);
            }
        }

        QueueChar *queue = generateQueueFromCharFreq(freqs);
        HuffTreeChar *huffTree = generateHuffTreeFromCharQueue(queue);
    }

    return 0;
}

QueueChar *generateQueueFromCharFreq(size_t freqs[256])
{
    size_t sortedIdx[256] = {0};
    size_t i = 0;

    printf("--------------------\n");
    while ((sortedIdx[i] = i) < 256)
    {
        if (freqs[sortedIdx[i]])
        {
            printf("[%d] - %d\n", i, freqs[sortedIdx[i]]);
        }
        i++;
    }

    charQuickSortIndex(freqs, sortedIdx, 0, 255);

    // print freqs sorted ids
    printf("--------------------\n");
    for (size_t i = 0; i < 256; i++)
    {
        if (freqs[sortedIdx[i]])
        {
            printf("[%d] - %d\n", sortedIdx[i], freqs[sortedIdx[i]]);
        }
    }
}

/**
    @brief ordena inteiros pelo método QuickSort
    @param vet vetor de inteiros
    @param left limite esquerdo do vetor
    @param right limite direito do vetor
    @precondition nenhuma
    @postcondition vetor é ordenado em ordem crescente
*/
void charQuickSortIndex(size_t vet[], size_t vetIdx[], size_t left, size_t right)
{
    size_t j;
    if (left < right)
    {
        j = charSeparate(vet, vetIdx, left, right);
        charQuickSortIndex(vet, vetIdx, left, j - 1);
        charQuickSortIndex(vet, vetIdx, j + 1, right);
    }
}

/**
    @brief função auxiliar de QuickSort
    @param vet vetor de inteiros
    @param left limite esquerdo
    @param right limite direito
    @precondition nenhuma
    @postcondition vetor é manipulado com referência a um pivô
*/
int charSeparate(size_t vet[], size_t vetIdx[], size_t left, size_t right)
{
    size_t pivo, pivoIdx, j, k, temp;

    pivo = vet[right];
    pivoIdx = vetIdx[right];
    j = left;
    for (k = left; k < right; k++)
    {
        if (vet[k] <= pivo)
        {
            temp = vet[j];
            vet[j] = vet[k];
            vet[k] = temp;
            temp = vetIdx[j];
            vetIdx[j] = vetIdx[k];
            vetIdx[k] = temp;
            j++;
        }
    }
    vet[right] = vet[j];
    vet[j] = pivo;
    vetIdx[right] = vetIdx[j];
    vetIdx[j] = pivoIdx;

    return j;
}

HuffTreeChar *generateHuffTreeFromCharQueue(QueueChar *queue)
{
    HuffTreeChar *htChar = (HuffTreeChar *)malloc(sizeof(HuffTreeChar));

    // htChar->tree = (Symbol *)malloc(sizeof(HuffTreeCharNode) * 2);
}
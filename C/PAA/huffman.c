#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"

int main(int argc, char const *argv[])
{
    char exitCode = 0;
    settings = parseSettings(argc, argv);

    printSettings(settings);

    if (argc == 1 || !settings->filePath)
    {
        printf("Especifique o arquivo de entrada.\n");
        printf("ex:\n");
        printf("./huffman [-w -l -d] arquivo.txt\n");
        return 1;
    }

    if (!settings->decompress)
    {
        exitCode = compressFile(settings);
    }
    else
    {
        exitCode = 2;
        printf("Funcionalidade não implementada.\n");
    }

    if (exitCode)
    {
        printf("[%d] Não foi possível comprimir o arquivo\n", exitCode);
    }

    return exitCode;
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
            case 'd':
                settings->decompress = TRUE;
                break;
            case 'v':
                settings->verbose = argv[i + 1][0] - '0';
                i++;
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
    printf("Verboso: %s\n", (settings->verbose) ? "Sim" : "Não");
    printf("Descomprimir: %s\n", (settings->decompress) ? "Sim" : "Não");
}

int compressFile()
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
        printf("Funcionalidade não implementada.\n");
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
        printf("Funcionalidade não implementada.\n");
        return 2;
    }
    else
    {
        char c;
        size_t freqs[256] = {0};
        while ((c = fgetc(inputFile)) != EOF)
        {
            freqs[(unsigned char)c]++;
        }
        freqs[(unsigned char)EOF]++;

        if (settings->verbose >= 3)
        {
            printf("Frequências dos characteres:\n");
            for (size_t i = 0; i < 256; i++)
            {
                if (freqs[i])
                {
                    printf("[%c] - %d\n", (char)i, freqs[i]);
                }
            }
        }

        HuffmanCharFileHeader fHeader = {0, 0};

        fwrite(&fHeader, sizeof(HuffmanCharFileHeader), 1, outputFile);

        QueueChar *queue = generateQueueFromCharFreq(freqs);
        HuffTreeChar *huffTree = generateHuffTreeFromQueueChar(queue);

        fseek(outputFile, 0, SEEK_SET);
        fHeader.huffTreeCharHeadOffset = writeHuffTreeChar(huffTree, outputFile);
        fHeader.dataOffset = ftell(outputFile);

        fseek(outputFile, 0, SEEK_SET);
        fwrite(&fHeader, sizeof(HuffmanCharFileHeader), 1, outputFile);
        fseek(outputFile, fHeader.dataOffset, SEEK_SET);

        SymbolCode huffCodes[256] = {0};
        generateHuffCodesChar(huffTree, huffCodes);

        if (settings->verbose >= 3)
        {
            printf("Códigos dos characteres:\n");
            for (size_t i = 0; i < 256; i++)
            {
                if (freqs[i])
                {
                    printf("[0x%04x|%02d] - %c\n", huffCodes[i].code, huffCodes[i].length, (char)i);
                }
            }
        }

        SymbolCode currentCode = {0, 0};
        SymbolCode writeBuff = {0, 0};
        fseek(inputFile, 0, SEEK_SET);
        while ((c = fgetc(inputFile)) != EOF)
        {
            currentCode = huffCodes[(unsigned char)c];
            writeSymbolCodeToFile(currentCode, writeBuff, huffCodes, outputFile);
        }
        /// Escrevendo EOF no final do arquivo
        {
            currentCode = huffCodes[(unsigned char)EOF];
            writeSymbolCodeToFile(currentCode, writeBuff, huffCodes, outputFile);
        }

        if (writeBuff.length)
        {
            writeBuff.code <<= 8 - writeBuff.length;
            fputc((unsigned char)writeBuff.code, outputFile);
        }

        // TODO: free huff tree memory
    }

    printf("%d\n", sizeof(char) + 2 * sizeof(unsigned int));
    printf("%d\n", sizeof(HuffTreeCharFile));

    return 0;
}

void writeSymbolCodeToFile(SymbolCode currentCode, SymbolCode writeBuff, SymbolCode huffCodes[256], FILE *outputFile)
{
    writeBuff.code <<= currentCode.length;
    writeBuff.code += currentCode.code;
    writeBuff.length += currentCode.length;

    if (writeBuff.length >= 8)
    {
        fputc((unsigned char)writeBuff.code, outputFile);
        writeBuff.length -= 8;
    }
}

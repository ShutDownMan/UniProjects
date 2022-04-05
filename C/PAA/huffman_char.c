#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "huffman_char.h"

QueueChar *generateQueueFromCharFreq(size_t freqs[256])
{
    QueueChar *queue = NULL;
    CharSymbol *charSymbols[256] = {NULL}, *currentSymbol;
    size_t charSymbolsLen = 0;

    for (size_t i = 0; i < 256; ++i)
    {
        if (freqs[i])
        {
            currentSymbol = charSymbols[charSymbolsLen++] = (CharSymbol *)malloc(sizeof(CharSymbol));
            currentSymbol->charactere = (char)i;
            currentSymbol->freq = freqs[i];
        }
    }

    charQuickSortIndex(charSymbols, 0, charSymbolsLen - 1);

    // // print freqs sorted ids
    // printf("--------------------\n");
    // for (size_t i = 0; i < charSymbolsLen; i++)
    // {
    //     if (charSymbols[i])
    //     {
    //         if (charSymbols[i]->charactere >= 0 && charSymbols[i]->charactere != '\n')
    //         {
    //             printf("[%c] - %d\n", charSymbols[i]->charactere, charSymbols[i]->freq);
    //         }
    //         else
    //         {
    //             printf("[#] - %d\n", charSymbols[i]->freq);
    //         }
    //     }
    // }

    for (size_t i = 0; i < charSymbolsLen; i++)
    {
        QueueChar *newQNode = (QueueChar *)malloc(sizeof(QueueChar));
        newQNode->treeSymbol = (HuffTreeChar *)malloc(sizeof(HuffTreeChar));

        newQNode->treeSymbol->symbol = charSymbols[i];
        newQNode->treeSymbol->isJoinNode = FALSE;
        newQNode->treeSymbol->leftChild = NULL;
        newQNode->treeSymbol->rightChild = NULL;

        newQNode->next = NULL;

        queue = pushQueueChar(queue, newQNode);
    }

    printf("-----------\n");
    printQueueChar(queue);

    return queue;
}

/**
    @brief ordena inteiros pelo método QuickSort
    @param vet vetor de inteiros
    @param left limite esquerdo do vetor
    @param right limite direito do vetor
    @precondition nenhuma
    @postcondition vetor é ordenado em ordem crescente
*/
void charQuickSortIndex(CharSymbol *vet[], size_t left, size_t right)
{
    int j;
    if (left < right)
    {
        j = charSeparate(vet, left, right);
        charQuickSortIndex(vet, left, j - 1);
        charQuickSortIndex(vet, j + 1, right);
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
int charSeparate(CharSymbol *vet[], size_t left, size_t right)
{
    size_t j, k;
    CharSymbol *pivo, *temp;

    pivo = vet[right];
    j = left;
    for (k = left; k < right; k++)
    {
        if (vet[k]->freq <= pivo->freq)
        {
            temp = vet[j];
            vet[j] = vet[k];
            vet[k] = temp;
            j++;
        }
    }
    vet[right] = vet[j];
    vet[j] = pivo;

    return j;
}

QueueChar *pushQueueChar(QueueChar *qHead, QueueChar *newNode)
{
    /// insert in queue, trivial case
    if (!qHead)
    {
        return newNode;
    }

    /// test head
    if (newNode->treeSymbol->symbol->freq < qHead->treeSymbol->symbol->freq)
    {
        newNode->next = qHead;
        return newNode;
    }

    /// iterate through queue in order to insert
    QueueChar *iter = qHead;
    for (; iter != NULL; iter = iter->next)
    {
        if (!iter->next || newNode->treeSymbol->symbol->freq < iter->next->treeSymbol->symbol->freq)
        {
            newNode->next = iter->next;
            iter->next = newNode;
            return qHead;
        }
    }

    return qHead;
}

HuffTreeChar *generateHuffTreeFromQueueChar(QueueChar *qHead)
{
    HuffTreeChar *ht = NULL;
    QueueChar *popped1, *popped2;

    do
    {
        popped1 = popQueueChar(&qHead);
        popped2 = popQueueChar(&qHead);

        if (popped1)
        {
            if (popped2)
            {
                QueueChar *newQNode = (QueueChar *)malloc(sizeof(QueueChar));
                newQNode->treeSymbol = (HuffTreeChar *)malloc(sizeof(HuffTreeChar));
                newQNode->treeSymbol->symbol = (CharSymbol *)malloc(sizeof(CharSymbol));
                newQNode->next = NULL;

                newQNode->treeSymbol->isJoinNode = TRUE;

                newQNode->treeSymbol->symbol->charactere = 0;
                newQNode->treeSymbol->symbol->freq = popped1->treeSymbol->symbol->freq + popped2->treeSymbol->symbol->freq;

                newQNode->treeSymbol->leftChild = popped1->treeSymbol;
                newQNode->treeSymbol->rightChild = popped2->treeSymbol;

                qHead = pushQueueChar(qHead, newQNode);

                free(popped1);
                free(popped2);
            }
        }
    } while (popped2);

    ht = popped1->treeSymbol;

    if (popped1)
    {
        free(popped1);
    }

    // printf("-----------\n");
    // printHuffTreeChar(ht);

    return ht;
}

QueueChar *popQueueChar(QueueChar **qHead)
{
    QueueChar *popped = (*qHead);

    if (popped)
    {
        (*qHead) = popped->next;

        popped->next = NULL;
    }

    return popped;
}

void printQueueChar(QueueChar *queue)
{
    QueueChar *iter = queue;
    for (; iter; iter = iter->next)
    {
        if (iter->treeSymbol->symbol->freq > 0)
        {
            switch (iter->treeSymbol->symbol->charactere)
            {
            case '\n':
            case '\t':
                printf("[%d] '@'\n", iter->treeSymbol->symbol->freq);
                break;

            default:
                printf("[%d] '%c'\n", iter->treeSymbol->symbol->freq, iter->treeSymbol->symbol->charactere);
                break;
            }
        }
    }
    // printf("{!}\n");
}

void printHuffTreeChar(HuffTreeChar *tree)
{
    if (!tree)
        return;

    if (tree->symbol->freq > 0)
    {
        switch (tree->symbol->charactere)
        {
        case '\n':
        case '\t':
            printf("[#] %d\n", tree->symbol->freq);
            break;

        default:
            if (tree->symbol->charactere)
            {
                printf("[%c] %d\n", tree->symbol->charactere, tree->symbol->freq);
            }
            else
            {
                printf("[@] %d\n", tree->symbol->freq);
            }
            break;
        }
    }

    printHuffTreeChar(tree->leftChild);
    printHuffTreeChar(tree->rightChild);
}

void generateHuffCodesChar(HuffTreeChar *huffTree, SymbolCode huffCodes[256])
{
    if (!huffTree)
    {
        return;
    }

    generateHuffCodesCharRec(huffTree, huffCodes, (SymbolCode){0, 0});
}

void generateHuffCodesCharRec(HuffTreeChar *huffTree, SymbolCode huffCodes[256], SymbolCode symbolCode)
{
    if (!huffTree)
        return;

    if (!huffTree->isJoinNode)
    {
        huffCodes[(unsigned char)huffTree->symbol->charactere] = symbolCode;
    }

    generateHuffCodesCharRec(huffTree->leftChild, huffCodes, (SymbolCode){(symbolCode.code << 1) | 0, symbolCode.length + 1});
    generateHuffCodesCharRec(huffTree->rightChild, huffCodes, (SymbolCode){(symbolCode.code << 1) | 1, symbolCode.length + 1});
}

size_t writeHuffTreeChar(HuffTreeChar *ht, FILE *outputFile)
{
    if(!ht)
        return -1;
    
    unsigned int leftNodeOffset = writeHuffTreeChar(ht->leftChild, outputFile);
    unsigned int rightNodeOffset = writeHuffTreeChar(ht->rightChild, outputFile);

    HuffTreeCharFile fileNode = (HuffTreeCharFile){ht->symbol->charactere, leftNodeOffset, rightNodeOffset};

    size_t currentOffset = ftell(outputFile);
    fwrite(&fileNode, sizeof(HuffTreeCharFile), 1, outputFile);

    return currentOffset;
}
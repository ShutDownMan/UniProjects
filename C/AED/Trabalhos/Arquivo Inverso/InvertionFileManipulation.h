//
// Created by Jedson on 11/2/2018.
//

#ifndef ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H
#define ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

#include <stdio.h>

#include "BTree.h"

#define MAXBIGSTR 128

typedef struct stopWordsList {
    char **words;
    int length;
} StopWordsList;

void getWordInvertedFile(FILE *txtFilesFile, StopWordsList *stopWordsList);

StopWordsList *readStopWordsList(FILE *stopWordsFile);

void addWordsFromFile(FILE *invertedFile, FILE *registryFile, StopWordsList *stopWordsList, FILE *wordsFile,
                      int wordsFileNum);

int getNextWord(char wordBuffer[], FILE *f);

char isValidWord(char word[], StopWordsList *stopWordsList);

char isValidChar(char c);

void printStopWordList(StopWordsList *stopWordsList);

/**
	@brief ordena strings pelo método QuickSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringQuickSort(char *vet[], int left, int right);

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int stringSeparate(char *vet[], int left, int right);

void freeStopWordList(StopWordsList *stopWordsList);

void printWordInvertedFile();

void printWordInvertedFileAux(FILE *invertedFile, FILE *registryFile, BTreeNode *node);

void printEntries(FILE *registryFile, int regPos);

void searchForEntry(FILE *textFilesFiles);

char **separateWords(char *searchLine, int *wordsLength);

void searchWords(FILE *txtFileFiles, FILE *invertedFile, FILE *regFile, char **words, int wordsLength);

char **getTxtPaths(FILE *txtFileFiles, int *length);

Entry **addAllEntries(FILE *regFile, Entry *entry, int *entryPoolLength);

Entry **updateEntryPool(FILE *regFile, Entry *entry, Entry **entryPool, int *entryPoolLength);

#endif //ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

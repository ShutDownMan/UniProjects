//
// Created by Jedson on 11/2/2018.
//

#ifndef ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H
#define ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

#include <stdio.h>

#include "BTree.h"

#define MAXFILEPATHLENGTH 128

typedef struct stopWordsList {
    char **words;
    int length;
} StopWordsList;

void getWordInversionFile(FILE *txtFilesFile, StopWordsList *stopWordsList);

StopWordsList *readStopWordsList(FILE *stopWordsFile);

void addWordsFromFile(FILE *invertedFile, FILE *registryFile, StopWordsList *stopWordsList, FILE *wordsFile,
                      int wordsFileNum);

int getNextWord(char wordBuffer[], FILE *f);

char isValidWord(char word[], StopWordsList *stopWordsList);

char isValidChar(char c);

void printStopWordList(StopWordsList *stopWordsList);

void freeStopWordList(StopWordsList *stopWordsList);

void printWordInvertedFile();

void printWordInvertedFileAux(FILE *invertedFile, FILE *registryFile, BTreeNode *node);

void printEntries(FILE *registryFile, int regPos);

#endif //ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

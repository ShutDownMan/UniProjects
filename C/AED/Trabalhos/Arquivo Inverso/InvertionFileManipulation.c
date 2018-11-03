//
// Created by Jedson on 11/2/2018.
//

#include <stdlib.h>
#include <string.h>

#include "InvertionFileManipulation.h"

void getWordInversionFile(FILE *txtFilesFile, StopWordsList *stopWordsList) {
    int i = 1;
    char line[MAXFILEPATHLENGTH];
    FILE *currentFile = NULL, *invertedFile = NULL, *registryFile = NULL;

    if ((invertedFile = fopen("invertedFile.bin", "wb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "wb+")) == NULL) return;

    createEmptyBTree(invertedFile);
    createEmptyRegistryFile(registryFile);

    while (fscanf(txtFilesFile, "%[^\n] ", line) != EOF) {
        currentFile = fopen(line, "r");

        printf("FILE --> %s\n", line);
        if (!currentFile) continue;

        addWordsFromFile(invertedFile, registryFile, stopWordsList, currentFile, i++);
    }

    fclose(invertedFile);
    fclose(registryFile);
}

StopWordsList *readStopWordsList(FILE *stopWordsFile) {
    StopWordsList *stopWordsList = (StopWordsList *) malloc(sizeof(StopWordsList));
    char line[MAXSTR];
    int i = 0;

    stopWordsList->length = 2;
    stopWordsList->words = malloc(sizeof(char *) * stopWordsList->length);

    while (fscanf(stopWordsFile, "%[^\n] ", line) != EOF) {
        if (i == stopWordsList->length) {
            stopWordsList->length *= 2;
            stopWordsList->words = realloc(stopWordsList->words, sizeof(char *) * stopWordsList->length);
        }
        stopWordsList->words[i++] = strcpy(malloc(sizeof(char) * strlen(line) + 1), line);
    }

    stopWordsList->length = i;
    stopWordsList->words = realloc(stopWordsList->words, sizeof(char *) * stopWordsList->length);

    return stopWordsList;
}

void addWordsFromFile(FILE *invertedFile, FILE *registryFile, StopWordsList *stopWordsList, FILE *wordsFile,
                      int wordsFileNum) {
    char word[MAXSTR];
    Entry *foundEntry = NULL;
    RegistryHeader *registryHeader = readRegistryHeader(registryFile);

    while (getNextWord(word, wordsFile) != EOF) {
        if (isValidWord(word, stopWordsList)) {
            /// insert on invertedFile

            printf("--> %s\n", word);

            if (!(foundEntry = searchEntryBTree(invertedFile, registryFile, word))) {
                Entry *newEntry = createEntry();

                newEntry->file = wordsFileNum;

                insertBTree(invertedFile, word, writeEntryToFile(registryFile, registryHeader, newEntry));
                foundEntry = searchEntryBTree(invertedFile, registryFile, word);
            } else {
                Entry *currentEntry = foundEntry, *nextEntry;
                while (currentEntry->file != wordsFileNum) {
                    nextEntry = readEntryFromFile(registryFile, currentEntry->nextEntryPos);
                    if (!nextEntry) {
                        Entry *newEntry = createEntry();

                        newEntry->file = wordsFileNum;

                        currentEntry->nextEntryPos = writeEntryToFile(registryFile, registryHeader, newEntry);
                        writeEntryToFile(registryFile, registryHeader, currentEntry);

                        nextEntry = newEntry;
                    }
                    free(currentEntry);
                    currentEntry = nextEntry;
                }

                foundEntry = currentEntry;
            }

            if (foundEntry) {
                foundEntry->quant++;
                writeEntryToFile(registryFile, registryHeader, foundEntry);
                printEntry(foundEntry);
                free(foundEntry);
            }
        }
    }

}

char isValidWord(char *word, StopWordsList *stopWordsList) {
    if (!word[0]) return 0;

    for (int i = 0; i < stopWordsList->length; ++i) {
        if (!strcmp(word, stopWordsList->words[i])) {
            return 0;
        }
    }

    return 1;
}

int getNextWord(char *wordBuffer, FILE *f) {
    int i = 0;
    char c = 'a', isValidCharacter;
    wordBuffer[0] = 0;

    do {
        if (fscanf(f, "%c", &c) == EOF && !i) return EOF;

        if ((isValidCharacter = isValidChar(c))) {
            wordBuffer[i++] = c;
        }
    } while (isValidCharacter);

    wordBuffer[i] = 0;

    return 0;
}

char isValidChar(char c) {
    return (c != '\n' && c != ' ' && c != '.' && c != ',' && c != '!' && c != '?' && c != ';' && c != ':');
}

void printStopWordList(StopWordsList *stopWordsList) {
    for (int i = 0; i < stopWordsList->length; ++i) {
        printf("%-16s\n", stopWordsList->words[i]);
    }
}


void freeStopWordList(StopWordsList *stopWordsList) {
    for (int i = 0; i < stopWordsList->length; ++i) {
        free(stopWordsList->words[i]);
    }

    free(stopWordsList);
}

void printWordInvertedFile() {
    BTreeHeader *header;
    BTreeNode *root;
    FILE *invertedFile = NULL, *registryFile = NULL;

    if ((invertedFile = fopen("invertedFile.bin", "rb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "rb+")) == NULL) return;
    header = readBTreeHeader(invertedFile);
    root = readBTreeNode(invertedFile, header->root);

    if (root) printWordInvertedFileAux(invertedFile, registryFile, root);

    free(root);
    free(header);

    fclose(invertedFile);
    fclose(registryFile);
}

void printWordInvertedFileAux(FILE *invertedFile, FILE *registryFile, BTreeNode *node) {
    BTreeNode *currentNode;

    if (!node) return;

    currentNode = readBTreeNode(invertedFile, node->children[0]);
    printWordInvertedFileAux(invertedFile, registryFile, currentNode);
    free(currentNode);
    for (int i = 0; i < node->keyNum; ++i) {
        printf("%-16s ", node->keys[i].id);
        printEntries(registryFile, node->keys[i].regPos);

        currentNode = readBTreeNode(invertedFile, node->children[i + 1]);
        printWordInvertedFileAux(invertedFile, registryFile, currentNode);

        free(currentNode);
    }
}

void printEntries(FILE *registryFile, int regPos) {
    Entry *currentEntry = readEntryFromFile(registryFile, regPos), *nextEntry;

    while (currentEntry) {
        printf("%d,%d ", currentEntry->file, currentEntry->quant);

        nextEntry = readEntryFromFile(registryFile, currentEntry->nextEntryPos);
        free(currentEntry);
        currentEntry = nextEntry;
    }
    printf("\n");
}

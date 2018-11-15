//
// Created by Jedson on 11/2/2018.
//

#include <stdlib.h>
#include <string.h>

#include "InvertionFileManipulation.h"

void getWordInvertedFile(FILE *txtFilesFile, StopWordsList *stopWordsList) {
    int i = 1;
    char line[MAXBIGSTR];
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
    stringQuickSort(stopWordsList->words, 0, stopWordsList->length - 1);
    for (int i = 0; i < stopWordsList->length; ++i) {
        printf("%-16s\n", stopWordsList->words[i]);
    }
}

/**
	@brief ordena strings pelo método QuickSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringQuickSort(char *vet[], int left, int right) {
    int j;
    if (left < right) {
        j = stringSeparate(vet, left, right);
        stringQuickSort(vet, left, j - 1);
        stringQuickSort(vet, j + 1, right);
    }
}

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int stringSeparate(char *vet[], int left, int right) {
    int j, k;
    char *temp, *pivot;

    pivot = vet[right];
    j = left;
    for (k = left; k < right; k++) {
        if (strcmp(vet[k], pivot) <= 0) {
            temp = vet[j];
            vet[j] = vet[k];
            vet[k] = temp;
            j++;
        }
    }

    vet[right] = vet[j];
    vet[j] = pivot;
    return j;
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

void searchForEntry(FILE *textFilesFiles) {
    BTreeHeader *header;
    BTreeNode *root;
    FILE *invertedFile = NULL, *registryFile = NULL;
    char searchLine[MAXBIGSTR], **words;
    int wordsLength;

    if ((invertedFile = fopen("invertedFile.bin", "rb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "rb+")) == NULL) return;
    header = readBTreeHeader(invertedFile);
    root = readBTreeNode(invertedFile, header->root);

    if (root) {
        printf("Type in the words to be searched: ");

        fflush(stdin);
        scanf("%[^\n]%*c", searchLine);

        words = separateWords(searchLine, &wordsLength);

        searchWords(textFilesFiles, invertedFile, registryFile, words, wordsLength);
    }

    free(root);
    free(header);

    fclose(invertedFile);
    fclose(registryFile);
}

char **separateWords(char *searchLine, int *wordsLength) {
    char **words, currentWord[MAXSTR];
    int offset, n, i, searchLineLength = (int) strlen(searchLine);

    *wordsLength = 2;
    words = (char **) malloc(sizeof(char *) * (*wordsLength));

    for (offset = n = i = 0; offset < searchLineLength; offset += n) {
        sscanf((const char *) (searchLine + offset), " %s%n", currentWord, &n);
        if (currentWord[0]) {
            if (i + 1 == *wordsLength) {
                *wordsLength *= 2;
                words = (char **) realloc(words, sizeof(char *) * (*wordsLength));
            }

            words[i++] = strcpy(malloc(strlen(currentWord) + 1), currentWord);

            printf("SEPARATE -> %s\n", words[i - 1]);
        }
    }

    *wordsLength = i;
    words = (char **) realloc(words, sizeof(char *) * (*wordsLength));

    return words;
}

void searchWords(FILE *txtFileFiles, FILE *invertedFile, FILE *regFile, char **words, int wordsLength) {
    Entry *regSearch;
    Entry **entryPool = NULL;
    int i, entryPoolLength = 0;
    int totalOcc = 0, txtPathsLength;

    char **txtPaths = getTxtPaths(txtFileFiles, &txtPathsLength);

    if (wordsLength) {
        printf("WORD -> %s\n", words[0]);
        entryPool = addAllEntries(regFile, searchEntryBTree(invertedFile, regFile, words[0]),
                                  &entryPoolLength);
    }

    for (i = 1; i < wordsLength; ++i) {
        printf("WORD2 -> %s\n", words[i]);

        regSearch = searchEntryBTree(invertedFile, regFile, words[i]);

        entryPool = updateEntryPool(regFile, regSearch, entryPool, &entryPoolLength);
        if (regSearch) {
        }

    }

    if (entryPool) {
        printf("SEARCH RESULTS: \n");
        for (i = 0; i < entryPoolLength; totalOcc += entryPool[i++]->quant);

        printf("qtd: %d\n", totalOcc);

        printf("documentos:\n");
        for (i = 0; i < entryPoolLength; ++i) {
            printf("%s\n", txtPaths[entryPool[i]->file - 1]);

            free(entryPool[i]);
        }
    } else {
        printf("No entries were found!\n");
    }

    for (i = 0; i < txtPathsLength; free(txtPaths[i++]));

    free(txtPaths);
    free(entryPool);
}

char **getTxtPaths(FILE *txtFileFiles, int *length) {
    int i;
    char str[MAXBIGSTR];

    fseek(txtFileFiles, 0, SEEK_SET);

    *length = 2;
    char **vet = (char **) malloc(sizeof(char *) * (*length));

    for (i = 0; !feof(txtFileFiles); ++i) {
        if (i + 1 == *length) {
            *length *= 2;
            vet = (char **) realloc(vet, sizeof(char *) * (*length));
        }
        fscanf(txtFileFiles, " %[^\n]%*c", str);
        vet[i] = strcpy(malloc(sizeof(char) * strlen(str) + 1), str);
    }

    *length = i;
    vet = (char **) realloc(vet, sizeof(char *) * (*length));

    return vet;
}

Entry **addAllEntries(FILE *regFile, Entry *entry, int *entryPoolLength) {
    int i = 0;
    Entry *currentEntry = NULL;

    *entryPoolLength = 2;
    Entry **pool = malloc(sizeof(Entry *) * (*entryPoolLength));

    currentEntry = entry;
    while (currentEntry) {
        printEntry(currentEntry);
        if (i + 1 >= *entryPoolLength) {
            *entryPoolLength *= 2;
            pool = realloc(pool, sizeof(Entry *) * (*entryPoolLength));
        }
        pool[i++] = currentEntry;
        currentEntry = readEntryFromFile(regFile, currentEntry->nextEntryPos);
    }
    *entryPoolLength = i;
    pool = realloc(pool, sizeof(Entry *) * (*entryPoolLength));

    return pool;
}

Entry **updateEntryPool(FILE *regFile, Entry *entry, Entry **entryPool, int *entryPoolLength) {
    Entry *currentEntry = NULL, *nextPoolEntry = NULL;

    int newEntryPoolLength = 2, j = 0, containsEntry = 0;
    Entry **newPool = malloc(sizeof(Entry *) * (newEntryPoolLength));

    currentEntry = entry;
    while (currentEntry) {
        nextPoolEntry = readEntryFromFile(regFile, currentEntry->nextEntryPos);

        containsEntry = 0;
        for (int i = 0; i < *entryPoolLength; ++i) {
            if (entryPool[i]) {
                if (entryPool[i]->file == currentEntry->file) {
                    containsEntry = 1;
                    if (j + 1 >= newEntryPoolLength) {
                        newEntryPoolLength *= 2;
                        newPool = realloc(newPool, sizeof(Entry *) * (newEntryPoolLength));
                    }
                    newPool[j++] = entryPool[i];
                    entryPool[i] = NULL;
                }
            }
        }
        if (containsEntry) {
            if (j + 1 >= newEntryPoolLength) {
                newEntryPoolLength *= 2;
                newPool = realloc(newPool, sizeof(Entry *) * (newEntryPoolLength));
            }

            newPool[j++] = currentEntry;
        } else {
            free(currentEntry);
        }

        currentEntry = nextPoolEntry;
    }

    for (int i = 0; i < *entryPoolLength; ++i) {
        if (entryPool[i]) free(entryPool[i]);
    }

    *entryPoolLength = j;
    newPool = realloc(newPool, sizeof(Entry *) * (*entryPoolLength));

    free(entryPool);

    return newPool;
}

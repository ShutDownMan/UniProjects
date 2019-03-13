//
// Created by Jedson on 11/2/2018.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "InvertionFileManipulation.h"

/*!
 * função para criação do arquivo invertido
 * @param txtFilesFile arquivo com os caminhos
 * @param stopWordsList lista de palavras de parada
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void getWordInvertedFile(FILE *txtFilesFile, StopWordsList *stopWordsList) {
    int i = 1;
    char line[MAXBIGSTR];
    FILE *currentFile = NULL, *invertedFile = NULL, *registryFile = NULL;

    /// tenta abrir os arquivos, se não for possível, aborta a função
    if ((invertedFile = fopen("invertedFile.bin", "wb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "wb+")) == NULL) return;

    /// inicialliza arquivos
    createEmptyBTree(invertedFile);
    createEmptyRegistryFile(registryFile);

    /// enquanto tiverem linhas a serem lidas no arquivo de caminhos
    while (fscanf(txtFilesFile, "%[^\n] ", line) != EOF) {
        /// abre arquivo da linha atual
        currentFile = fopen(line, "r");

        printf("FILE --> %s\n", line);
        /// se arquivo não pode ser aberto, continua para proxima linha
        if (!currentFile) continue;

        /// filtra palavras do arquivo para adicionar ao arquivo inverso
        addWordsFromFile(invertedFile, registryFile, stopWordsList, currentFile, i++);

        fclose(currentFile);
    }

    /// fecha arquivos usados
    fclose(invertedFile);
    fclose(registryFile);
}

/*!
 * função para leitura das palavras de parada
 * @param stopWordsFile arquivo com as palavas de parada
 * @return lista de palavras de parada
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
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

/*!
 * função para adicionar palavras do arquivo passado para o arquivo inverso
 * @param invertedFile arquivo inverso
 * @param registryFile arquivo de registros
 * @param stopWordsList lista de palavras de parada
 * @param wordsFile arquivo com as palavras
 * @param wordsFileNum número do arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void addWordsFromFile(FILE *invertedFile, FILE *registryFile, StopWordsList *stopWordsList, FILE *wordsFile,
                      int wordsFileNum) {
    char word[MAXSTR];
    Entry *foundEntry = NULL;
    RegistryHeader *registryHeader = readRegistryHeader(registryFile);

    /// enquanto existir uma proxima palavra no arquivo
    while (getNextWord(word, wordsFile) != EOF) {
        /// se palavra não é stopword
        if (isValidWord(word, stopWordsList)) {
            /// insert on invertedFile

//            printf("--> %s\n", word);
            /// se palavra não existe na arvore
            if (!(foundEntry = searchEntryBTree(invertedFile, registryFile, word))) {
                /// adiciona palavra na arvore
                Entry *newEntry = createEntry();

                newEntry->file = wordsFileNum;

                insertBTree(invertedFile, word, writeEntryToFile(registryFile, registryHeader, newEntry));
                foundEntry = searchEntryBTree(invertedFile, registryFile, word);
            } else { //< se palavra existe na arvore

                /// procura registro e adiciona nova ocorrência
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

            /// atualiza registro no arquivo
            if (foundEntry) {
                foundEntry->quant++;
                writeEntryToFile(registryFile, registryHeader, foundEntry);
                free(foundEntry);
            }
        }
    }
}

/*!
 * função para testar se palavra é válida
 * @param word palavra a ser testada
 * @param stopWordsList lista de palavras não aceitas
 * @return retorna se palavra é valida
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
char isValidWord(char *word, StopWordsList *stopWordsList) {
    if (!word[0] || !word[1]) return 0;

    /// testa se palavra é stopword
    for (int i = 0; i < stopWordsList->length; ++i) {
        if (!strcmp(word, stopWordsList->words[i])) {
            return 0;
        }
    }

    return 1;
}

/*!
 * função que retorna proxima palavra lida do arquivo passado
 * @param wordBuffer buffer da palavra lida
 * @param f arquivo a ser lido
 * @return se é fim de arquivo ou não
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
int getNextWord(char *wordBuffer, FILE *f) {
    int i = 0;
    char c = 'a', isValidCharacter;
    wordBuffer[0] = 0;

    /// lê char por char até montar proxima palavra no arquivo
    do {
        fscanf(f, "%c", &c);
        if (feof(f) && !i) return EOF;

        if ((isValidCharacter = isValidChar(c))) {
            wordBuffer[i++] = c;
        }

        if (feof(f)) return EOF;
    } while (isValidCharacter);

    wordBuffer[i] = 0;

    return 0;
}

/*!
 * função para testar de caractere é valido
 * @param c caractere a ser testado
 * @return se caractere é valido
 * @precondition nenhuma
 * @postcondition nenhuma
 */
char isValidChar(char c) {
    /// testa se charactere é pontuação
//    return (c != '\n' && c != ' ' && c != '.' && c != ',' && c != '!' && c != '?' && c != ';' && c != ':');
    return (isalnum(c) || c == '-' || c == '\'');
}

/*!
 * printa na saida padrão lista de stopwords
 * @param stopWordsList lista de stopwords
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
void printStopWordList(StopWordsList *stopWordsList) {
    /// ordena lista de stopwords
    stringQuickSort(stopWordsList->words, 0, stopWordsList->length - 1);
    /// printa cada palavra na saida padrão
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


/*!
 * libera memória utilizada pela lista de stopwords
 * @param stopWordsList lista de stopwords
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
void freeStopWordList(StopWordsList *stopWordsList) {
    /// libera memória utilizada pela lista de stopwords
    for (int i = 0; i < stopWordsList->length; ++i) {
        free(stopWordsList->words[i]);
    }

    free(stopWordsList);
}

/*!
 * printa na saida padrão o arquivo invertido
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printWordInvertedFile() {
    BTreeHeader *header;
    BTreeNode *root;
    FILE *invertedFile = NULL, *registryFile = NULL;

    /// tenta abrir arquivos necessários
    if ((invertedFile = fopen("invertedFile.bin", "rb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "rb+")) == NULL) return;

    /// lê dos arquivos o cabeçalho e nó raiz
    header = readBTreeHeader(invertedFile);
    root = readBTreeNode(invertedFile, header->root);

    /// printa na saida padrão o arquivo invertido ordenado
    if (root) printWordInvertedFileAux(invertedFile, registryFile, root);

    /// libera memória utilizada
    free(root);
    free(header);

    fclose(invertedFile);
    fclose(registryFile);
}

/*!
 * função auxiliar recursiva para printar na saida padrão o arquivo invertido
 * @param invertedFile arquivo invertido aberto
 * @param registryFile arquivo de registros aberto
 * @param node nó atual a ser computado
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void printWordInvertedFileAux(FILE *invertedFile, FILE *registryFile, BTreeNode *node) {
    BTreeNode *currentNode;

    /// se raiz é nula, aborta função
    if (!node) return;

    /// iteração in ordem recursiva da arvore no arquivo invertido
    currentNode = readBTreeNode(invertedFile, node->children[0]);
    printWordInvertedFileAux(invertedFile, registryFile, currentNode);
    free(currentNode);

    for (int i = 0; i < node->keyNum; ++i) {
        /// printa chave do nó atual
        printf("%-16s ", node->keys[i].id);
        /// printa registros arquivo/quantidade
        printEntries(registryFile, node->keys[i].regPos);

        /// printa filho direito
        currentNode = readBTreeNode(invertedFile, node->children[i + 1]);
        printWordInvertedFileAux(invertedFile, registryFile, currentNode);

        free(currentNode);
    }
}

/*!
 * função para printar registros de determinada chave no arquivo invertido
 * @param registryFile arquivo de registros
 * @param regPos posição do registro no arquivo
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void printEntries(FILE *registryFile, int regPos) {
    /// itera sobre todos os registros em cadeia no arquivo
    Entry *currentEntry = readEntryFromFile(registryFile, regPos), *nextEntry;

    while (currentEntry) {
        /// printa o atual
        printf("%d,%d ", currentEntry->file, currentEntry->quant);

        /// carrega o proximo registro
        nextEntry = readEntryFromFile(registryFile, currentEntry->nextEntryPos);
        free(currentEntry);
        currentEntry = nextEntry;
    }
    printf("\n");
}

/*!
 * função que printa na saida padrão o resultado da pesquisa feita pelo usuário
 * @param textFilesFiles arquivo com os caminhos
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void searchForEntry(FILE *textFilesFiles) {
    BTreeHeader *header;
    BTreeNode *root;
    FILE *invertedFile = NULL, *registryFile = NULL;
    char searchLine[MAXBIGSTR], **words;
    int wordsLength;

    /// abre arquivos necessários para a pesquisa
    if ((invertedFile = fopen("invertedFile.bin", "rb+")) == NULL) return;
    if ((registryFile = fopen("registryFile.bin", "rb+")) == NULL) return;

    /// lê cabeçalho e nó raiz do arquivo invertido
    header = readBTreeHeader(invertedFile);
    root = readBTreeNode(invertedFile, header->root);

    /// se raiz existe
    if (root) {
        printf("Type in the words to be searched: ");

        /// lê da entrada padrão pesquisa do usuário
        fflush(stdin);
        scanf("%[^\n]%*c", searchLine);

        /// separa termos de pesquisa
        words = separateWords(searchLine, &wordsLength);

        /// pesquisa no arquivo
        searchWords(textFilesFiles, invertedFile, registryFile, words, wordsLength);
    }

    free(root);
    free(header);

    fclose(invertedFile);
    fclose(registryFile);
}

/*!
 * separa palavras a partir de uma string de pesquisa
 * @return vetor de strings das palavras separadas
 * @precondition nenhuma
 * @postcondition retorna vetor e atualiza wordsLength para tamanho deste
 */
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

//            printf("SEPARATE -> %s\n", words[i - 1]);
        }
    }

    *wordsLength = i;
    words = (char **) realloc(words, sizeof(char *) * (*wordsLength));

    return words;
}

/*!
 * função para pesquisa de palavras digitadas pelo usuário
 * @param txtFileFiles arquivo com os caminhos
 * @param invertedFile arquivo invertido
 * @param regFile arquivo de registros
 * @param words palavras da pesquisa
 * @param wordsLength quantidade de palavras na pesquisa
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void searchWords(FILE *txtFileFiles, FILE *invertedFile, FILE *regFile, char **words, int wordsLength) {
    Entry *regSearch;
    Entry **entryPool = NULL;
    int i, entryPoolLength = 0;
    int totalOcc = 0, txtPathsLength;

    /// pega caminhos dos arquivos apontados pelos registros
    char **txtPaths = getTxtPaths(txtFileFiles, &txtPathsLength);

    /// se existe palavras a serem buscadas
    if (wordsLength) {
//        printf("WORD -> %s\n", words[0]);
        /// adiciona todos os resultados da primeira palavra
        entryPool = addAllEntries(regFile, searchEntryBTree(invertedFile, regFile, words[0]),
                                  &entryPoolLength);
    }

    /// faz intercesão dos resultados com as outras palavras
    for (i = 1; i < wordsLength; ++i) {
//        printf("WORD2 -> %s\n", words[i]);

        regSearch = searchEntryBTree(invertedFile, regFile, words[i]);

        entryPool = updateEntryPool(regFile, regSearch, entryPool, &entryPoolLength);
    }

    /// se exitem resultados sobrando
    if (entryPoolLength) {
//        printf("SEARCH RESULTS: \n");

        /// vetor para checkagem de arquivos duplicados
        int duplicate[txtPathsLength];
        memset(duplicate, 0, sizeof(int) * txtPathsLength);

        /// para cada registro em entrypool
        for (i = totalOcc = 0; i < entryPoolLength; ++i) {
            /// checka se já foi tratado
            if (!duplicate[entryPool[i]->file - 1]) {
                /// atualiza número de arquivos diferentes
                totalOcc++;
                duplicate[entryPool[i]->file - 1] = 1;
            }
        }

        /// printa numero de arquivos diferentes e cada arquivo que ocorrem as palavras
        printf("qtd: %d\n", totalOcc);
        printf("documentos:\n");
        for (i = 0; i < entryPoolLength; ++i) {
            if (duplicate[entryPool[i]->file - 1]) {
                printf("%s\n", txtPaths[entryPool[i]->file - 1]);
                duplicate[entryPool[i]->file - 1] = 0;
            }

            /// libera itens em entryPool
            free(entryPool[i]);
        }
    } else {
        printf("No entries were found!\n");
    }

    /// libera todos os caminhos alocados
    for (i = 0; i < txtPathsLength; free(txtPaths[i++]));

    /// libera vetores utilizados
    free(txtPaths);
    free(entryPool);
}

/*!
 * lê do arquivo passado os caminhos
 * @param txtFileFiles arquivo com os caminhos
 * @param length ramanho do vetor de strings a ser retornado
 * @return vetor de strings com os caminhos
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
char **getTxtPaths(FILE *txtFileFiles, int *length) {
    int i;
    char str[MAXBIGSTR];

    /// vai para o inicio do arquivo
    fseek(txtFileFiles, 0, SEEK_SET);

    /// aloca espaço para 2 strings
    *length = 2;
    char **vet = (char **) malloc(sizeof(char *) * (*length));

    /// enquanto houver linhas no arquivo
    for (i = 0; !feof(txtFileFiles); ++i) {

        /// se estourar o número de strings alocadas
        if (i + 1 == *length) {
            /// dobra o tamanho alocado e realoca
            *length *= 2;
            vet = (char **) realloc(vet, sizeof(char *) * (*length));
        }
        /// armazena string lida no vetor
        fscanf(txtFileFiles, " %[^\n]%*c", str);
        vet[i] = strcpy(malloc(sizeof(char) * strlen(str) + 1), str);
    }

    /// realoca tudo para o tamanho final
    *length = i;
    vet = (char **) realloc(vet, sizeof(char *) * (*length));

    /// retorna vetor de strings
    return vet;
}

/*!
 * função para adicionar todos os registros em cadeia na lista de registros
 * @param regFile arquivo de registros
 * @param entry registro cabeça da lista encadeada em arquivo
 * @param entryPoolLength tamanho da lista de registros
 * @return lista de registros alocada
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
Entry **addAllEntries(FILE *regFile, Entry *entry, int *entryPoolLength) {
    int i = 0;
    Entry *currentEntry = NULL;

    /// aloca espaço para 2 registros
    *entryPoolLength = 2;
    Entry **pool = malloc(sizeof(Entry *) * (*entryPoolLength));

    /// enquanto tiver registros na lista
    currentEntry = entry;
    while (currentEntry) {
        /// armazena e realoca quando tamanho estourado
//        printEntry(currentEntry);
        if (i + 1 >= *entryPoolLength) {
            *entryPoolLength *= 2;
            pool = realloc(pool, sizeof(Entry *) * (*entryPoolLength));
        }
        pool[i++] = currentEntry;
        currentEntry = readEntryFromFile(regFile, currentEntry->nextEntryPos);
    }
    /// realoca tudo para tamanho final
    *entryPoolLength = i;
    pool = realloc(pool, sizeof(Entry *) * (*entryPoolLength));

    /// retorna registros
    return pool;
}

/*!
 * função para intercessão dos registros no vetor para com o da lista encadeada
 * @param regFile arquivo de registros
 * @param entry registro cabeça da lista encadeada em arquivo
 * @param entryPool vetor de registros
 * @param entryPoolLength tamanho da lista de registros
 * @return vetor de registros atualizado
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma0
 */
Entry **updateEntryPool(FILE *regFile, Entry *entry, Entry **entryPool, int *entryPoolLength) {
    Entry *currentEntry = NULL, *nextPoolEntry = NULL;

    /// aloca espaço do vetor de registros
    int newEntryPoolLength = 2, j = 0, containsEntry = 0;
    Entry **newPool = malloc(sizeof(Entry *) * (newEntryPoolLength));

    /// para cada registro faz intercessão com o vetor
    currentEntry = entry;
    while (currentEntry) {
        nextPoolEntry = readEntryFromFile(regFile, currentEntry->nextEntryPos);

        containsEntry = 0;
        for (int i = 0; i < *entryPoolLength; ++i) {
            if (entryPool[i]) {
                /// se arquivo também é presente no vetor passado
                if (entryPool[i]->file == currentEntry->file) {
                    /// adiciona ele ao vetor
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

    /// libera registros que sobraram no vetor antigo
    for (int i = 0; i < *entryPoolLength; ++i) {
        if (entryPool[i]) free(entryPool[i]);
    }

    /// realoca tudo para tamanho final
    *entryPoolLength = j;
    newPool = realloc(newPool, sizeof(Entry *) * (*entryPoolLength));

    free(entryPool);

    return newPool;
}

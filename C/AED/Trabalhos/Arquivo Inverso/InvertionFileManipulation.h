//
// Created by Jedson on 11/2/2018.
//

#ifndef ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H
#define ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

#include <stdio.h>

#include "BTree.h"

#define MAXBIGSTR 128

/// estrutura para vetor de palavras
typedef struct stopWordsList {
    char **words;
    int length;
} StopWordsList;

/*!
 * função para criação do arquivo invertido
 * @param txtFilesFile arquivo com os caminhos
 * @param stopWordsList lista de palavras de parada
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void getWordInvertedFile(FILE *txtFilesFile, StopWordsList *stopWordsList);

/*!
 * função para leitura das palavras de parada
 * @param stopWordsFile arquivo com as palavas de parada
 * @return lista de palavras de parada
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
StopWordsList *readStopWordsList(FILE *stopWordsFile);

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
                      int wordsFileNum);

/*!
 * função que retorna proxima palavra lida do arquivo passado
 * @param wordBuffer buffer da palavra lida
 * @param f arquivo a ser lido
 * @return se é fim de arquivo ou não
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
int getNextWord(char wordBuffer[], FILE *f);

/*!
 * função para testar se palavra é válida
 * @param word palavra a ser testada
 * @param stopWordsList lista de palavras não aceitas
 * @return retorna se palavra é valida
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
char isValidWord(char word[], StopWordsList *stopWordsList);

/*!
 * função para testar de caractere é valido
 * @param c caractere a ser testado
 * @return se caractere é valido
 * @precondition nenhuma
 * @postcondition nenhuma
 */
char isValidChar(char c);

/*!
 * printa na saida padrão lista de stopwords
 * @param stopWordsList lista de stopwords
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
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

/*!
 * libera memória utilizada pela lista de stopwords
 * @param stopWordsList lista de stopwords
 * @precondition lista de stopword tem que estar alocada
 * @postcondition nenhuma
 */
void freeStopWordList(StopWordsList *stopWordsList);

/*!
 * printa na saida padrão o arquivo invertido
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printWordInvertedFile();

/*!
 * função auxiliar recursiva para printar na saida padrão o arquivo invertido
 * @param invertedFile arquivo invertido aberto
 * @param registryFile arquivo de registros aberto
 * @param node nó atual a ser computado
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void printWordInvertedFileAux(FILE *invertedFile, FILE *registryFile, BTreeNode *node);

/*!
 * função para printar registros de determinada chave no arquivo invertido
 * @param registryFile arquivo de registros
 * @param regPos posição do registro no arquivo
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void printEntries(FILE *registryFile, int regPos);

/*!
 * função que printa na saida padrão o resultado da pesquisa feita pelo usuário
 * @param textFilesFiles arquivo com os caminhos
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
void searchForEntry(FILE *textFilesFiles);

/*!
 * separa palavras a partir de uma string de pesquisa
 * @return vetor de strings das palavras separadas
 * @precondition nenhuma
 * @postcondition retorna vetor e atualiza wordsLength para tamanho deste
 */
char **separateWords(char *searchLine, int *wordsLength);

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
void searchWords(FILE *txtFileFiles, FILE *invertedFile, FILE *regFile, char **words, int wordsLength);

/*!
 * lê do arquivo passado os caminhos
 * @param txtFileFiles arquivo com os caminhos
 * @param length ramanho do vetor de strings a ser retornado
 * @return vetor de strings com os caminhos
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
char **getTxtPaths(FILE *txtFileFiles, int *length);

/*!
 * função para adicionar todos os registros em cadeia na lista de registros
 * @param regFile arquivo de registros
 * @param entry registro cabeça da lista encadeada em arquivo
 * @param entryPoolLength tamanho da lista de registros
 * @return lista de registros alocada
 * @precondition arquivos tem que estar abertos e com direito de leitura
 * @postcondition nenhuma
 */
Entry **addAllEntries(FILE *regFile, Entry *entry, int *entryPoolLength);

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
Entry **updateEntryPool(FILE *regFile, Entry *entry, Entry **entryPool, int *entryPoolLength);

#endif //ARQUIVO_INVERSO_INVERTIONFILEMANIPULATION_H

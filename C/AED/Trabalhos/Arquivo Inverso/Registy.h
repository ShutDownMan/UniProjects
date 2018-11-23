//
// Created by Jedson on 11/2/2018.
//

#ifndef ARQUIVO_INVERSO_REGISTY_H
#define ARQUIVO_INVERSO_REGISTY_H

#include <stdio.h>

/// estrutura de registro em arquivo
typedef struct entry {
    int file, quant, entryPos, nextEntryPos;
} Entry;

/// estrura de cabeçalho de arquivo de registros
typedef struct registryHeader {
    int topPos;
} RegistryHeader;

//- INITIALIZE -//

/*!
 * função para inicializar arquivo de registros
 * @param f arquivo de registros a ser inicializado
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void createEmptyRegistryFile(FILE *f);

/*!
 * função para criação de registro
 * @return registro alocado e inicializado
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
Entry *createEntry();

//- WRITE -//

/*!
 * função para escrita de cabeçalgo em arquivo de registros
 * @param f arquivo a ser escrito
 * @param header cabeçalho a ser escrito no arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void writeRegistryHeader(FILE *f, RegistryHeader *header);

/*!
 * função para escrita de registro em arquivo
 * @param f arquivo de registros
 * @param header cabeçalho do arquivo
 * @param entry registro a ser escrito
 * @return posição de escrita do registro
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
int writeEntryToFile(FILE *f, RegistryHeader *header, Entry *entry);

//- READ -//

/*!
 * lê cabeçalho do arquivo passado
 * @param f arquivo de registros
 * @return cabeçalho do arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
RegistryHeader *readRegistryHeader(FILE *f);

/*!
 * função para leitura de registro a partir de posição dada
 * @param f arquivo de registros
 * @param pos posição para leitura
 * @return registro lido do arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
Entry *readEntryFromFile(FILE *f, int pos);

//- SHOW -//

void printRegistryHeader(RegistryHeader *header);

void printEntry(Entry *entry);

#endif //ARQUIVO_INVERSO_REGISTY_H

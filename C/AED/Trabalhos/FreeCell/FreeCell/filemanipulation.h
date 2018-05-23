#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

typedef int ItemType;

typedef struct header {
    int freeCellsHeads[4];
    int homeCellsHeads[4], tableauHeads[8];
    int topPos;
} Header;

typedef struct fileNode {
    ItemType val;
    int next;
} FileNode;

///
/// \brief  openBinaryFile, abre arquivo binário
/// \param  fileName, nome do arquivo
/// \param  mode, modo de abertura
/// \return arquivo aberto
/// \pre    nenhuma
/// \post   nenhuma
///
FILE *openBinaryFile(char fileName[], char mode[]);

///
/// \brief  createEmptyList, inicializa uma lista de nós em arquivo
/// \param  f, arquivo a ser modificado
/// \pre    nenhuma
/// \post   lista é criada dentro do arquivo
///
void createEmptyList(FILE *f);

///
/// \brief  createFileNode, inicializa um nó de arquivo
/// \param  val, valor a ser salvo
/// \return nó alocado e inicializado
/// \pre    nenhuma
/// \post   nenhuma
///
FileNode *createFileNode(ItemType val);

///
/// \brief  writeHeaderToFile, escreve cabeçalho em arquivo
/// \param  f, arquivo a ser modificado
/// \param  header, cabeçalho a ser escrito
/// \pre    arquivo não pode ser nulo
/// \post   cabeçalho é escrito no arquivo
///
void writeHeaderToFile(FILE *f, Header *header);

///
/// \brief  writeNodeToFile, escreve nó em arquivo
/// \param  f, arquivo a ser modificado
/// \param  toWrite, nó a ser escrito
/// \param  pos, posição no arquivo a ser escrito
/// \pre    arquivo não pode ser nulo
/// \post   nó é escrito no arquivo
///
void writeNodeToFile(FILE *f, FileNode *toWrite, int pos);

///
/// \brief  readHeader, lê cabeçalho do arquivo
/// \param  f, arquivo a ser lido
/// \return cabeçalho lido
/// \pre    arquivo não pode ser nulo
/// \post   nenhuma
///
Header *readHeader(FILE *f);

///
/// \brief  readFileNode, lê um nó em arquivo
/// \param  f, arquivo a ser lido
/// \param  pos, posição do nó em arquivo
/// \return nó lido
/// \pre    arquivo não pode ser nulo
/// \post   nenhuma
///
FileNode *readFileNode(FILE *f, int pos);

///
/// \brief  insertNodeOnFreeCell, insere nó em free cell no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index da free cell
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserida
///
void insertNodeOnFreeCell(FILE *f, int index, ItemType val);

///
/// \brief  insertNodeOnHomeCell, insere nó em home cell no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index do da lista a ser inserido
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserido
///
void insertNodeOnHomeCell(FILE *f, int index, ItemType val);

///
/// \brief  insertNodeOnTableau, insere nó em tableau no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index da pilha a ser inserido
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserido
///
void insertNodeOnTableau(FILE *f, int index, ItemType val);

///
/// \brief  freeFileNode, libera espaço em memória utilizado para os nós em arquivo
/// \param  node, nó a ser liberado
/// \pre    nenhuma
/// \post   espaço de memória do nó é liberado
///
void freeFileNode(FileNode *node);

#endif // FILEMANIPULATION_H

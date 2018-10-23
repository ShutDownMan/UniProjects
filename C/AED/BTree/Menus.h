//
// Created by Jedson on 10/22/2018.
//

#ifndef BTREE_MENUS_H
#define BTREE_MENUS_H

#include "EntryManipulation.h"
#include "BTree.h"

#define MAXSTR 256

/**
 * inicializa cabeçalho nos arquivos indicados
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition cabeçalhos são escritos nos arquivos
 */
void initializeFiles(FILE *treeFile, FILE *regFile);

/**
 * carrega para os arquivos binários o arquivo de texto indicado pelo console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void loadFileMenu(FILE *treeFile, FILE *regFile);

/**
 * lê do arquivo passado novos registros e adiciona estes aos arquivos binários
 * @param fileName nome do arquivo a ser lido
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition registros são carregados para os arquivos
 */
void readRegFromFile(char *fileName, FILE *treeFile, FILE *regFile);

/**
 * lê do cosole um novo regstro e adiciona este aos arquivos binários
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition se aceito, novo registro é adicionado aos arquivos
 */
void readRegFromConsole(FILE *treeFile, FILE *regFile);

/**
 * pesquisa por registro a partir do código e printa no console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void searchEntry(FILE *treeFile, FILE *regFile);

/**
 * pesquisa por registro a partir de código e o retorna
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @param code código a ser pesquisado
 * @return registro se encontrado
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
Entry *searchEntryBTree(FILE *treeFile, FILE *regFile, int code);

/**
 * printa registros em ordem de código no console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void printRegister(FILE *treeFile, FILE *regFile);

/**
 * passa por todos registros printando em ordem crescente de código
 * @param treeFile arquivo de árvore B
 * @param bTreeHeader cabeçalho de árvore B
 * @param regFile arquivo de registros
 * @param regFileHeader cabeçalho de registros
 * @param node nó atual
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void printRegisterRec(FILE *treeFile, BTreeHeader *bTreeHeader, FILE *regFile, RegFileHeader *regFileHeader,
                      BTreeNode *node);

/**
 * modifica registro indicado
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void modifyEntry(FILE *treeFile, FILE *regFile);

#endif //BTREE_MENUS_H

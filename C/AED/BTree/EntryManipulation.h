//
// Created by Jedson on 10/22/2018.
//

#ifndef BTREE_REGISTRYMANIPULATION_H
#define BTREE_REGISTRYMANIPULATION_H

#include <stdio.h>

#define NAMELENGTH 128
#define CPFLENGTH 24
#define CRMLENGTH 24
#define EXPERTISELENGTH 128
#define RGLENGTH 16
#define TELEPHONELENGTH 24
#define CELLPHONELENGTH 24
#define EMAILLENGTH 24
#define ADDRESSLENGTH 128
#define BIRTHDATELENGTH 12

/// estrutura de registro de médico
typedef struct Entry {
    int id;
    char name[NAMELENGTH];
    char sex;
    char cpf[CPFLENGTH];
    char crm[CRMLENGTH];
    char expertise[EXPERTISELENGTH];
    char rg[RGLENGTH];
    char telephone[TELEPHONELENGTH];
    char cellphone[CELLPHONELENGTH];
    char email[EMAILLENGTH];
    char address[ADDRESSLENGTH];
    char birthdate[BIRTHDATELENGTH];
} Entry;

/// estrutura de cabeçalho do arquivo de registros
typedef struct RegFileHeader {
    int topPos, freeRegRoot;
} RegFileHeader;

/// estrutura de nó livre em arquivo de registro
typedef struct FreeReg {
    int next;
} FreeReg;

//- INITIALIZE -//

/**
 * inicializa arquivo de registros
 * @param regFile arquivo de registro
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition cabeçalho é inicializado no arquivo indicado
 */
void createEmptyRegList(FILE *regFile);

/**
 * cria um novo registro e o retorna
 * @return registro alocado e inicializado
 * @preconddtion nenhuma
 * @postconddtion novo registro é criado e retornado
 */
Entry *createEntry();

/**
 * função para inicialização de rgistro
 * @return um novo registro vazio estaticamente alocado
 * @precondition nenhuma
 * @postcondition nenhuma
 */
Entry emptyEntry();

//- READ -//

/**
 * lê cabeçalho de arquivo de registros do arquivo indicado
 * @param regFile arquivo de registros
 * @return cabecalho criado
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition cabeçalho é criado e retornado
 */
RegFileHeader *readRegHeader(FILE *regFile);

/**
 * lê um registro livre na posição indicada
 * @param regFile arquivo de registros
 * @param header cabelalho do arquivo
 * @param pos posição indicada
 * @return nó lido
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition nenhuma
 */
FreeReg *readFreeReg(FILE *regFile, RegFileHeader *header, int pos);

/**
 *
 * @param regFile arquivo de registros
 * @param header cabeçalho do arquivo de registros
 * @param pos posição do registro a ser lido
 * @return registro lido
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition registro é lido e retornado
 */
Entry *readEntry(FILE *regFile, RegFileHeader *header, int pos);

//- WRITE -//

/**
 * escreve cabeçalho do arquivo de registros e o retorna
 * @param regFile arquivo de registros
 * @param header cabeçalho a ser escrito
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition cabeçalho passado é escrito no arquivo de registros
 */
void writeRegHeaderToFile(FILE *regFile, RegFileHeader *header);

/**
 * escreve 
 * @param regFile
 * @param header
 * @param reg
 * @return
 */
int writeRegToFile(FILE *regFile, RegFileHeader *header, Entry *reg);

//- MODIFY -//

void modifyTelephone(Entry *reg);

void modifyCellphone(Entry *reg);

void modifyEmail(Entry *reg);

void modifyAddress(Entry *reg);

//- VALIDATION -//

int isValidCPF(char *str);

int isValidCellphone(char *str);

int isValidTelephone(char *str);

int isValidDate(char *str);

//- SHOW -//

void printEntry(Entry *entry);

#endif //BTREE_REGISTRYMANIPULATION_H

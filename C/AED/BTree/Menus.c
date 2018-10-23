//
// Created by Jedson on 10/22/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Menus.h"

/**
 * inicializa cabeçalho nos arquivos indicados
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition cabeçalhos são escritos nos arquivos
 */
void initializeFiles(FILE *treeFile, FILE *regFile) {
    printf("Entry length = %d\n", (int) sizeof(Entry));

    createEmptyBTree(treeFile);
    createEmptyRegList(regFile);
}

/**
 * carrega para os arquivos binários o arquivo de texto indicado pelo console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void loadFileMenu(FILE *treeFile, FILE *regFile) {
    char fileName[MAXSTR];

    printf("Arquivo de entrada: ");
    fflush(stdin);
    scanf("%[^\n]%*c", fileName);
    readRegFromFile(fileName, treeFile, regFile);
//    readRegFromFile("cadastros.txt", treeFile, regFile);
}

/**
 * lê do arquivo passado novos registros e adiciona estes aos arquivos binários
 * @param fileName nome do arquivo a ser lido
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition registros são carregados para os arquivos
 */
void readRegFromFile(char *fileName, FILE *treeFile, FILE *regFile) {
    FILE *f = fopen(fileName, "r+");
    if (!f) {
        printf("Arquivo vazio!\n");
        return;
    }

    RegFileHeader *header = readRegHeader(regFile);
    Entry *reg = createEntry();

    while (!feof(f)) {
        *reg = emptyEntry();
        fscanf(f, "%d", &reg->id);
        fseek(f, +1, SEEK_CUR);
        printf("%d\n", reg->id);

        fscanf(f, "%[^:]", reg->name);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->name);

        fscanf(f, "%c", &reg->sex);
        fseek(f, +1, SEEK_CUR);
        printf("%c\n", reg->sex);

        fscanf(f, " %[^:]", reg->cpf);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->cpf);

        fscanf(f, " %[^:]", reg->crm);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->crm);

        fscanf(f, " %[^:]", reg->expertise);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->expertise);

        fscanf(f, " %[^:]", reg->rg);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->rg);

        fscanf(f, " %[^:]", reg->telephone);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->telephone);

        fscanf(f, " %[^:] ", reg->cellphone);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->cellphone);

        fscanf(f, "%[^:]", reg->email);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->email);

        fscanf(f, "%[^:]", reg->address);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->address);

        fscanf(f, "%[^\n]%*c", reg->birthdate);
        printf("%s\n", reg->birthdate);

        if (!reg->rg[0]) {
            printf("RG Invalido!\n");
        } else if (reg->id == -1) {
            printf("Codigo Invalido!\n");
        } else if (!reg->name[0]) {
            printf("Nome Invalido!\n");
        } else if (reg->sex == '\0') {
            printf("Sexo Invalido!\n");
        } else if (!isValidCPF(reg->cpf)) {
            printf("CPF Invalido!\n");
        } else if (!reg->crm[0]) {
            printf("CRM Invalido!\n");
        } else if (reg->telephone[0] && !isValidTelephone(reg->telephone)) {
            printf("Numero de telefone Invalido!\n");
        } else if (reg->cellphone[0] && !isValidCellphone(reg->cellphone)) {
            printf("Numero de celular Invalido!\n");
        } else if (!isValidDate(reg->birthdate)) {
            printf("Data de nascimento Invalida!\n");
        } else {
            int pos = writeRegToFile(regFile, header, reg);
            insertBTree(treeFile, reg->id, pos);
            printBTree(treeFile);
        }
        printf("-----------------\n");
    }

    free(reg);
}

/**
 * lê do cosole um novo regstro e adiciona este aos arquivos binários
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition se aceito, novo registro é adicionado aos arquivos
 */
void readRegFromConsole(FILE *treeFile, FILE *regFile) {
    Entry *newReg = createEntry();

    printf("Codigo: ");
    scanf("%d", &newReg->id);

    printf("Nome: ");
    scanf(" %[^\n]%*c", newReg->name);

    printf("Sex: ");
    scanf("%c", &newReg->sex);

    printf("CPF: ");
    scanf(" %[^\n]%*c", newReg->cpf);

    printf("CRM: ");
    scanf("%[^\n]%*c", newReg->crm);

    printf("Area de especialidade: ");
    scanf("%[^\n]%*c", newReg->expertise);

    printf("RG: ");
    scanf("%[^\n]%*c", newReg->rg);

    printf("Numero de telefone: ");
    scanf("%[^\n]%*c", newReg->telephone);

    printf("Numero de celular: ");
    scanf("%[^\n]%*c", newReg->cellphone);

    printf("Email: ");
    scanf("%[^\n]%*c", newReg->email);

    printf("Endereco: ");
    scanf("%[^\n]%*c", newReg->address);

    printf("Data de nascimento: ");
    scanf("%[^\n]%*c", newReg->birthdate);
    if (!newReg->rg[0]) {
        printf("RG Invalido!\n");
    } else if (newReg->id == -1) {
        printf("Codigo Invalido!\n");
    } else if (!newReg->name[0]) {
        printf("Nome Invalido!\n");
    } else if (newReg->sex == '\0') {
        printf("Sexo Invalido!\n");
    } else if (!isValidCPF(newReg->cpf)) {
        printf("CPF Invalido!\n");
    } else if (!newReg->crm[0]) {
        printf("CRM Invalido!\n");
    } else if (newReg->telephone[0] && !isValidTelephone(newReg->telephone)) {
        printf("Numero de telefone Invalido!\n");
    } else if (newReg->cellphone[0] && !isValidCellphone(newReg->cellphone)) {
        printf("Numero de celular Invalido!\n");
    } else if (!isValidDate(newReg->birthdate)) {
        printf("Data de nascimento Invalida!\n");
    } else {
        RegFileHeader *header = readRegHeader(regFile);
        int pos = writeRegToFile(regFile, header, newReg);

        insertBTree(treeFile, newReg->id, pos);
        printBTree(treeFile);

        free(header);
    }

    free(newReg);
}

/**
 * pesquisa por registro a partir do código e printa no console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void searchEntry(FILE *treeFile, FILE *regFile) {
    int code;
    Entry *found = NULL;

    printf("Digite o codigo a ser pesquisado: ");
    scanf("%d", &code);

    found = searchEntryBTree(treeFile, regFile, code);

    free(found);
}

/**
 * pesquisa por registro a partir de código e o retorna
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @param code código a ser pesquisado
 * @return registro se encontrado
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
Entry *searchEntryBTree(FILE *treeFile, FILE *regFile, int code) {
    BTreeHeader *bTreeHeader = readBTreeHeader(treeFile);
    RegFileHeader *regFileHeader = readRegHeader(regFile);
    BTreeNode *root = readBTreeNode(treeFile, bTreeHeader->root);
    BTreeNode *currentNode = root;
    Entry *foundEntry = NULL;
    int pos, found;

    if (root) {
        while (!(found = searchBTreePos(currentNode, code, &pos)) && !isLeaf(currentNode)) {
            freeBTreeNode(currentNode);
            currentNode = readBTreeNode(treeFile, pos);
        }

        if (found) {
            system("CLS");
            foundEntry = readEntry(regFile, regFileHeader, currentNode->keys[pos].regPos);
        } else {
            printf("Registro nao encontrado!\n");
        }

        freeBTreeNode(currentNode);
    }

    free(bTreeHeader);
    free(regFileHeader);

    return foundEntry;
}

/**
 * printa registros em ordem de código no console
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void printRegister(FILE *treeFile, FILE *regFile) {
    BTreeHeader *bTreeHeader = readBTreeHeader(treeFile);
    RegFileHeader *regFileHeader = readRegHeader(regFile);

    BTreeNode *root = readBTreeNode(treeFile, bTreeHeader->root);

    if (root) {
        printRegisterRec(treeFile, bTreeHeader, regFile, regFileHeader, root);
    }

    free(bTreeHeader);
    free(regFileHeader);
}

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
                      BTreeNode *node) {
    BTreeNode *childNode = NULL;
    Entry *currentEntry = NULL;

    if (!node)
        return;

    for (int i = 0; i < node->keyNum; ++i) {
        printRegisterRec(treeFile, bTreeHeader, regFile, regFileHeader,
                         childNode = readBTreeNode(treeFile, node->children[i]));
        printEntry(currentEntry = readEntry(regFile, regFileHeader, node->keys[i].regPos));
        printf("\n----------------------\n");

        freeBTreeNode(childNode);
        free(currentEntry);
    }
    printRegisterRec(treeFile, bTreeHeader, regFile, regFileHeader,
                     childNode = readBTreeNode(treeFile, node->children[node->keyNum]));
    freeBTreeNode(childNode);
}

/**
 * modifica registro indicado
 * @param treeFile arquivo de árvore B
 * @param regFile arquivo de registros
 * @precondition arquivos tem que estar abertos e ter direito de escrita
 * @postcondition nenhuma
 */
void modifyEntry(FILE *treeFile, FILE *regFile) {
    BTreeHeader *bTreeHeader = readBTreeHeader(treeFile);
    RegFileHeader *regFileHeader = readRegHeader(regFile);
    Entry *foundEntry;
    int code, choice;

    fflush(stdin);
    printf("Digite o codigo a ser alterado: ");
    scanf("%d", &code);

    if ((foundEntry = searchEntryBTree(treeFile, regFile, code))) {
        do {
            system("CLS");

            printf("-------------------------------\n");
            printEntry(foundEntry);
            printf("-------------------------------\n");


            printf("[1] - Alterar numero de telefone\n");
            printf("[2] - Alterar numero de celular\n");
            printf("[3] - Alterar email\n");
            printf("[4] - Alterar endereco\n");

            printf("[0] - Fechar\n");
            printf("    Opcao: ");

            fflush(stdin);
            scanf("%d", &choice);

            switch (choice) {
                case 0:
                    break;
                case 1:
                    modifyTelephone(foundEntry);
                    break;
                case 2:
                    modifyCellphone(foundEntry);
                    break;
                case 3:
                    modifyEmail(foundEntry);
                    break;
                case 4:
                    modifyAddress(foundEntry);
                    break;
                default:
                    printf("Escolha invalida");
                    getch();
                    break;
            }
        } while (choice);
    }

    free(bTreeHeader);
    free(regFileHeader);
}
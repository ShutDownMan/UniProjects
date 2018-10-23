//
// Created by Jedson on 10/22/2018.
//

#include <stdio.h>
#include <stdlib.h>

#include "Menus.h"

void initializeFiles(FILE *treeFile, FILE *regFile) {
    printf("Entry length = %d\n", (int) sizeof(Entry));

    createEmptyBTree(treeFile);
    createEmptyRegList(regFile);
}

void loadFileMenu(FILE *treeFile, FILE *regFile) {
    char fileName[MAXSTR];

    printf("Arquivo de entrada: ");
//    scanf("%[^\n]%*c", fileName);
//    readRegFromFile(fileName, treeFile, regFile);
    readRegFromFile("cadastros.txt", treeFile, regFile);
}

void readRegFromFile(char *fileName, FILE *treeFile, FILE *regFile) {
    FILE *f = fopen(fileName, "r+");
    if (!f) {
        printf("Arquivo vazio!\n");
        return;
    }

    RegFileHeader *header = readRegHeader(regFile);
    Entry *reg = createEntry();

    while (!feof(f)) {
        fscanf(f, "%d", &reg->id);
        fseek(f, +1, SEEK_CUR);
        printf("%d\n", reg->id);

        fscanf(f, "%[^:]", reg->name);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->name);

        fscanf(f, " %c ", &reg->sex);
        fseek(f, +1, SEEK_CUR);
        printf("%c\n", reg->sex);

        fscanf(f, "%[^:]", reg->cpf);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->cpf);

        fscanf(f, "%[^:]", reg->crm);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->crm);

        fscanf(f, "%[^:]", reg->expertise);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->expertise);

        fscanf(f, "%[^:]", reg->rg);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->rg);

        fscanf(f, "%[^:]", reg->telephone);
        fseek(f, +1, SEEK_CUR);
        printf("%s\n", reg->telephone);

        fscanf(f, "%[^:]", reg->cellphone);
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

        if (!reg->rg[0] || reg->id == -1 || !reg->name[0] || reg->sex == '\0' || !reg->cpf[0] ||
            !isValidCPF(reg->cpf) || !reg->crm[0] || !isValidTelephone(reg->telephone) ||
            !isValidCellphone(reg->cellphone) ||
            !reg->birthdate[0]) {
            printf("Cadastro Invalido!\n");
        } else {
            int pos = writeRegToFile(regFile, header, reg);
            insertBTree(treeFile, reg->id, pos);
            printBTree(treeFile);
        }
        printf("-----------------\n");
    }

    free(reg);
}

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

    if (!newReg->rg[0] || newReg->id == -1 || !newReg->name[0] || newReg->sex == '\0' || !newReg->cpf[0] ||
        !isValidCPF(newReg->cpf) || !newReg->crm[0] || !isValidTelephone(newReg->telephone) ||
        !isValidCellphone(newReg->cellphone) ||
        !newReg->birthdate[0]) {

        printf("Cadastro Invalido!\n");

    } else {
        RegFileHeader *header = readRegHeader(regFile);
        int pos = writeRegToFile(regFile, header, newReg);

        insertBTree(treeFile, newReg->id, pos);
        printBTree(treeFile);

        free(header);
    }

    free(newReg);
}

void searchEntry(FILE *treeFile, FILE *regFile) {
    BTreeHeader *bTreeHeader = readBTreeHeader(treeFile);
    RegFileHeader *regFileHeader = readRegHeader(regFile);
    BTreeNode *root = readBTreeNode(treeFile, bTreeHeader->root);
    BTreeNode *currentNode = root;
    int code, pos, found;

    if (root) {
        printf("Digite o codigo a ser pesquisado: ");
        scanf("%d", &code);

        while (!(found = searchBTreePos(currentNode, code, &pos)) && !isLeaf(currentNode)) {
            freeBTreeNode(currentNode);
            currentNode = readBTreeNode(treeFile, pos);
        }

        if (found) {
            system("CLS");
            Entry *entry = readEntry(regFile, regFileHeader, currentNode->keys[pos].regPos);
            printEntry(entry);
            free(entry);
            freeBTreeNode(currentNode);
        } else {
            printf("Registro nao encontrado!\n");
        }


    }

    free(bTreeHeader);
    free(regFileHeader);
}

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

void printRegisterRec(FILE *treeFile, BTreeHeader *bTreeHeader, FILE *regFile, RegFileHeader *regFileHeader,
                      BTreeNode *node) {
    BTreeNode *childNode = NULL;
    Entry *currentEntry = NULL;

    if (!node)
        return;

    for (int i = 0; i < node->keyNum; ++i) {
        printRegisterRec(treeFile, bTreeHeader, regFile, regFileHeader, childNode = readBTreeNode(treeFile, node->children[i]));
        printEntry(currentEntry = readEntry(regFile, regFileHeader, node->keys[i].regPos));
        printf("\n----------------------\n");

        freeBTreeNode(childNode);
        free(currentEntry);
    }
    printRegisterRec(treeFile, bTreeHeader, regFile, regFileHeader, childNode = readBTreeNode(treeFile, node->children[node->keyNum]));
    freeBTreeNode(childNode);
}
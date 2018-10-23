//
// Created by Jedson on 10/22/2018.
//

#include "EntryManipulation.h"

#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "string.h"

#define MAXSTR 256


//- INITIALIZE -//

void createEmptyRegList(FILE *regFile) {
    RegFileHeader header;

    header.topPos = 0;
    header.freeRegRoot = -1;

    writeRegHeaderToFile(regFile, &header);
}

Entry *createEntry() {
    Entry *newReg = (Entry *) malloc(sizeof(Entry));

    *newReg = emptyEntry();

    return newReg;
}

Entry emptyEntry() {
    Entry emptyEntry;

    emptyEntry.id = 0;
    emptyEntry.name[0] = '\0';
    emptyEntry.sex = '\0';
    emptyEntry.cpf[0] = '\0';
    emptyEntry.crm[0] = '\0';
    emptyEntry.expertise[0] = '\0';
    emptyEntry.rg[0] = '\0';
    emptyEntry.telephone[0] = '\0';
    emptyEntry.cellphone[0] = '\0';
    emptyEntry.email[0] = '\0';
    emptyEntry.address[0] = '\0';
    emptyEntry.birthdate[0] = '\0';

    return emptyEntry;
}

//- READ -//

RegFileHeader *readRegHeader(FILE *regFile) {
    RegFileHeader *header = (RegFileHeader *) malloc(sizeof(RegFileHeader));

    fseek(regFile, 0, SEEK_SET);

    fread(header, sizeof(RegFileHeader), 1, regFile);

    return header;
}

FreeReg *readFreeReg(FILE *regFile, RegFileHeader *header, int pos) {
    FreeReg *freeReg = (FreeReg *) malloc(sizeof(FreeReg));

    if (!header)
        return NULL;

    fseek(regFile, sizeof(RegFileHeader) + sizeof(Entry) * pos, SEEK_SET);

    fread(freeReg, sizeof(FreeReg), 1, regFile);

    return freeReg;
}

Entry *readEntry(FILE *regFile, RegFileHeader *header, int pos) {
    Entry *entry = (Entry *) malloc(sizeof(Entry));

    if (!header)
        return NULL;

    fseek(regFile, sizeof(RegFileHeader) + sizeof(Entry) * pos, SEEK_SET);

    fread(entry, sizeof(Entry), 1, regFile);

    return entry;
}

//- WRITE -//

void writeRegHeaderToFile(FILE *regFile, RegFileHeader *header) {
    if (!header)
        return;

    fseek(regFile, 0, SEEK_SET);

    fwrite(header, sizeof(RegFileHeader), 1, regFile);
}

int writeRegToFile(FILE *regFile, RegFileHeader *header, Entry *reg) {
    int pos = 0;

    if (!header)
        return -1;

    if ((pos = header->freeRegRoot) == -1) {
        pos = header->topPos++;
    } else {
        FreeReg *freeReg = readFreeReg(regFile, header, pos);
        header->freeRegRoot = freeReg->next;
        free(freeReg);
    }

    fseek(regFile, sizeof(RegFileHeader) + sizeof(Entry) * pos, SEEK_SET);

    fwrite(reg, sizeof(Entry), 1, regFile);

    writeRegHeaderToFile(regFile, header);

    return pos;
}

//- MODIFY -//

void modifyTelephone(Entry *reg) {
    char str[MAXSTR] = {0};

    fflush(stdin);
    printf("digite um novo numero de telefone: ");
    scanf("%[^\n]%*c", str);

    if (isValidCellphone(str)) {
        strcpy(reg->telephone, str);
        printf("numero de telefone modificado!\n");
    } else {
        printf("numero de telefone invalido!\n");
    }
    getch();
}

void modifyCellphone(Entry *reg) {
    char str[MAXSTR] = {0};

    fflush(stdin);
    printf("digite um novo numero de celular: ");
    scanf("%[^\n]%*c", str);

    if (isValidCellphone(str)) {
        strcpy(reg->cellphone, str);
        printf("numero de celular modificado!\n");
    } else {
        printf("numero de celular invalido!\n");
    }
    getch();
}

void modifyEmail(Entry *reg) {
    char str[MAXSTR] = {0};

    fflush(stdin);
    printf("digite um novo email: ");
    scanf("%[^\n]%*c", str);

    if (str[0]) {
        strcpy(reg->email, str);
        printf("email modificado!\n");
    } else {
        printf("email invalido!\n");
    }
    getch();
}

void modifyAddress(Entry *reg) {
    char str[MAXSTR] = {0};

    fflush(stdin);
    printf("digite um novo endereco: ");
    scanf("%[^\n]%*c", str);

    if (str[0]) {
        strcpy(reg->address, str);
        printf("endereco modificado!\n");
    } else {
        printf("endereco invalido!\n");
    }
    getch();
}

//- VALIDATION -//

int isValidCPF(char *str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}

int isValidCellphone(char *str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}

int isValidTelephone(char *str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}

int isValidDate(char *str) {
    int numCount = 0, barCount = 0;

    for (int i = 0; str[i]; ++i) {
        numCount += isdigit(str[i]);
        barCount += str[i] == '/';
    }

    if((numCount < 6 || numCount > 8) || barCount != 2)
        return 0;

    return 1;
}

//- SHOW -//

void printEntry(Entry *entry) {
    if (!entry)
        return;

    printf("Codigo: ");
    printf("%d\n", entry->id);

    printf("Nome: ");
    printf("%s\n", entry->name);

    printf("Sex: ");
    printf("%c\n", entry->sex);

    printf("CPF: ");
    printf("%s\n", entry->cpf);

    printf("CRM: ");
    printf("%s\n", entry->crm);

    printf("Area de especialidade: ");
    printf("%s\n", entry->expertise);

    printf("RG: ");
    printf("%s\n", entry->rg);

    printf("Numero de telefone: ");
    printf("%s\n", entry->telephone);

    printf("Numero de celular: ");
    printf("%s\n", entry->cellphone);

    printf("Email: ");
    printf("%s\n", entry->email);

    printf("Endereco: ");
    printf("%s\n", entry->address);

    printf("Data de nascimento: ");
    printf("%s\n", entry->birthdate);
}
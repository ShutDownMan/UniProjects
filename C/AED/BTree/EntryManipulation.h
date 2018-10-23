//
// Created by Jedson on 10/22/2018.
//

#ifndef BTREE_REGISTRYMANIPULATION_H
#define BTREE_REGISTRYMANIPULATION_H

#include <stdio.h>

#define NAMELENGTH 128
#define CPFLENGTH 12
#define CRMLENGTH 20
#define EXPERTISELENGTH 128
#define RGLENGTH 12
#define TELEPHONELENGTH 14
#define CELLPHONELENGTH 13
#define EMAILLENGTH 14
#define ADDRESSLENGTH 128
#define BIRTHDATELENGTH 11

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

typedef struct RegFileHeader {
    int topPos, freeRegRoot;
} RegFileHeader;

typedef struct FreeReg {
    int next;
} FreeReg;

//- INITIALIZE -//

void createEmptyRegList(FILE *regFile);

Entry *createEntry();

//- READ -//

RegFileHeader *readRegHeader(FILE *regFile);

FreeReg *readFreeReg(FILE *regFile, RegFileHeader *header, int pos);

Entry *readEntry(FILE *regFile, RegFileHeader *header, int pos);

//- WRITE -//

void writeRegHeaderToFile(FILE *regFile, RegFileHeader *header);

int writeRegToFile(FILE *regFile, RegFileHeader *header, Entry *reg);

//- MODIFY -//

void modifyName(Entry *reg);

void modifySex(Entry *reg);

void modifyCPF(Entry *reg);

void modifyCRM(Entry *reg);

void modifyExpertise(Entry *reg);

void modifyRG(Entry *reg);

void modifyTelephone(Entry *reg);

void modifyCellphone(Entry *reg);

void modifyEmail(Entry *reg);

void modifyAddress(Entry *reg);

void modifyAdress(Entry *reg);

void modifyBirthDate(Entry *reg);

//- VALIDATION -//

int isValidCPF(char *str);

int isValidCellphone(char *str);

int isValidTelephone(char *str);

//- SHOW -//

void printEntry(Entry *entry);

#endif //BTREE_REGISTRYMANIPULATION_H

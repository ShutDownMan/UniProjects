//
// Created by Jedson on 10/22/2018.
//

#include "EntryManipulation.h"
#include <stdlib.h>


//- INITIALIZE -//

void createEmptyRegList(FILE *regFile) {
    RegFileHeader header;

    header.topPos = 0;
    header.freeRegRoot = -1;

    writeRegHeaderToFile(regFile, &header);
}

Entry *createEntry() {
    Entry *newReg = (Entry *) malloc(sizeof(Entry));

    newReg->id = 0;
    newReg->name[0] = '\0';
    newReg->sex = '\0';
    newReg->cpf[0] = '\0';
    newReg->crm[0] = '\0';
    newReg->expertise[0] = '\0';
    newReg->rg[0] = '\0';
    newReg->telephone[0] = '\0';
    newReg->cellphone[0] = '\0';
    newReg->email[0] = '\0';
    newReg->address[0] = '\0';
    newReg->birthdate[0] = '\0';

    return newReg;
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

    fwrite(&reg->id, sizeof(int), 1, regFile);
    fwrite(reg->name, sizeof(char) * NAMELENGTH, 1, regFile);
    fwrite(&reg->sex, sizeof(char), 1, regFile);
    fwrite(reg->cpf, sizeof(char) * CPFLENGTH, 1, regFile);
    fwrite(reg->crm, sizeof(char) * CRMLENGTH, 1, regFile);
    fwrite(reg->expertise, sizeof(char) * EXPERTISELENGTH, 1, regFile);
    fwrite(reg->rg, sizeof(char) * RGLENGTH, 1, regFile);
    fwrite(reg->telephone, sizeof(char) * TELEPHONELENGTH, 1, regFile);
    fwrite(reg->cellphone, sizeof(char) * CELLPHONELENGTH, 1, regFile);
    fwrite(reg->email, sizeof(char) * EMAILLENGTH, 1, regFile);
    fwrite(reg->address, sizeof(char) * ADDRESSLENGTH, 1, regFile);
    fwrite(reg->birthdate, sizeof(char) * BIRTHDATELENGTH, 1, regFile);

    writeRegHeaderToFile(regFile, header);

    return pos;
}

//- MODIFY -//

void modifyName(Entry *reg) {

}

void modifySex(Entry *reg) {

}

void modifyCPF(Entry *reg) {

}

void modifyCRM(Entry *reg) {

}

void modifyExpertise(Entry *reg) {

}

void modifyRG(Entry *reg) {

}

void modifyTelephone(Entry *reg) {

}

void modifyCellphone(Entry *reg) {

}

void modifyEmail(Entry *reg) {

}

void modifyAddress(Entry *reg) {

}

void modifyAdress(Entry *reg) {

}

void modifyBirthDate(Entry *reg) {

}

//- VALIDATION -//

int isValidCPF(char *str) {
    return 1;
}

int isValidCellphone(char *str) {
    return 1;
}

int isValidTelephone(char *str) {
    return 1;
}

//- SHOW -//

void printEntry(Entry *entry) {
    if(!entry)
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
//
// Created by Jedson on 10/22/2018.
//

#ifndef BTREE_MENUS_H
#define BTREE_MENUS_H

#include "EntryManipulation.h"
#include "BTree.h"

#define MAXSTR 256

void initializeFiles(FILE *treeFile, FILE *regFile);

void loadFileMenu(FILE *treeFile, FILE *regFile);

void readRegFromFile(char *fileName, FILE *treeFile, FILE *regFile);

void readRegFromConsole(FILE *treeFile, FILE *regFile);

void searchEntry(FILE *treeFile, FILE *regFile);

void printRegister(FILE *treeFile, FILE *regFile);

void printRegisterRec(FILE *treeFile, BTreeHeader *bTreeHeader, FILE *regFile, RegFileHeader *regFileHeader,
                      BTreeNode *node);

#endif //BTREE_MENUS_H

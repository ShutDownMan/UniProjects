//
// Created by Jedson on 10/19/2018.
//
#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>

#define ORDER 5

typedef struct BTreeNode {
    int keyNum, nodePos;
    int keys[ORDER];
    int data[ORDER];
    int children[ORDER];
} BTreeNode;

//typedef BTreeNode *BTree;

typedef struct freeNode {
    int nextNode;
} freeNode;

typedef struct BTreeHeader {
    int root, nodesQuantity, freeNodesRoot, freeNodesQuantity;
} BTreeHeader;

//- INITIALIZE -//

void createEmptyBTree(FILE *f);

BTreeNode *createNode();

//- WRITE -//

void writeHeaderToFile(FILE *f, BTreeHeader *header);

int writeNodeToFile(FILE *f, BTreeNode *node, BTreeHeader *header);

void insert(FILE *f, int info);

void insertAux(FILE *f, BTreeHeader *header, BTreeNode *root, int info);

void insertOnRight(BTreeNode *root, int pos, int info, int p);

int overflow(BTreeNode *root);

BTreeNode *split(BTreeNode *root, int *m);

int searchBTreePos(BTreeNode *root, int info, int *pos);

int isLeaf(BTreeNode *root);

//- READ -//

BTreeHeader *readHeader(FILE *f);

BTreeNode *readBTreeNode(FILE *f, int pos);

//- REMOVE -//

void freeBTreeNode(BTreeNode *node);

//- SHOW -//

void printHeader(BTreeHeader *header);

void printBTree(FILE *f);

void printBTreeNodeChildren(BTreeNode *node);

void printBTreeNodeKeys(BTreeNode *node);


#endif
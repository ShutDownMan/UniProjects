//
// Created by Jedson on 10/19/2018.
//

#include <stdlib.h>

#include "BTree.h"

//- INITIALIZE -//

///
/// \param f
void createEmptyBTree(FILE *f) {
    BTreeHeader header;

    header.root = -1;
    header.nodeQuantity = 0;
    header.freeNodesRoot = -1;

    writeHeaderToFile(f, &header);
}

/// create a Btree file node
/// \return BTree file node allocated and initialized
BTreeNode *createNode() {
    BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));

    for (int i = 0; i < ORDER - 1; ++i) {
        node->children[i] = -1;
        node->keys[i] = 0;
    }
    node->children[ORDER - 1] = -1;

    node->keyNum = 0;
    node->nodePos = -1;

    return node;
}

//- WRITE -//

///
/// \param f
/// \param header
void writeHeaderToFile(FILE *f, BTreeHeader *header) {
    if (!header)
        return;

    fseek(f, 0, SEEK_SET);

    fwrite(header, sizeof(BTreeHeader), 1, f);
}

int writeNodeToFile(FILE *f, BTreeNode *node, BTreeHeader *header) {
    int pos;

    if (!header)
        return -1;

    if ((pos = node->nodePos) == -1)
        pos = header->nodeQuantity++;

    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    fwrite(node, sizeof(BTreeNode), 1, f);

    node->nodePos = pos;

    return pos;
}

void insert(FILE *f, int info) {
    BTreeHeader *header = readHeader(f);

    BTreeNode *root = readBTreeNode(f, header->root);
    BTreeNode *newNode;

    if (!root) {
        newNode = createNode();

        newNode->keys[0] = info;
        newNode->keyNum = 1;

        writeNodeToFile(f, newNode, header);
        header->root = 0;
    } else {
        insertAux(f, header, root, info);
        if (overflow(root)) {
            int m;
            newNode = split(root, &m);
            BTreeNode *newRoot = createNode();

            newRoot->keys[0] = m;
            newRoot->children[0] = header->root;

            newRoot->keyNum = 1;

            newRoot->children[1] = writeNodeToFile(f, newNode, header);
            header->root = writeNodeToFile(f, newRoot, header);
            writeNodeToFile(f, root, header);

            freeBTreeNode(newNode);
            freeBTreeNode(newRoot);
        }
    }

    freeBTreeNode(root);
    free(header);

    writeHeaderToFile(f, header);
}

void insertAux(FILE *f, BTreeHeader *header, BTreeNode *root, int info) {
    int pos;

    if (!searchBTreePos(root, info, &pos)) {
        if (isLeaf(root)) {
            insertOnRight(root, pos, info, -1);
        } else {
            BTreeNode *node = readBTreeNode(f, root->children[pos]);
            insertAux(f, header, node, info);
            if (overflow(node)) {
                int m;
                BTreeNode *aux = split(node, &m);

                insertOnRight(root, pos, m, writeNodeToFile(f, aux, header));
            }
        }
    }
}

void insertOnRight(BTreeNode *root, int pos, int k, int p) {
    for (int i = root->keyNum; i > pos; --i) {
        root->keys[i] = root->keys[i - 1];
        root->children[i + 1] = root->children[i];
    }

    root->keys[pos] = k;
    root->children[pos + 1] = p;
    root->keyNum++;
}

int overflow(BTreeNode *root) {
    return (!root->keys[0]);
}

BTreeNode *split(BTreeNode *root, int *m) {
    BTreeNode *newNode = (BTreeNode *) malloc(sizeof(BTreeNode));

    int q = root->keyNum / 2;
    newNode->keyNum = root->keyNum - q - 1;
    root->keyNum = q;

    *m = root->keys[q];

    newNode->children[0] = root->children[q + 1];
    for (int i = 0; i < newNode->keyNum; ++i) {
        newNode->keys[i] = root->keys[q + i + 1];
        newNode->children[i + 1] = root->children[q + i + 2];
    }

    return newNode;
}

int searchBTreePos(BTreeNode *root, int info, int *pos) {
    for ((*pos) = 0; (*pos) < root->keyNum; (*pos)++) {
        if (info == root->children[(*pos)])
            return 1;
        else if (info < root->keys[(*pos)])
            break;
    }

    return 0;
}

int isLeaf(BTreeNode *root) {
    return (!root->children[0]);
}

//- READ -//

BTreeHeader *readHeader(FILE *f) {
    BTreeHeader *header = (BTreeHeader *) malloc(sizeof(BTreeHeader));

    fseek(f, 0, SEEK_SET);

    fread(header, sizeof(BTreeHeader), 1, f);

    return header;
}

///
/// \param f
/// \param pos
/// \return
BTreeNode *readBTreeNode(FILE *f, int pos) {
    BTreeNode *node;

    if (pos == -1)
        return NULL;

    node = (BTreeNode *) malloc(sizeof(BTreeNode));

    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    fread(node, sizeof(BTreeNode), 1, f);

    return node;
}

//- REMOVE -//

void freeBTreeNode(BTreeNode *node) {
    free(node);
}

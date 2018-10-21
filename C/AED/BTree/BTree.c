//
// Created by Jedson on 10/19/2018.
//

#include <stdlib.h>

#include "BTree.h"
#include "Queue.h"

//- INITIALIZE -//

///
/// \param f
void createEmptyBTree(FILE *f) {
    BTreeHeader header;

    header.root = -1;
    header.nodesQuantity = 0;
    header.freeNodesRoot = -1;
    header.freeNodesQuantity = 0;

    writeHeaderToFile(f, &header);
}

/// create a Btree file node
/// \return BTree file node allocated and initialized
BTreeNode *createNode() {
    BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));

    for (int i = 0; i < ORDER; ++i) {
        node->keys[i] = 0;
        node->data[i] = -1;
        node->children[i] = -1;
    }

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
        pos = header->nodesQuantity++;

//    printf("pos = %d\n", pos);

    node->nodePos = pos;

    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    fwrite(node, sizeof(BTreeNode), 1, f);

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

            freeBTreeNode(newNode);
            freeBTreeNode(newRoot);
        }
        writeNodeToFile(f, root, header);
    }

//    printHeader(header);
    writeHeaderToFile(f, header);

    freeBTreeNode(root);
    free(header);
}

void insertAux(FILE *f, BTreeHeader *header, BTreeNode *root, int info) {
    int pos = 0;

    if (!searchBTreePos(root, info, &pos)) {
        if (isLeaf(root)) {
            insertOnRight(root, pos, info, -1);
        } else {
            BTreeNode *node = readBTreeNode(f, root->children[pos]);
            insertAux(f, header, node, info);
            if (overflow(node)) {
                int m;
//                printf("info %d\n", node->keyNum);
//                printf("info %d\n", node->nodePos);
                BTreeNode *aux = split(node, &m);
                insertOnRight(root, pos, m, writeNodeToFile(f, aux, header));
                writeNodeToFile(f, node, header);

                freeBTreeNode(aux);
            }
        }
    }
    writeNodeToFile(f, root, header);

//    printf("nodeQuant = %d\n", header->nodesQuantity);
}

void insertOnRight(BTreeNode *root, int pos, int info, int p) {
    for (int i = root->keyNum+1; i > pos; --i) {
        root->keys[i] = root->keys[i - 1];
        root->children[i + 1] = root->children[i];
    }
//    printf("infort = %d\n", pos);

    root->keys[pos] = info;
    root->children[pos + 1] = p;
    root->keyNum++;
}

int overflow(BTreeNode *root) {
    return (root->keyNum == ORDER);
}

BTreeNode *split(BTreeNode *root, int *m) {
    BTreeNode *newNode = createNode();

    int q = ORDER / 2;
    newNode->keyNum = q;
    root->keyNum = q;

    *m = root->keys[q];

    newNode->children[0] = root->children[q + 1];
    for (int i = 0; i < newNode->keyNum; ++i) {
        newNode->keys[i] = root->keys[q + i + 1];
        newNode->children[i + 1] = root->children[q + i + 2];
//        root->keys[q + i + 1] = 0;
//        root->children[q + i + 2] = -1;
    }

    return newNode;
}

int searchBTreePos(BTreeNode *root, int info, int *pos) {
    for ((*pos) = 0; (*pos) < root->keyNum; (*pos)++) {
        if (info == root->keys[(*pos)])
            return 1;
        else if (info < root->keys[(*pos)])
            return 0;
    }
    return 0;
}

int isLeaf(BTreeNode *root) {
    return (root->children[0] == -1);
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
    if (!node)
        free(node);
}

//- SHOW -//

void printHeader(BTreeHeader *header) {
    printf("--------------------\n");
    printf("Root = %d\n", header->root);
    printf("Node Quantity = %d\n", header->nodesQuantity);
    printf("Free Nodes Root = %d\n", header->freeNodesRoot);
    printf("--------------------\n");
}

void printBTree(FILE *f) {
    BTreeHeader *header = readHeader(f);
    BTreeNode *root = readBTreeNode(f, header->root);
    Queue *q = createQueue();
    int nodeCount;

    pushQ(q, root);

    nodeCount = q->count;
    while (nodeCount) {
        while (nodeCount > 0) {
            QNode *qNode = popQ(q);
            BTreeNode *bTreeNode = (BTreeNode *) qNode->info;

            printBTreeNodeKeys(bTreeNode);
            printf(" ");

            for (int i = 0; i <= bTreeNode->keyNum; ++i) {
                if (bTreeNode->children[i] != -1)
                    pushQ(q, readBTreeNode(f, bTreeNode->children[i]));
            }
            nodeCount--;

            free(qNode);
            freeBTreeNode(bTreeNode);
        }
        printf("\n");
        nodeCount = q->count;
    }

    freeBTreeNode(root);
    deleteQueue(q);
}

void printBTreeNodeChildren(BTreeNode *node) {
    printf("[");
    for (int i = 0; i < node->keyNum; ++i) {
        printf("%d,", node->children[i]);
    }
    printf("%d", node->children[node->keyNum]);
    printf("]");
}

void printBTreeNodeKeys(BTreeNode *node) {
    printf("[");
    for (int i = 0; i < node->keyNum - 1; ++i) {
        printf("%d,", node->keys[i]);
    }
    printf("%d", node->keys[node->keyNum - 1]);
    printf("]");
}
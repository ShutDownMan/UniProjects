#ifndef MAIN_H
#define MAIN_H


typedef struct domino {
    int x, y;
} Domino;

typedef Domino *ItemType;

typedef struct node {
    ItemType info;
    struct node *next;
} Node;

typedef struct list {
    int length;
    Node *head;
    Node *tail;
} List;

List *createList();

void readInputSet(List *inList, int setQnt);

Domino *createDomino(int x, int y);

List *insertOnHead(List *wList, ItemType info);

List *insertOnTail(List *inList, ItemType info);

Node *createNode(ItemType info);

void printSet(List *set);

void freeList(List *rList);

void freeListInfo(List *rList);

int isPossibleGame(List *inSet, List *gameSet);

int isPossiblePivot(ItemType pivot, List *unused, List *gameSet);

void cpyList(List *dest, List *from);

void removeNode(List *rList, ItemType info);

ItemType pop(List *rList);

ItemType popNodePos(List *rList, int n);

void swap(int *a, int *b);

#endif // MAIN_H

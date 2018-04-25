#ifndef LIST_H
#define LIST_H

typedef struct List {
    int info;
    struct List* next;
} List;

List *insertOnHead(List *&list, int info);

List *insertOnTail(List *&list, int info);

void printList(List *list);

void freeList(List *list);

List *createList(int val);

#endif LIST_H

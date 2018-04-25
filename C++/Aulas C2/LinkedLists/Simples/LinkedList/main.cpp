#include <iostream>

#include "ListStructured.h"

using namespace std;

int main() {
    List *list = NULL;

    list = insertOnTail(list, 1);
    list = insertOnTail(list, 2);
    list = insertOnTail(list, 4);
    list = insertOnTail(list, 3);
    list = insertOnTail(list, 2);

    printList(list);

    freeList(list);

    return 0;
}

List *insertOnHead(List *&list, int val) {
    List *aux;

    if(!list) {
        list = createList(val);
        return list;
    }

    aux = createList(val);
    aux->next = list;
    list = aux;
    return aux;
}

List *insertOnTail(List *&list, int val) {
    if(!list) {
        list = createList(val);
        return list;
    }

    if(list->next) {
        list->next = insertOnTail(list->next, val);
    } else {
        list->next = createList(val);
    }
    return list;
}

void printList(List *list) {
    if(!list) {
        printf("This list is empty\n");
        return;
    }

    printf("(%d)->", list->info);
    if(list->next) {
        printList(list->next);
    } else {
        printf("(!);\n");
    }
}

void freeList(List *list) {
    if(!list) return;

    if(list->next) {
        freeList(list->next);
    }
    free(list);
}

List *createList(int val) {
    List *newList = (List*)malloc(sizeof(List));

    newList->info = val;
    newList->next = NULL;

    return newList;
}

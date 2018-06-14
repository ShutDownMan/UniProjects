#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void) {
    List *inputSet = createList();
    List *gameSet = createList();
    int i, setQnt;

    scanf("%d", &setQnt);
    for(i = 0; setQnt; ++i) {
        readInputSet(inputSet, setQnt);

        printSet(inputSet);

        printf("Teste %d\n", i+1);
        if(isPossibleGame(inputSet, gameSet)) {
            printf("sim\n");
            printSet(gameSet);
            freeList(gameSet);
        } else {
            printf("nao\n");
        }

        freeListInfo(inputSet);

        printf("---------------\n");
        scanf("%d", &setQnt);
    }

    return 0;
}

List *createList() {

    List *newList = (List *)malloc(sizeof(List));

    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;

    return newList;
}

void readInputSet(List *inList, int setQnt) {
    int i, x, y;

    for(i = 0; i < setQnt; ++i) {
        scanf("%d %d", &x, &y);
        insertOnTail(inList, createDomino(x, y));
    }
}

Domino *createDomino(int x, int y) {
    Domino *newDomino = (Domino *)malloc(sizeof(Domino));

    newDomino->x = x;
    newDomino->y = y;

    return newDomino;
}

List *insertOnHead(List *aList, ItemType info) {
    Node *newNode = createNode(info);

    newNode->next = aList->head;
    aList->head = newNode;

    if(aList->tail == NULL) aList->tail = newNode;

    aList->length++;
    return aList;
}

List *insertOnTail(List *aList, ItemType info) {
    Node *newNode = createNode(info);

    if(!aList->head) {
        aList->head = newNode;
        aList->tail = newNode;
        aList->length++;
        return aList;
    }

    aList->tail->next = newNode;
    aList->tail = newNode;
    aList->length++;

    return aList;
}

Node *createNode(ItemType info) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->info = info;
    newNode->next = NULL;

    return newNode;
}

void printSet(List *set) {
    Node *tracer;

    for(tracer = set->head; tracer; tracer = tracer->next) {
        printf("%d %d", tracer->info->x, tracer->info->y);
        if(tracer->next)
            printf("|");
    }
    printf("\n");
}

void freeList(List *aList) {
    Node *tracer, *aux;

    for(tracer = aList->head; tracer; ) {
        aux = tracer->next;
        free(tracer);
        tracer = aux;
    }

    aList->head = NULL;
    aList->tail = NULL;
    aList->length = 0;
}

void freeListInfo(List *aList) {
    Node *tracer, *aux;

    for(tracer = aList->head; tracer; ) {
        aux = tracer->next;
        free(tracer->info);
        free(tracer);
        tracer = aux;
    }

    aList->head = NULL;
    aList->tail = NULL;
    aList->length = 0;
}

int isPossibleGame(List *aList, List *gameSet) {
    int i, isPossible;
    List *available = createList();
    Domino *pivot;

    cpyList(available, aList);

    isPossible = 0;
    for(i = 0; i < aList->length && !isPossible; ++i) {
        pivot = pop(available);

        if(isPossiblePivot(pivot, available, gameSet)) {
            isPossible = 1;
            insertOnHead(gameSet, pivot);
        } else {
            swap(&pivot->x, &pivot->y);

            if(isPossiblePivot(pivot, available, gameSet)) {
                isPossible = 1;
                insertOnHead(gameSet, pivot);
            } else {
                insertOnTail(available, pivot);
            }
        }

        // test other side
    }

    freeList(available);

    return isPossible;
}

int isPossiblePivot(ItemType pivot, List *aList, List *gameSet) {
    int matching, isPossible;
    Node *tracer;
    Domino *newPivot;
    List *available = createList();

    isPossible = 0;

    cpyList(available, aList);

    if(!available->length) isPossible = 1;

    for(tracer = aList->head; tracer && !isPossible;) {
        matching = 0;
        if(pivot->y == tracer->info->x) {
            matching = 1;
        } else if(pivot->y == tracer->info->y) {
            matching = 1;
            swap(&tracer->info->x, &tracer->info->y);
        }

        if(matching) {
            newPivot = tracer->info;

            removeNode(available, newPivot);

            if(isPossiblePivot(newPivot, available, gameSet)) {
                insertOnHead(gameSet, newPivot);
                isPossible = 1;
            } else {
                insertOnHead(available, newPivot);
                tracer = tracer->next;
            }
        } else {
            tracer = tracer->next;
        }
    }

    freeList(available);

    return isPossible;
}

void cpyList(List *dest, List *from) {
    Node *tracer;

    for(tracer = from->head; tracer; tracer = tracer->next) {
        insertOnTail(dest, tracer->info);
    }

    dest->length = from->length;
}

void removeNode(List *aList, ItemType info) {
    Node *tracer, *aux;

    if(!aList->head) return;

    if(aList->head->info == info) {
        aux = aList->head;
        aList->head = aList->head->next;
        if(!aList->head) aList->tail = NULL;
        free(aux);
        aList->length--;
        return;
    }

    for(tracer = aList->head; tracer->next; ) {
        if(tracer->next->info == info) {
            aux = tracer->next;
            tracer->next = aux->next;
            if(aux == aList->tail) {
                aList->tail = tracer;
            }
            free(aux);
            aList->length--;
        } else {
            tracer = tracer->next;
        }
    }
}

ItemType pop(List *aList) {
    Node *aux;
    ItemType res;

    if(!aList->length) return NULL;

    aux = aList->head;
    aList->head = aList->head->next;

    if(!aList->head) aList->tail = NULL;

    res = aux->info;
    free(aux);
    aList->length--;

    return res;
}

ItemType popNodePos(List *aList, int n) {
    Node *tracer, *aux;
    ItemType res;

    if(!aList->length) return NULL;

    if(!n) return pop(aList);

    for(tracer = aList->head; tracer->next; tracer = tracer->next) {
        if(!(n--)) {
            aux = tracer->next;
            tracer->next = tracer->next->next;
            if(aux == aList->tail) {
                aList->tail = tracer;
            }
            res = aux->info;
            free(aux);
            aList->length--;
            return res;
        }
    }

    return NULL;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

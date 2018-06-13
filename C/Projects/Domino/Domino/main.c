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

List *insertOnHead(List *inList, ItemType info) {
    Node *newNode = createNode(info);

    newNode->next = inList->head;
    inList->head = newNode;

    if(inList->tail == NULL) inList->tail = newNode;

    inList->length++;
    return inList;
}

List *insertOnTail(List *inList, ItemType info) {
    Node *newNode = createNode(info);

    if(!inList->head) {
        inList->head = newNode;
        inList->tail = newNode;
        inList->length++;
        return inList;
    }

    inList->tail->next = newNode;
    inList->tail = newNode;
    inList->length++;

    return inList;
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

void freeList(List *rList) {
    Node *tracer, *aux;

    for(tracer = rList->head; tracer; ) {
        aux = tracer->next;
        free(tracer);
        tracer = aux;
    }

    rList->head = NULL;
    rList->tail = NULL;
    rList->length = 0;
}

void freeListInfo(List *rList) {
    Node *tracer, *aux;

    for(tracer = rList->head; tracer; ) {
        aux = tracer->next;
        free(tracer->info);
        free(tracer);
        tracer = aux;
    }

    rList->head = NULL;
    rList->tail = NULL;
    rList->length = 0;
}

int isPossibleGame(List *inSet, List *gameSet) {
    int i, isPossible;
    List *available = createList();
    Domino *pivot;

    cpyList(available, inSet);

    isPossible = 0;
    for(i = 0; i < inSet->length && !isPossible; ++i) {
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

int isPossiblePivot(ItemType pivot, List *inSet, List *gameSet) {
    int matching, isPossible;
    Node *tracer;
    Domino *newPivot;
    List *available = createList();

    isPossible = 0;

    cpyList(available, inSet);

    if(!available->length) isPossible = 1;

    for(tracer = inSet->head; tracer && !isPossible;) {
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

void removeNode(List *rList, ItemType info) {
    Node *tracer, *aux;

    if(!rList->head) return;

    if(rList->head->info == info) {
        aux = rList->head;
        rList->head = rList->head->next;
        if(!rList->head) rList->tail = NULL;
        free(aux);
        rList->length--;
        return;
    }

    for(tracer = rList->head; tracer->next; ) {
        if(tracer->next->info == info) {
            aux = tracer->next;
            tracer->next = aux->next;
            if(aux == rList->tail) {
                rList->tail = tracer;
            }
            free(aux);
            rList->length--;
        } else {
            tracer = tracer->next;
        }
    }
}

ItemType pop(List *rList) {
    Node *aux;
    ItemType res;

    if(!rList->length) return NULL;

    aux = rList->head;
    rList->head = rList->head->next;

    if(!rList->head) rList->tail = NULL;

    res = aux->info;
    free(aux);
    rList->length--;

    return res;
}

ItemType popNodePos(List *rList, int n) {
    Node *tracer, *aux;
    ItemType res;

    if(!rList->length) return NULL;

    if(!n) return pop(rList);

    for(tracer = rList->head; tracer->next; tracer = tracer->next) {
        if(!(n--)) {
            aux = tracer->next;
            tracer->next = tracer->next->next;
            if(aux == rList->tail) {
                rList->tail = tracer;
            }
            res = aux->info;
            free(aux);
            rList->length--;
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

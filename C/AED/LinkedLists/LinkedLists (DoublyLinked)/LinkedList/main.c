#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
    List *list1;

    list1 = readList();
    printList(list1);

    removeNodes(list1, 1);
    printListRev(list1);

    return 0;
}

// EXERCISE FUNCTIONS //

int isEmpty(List *list) {
    return !(list->head);
}

List *insertOnHead(List *list, ItemType val) {
    Node *next;

    if(isEmpty(list)) {
        list->head = createNode(val);
        list->tail = list->head;
        return list;
    }

    next = list->head;
    list->head = createNode(val);
    list->head->next = next;

    return list;
}

List *insertOnTail(List *list, ItemType val) {
    Node *newNode, *tail;

    if(isEmpty(list)) {
        list->head = createNode(val);
        list->tail = list->head;
        return list;
    }

    newNode = createNode(val);
    tail = list->tail;

    insertNodeOnTail(list->head, newNode);

    list->tail = newNode;
    list->tail->prev = tail;

    return list;
}

Node *insertNodeOnTail(Node *node, Node *newNode) {
    if(!node) return newNode;

    node->next = insertNodeOnTail(node->next, newNode);

    return node;
}

void removeNodes(List *list, ItemType val) {
    Node **tracer, *next;
    if(isEmpty(list)) return;

    for(tracer = &list->head; (*tracer) && (*tracer)->next; ) {
        if((*tracer)->next->info == val) {
            next = (*tracer)->next->next;
            free((*tracer)->next);
            (*tracer)->next = next;

            if(next) {
                next->prev = *tracer;
            }
        } else {
            tracer = &(*tracer)->next;
        }
    }

    if(list->head && list->head->info == val) {
        next = list->head->next;
        free(list->head);
        list->head = next;

        if(next) {
            next->prev = NULL;
            tracer = &next;
        }
    }

    list->tail = *tracer;
}

// HELPER FUNCTIONS //

List *readList() {
    List *list = createList();
    ItemType val;

    printf("Type in a value to start the list: ");
    scanf(ItemFormat, &val);
    list->head = createNode(val);
    list->tail = list->head;

    printf("Type in a new value to be added: ");
    scanf("%d", &val);
    while(val >= 0) {
        insertOnTail(list, val);

        printf("Type in a new value to be added: ");
        scanf("%d", &val);
    }

    return list;
}

void printList(List *list) {
    Node **tracer;
    char format[MAX];

    sprintf(format, "(%s)-> ", ItemFormat);

    printf("Lista Encadeada {(%p)-> ... (%p)}: ", list->head, list->tail);
    for(tracer = &list->head; *tracer; tracer = &(*tracer)->next) {
        printf(format, (*tracer)->info);
    }

    printf("(!);\n");
}

void printListRev(List *list) {
    Node **tracer;
    char format[MAX];

    sprintf(format, "(%s)-> ", ItemFormat);

    printf("Lista Encadeada {(%p)-> ... (%p)}: ", list->head, list->tail);
    for(tracer = &list->tail; *tracer; tracer = &(*tracer)->prev) {
        printf(format, (*tracer)->info);
    }

    printf("(!);\n");
}

List *createList() {
    List *newList = malloc(sizeof(List));

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

Node *createNode(ItemType val) {
    Node *newNode = malloc(sizeof(Node));

    newNode->info = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

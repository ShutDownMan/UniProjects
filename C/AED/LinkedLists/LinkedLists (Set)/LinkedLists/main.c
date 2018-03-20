#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char *argv[]) {
    List *start1, *start2;

    createLinkedList(&start1);
    printList(start1);

//    createLinkedList(&start2);
//    printList(start2);

    printList(invert(start1));
//    printf("start2 contains start1: %d\n", isContained(start1, start2));
    printList(start1);

    return 0;
}

int isEmpty(List *list) {
    return !list;
}

// LINKED LIST FUNCTIONS //

List* insert(List **list, int val) {
    if(isEmpty(*list) || (*list)->val == val) return *list;

    if((*list)->next) {
        insert(&(*list)->next, val);
        return *list;
    }

    (*list)->next = createKnot(val);

    return *list;
}

List* remove(List **list, int val) {
    struct knot* next;

    if(isEmpty(*list)) return *list;

    if((*list)->val == val) {
        next = (*list)->next;
        free(*list);
        *list = next;
        return next;
    }

    remove(&(*list)->next, val);
    return *list;
}

List* invert(List *list) {
    struct knot *acc;

    if(isEmpty(list->next)) return cpyKnot(list);

    acc = invert(list->next);
    insert(&acc, list->val);

    return acc;
}

List* concat(List *list1, List *list2) {
    struct knot* knot;

    if(isEmpty(list1)) return cpyList(list2);

    knot = cpyKnot(list1);
    knot->next = concat(list1->next, list2);

    return knot;
}

List* merge(List *list1, List *list2) {
    struct knot* knot;

    if(isEmpty(list1)) return cpyKnot(list2);

    knot = cpyKnot(list1);
    knot->next = merge(list2, list1->next);

    return knot;
}

List* append(List *list1, List *list2) {
    if(isEmpty(list1)) return list2;

    list1->next = concat(list1->next, list2);

    return list1;
}

int contains(List *list, int val) {
    if(isEmpty(list)) return 0;

    if(list->val == val) {
        return 1;
    }

    return contains(list->next, val);
}

List *unionSet(List *list1, List *list2) {
    List* newList = concat(list1, list2);

    return removeDupes(newList);
}

List *IntersectionSet(List *list1, List *list2) {
    struct knot *aux1, *aux2, *aux3, *aux4, *_res;

    // (a u b) - (((a u b) - a) u ((a u b) - b))
    aux1 = unionSet(list1, list2);
    aux2 = differenceSet(aux1, list2);
    aux3 = differenceSet(aux1, list1);
    aux4 = unionSet(aux2, aux3);
    _res = differenceSet(aux1, aux4);

    removeList(aux1);
    removeList(aux2);
    removeList(aux3);
    removeList(aux4);

    return _res;
}

List *differenceSet(List *list1, List *list2) {
    struct knot **tracer, *acc;

    if(isEmpty(list1)) return NULL;

    acc = cpyList(list1);
    for(tracer = &list2; *tracer; tracer = &(*tracer)->next) {
        if(contains(acc, (*tracer)->val)) {
            remove(&acc, (*tracer)->val);
        }
    }

    return acc;
}

int isContained(List *list1, List *list2) {
    struct knot **tracer;
    if(isEmpty(list1)) return 1;

    for(tracer = &list1; *tracer; tracer = &(*tracer)->next) {
        if(!contains(list2, (*tracer)->val)) {
            return 0;
        }
    }

    return 1;
}

// HELPER FUNCTIONS //

void createLinkedList(List **head) {
    int val;

    printf("Type in a value to start the list: ");
    scanf("%d", &val);
    *head = createKnot(val);

    printf("Type in a new value to be added: ");
    scanf("%d", &val);
    while(val >= 0) {
        insert(head, val);

        printf("Type in a new value to be added: ");
        scanf("%d", &val);
    }
}

List* createKnot(int val) {
    struct knot* newKnot = malloc(sizeof(struct knot));

    newKnot->val = val;
    newKnot->next = NULL;

    return newKnot;
}

void printList(List *head) {
    struct knot* curr = NULL;

    printf("Linked List: \n");

    curr = head;
    while(curr) {
        printf("(%d)-> ", curr->val);
        curr = curr->next;
    }
    printf("(!).\n");
}

List* cpyKnot(List *list) {
    struct knot *newKnot;

    if(isEmpty(list)) return NULL;

    newKnot = createKnot(0);
    memcpy(newKnot, list, sizeof(struct knot));

    printf("[%d]\n", newKnot->val);

    return newKnot;
}

List* cpyList(List* list) {
    struct knot *head;

    if(isEmpty(list)) return NULL;

    head = cpyKnot(list);

    head->next = cpyList(head->next);

    return head;
}

void removeList(List *list) {
    if(isEmpty(list)) return;

    removeList(list->next);
    free(list);

    return;
}

List* removeDupes(List* list) {
    struct knot **tracer, *acc;

    if(isEmpty(list)) return 0;

    acc = createKnot(list->val);
    for(tracer = &list->next; *tracer; tracer = &(*tracer)->next) {
        if(!contains(acc, (*tracer)->val)) {
            if(isEmpty(acc)) {
                acc = createKnot((*tracer)->val);
            } else {
                insert(&acc, (*tracer)->val);
            }
        }
    }

    removeList(list->next);
    list->next = acc->next;

    return list;
}

void addTen(List *list) {
    if(isEmpty(list)) return;

    addTen(list->next);
    list->val += 10;

    return;
}

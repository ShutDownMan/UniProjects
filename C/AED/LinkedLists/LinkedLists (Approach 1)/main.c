#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char *argv[]) {
    List *start1, *start2;

    createLinkedList(&start1);
    printList(start1);

    createLinkedList(&start2);
    printList(start2);

    printList(remove(invert(start1), 1));
    printList(start1);

    return 0;
}

// LINKED LIST FUNCTIONS //

int isEmpty(List *list) {
    return !list;
}

List* insert(List *list, int val) {
    struct knot **tracer;

    if(isEmpty(list)) {
        return NULL;
    }

    for(tracer = &list; *tracer; tracer = &(*tracer)->next)
        ;

    *tracer = createKnot(val);

    return list;
}

List* remove(List *list, int val) {
    struct knot* old;
    struct knot** tracer;
    char present = 0;

    if(isEmpty(list)) return NULL;

    for(tracer = &list; *tracer && !(present = ((*tracer)->val == val)); tracer = &(*tracer)->next)
        ;

    if(present) {
        old = *tracer;
        *tracer = (*tracer)->next;
        free(old);
    }

    return list;
}

List* invert(List *list) {
    struct knot *l_old, *l_current, *l_next;

    if(isEmpty(list) || !list->next) return list;

    l_next = l_current = l_old = cpyList(list);
    l_next = l_next->next->next;
    l_current = l_current->next;
    l_old->next = NULL;
    l_current->next = l_old;

    for(; l_next; l_current->next = l_old) {
        l_old = l_current;
        l_current = l_next;
        l_next = l_next->next;
    }

    return l_current;
}

List* concat(List *list1, List *list2) {
    struct knot *tracer, *head;

    if(isEmpty(list1) || isEmpty(list2)) return NULL;

    head = cpyKnot(list1);
    for(tracer = head; tracer->next; tracer = tracer->next) {
        tracer->next = cpyKnot(tracer->next);
    }

    tracer->next = cpyList(list2);

    return head;
}

List* merge(List *list1, List *list2) {
    struct knot *head, *next, *rest, *current;

    if(isEmpty(list1) || isEmpty(list2)) return NULL;

    head = cpyList(list1);

    current = head;
    next = cpyList(list2);
    for(; rest;) {
        rest = current->next;
        current->next = next;

        current = next;
        next = rest;
    }

    return cpyKnot(list1);
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
        insert(*head, val);

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

//    printf("[%d]\n", newKnot->val);

    return newKnot;
}

List* cpyList(List* list) {
    struct knot *tracer, *head;

    if(isEmpty(list)) return NULL;

    head = cpyKnot(list);
    for(tracer = head; tracer->next; tracer = tracer->next) {
        tracer->next = cpyKnot(tracer->next);
    }

    return head;
}

/*
    querido diário, já é o quarto dia e eu ainda nn terminei essa lista.
    Um dia talvez...
*/

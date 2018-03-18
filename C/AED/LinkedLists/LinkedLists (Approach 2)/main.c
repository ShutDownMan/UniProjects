#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[]) {
    List *start1, *start2;

    createLinkedList(&start1);
    printList(start1);

    createLinkedList(&start2);
    printList(start2);

    start1 = merge(start1, start2);

    printList(start1);

    return 0;
}

int isEmpty(List *list) {
    return !list;
}

// LINKED LIST FUNCTIONS //

List* insert(List *list, int val) {
    if(isEmpty(list)) return NULL;

    if(list->next) {
        insert(list->next, val);
        return list;
    }

    list->next = createKnot(val);

    return list;
}

List* remove(List *list, int val) {
    struct knot* next;
    char present = 0;

    if(isEmpty(list)) return NULL;

    if(list->next && !(present = (list->val == val))) {
        list->next = remove(list->next, val);
        return list;
    }

    if(present) {
        next = list->next;
        free(list);
        return next;
    }

    return list;
}

List* invert(List *list) {
    struct knot* rest;

    if(isEmpty(list->next)) return list;

    rest = invert(list->next);

    list->next->next = list;

    list->next = NULL;

    return rest;
}

List* concat(List *list1, List *list2) {
    if(isEmpty(list1)) return list2;

    list1->next = concat(list1->next, list2);

    return list1;
}

List* merge(List *list1, List *list2) {
    if(isEmpty(list1)) return list2;

    list1->next = merge(list2, list1->next);

    return list1;
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

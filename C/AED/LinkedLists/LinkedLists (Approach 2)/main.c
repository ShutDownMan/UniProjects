#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[]) {
    List* start;

    createLinkedList(&start);
    printList(start);
    remove(start, 3);
    printList(start);

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

// HELPER FUNCTIONS //

void createLinkedList(List **head) {
    int val;
    struct knot* newKnot = *head;

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

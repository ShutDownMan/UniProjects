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

    start1 = remove_mult(start1, 1);
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

List* insert_apos(List *list, int val, int x) {
    List *aux;

    if(isEmpty(list)) {
        return createKnot(x);
    }

    if(list->val != x && list->next) {
        insert_apos(list->next, val, x);
        return list;
    }

    aux = list->next;
    list->next = createKnot(val);
    list->next->next = aux;

    return list;
}

/*List* remove(List *list, int val) {
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
}*/

List* insere_ordered(List *li, int val){
    List* newNode = NULL, *aux = NULL;

    if(!li || li->val > val) {
        newNode = (List *) malloc(sizeof(List));
        newNode->val = val;
        newNode->next = li;
        return newNode;
    }

    if(!li->next || li->next->val > val) {
        newNode = (List *) malloc(sizeof(List));
        newNode->val = val;
        aux = li->next;
        li->next = newNode;
        newNode->next = aux;
    } else {
        li->next = insere_ordered(li->next, val);
    }

    return li;
}

List* remove_mult(List *list, int val) {
    struct knot* aux;

    if(isEmpty(list)) return NULL;

    if(list->val == val) {
        aux = list->next;
        free(list);
        return remove_mult(aux, val);
    }

    list->next = remove_mult(list->next, val);

    return list;
}

List* invert(List *list) {
    struct knot *acc;

    if(isEmpty(list->next)) return cpyKnot(list);

    acc = invert(list->next);
    insert(acc, list->val);

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

// HELPER FUNCTIONS //

void createLinkedList(List **head) {
    int val;

    printf("Type in a value to start the list: ");
    scanf("%d", &val);
    *head = createKnot(val);

    printf("Type in a new value to be added: ");
    scanf("%d", &val);
    while(val >= 0) {
        *head = insere_ordered(*head, val);

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

List *remove_repetido(List *list) {
    List *aux;
    if(!list) return NULL;

    if(list->next) {
        if(list->val == list->next->val) {
            aux = list->next->next;
            free(list->next);
            list->next = aux;
            remove_repetido(list);
        } else {
            remove_repetido(list->next);
        }
    }
    return list;
}


// HELP ME //

/*Lista* remover(Lista* l, int info){
    Lista* aux = NULL;

    if(!l) return NULL;

    if(l->info == info) {
        aux = l->prox;
        free(l);
        return aux;
    }

    if(l->prox && l->prox->info == info) {
        aux = l->prox->prox;
        free(l->prox);
        l->prox = aux;
    } else {
        l->prox = remover(l->prox, info);
    }

    return l;
}*/
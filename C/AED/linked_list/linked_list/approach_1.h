#ifndef APPROACH_1_H
#define APPROACH_1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct knot {
    int val;
    struct knot* next;
} List;

int isEmpty(List* lst);
List* insert(List* list, int val);
List* remove(List* list, int val);
void printList(List* list);
List* invert(List* list);
List* concat(List* list1, List* lst2);
List* merge(List* list1, List* list2);

int isEmpty(List* lst) {
    if(lst == NULL)
        return 1;
    return 0;
}

List* insert(List* list, int val) {
    struct knot** tracer;

    for(tracer = &list;*tracer;tracer = &(*tracer)->next)
        ;

    *tracer = malloc(sizeof(struct knot));
    (*tracer)->val = val;
    (*tracer)->next = NULL;

    return list;
}

List* remove(List* list, int val) {
    struct knot* old;
    struct knot** tracer;
    char present = 0;

    for(tracer = &list;*tracer && !(present = ((*tracer)->val == val));tracer = &(*tracer)->next)
        ;

    if(present) {
        old = *tracer;
        *tracer = (*tracer)->next;
        free(old);
    }

    return list;
}

#endif // APPROACH_1_H

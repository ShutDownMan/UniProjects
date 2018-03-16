#include <stdio.h>
#include <stdlib.h>
#include "approach_1.h"

void createLinkedList(List* list) {
    int val;
    struct knot* newKnot = list;

    printf("Type in a value to be added: \n");
    scanf("%d", &val);
    while(val >= 0) {
        insert(list, val);

        printf("Type in a value to be added: \n");
        scanf("%d", &val);
    }
}

int main(int argc, char *argv[]) {
    List* list;

    createLinkedList(list);

    // printf("Hello World!\n");


    return 0;
}

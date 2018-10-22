#include <stdio.h>

#include "BTree.h"

int main() {
    FILE *f = fopen("btree.dat", "wb+");

    createEmptyBTree(f);

//    insert(f, 100);
//    insert(f, 101);
    insert(f, 2, 0);
    insert(f, 24, 0);
    insert(f, 8, 0);
    insert(f, 32, 0);
    insert(f, 16, 0);
    insert(f, 12, 0);
//    insert(f, -51);
//    insert(f, 65);
    insert(f, 15, 0);
    insert(f, 5, 0);
//    insert(f, 1);
    insert(f, 36, 0);
//    insert(f, -41);
    insert(f, 14, 0);
    insert(f, 46, 0);

    printBTree(f);

    printf("-----------\n");

    removeBTree(f, 36);
//    insert(f, 16);
//    removeBTree(f, 5);

    printBTree(f);

    return 0;
}
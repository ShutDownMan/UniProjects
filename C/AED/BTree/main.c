#include <stdio.h>

#include "BTree.h"

int main() {
    FILE *f = fopen("btree.dat", "wb+");

    createEmptyBTree(f);

    insert(f, -2);
    insert(f, 24);
    insert(f, -8);
    insert(f, 32);
    insert(f, -45);
    insert(f, -16);
    insert(f, 16);
    insert(f, -51);
    insert(f, 65);
    insert(f, -5);
    insert(f, 1);
    insert(f, 12);

    printBTree(f);

    return 0;
}
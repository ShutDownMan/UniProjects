#include <stdio.h>

#include "BTree.h"

int main() {
    FILE *f = fopen("btree.dat", "wb+");

    createEmptyBTree(f);

    insert(f, -2);
    insert(f, -8);
    insert(f, -45);
    insert(f, -16);
    insert(f, -51);


    return 0;
}
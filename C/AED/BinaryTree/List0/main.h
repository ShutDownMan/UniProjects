#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

typedef struct no {
    int info;
    struct no *right;
    struct no *left;
} Tree;

Tree *insertTree(Tree **tree, int info);

#endif // MAIN_H
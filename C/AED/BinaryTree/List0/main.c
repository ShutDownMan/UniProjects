#include <stdlib.h>
#include "main.h"


void printTree(Tree *tree);

Tree *createNode(int info);

int main() {
    Tree *tree = NULL;

    insertTree(&tree, 25);
    insertTree(&tree, 11);
    insertTree(&tree, 9);
    insertTree(&tree, 33);
    insertTree(&tree, 17);
    insertTree(&tree, 5);
    insertTree(&tree, 45);
    insertTree(&tree, 50);
    insertTree(&tree, 27);
    insertTree(&tree, 30);
    insertTree(&tree, 22);
    insertTree(&tree, 12);
    insertTree(&tree, 8);

    printTree(tree);

    return 0;
}

Tree *insertTree(Tree **tree, int info) {
    if(!(*tree)) {
        *tree = createNode(info);
        return *tree;
    }

    if(info < (*tree)->info) {
        return insertTree(&((*tree)->left), info);
    }

    return insertTree(&((*tree)->right), info);
}

Tree *createNode(int info) {
    Tree *newNode = (Tree*)malloc(sizeof(Tree));

    newNode->info = info;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printTree(Tree *tree) {
    if(!tree) {
        printf("--- ");
        return;
    }

    printf("%3d ", tree->info);
    printTree(tree->left);
    printTree(tree->right);
}

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	void **m_array;
	int size, alocatedSpace, finalInd;
} List;

List *createList();

List *addToList(List *array, void *item);

void *getListItemFromIndex(List *list, int index);

void freeList(List *list);

#endif // LIST_H
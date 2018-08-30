#include "list.h"

List *createList() {
	List *newList = malloc(sizeof(List));

	newList->size = 0;
	newList->finalInd = 0;
	newList->alocatedSpace = 1;
	newList->m_array = malloc(sizeof(void *));

	return newList;
}

List *addToList(List *list, void *item) {
	if(list->size+1 > list->alocatedSpace) {
		list->alocatedSpace *= 2;
		list->m_array = realloc(list->m_array, sizeof(void *)*list->alocatedSpace);
	}

	list->m_array[list->finalInd++] = item;
	list->size++;

	return list;
}

void *getListItemFromIndex(List *list, int index) {
	if(index >= 0 && index < list->size) {
		return list->m_array[index];
	}

	return NULL;
}

void freeList(List *list) {
	free(list);
}
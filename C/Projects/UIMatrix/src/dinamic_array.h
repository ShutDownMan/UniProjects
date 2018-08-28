#ifndef DINAMIC_ARRAY
#define DINAMIC_ARRAY

#include <stdio.h>
#include <stdlib.h>

typedef struct dinamicArray {
	void **m_array;
	int size, alocatedSpace, finalInd;
} DinamicArray;

DinamicArray *createDinamicArray();

DinamicArray *addDinamicArray(DinamicArray *array, void *item);

#endif // DINAMIC_ARRAY
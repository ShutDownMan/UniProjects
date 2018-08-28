#include "dinamic_array.h"

DinamicArray *createDinamicArray() {
	DinamicArray *newDinamicArray = malloc(sizeof(DinamicArray));

	newDinamicArray->size = 0;
	newDinamicArray->finalInd = 0;
	newDinamicArray->alocatedSpace = 1;
	newDinamicArray->m_array = malloc(sizeof(void *));

	return newDinamicArray;
}

DinamicArray *addDinamicArray(DinamicArray *dinamicArray, void *item) {
	if(dinamicArray->size+1 > dinamicArray->alocatedSpace) {
		dinamicArray->alocatedSpace *= 2;
		dinamicArray->m_array = realloc(dinamicArray->m_array, sizeof(void *)*dinamicArray->alocatedSpace);
	}

	dinamicArray->m_array[dinamicArray->finalInd++] = item;
	dinamicArray->size++;

	return dinamicArray;
}
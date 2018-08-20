#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "function_clock.h"
#include "sorts.h"
#include "start.h"

/**
	@brief getTimeTaken armazena e retorna o tempo tomado por um
		determinado método de ordenação em inteiros
	@param sortType método de ordenação
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@return tempo tomado pelo método em segundos
	@precondition nenhuma
	@postcondition nenhuma
*/
double getTimeTaken(int sortType, int vet[], int length) {
	clock_t t;
	double time_taken;
	int *vetCpy = copyVet(vet, length);

	t = clock();
	switch(sortType) {
		case SORT_TYPE_INSERTION: {
			numericSelectionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_SELECTION: {
			numericInsertionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_QUICKSORT: {
			numericQuickSort(vetCpy, 0, length-1);
			break;
		}

		case SORT_TYPE_MERGE: {
			numericMergeSort(vetCpy, 0, length);
			break;
		}

		case SORT_TYPE_HEAP: {
			numericHeapSort(vetCpy-1, length);
			break;
		}

		case SORT_TYPE_BUBBLE: {
			numericBubbleSort(vetCpy, length);
			break;
		}

		default: {
			fprintf(stdout, "invalid sort type (%d)\n", sortType);
			break;
		}
	}
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;

	free(vetCpy);

	return time_taken;
}

/**
	@brief copyVet retorna uma cópia de um vetor de inteiros
	@param vet vetor de inteiros original
	@param length tamanho do vetor
	@return vetor cópia
	@precondition nenhuma
	@postcondition nenhuma
*/
int *copyVet(int vet[], int length) {
	int i;
	int *newVet = (int *)malloc(sizeof(int)*length);

	for(i = 0; i < length; ++i)
		newVet[i] = vet[i];

	return newVet;
}

/**
	@brief getTimeTaken armazena e retorna o tempo tomado por um
		determinado método de ordenação em strings
	@param sortType método de ordenação
	@param vet vetor de strings
	@param length tamanho do vetor
	@return tempo tomado pelo método em segundos
	@precondition nenhuma
	@postcondition nenhuma
*/
double getTimeTakenStr(int sortType, char *vet[], int length) {
	clock_t t;
	double time_taken;
	char **vetCpy = copyStrVet(vet, length);

	t = clock();
	switch(sortType) {
		case SORT_TYPE_INSERTION: {
			stringSelectionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_SELECTION: {
			stringInsertionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_QUICKSORT: {
			stringQuickSort(vetCpy, 0, length-1);
			break;
		}

		case SORT_TYPE_MERGE: {
			stringMergeSort(vetCpy, 0, length);
			break;
		}

		case SORT_TYPE_HEAP: {
			stringHeapSort(vetCpy-1, length);
			break;
		}

		case SORT_TYPE_BUBBLE: {
			stringBubbleSort(vetCpy, length);
			break;
		}

		default: {
			fprintf(stdout, "invalid sort type (%d)\n", sortType);
			break;
		}
	}
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;

	free(vetCpy);

	return time_taken;
}

char **copyStrVet(char *vet[], int length) {
	int i;
	char **newVet = (char **)malloc(sizeof(char *) * length);

	for(i = 0; i < length; ++i)
		newVet[i] = vet[i];

	return newVet;
}
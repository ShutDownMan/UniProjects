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
	/// pega cópia do vetor original
	int *vetCpy = copyVet(vet, length);

	/// armazena tempo atual
	t = clock();
	switch(sortType) {
		/// ordena vetor pelo método selection
		case Insertion: {
			numericInsertionSort(vetCpy, length);
			break;
		}

		/// ordena vetor pelo método insertion
		case Selection: {
			numericSelectionSort(vetCpy, length);
			break;
		}

		/// ordena vetor pelo método quicksort
		case Quicksort: {
			numericQuickSort(vetCpy, 0, length-1);
			break;
		}

		/// ordena vetor pelo método merge
		case Merge: {
			numericMergeSort(vetCpy, 0, length);
			break;
		}

		/// ordena vetor pelo método heap
		case Heap: {
			numericHeapSort(vetCpy-1, length);
			break;
		}

		/// ordena vetor pelo método bubble
		case Bubble: {
			numericBubbleSort(vetCpy, length);
			break;
		}

		/// tipo de ordenação invalido
		default: {
			fprintf(stdout, "invalid sort type (%d)\n", sortType);
			break;
		}
	}
	/// armazena tempo de execução que levou a ordenação
	t = clock() - t;

	/// converte tempo para segundos
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	/// libera memória alocada para o vetor cópia
	free(vetCpy);

	/// retorna tempo em segundos
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
	/// aloca memória para o vetor
	int *newVet = (int *)malloc(sizeof(int)*length);

	/// copia cada elemento para o vetor cópia
	for(i = 0; i < length; ++i)
		newVet[i] = vet[i];

	/// retorna vetor cópia
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
	/// pega cópia do vetor original
	char **vetCpy = copyStrVet(vet, length);

	/// armazena tempo atual
	t = clock();
	switch(sortType) {
		/// ordena vetor pelo método selection
		case Insertion: {
			stringSelectionSort(vetCpy, length);
			break;
		}

		/// ordena vetor pelo método insertion
		case Selection: {
			stringInsertionSort(vetCpy, length);
			break;
		}

		/// ordena vetor pelo método quicksort
		case Quicksort: {
			stringQuickSort(vetCpy, 0, length-1);
			break;
		}

		/// ordena vetor pelo método merge
		case Merge: {
			stringMergeSort(vetCpy, 0, length);
			break;
		}

		/// ordena vetor pelo método heap
		case Heap: {
			stringHeapSort(vetCpy-1, length);
			break;
		}

		/// ordena vetor pelo método bubble
		case Bubble: {
			stringBubbleSort(vetCpy, length);
			break;
		}

		/// tipo de ordenação invalido
		default: {
			fprintf(stdout, "invalid sort type (%d)\n", sortType);
			break;
		}
	}
	/// armazena tempo de execução que levou a ordenação
	t = clock() - t;

	/// converte tempo para segundos
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	/// libera memória alocada para o vetor cópia
	free(vetCpy);

	/// retorna tempo em segundos
	return time_taken;
}

/**
	@brief copyStrVet retorna uma cópia de um vetor de inteiros
	@param vet vetor de strings original
	@param length tamanho do vetor
	@return vetor cópia
	@precondition nenhuma
	@postcondition nenhuma
*/
char **copyStrVet(char *vet[], int length) {
	int i;
	/// aloca memória para o vetor
	char **newVet = (char **)malloc(sizeof(char *) * length);

	/// copia cada elemento para o vetor cópia
	for(i = 0; i < length; ++i)
		newVet[i] = vet[i];

	/// retorna vetor cópia
	return newVet;
}
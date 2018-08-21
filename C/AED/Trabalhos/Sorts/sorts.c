#include <stdlib.h>
#include <string.h>

#include "sorts.h"

// NUMERIC SORTING //

/**
	@brief ordena inteiros pelo método Selection
	@param vet vetor de inteiros
	@param length tamanho do vetortamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericSelectionSort(int vet[], int length) {
	int i, j, min, x;
	for (i = 0; i < length-1; i++) {
		min = i;
		for (j = i+1; j < length; j++)
			if(vet[j] < vet[min]) min = j;
		x = vet[i]; vet[i] = vet[min]; vet[min] = x;
	}
}

/**
	@brief ordena inteiros pelo método Insertion
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericInsertionSort(int vet[], int length) {
	int i, j, aux;
	for (j = 1; j < length; j++) {
		aux = vet[j];
		for (i = j-1; i >= 0 && vet[i] > aux; i--)
			vet[i+1] = vet[i];
		vet[i+1] = aux;
	}
}

/**
	@brief ordena inteiros pelo método QuickSort
	@param vet vetor de inteiros
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericQuickSort(int vet[], int left, int right) {
	int j;
	if(left < right) {
		j = numericSeparate(vet, left, right);
		numericQuickSort(vet, left, j-1);
		numericQuickSort(vet, j+1, right);
	}
}

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de inteiros
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int numericSeparate(int vet[], int left, int right) {
	int pivo, j, k, temp;

	pivo = vet[right]; j = left;
	for(k = left; k < right; k++) {
		if(vet[k] <= pivo) {
			temp = vet[j]; vet[j] = vet[k]; vet[k] = temp;
			j++;
		}
	}
	vet[right] = vet[j]; vet[j] = pivo;
	return j;
}

/**
	@brief ordena inteiros pelo método MergeSort
	@param vet vetor de inteiros
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericMergeSort(int vet[], int left, int right) {
	int mid;
	if(left < right-1) {
		mid = (left+right)/2;

		numericMergeSort(vet, left, mid);
		numericMergeSort(vet, mid, right);
		numericMerge(vet, left, mid, right);
	}
}

/**
	@brief função auxiliar de mergesort
	@param vet vetor de inteiros
	@param left limite esquerdo
	@param mid meio
	@param right limite direito
	@precondition nenhuma
	@postcondition nenhuma
*/
void numericMerge(int vet[], int left, int mid, int right) {
	int i, j, k, *vetAux;
	vetAux = malloc((right-left)*sizeof(int));
	i = left; j = mid; k = 0;

	while( i < mid && j < right) {
		if(vet[i] <= vet[j]) vetAux[k++] = vet[i++];
		else vetAux[k++] = vet[j++];
	}

	while (i < mid) vetAux[k++] = vet[i++];
	while (j < right) vetAux[k++] = vet[j++];

	for(i = left; i < right; i++) {
		vet[i] = vetAux[i-left];
	}

	free(vetAux);
}

/**
	@brief ordena inteiros pelo método HeapSort
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericHeapSort(int vet[], int length) {
	int mid;
	for(mid = 1; mid < length; mid++)
		numericInsertHeap(vet, mid);
	for(mid = length; mid > 1; mid--) {
		int aux = vet[1]; vet[1] = vet[mid]; vet[mid] = aux;
		numericHeapify(vet, mid-1);
	}
}

/**
	@brief função auxiliar de HeapSort
	@param vet vetor de inteiros
	@param mid meio
	@precondition nenhuma
	@postcondition elementos são ordenados em forma de heap
*/
void numericInsertHeap(int vet[], int mid) {
	int f = mid+1;
	while (f > 1 && vet[f/2] < vet[f]) {
		int aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f = f/2;
	}
}

/**
	@brief fução auxiliar de HeapSort
	@param vet vetor de inteiros
	@param mid meio
	@precondition nenhuma
	@postcondition vetor é organizado para satisfazer as propriedades heap
*/
void numericHeapify(int vet[], int mid) {
	int aux, f = 2;

	while (f <= mid) {
		if(f < mid && vet[f] < vet[f+1]) ++f;
		if(vet[f/2] >= vet[f]) break;
		aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f *= 2;
	}
}

/**
	@brief ordena inteiros pelo método BubbleSort
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericBubbleSort(int vet[], int length) {
	int i, j, aux;

	for(i = length - 1; i >= 0; i--) {
		for(j = 1; j <= i; j++) {
			if(vet[j-1] > vet[j]) {
				aux = vet[j-1];
				vet[j-1] = vet[j];
				vet[j] = aux;
			}
		}
	}
}

// STRING SORTING //

/**
	@brief ordena strings pelo método Selection
	@param vet vetor de strings
	@param length tamanho do vetortamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringSelectionSort(char *vet[], int length) {
	int i, j, min;
	char *x;
	for (i = 0; i < length-1; i++) {
		min = i;
		for (j = i+1; j < length; j++)
			if(strcmp(vet[j], vet[min]) < 0) min = j;
		x = vet[i]; vet[i] = vet[min]; vet[min] = x;
	}
}

/**
	@brief ordena strings pelo método Insertion
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringInsertionSort(char *vet[], int length) {
	int i, j;
	char *aux;
	for (j = 1; j < length; j++) {
		aux = vet[j];
		for (i = j-1; i >= 0 && (strcmp(vet[i], aux) > 0); i--)
			vet[i+1] = vet[i];
		vet[i+1] = aux;
	}
}

/**
	@brief ordena strings pelo método QuickSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringQuickSort(char *vet[], int left, int right) {
	int j;
	if(left < right) {
		j = stringSeparate(vet, left, right);
		stringQuickSort(vet, left, j-1);
		stringQuickSort(vet, j+1, right);
	}
}

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int stringSeparate(char *vet[], int left, int right) {
	int j, k;
	char *temp, *pivot;

	pivot = vet[right]; j = left;
	for(k = left; k < right; k++) {
		if(strcmp(vet[k], pivot) <= 0) {
			temp = vet[j]; vet[j] = vet[k]; vet[k] = temp;
			j++;
		}
	}

	vet[right] = vet[j]; vet[j] = pivot;
	return j;
}

/**
	@brief ordena strings pelo método MergeSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringMergeSort(char *vet[], int left, int right) {
	int mid;
	if(left < right-1) {
		mid = (left+right)/2;

		stringMergeSort(vet, left, mid);
		stringMergeSort(vet, mid, right);
		stringMerge(vet, left, mid, right);
	}
}

/**
	@brief função auxiliar de MergeSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param mid meio
	@param right limite direito
	@precondition nenhuma
	@postcondition nenhuma
*/
void stringMerge(char *vet[], int left, int mid, int right) {
	int i, j, k;
	char **vetAux;

	vetAux = malloc((right-left)*sizeof(char*));
	i = left; j = mid; k = 0;

	while(i < mid && j < right) {
		if(strcmp(vet[i], vet[j]) <= 0) vetAux[k++] = vet[i++];
		else vetAux[k++] = vet[j++];
	}

	while (i < mid) vetAux[k++] = vet[i++];
	while (j < right) vetAux[k++] = vet[j++];

	for(i = left; i < right; i++) {
		vet[i] = vetAux[i-left];
	}

	free(vetAux);
}

/**
	@brief ordena strings pelo método HeapSort
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringHeapSort(char *vet[], int length) {
	int mid;
	for(mid = 1; mid < length; mid++)
		stringInsertHeap(vet, mid);
	for(mid = length; mid > 1; mid--) {
		char *aux = vet[1]; vet[1] = vet[mid]; vet[mid] = aux;
		stringHeapify(vet, mid-1);
	}
}


/**
	@brief função auxiliar de HeapSort
	@param vet vetor de strings
	@param mid meio
	@precondition nenhuma
	@postcondition elementos são ordenados em forma de heap
*/
void stringInsertHeap(char *vet[], int mid) {
	int f = mid+1;
	while (f > 1 && strcmp(vet[f/2], vet[f]) < 0) {
		char *aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f = f/2;
	}
}

/**
	@brief fução auxiliar de HeapSort
	@param vet vetor de strings
	@param mid meio
	@precondition nenhuma
	@postcondition vetor é organizado para satisfazer as propriedades heap
*/
void stringHeapify(char *vet[], int mid) {
	int f = 2;
	char *aux;

	while (f <= mid) {
		if(f < mid && strcmp(vet[f], vet[f+1]) < 0) ++f;
		if(strcmp(vet[f/2], vet[f]) >= 0) break;
		aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f *= 2;
	}
}

/**
	@brief ordena inteiros pelo método BubbleSort
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void stringBubbleSort(char *vet[], int length) {
	int i, j;
	char *aux;

	for(i = length - 1; i >= 0; i--) {
		for(j = 1; j <= i; j++) {
			if(strcmp(vet[j-1], vet[j]) > 0) {
				aux = vet[j-1];
				vet[j-1] = vet[j];
				vet[j] = aux;
			}
		}
	}
}
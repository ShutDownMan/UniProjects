#ifndef SORTS_H
#define SORTS_H

/**
	@brief ordena inteiros pelo método Selection
	@param vet vetor de inteiros
	@param length tamanho do vetortamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericSelectionSort(int vet[], int length);

/**
	@brief ordena inteiros pelo método Insertion
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericInsertionSort(int vet[], int length);

/**
	@brief ordena inteiros pelo método QuickSort
	@param vet vetor de inteiros
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericQuickSort(int vet[], int left, int right);

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de inteiros
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int numericSeparate(int vet[], int left, int right);

/**
	@brief ordena inteiros pelo método MergeSort
	@param vet vetor de inteiros
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericMergeSort(int vet[], int left, int right);

/**
	@brief função auxiliar de mergesort
	@param vet vetor de inteiros
	@param left limite esquerdo
	@param mid meio
	@param right limite direito
	@precondition nenhuma
	@postcondition nenhuma
*/
void numericMerge(int vet[], int left, int mid, int right);

/**
	@brief ordena inteiros pelo método HeapSort
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericHeapSort(int vet[], int length);

/**
	@brief função auxiliar de HeapSort
	@param vet vetor de inteiros
	@param mid meio
	@precondition nenhuma
	@postcondition elementos são ordenados em forma de heap
*/
void numericInsertHeap(int vet[], int mid);

/**
	@brief fução auxiliar de HeapSort
	@param vet vetor de inteiros
	@param mid meio
	@precondition nenhuma
	@postcondition vetor é organizado para satisfazer as propriedades heap
*/
void numericHeapify(int vet[], int mid);

/**
	@brief ordena inteiros pelo método BubbleSort
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void numericBubbleSort(int vet[], int length);

// STRING SORTING //

/**
	@brief ordena strings pelo método Selection
	@param vet vetor de strings
	@param length tamanho do vetortamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringSelectionSort(char *vet[], int length);

/**
	@brief ordena strings pelo método Insertion
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringInsertionSort(char *vet[], int length);

/**
	@brief ordena strings pelo método QuickSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringQuickSort(char *vet[], int left, int right);

/**
	@brief função auxiliar de QuickSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param right limite direito
	@precondition nenhuma
	@postcondition vetor é manipulado com referência a um pivô
*/
int stringSeparate(char *vet[], int left, int right);

/**
	@brief ordena strings pelo método MergeSort
	@param vet vetor de strings
	@param left limite esquerdo do vetor
	@param right limite direito do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringMergeSort(char *vet[], int left, int right);

/**
	@brief função auxiliar de MergeSort
	@param vet vetor de strings
	@param left limite esquerdo
	@param mid meio
	@param right limite direito
	@precondition nenhuma
	@postcondition nenhuma
*/
void stringMerge(char *vet[], int left, int mid, int right);

/**
	@brief ordena strings pelo método HeapSort
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem alfabética
*/
void stringHeapSort(char *vet[], int length);

/**
	@brief função auxiliar de HeapSort
	@param vet vetor de strings
	@param mid meio
	@precondition nenhuma
	@postcondition elementos são ordenados em forma de heap
*/
void stringInsertHeap(char *vet[], int mid);

/**
	@brief fução auxiliar de HeapSort
	@param vet vetor de strings
	@param mid meio
	@precondition nenhuma
	@postcondition vetor é organizado para satisfazer as propriedades heap
*/
void stringHeapify(char *vet[], int mid);

/**
	@brief ordena inteiros pelo método BubbleSort
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition vetor é ordenado em ordem crescente
*/
void stringBubbleSort(char *vet[], int length);

#endif // SORTS_H
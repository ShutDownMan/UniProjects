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
	@brief função auxiliar de 
	@param vet vetor de inteiros
	@param left 
	@param mid 
	@param right 
	@precondition 
	@postcondition 
*/
void numericMerge(int vet[], int left, int mid, int right);

/**
	@brief 
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition 
	@postcondition 
*/
void numericHeapSort(int vet[], int length);

/**
	@brief 
	@param vet vetor de inteiros
	@param mid 
	@precondition 
	@postcondition 
*/
void numericInsertHeap(int vet[], int mid);

/**
	@brief 
	@param vet vetor de inteiros
	@param mid 
	@precondition 
	@postcondition 
*/
void numericHeapify(int vet[], int mid);

/**
	@brief 
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@precondition 
	@postcondition 
*/
void numericBubbleSort(int vet[], int length);

// STRING SORTING //

/**
	@brief 
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition 
	@postcondition 
*/
void stringSelectionSort(char *vet[], int length);

/**
	@brief 
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition 
	@postcondition 
*/
void stringInsertionSort(char *vet[], int length);

/**
	@brief 
	@param vet vetor de strings
	@param left 
	@param right 
	@precondition 
	@postcondition 
*/
void stringQuickSort(char *vet[], int left, int right);

/**
	@brief 
	@param vet vetor de strings
	@param left 
	@param right 
	@precondition 
	@postcondition 
*/
int stringSeparate(char *vet[], int left, int right);

/**
	@brief 
	@param vet vetor de strings
	@param left 
	@param right 
	@precondition 
	@postcondition 
*/
void stringMergeSort(char *vet[], int left, int right);

/**
	@brief 
	@param vet vetor de strings
	@param left 
	@param mid 
	@param right 
	@precondition 
	@postcondition 
*/
void stringMerge(char *vet[], int left, int mid, int right);

/**
	@brief 
	@param vet vetor de strings
	@param left 
	@param mid 
	@param right 
	@precondition 
	@postcondition 
*/
void stringHeapSort(char *vet[], int length);

/**
	@brief 
	@param vet vetor de strings
	@param mid 
	@precondition 
	@postcondition 
*/
void stringInsertHeap(char *vet[], int mid);

/**
	@brief 
	@param vet vetor de strings
	@param mid 
	@precondition 
	@postcondition 
*/
void stringHeapify(char *vet[], int mid);

/**
	@brief 
	@param vet vetor de strings
	@param length tamanho do vetor
	@precondition 
	@postcondition 
*/
void stringBubbleSort(char *vet[], int length);

#endif // SORTS_H
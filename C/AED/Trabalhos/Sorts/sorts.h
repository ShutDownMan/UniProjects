#ifndef SORTS_H
#define SORTS_H

void numericSelectionSort(int vet[], int length);

void numericInsertionSort(int vet[], int length);

void numericQuickSort(int vet[], int left, int right);

int numericSeparate(int vet[], int left, int right);

void numericMergeSort(int vet[], int left, int right);

void numericMerge(int vet[], int left, int mid, int right);

void numericHeapSort(int vet[], int length);

void numericInsertHeap(int vet[], int mid);

void numericHeapify(int vet[], int mid);

void numericBubbleSort(int vet[], int length);

// STRING SORTING //

void stringSelectionSort(char *vet[], int length);

void stringInsertionSort(char *vet[], int length);

void stringQuickSort(char *vet[], int left, int right);

int stringSeparate(char *vet[], int left, int right);

void stringMergeSort(char *vet[], int left, int right);

void stringMerge(char *vet[], int left, int mid, int right);

void stringHeapSort(char *vet[], int length);

void stringInsertHeap(char *vet[], int mid);

void stringHeapify(char *vet[], int mid);

void stringBubbleSort(char *vet[], int length);

#endif // SORTS_H
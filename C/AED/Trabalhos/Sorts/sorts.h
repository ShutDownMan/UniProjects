#ifndef SORTS_H
#define SORTS_H

void selectionSort(int vet[], int length);

void insertionSort(int vet[], int length);

void quickSort(int vet[], int left, int right);

int separate(int vet[], int left, int right);

void mergeSort(int vet[], int left, int right);

void merge(int vet[], int left, int mid, int right);

void heapSort(int vet[], int length);

void insertHeap(int vet[], int mid);

void heapify(int vet[], int mid);

void bubbleSort(int vet[], int length);

#endif // SORTS_H
#include <stdlib.h>

#include "sorts.h"

void selectionSort(int vet[], int length) {
	int i, j, min, x;
	for (i = 0; i < length-1; i++) {
		min = i;
		for (j = i+1; j < length; j++)
			if(vet[j] < vet[min]) min = j;
		x = vet[i]; vet[i] = vet[min]; vet[min] = x;
	}
}

void insertionSort(int vet[], int length) {
	int i, j, aux;
	for (j = 1; j < length; j++) {
		aux = vet[j];
		for (i = j-1; i >= 0 && vet[i] > aux; i--)
			vet[i+1] = vet[i];
		vet[i+1] = aux;
	}
}

void quickSort(int vet[], int left, int right) {
	int j;
	if(left < right) {
		j = separate(vet, left, right);
		quickSort(vet, left, j-1);
		quickSort(vet, j+1, right);
	}
}

int separate(int vet[], int left, int right) {
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

void mergeSort(int vet[], int left, int right) {
	int mid;
	if(left < right-1) {
		mid = (left+right)/2;

		mergeSort(vet, left, mid);
		mergeSort(vet, mid, right);
		merge(vet, left, mid, right);
	}
}

void merge(int vet[], int left, int mid, int right) {
	int i, j, k, *vet_aux;
	vet_aux = malloc((right-left)*sizeof(int));
	i = left; j = mid; k = 0;

	while( i < mid && j < right) {
		if(vet[i] <= vet[j]) vet_aux[k++] = vet[i++];
		else vet_aux[k++] = vet[j++];
	}

	while (i < mid) vet_aux[k++] = vet[i++];
	while (j < right) vet_aux[k++] = vet[j++];

	for(i = left; i < right; i++) {
		vet[i] = vet_aux[i-left];
	}

	free(vet_aux);
}

void heapSort(int vet[], int length) {
	int mid;
	for(mid = 1; mid < length; mid++)
		insertHeap(vet, mid);
	for(mid = length; mid > 1; mid--) {
		int aux = vet[1]; vet[1] = vet[mid]; vet[mid] = aux;
		heapify(vet, mid-1);
	}
}

void insertHeap(int vet[], int mid) {
	int f = mid+1;
	while (f > 1 && vet[f/2] < vet[f]) {
		int aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f = f/2;
	}
}

void heapify(int vet[], int mid) {
	int aux, f = 2;

	while (f <= mid) {
		if(f < mid && vet[f] < vet[f+1]) ++f;
		if(vet[f/2] >= vet[f]) break;
		aux = vet[f/2]; vet[f/2] = vet[f]; vet[f] = aux;
		f *= 2;
	}
}

void bubbleSort(int vet[], int length) {
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
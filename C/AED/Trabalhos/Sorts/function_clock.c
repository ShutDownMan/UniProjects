#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "function_clock.h"
#include "sorts.h"
#include "start.h"

double getTimeTaken(int sortType, int vet[], int length) {
	clock_t t;
	double time_taken;
	int *vetCpy = copyVet(vet, length);


	t = clock();
	switch(sortType) {
		case SORT_TYPE_INSERTION: {
			selectionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_SELECTION: {
			insertionSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_QUICKSORT: {
			quickSort(vetCpy, 0, length);
			break;
		}

		case SORT_TYPE_MERGE: {
			mergeSort(vetCpy, 0, length);
			break;
		}

		case SORT_TYPE_HEAP: {
			heapSort(vetCpy, length);
			break;
		}

		case SORT_TYPE_BUBBLE: {
			bubbleSort(vetCpy, length);
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

int *copyVet(int vet[], int length) {
	int i;
	int *newVet = (int *)malloc(sizeof(int)*length);

	for(i = 0; i < length; ++i)
		newVet[i] = vet[i];

	return newVet;
}
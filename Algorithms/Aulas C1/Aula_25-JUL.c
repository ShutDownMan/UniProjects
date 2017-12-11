#include <stdio.h>

void scanNewVet(int newVet[], int *length);

int getLowestInd(int vet[], int length);

void swap(int *a, int *b);

void printVet(int vet[], int length);

void sortOf(int vet[], int length);

void bubbleSort(int vet[], int length);

int main(int argc, char const *argv[]) {
	int vet[100] = {0};
	int length, lowestInd;

	do {
		scanNewVet(vet, &length);

		bubbleSort(vet, length);

		printVet(vet, length);
	} while(length != 0);


	return 0;
}

void scanNewVet(int newVet[], int *length) {
	int currVal, i;

	scanf("%d", length);

	for(i = 0; i < *length; ++i) {
		scanf("%d", &currVal);
		newVet[i] = currVal;
	}
}

int getLowestInd(int vet[], int length) {
	int lowestInd = 0, i;
	for(i = 1; i < length; ++i) {
		if(vet[i] < vet[lowestInd]) lowestInd = i;
	}
	return lowestInd;
}

int getHighestInd(int vet[], int length) {
	int highestInd = 0, i;
	for(i = 1; i < length; ++i) {
		if(vet[i] > vet[highestInd]) highestInd = i;
	}
	return highestInd;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printVet(int vet[], int length) {
	int i;
	printf("Length = %d\n", length);
	for(i = 0; i < length; ++i) {
		printf("\t>vet[%d] = %d\n", i, vet[i]);
	}
}

void sortOf(int vet[], int length) {
	int highestInd;

	highestInd = getHighestInd(vet, length);
	if(vet[highestInd] > vet[0])
		swap(&vet[0], &vet[highestInd]);
}

void bubbleSort(int vet[], int length) {
	int i;
	
	for(i = 0; i < length; ++i) {
		sortOf(&vet[i], length-i);
	}
}
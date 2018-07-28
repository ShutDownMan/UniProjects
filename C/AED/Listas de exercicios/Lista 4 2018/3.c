#include <stdio.h>

#define MAXNUMBER 500

void selectionSort(int vet[], int length) {
	int i, min = 0, aux;

	if(length <= 0) return;

	for(i = 1; i < length; i++) {
		if(vet[i] < vet[min])
			min = i;
	}

	aux = vet[0]; vet[0] = vet[min]; vet[min] = aux;

	selectionSort(vet+1, length-1);
}

void readRandVet(int vet[]) {
	int i;

	for(i = 0; i < MAXNUMBER; ++i) {
		scanf("%d", &vet[i]);
	}
}

void printVet(int vet[]) {
	int i;

	for(i = 0; i < MAXNUMBER; ++i) {
		printf("%d\n", vet[i]);
	}
}

int main(void) {
	int vet[MAXNUMBER];

	readRandVet(vet);

	selectionSort(vet, MAXNUMBER);

	printVet(vet);

	return 0;
}
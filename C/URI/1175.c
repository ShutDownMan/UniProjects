#include <stdio.h>

void scanVet(int vet[]) {
	int i;
	
	for(i = 0; i < 100; ++i) {
		scanf("%d", &vet[i]);
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapVet(int vet[]) {
	int i;
	for(i = 0; i < 10; ++i) {
		// troca os valores de posição
		swap(&vet[i], &vet[19-i]);
	}
}

void printVet(int vet[]) {
	int i;
	for(i = 0; i < 20; ++i) {
		printf("N[%d] = %d\n", i, vet[i]);
	}
}

int main() {
	int i;
	int vet[100];

	// Lê valores de um vetor
	scanVet(vet);

	// inverte valores
	swapVet(vet);

	// Printa vetor invertido
	printVet(vet);

	return 0;
}
#include <stdio.h>

void scanVet(int length, int vet[]) {
	int i;

	for(i = 0; i < length; ++i) {
		scanf("%d ", &vet[i]);
	}
}

void menor(int length, int vet[]) {
	int i, lowestInd = 0;

	for(i = 1; i < length; ++i) {
		if(vet[lowestInd] > vet[i]) {
			lowestInd = i;
		}
	}
	printf("Menor valor: %d\n", vet[lowestInd]);
	printf("Posicao: %d\n", lowestInd);
}

int main(int argc, char const *argv[]) {
	int length, vet[1000];

	scanf("%d ", &length);

	scanVet(length, vet);

	menor(length, vet);

	return 0;
}
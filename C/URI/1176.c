#include <stdio.h>

void createFib(long long unsigned int vet[]) {
	int i;

	vet[0] = 0;
	vet[1] = 1;

	for(i = 2; i < 61; ++i) {
		vet[i] = vet[i-1] + vet[i-2];
	}
}

void printVet(long long unsigned int vet[], int ind) {
	printf("Fib(%d) = %llu\n", ind, vet[ind]);
}

int main() {
	int cdt, ind, i;
	long long unsigned int vet[61];

	createFib(vet);

	scanf("%d", &cdt);

	for(i = 0; i < cdt; ++i) {
		scanf("%d", &ind);

		printVet(vet, ind);
	}


	return 0;
}
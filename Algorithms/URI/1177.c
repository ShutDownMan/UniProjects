#include <stdio.h>

void makeVet(int vet[], int num) {
	int i;
	for(i = 1; i < 1000; ++i) {
		vet[i] = i%num;
	}
}

void printVet(int vet[]) {
	int i;
	for(i = 0; i < 1000; ++i) {
		printf("N[%d] = %d\n", i, vet[i]);
	}
}

int main(int argc, char const *argv[]) {
	int vet[1000], num;

	scanf("%d", &num);

	makeVet(vet, num);

	printVet(vet);

	return 0;
}
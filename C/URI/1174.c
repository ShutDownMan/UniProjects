#include <stdio.h>

void scanVet(float vet[]) {
	int i;
	float in_cur;
	for(i = 0; i < 100; ++i) {
		scanf("%f", &in_cur);
		vet[i] = in_cur;
	}
}

void printVet(float vet[]) {
	int i;
	for(i = 0; i < 100; ++i) {
		if(vet[i] <= 10) {
			printf("A[%d] = %.1f\n", i, vet[i]);
		}
	}
}

int main() {
	int i;
	float vet[100];

	scanVet(vet);

	printVet(vet);

	return 0;
}
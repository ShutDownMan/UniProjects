#include <stdio.h>

#define MAX 60

void fibonacci(long long unsigned int fibG[], int n) {
	int i;

	for(i = 0; i < n; ++i) {
		printf("%d ", fibG[i]);
	}
	printf("\n");
}

void prepara_fibonacci(long long unsigned int fibG[]) {
	int i;

	fibG[0] = 1;
	fibG[1] = 1;

	for(i = 2; i < 60; ++i) {
		fibG[i] = fibG[i-1] + fibG[i-2];
	}
}

int main() {
	long long unsigned int fibG[MAX];
	int entradas[MAX], tam;
	int nG, i;

	prepara_fibonacci(fibG);

	scanf("%d", &nG);
	for(i = tam = 0; nG != -1; ++i) {
		entradas[i] = nG;
		scanf("%d", &nG);
	}
	tam = i;

	for(i = 0; i < tam; ++i) {
		fibonacci(fibG, entradas[i]);
	}
}
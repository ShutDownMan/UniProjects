#include <stdio.h>

void makeVet(double vet[], double num) {
	int i;
	vet[0] = num;

	for(i = 1; i < 100; ++i) {
		vet[i] = vet[i-1]/2;
	}
}

void printVet(double vet[]) {
	int i;
	for(i = 0; i < 100; ++i) {
		printf("N[%d] = %.4lf\n", i, vet[i]);
	}
}

int main(int argc, char const *argv[]) {
	double vet[100], num;

	scanf("%lf", &num);

	makeVet(vet, num);

	printVet(vet);

	return 0;
}
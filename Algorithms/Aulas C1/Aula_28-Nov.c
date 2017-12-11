#include <stdio.h>

#define MAX 128

void loadVet(int vet[], int* length) {
	int i;

	scanf("%d", length);

	for (i = 0; i < *length; ++i) {
		scanf("%d", &vet[i]);
	}

}

int qImpar(int vet[], int length) {
	int i, quant;

	quant = 0;
	for (i = 0; i < length; ++i) {
		quant += vet[i] & 1;
	}

	return quant;
}

int clrBit(int x, int t) {
	return (1 << t) & x;
}


int setBit(int x, int t) {
	return ~(1 << t) | x;
}


int flipBit(int x, int t) {
	 return x ^ (1 << t);
}


int qPar(int vet[], int length) {
	int i, quant;

	quant = 0;
	for (i = 0; i < length; ++i) {
		quant += (~vet[i]) & 1;
	}

	return quant;
}

int xcountBits(int x) {
	int sum;

	for(sum = 0; x; x >>= 1) {
		sum += x & 1;
	}

	return sum;
}

int countBits(int x) {
	if(!x) return 0;

	return (x&1) + countBits(x>>1);
}

int sumVet(int vet[], int length) {
	if(!length) return 0;

	return vet[0] + sumVet(vet++, length-1);
}

int main(int argc, char const *argv[]) {
	int vet[MAX], length;
	int x, y, z;

	loadVet(vet, &length);

	printf("Quant de impares = %d\n", qImpar(vet, length));
	printf("Quant de pares = %d\n", qPar(vet, length));

	printf("SumVet = %d\n", sumVet(vet, length));

	x = 35;
	y = 3;

	//z = x & 0xAAAAAAAAAAAAAAAA | y & 0x5555555555555555;
	//z = (x | 0xAAAAAAAAAAAAAAAA) & (y | 0x5555555555555555);

	z = x >> y;

	printf("val = 0x%p\n", z);
	printf("val = %d\n", z);

	printf("soma = %d\n", countBits(5));


	return 0;
}
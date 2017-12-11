#include <stdio.h>
#define PRIME_LENGTH 7

void getDivs(int* length, int vet[], int num);

void getPrimeFactors(int* length, int vet[], int num);

void printVet(int length, int vet[]);

int primes[PRIME_LENGTH];

int main(int argc, char const *argv[]) {
	int divs[100], length, num;

	scanf("%d", &num);
	while(num) {
		//getDivs(&length, divs, num);
		getPrimeFactors(&length, divs, num);
		printVet(length, divs);

		scanf("%d", &num);
	}

	return 0;
}

void getDivs(int* length, int vet[], int num) {
	int curInd = 0;
	for(int i = 2; i <= num/2; ++i) {
		if(num%i == 0) {
			vet[curInd] = i;
			curInd++;
		}
	}
	*length = curInd;
}

void getPrimeFactors(int* length, int vet[], int num) {
	int curInd = 0;
	while(num > 1) {
		for(int i = 0; i < PRIME_LENGTH;) {
			if(num%primes[i] == 0) {
				vet[curInd] = primes[i];
				curInd++;
				num /= primes[i];
			} else {
				i++;
			}
		}
	}
	*length = curInd;
}

void printVet(int length, int vet[]) {
	if(length > 0) {
		for(int i = 0; i < length; ++i) {
			printf("V[%d] = %d\n", i, vet[i]);
		}
		printf("----------------\n");
	} else {
		printf("\a-\n");
	}
}
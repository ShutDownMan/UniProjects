#ifndef _VETOR_H_
#define _VETOR_H_
#include <stdio.h>

void populateVet(int vet[], int length) {
	int i;
	for(i = 0; i < length; ++i) {
		scanf("%d", &vet[i]);
	}
}

double getMedia(int vet[], int length) {
	int sum = 0, i;
	
	for(i = 0; i < length; ++i) {
		sum += vet[i];
	}

	return sum/length;
}

void printaPP(int vet[], int length, double media) {
	int i;
	for(int i = 0; i < length; ++i) {
		if(vet[i] > media) {
			printf("%d\n", vet[i]);
		}
	}
}

void printaInverso(int vet[], int length) {
	int i;
	for(i = length-1; i >= 0; --i) {
		printf("%d\n", vet[i]);
	}
}

void printaImpar(int vet[], int length) {
	int i;
	for(i = 0; i < length; ++i) {
		if(vet[i] %2 != 0) {
			printf("%d\n", vet[i]);
		}
	}
}

void createB(int vet[], int length, int newVet[]) {
	int i;
	for(i = 0; i < length-1; ++i) {
		newVet[i] = vet[i] + vet[i+1];
	}
}

int containsH(int vet[], int length, int numToSearch) {
	int i, hits;
	for (i = 0, hits = 0; i < length; ++i) {
		if(vet[i] == numToSearch) {
			hits ++;
		}
	}
	return hits;
}

void ToXVI(int num) {
	int i;
	char romanN[10][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};

	if (num <= 10) {
		printf("%s\n", romanN[num-1]);	
	}

}

#endif
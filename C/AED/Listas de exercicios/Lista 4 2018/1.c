#include <stdio.h>
#include <stdlib.h>

#define MAXNUMBER 500
#define FNUM 101

int binarySearch(int vet[], int n, int x) {
	int e, m, d;
	e = -1; d = n;

	while(e < d-1) {
		m = (e+d)/2;
		if(vet[m] < m) {
			e = m;
		} else {
			d = m;
		}
	}

	return d;
}

void readRandVet(int vet[]) {
	int i;

	for(i = 0; i < MAXNUMBER; ++i) {
		scanf("%d", &vet[i]);
	}
}

int main(void) {
	int vet[MAXNUMBER] = {0};
	int foundInd = 0;

	readRandVet(vet);

	foundInd = binarySearch(vet, MAXNUMBER, FNUM);

	if(foundInd < MAXNUMBER) {
		printf("vet[%d] = %d\n", foundInd, vet[foundInd]);
	}

	return 0;
}
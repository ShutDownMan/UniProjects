#include <stdio.h>
#define MAX 100

void readvet(int length, int vet[]) {
	int i;

	for (i = 0; i < length; ++i) {
		scanf("%d", &vet[i]);
		//printf("vet[%d] = %d\n", i, vet[i]);
	}
}

int* concat(int length1, int vet1[], int length2, int vet2[], int* newlength, int newvet[]) {
	int i, j, hasNum;

	hasNum = (*newlength) = 0;
	for (i = 0; i < length1; ++i) {
		for (j = 0; j < (*newlength); ++j) {
			if(vet1[i] == newvet[j]) {
				hasNum = 1;
				break;
			}
		}

		if(!hasNum) newvet[(*newlength)++] = vet1[i];
		hasNum = 0;
	}

	hasNum = 0;
	for (i = 0; i < length2; ++i) {
		for (j = 0; j < (*newlength); ++j) {
			if(vet1[i] == newvet[j]) {
				hasNum = 1;
				break;
			}
		}

		if(!hasNum) newvet[(*newlength)++] = vet2[i];
		hasNum = 0;
	}

	return newvet;
}

void printvet(int vet[], int length) {
	int i;

	for (i = 0; i < length; ++i) {
		printf("vet[%d] = %d\n", i, vet[i]);
	}
}

int main(int argc, char const *argv[]) {
	int vets[MAX][MAX];
	int lengths[MAX], i_length;

	int newvet[MAX], newlength;

	i_length = 0;
	scanf("%d", &lengths[i_length]);
	while(lengths[i_length]) {
		readvet(lengths[i_length], vets[i_length]);

		scanf("%d", &lengths[++i_length]);
	}

	concat(lengths[0], vets[0], lengths[1], vets[1], &newlength, newvet);

	printf("%d\n", newlength);

	printvet(newvet, newlength);

	return 0;
}
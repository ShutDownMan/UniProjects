#include <stdio.h>
#include <math.h>
#define VET_LENGTH 256

int scanVet(int* length, int vet[]) {
	int i;

	scanf("%d", length);

	for (int i = 0; i < *length; ++i) {
		scanf("%d", &vet[i]);
	}
}

float getAverage(int length, int vet[]) {
	int i, sum;

	sum = 0;
	for (i = 0; i < length; ++i) {
		sum += vet[i];
	}

	return sum/(i+1);
}

int getLowestValueInd(int length, int vet[]) {
	int i, lowestValInd;

	lowestValInd = 0;
	for (i = 1; i < length; ++i) {
		if(vet[i] < vet[lowestValInd]) {
			lowestValInd = i;
		}
	}

	return lowestValInd;
}

int printHiAvrg(int length, int vet[], int average) {
	int i;

	printf("Media = %d\n", average);
	for (i = 0; i < length; ++i) {
		if(vet[i] > average) {
			printf("\tvet[%d] = %d\n", i, vet[i]);
		}
	}
}

int swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortOfAsc(int length, int vet[]) {
	int i, lowestValInd;

	lowestValInd = getLowestValueInd(length, vet);
	if(vet[0] > vet[lowestValInd]) {
		swap(&vet[0], &vet[lowestValInd]);
	}
}

void bubbleSort(int length, int vet[]) {
	int i;

	for (i = 0; i < length -1; ++i) {
		sortOfAsc(length-i, &vet[i]);
	}

}

void printVet(int length, int vet[]) {
	int i;

	printf("-------------\n");
	for (int i = 0; i < length; ++i) {
		printf("vet[%d] = %d\n", i, vet[i]);
	}
}

void concatEvenOdd(int length, int vet[], int oddLength, int odd[], int evenLength, int even[]) {
	int i, count;

	if(abs(oddLength-evenLength) < 2) {
		count = 0;

		for (i = 0; i < length; i+=2) {
			vet[i] = odd[i];
			vet[i+1] = even[i];
		}
	}
}

void evenOddMatrix(int length, int vet[]) {
	int i, oddCount = -1, evenCount = -1;
	int even[VET_LENGTH], odd[VET_LENGTH];

	for (i = 0; i < length; ++i) {
		if(vet[i]%2) {
			odd[++oddCount] = vet[i];
		} else {
			even[++evenCount] = vet[i];
		}
	}

	printVet(++oddCount, odd);
	printVet(++evenCount, even);

	bubbleSort(evenCount, even);
	bubbleSort(oddCount, odd);

	concatEvenOdd(length, vet, oddCount, odd, evenCount, even);
}

int main(int argc, char const *argv[]) {
	int length, vet[VET_LENGTH], tmp;

	scanVet(&length, vet);
	//printf("Media = %g\n", getAverage(length, vet));

	//tmp = getLowestValueInd(length, vet);
	//printf("vet[%d] = %d\n", tmp, vet[tmp]);
	//printHiAvrg(length, vet, getAverage(length, vet));

	//bubbleSort(length, vet);

	evenOddMatrix(length, vet);
	printVet(length, vet);

	return 0;
}

void _17() {
	int i;
	int newVet[10];

	for (int i = 0; i < 10; ++i) {
		newVet[i] = i%2;
	}
}
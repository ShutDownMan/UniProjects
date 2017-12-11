#include <stdio.h>

void scanVet(int length, long int vet[length]) {
	int cur;
	for(int i = 0; i < length; ++i) {
		scanf("%ld", &cur);
		vet[i] = cur;
	}
}

void printVet(int length, long int vet[length]) {
	for(int i = 0; i < length; ++i) {
		printf("vet[%d] = %ld\n", i, vet[i]);
	}
}

void getHighest(int length, long int vet[length]) {
	int highestInd = 0;
	for(int i = 1; i < length; ++i) {
		if(vet[highestInd] < vet[i]) {
			highestInd = i;
		}
	}
	printf("Higest => vet[%d] = %ld\n", highestInd, vet[highestInd]);
}

void getLowest(int length, long int vet[length]) {
	int lowestInd = 0;
	for(int i = 1; i < length; ++i) {
		if(vet[lowestInd] > vet[i]) {
			lowestInd = i;
		}
	}
	printf("Lowest => vet[%d] = %ld\n", lowestInd, vet[lowestInd]);
}

void fromToVet(long int vet[], int a, int b) {
	for(int i = a; i <= b; ++i) {
		printf("vet[%d] = %ld\n", i, vet[i]);
	}
}

void getSum(int length, long int vet[length]) {
	int sum = 0;
	for(int i = 0; i < length; ++i) {
		sum += vet[i];
	}
	printf("Sum = %ld\n", sum);
}

void getAvrg(int length, long int vet[length]) {
	int sum = 0, avrg = 0;
	for(int i = 0; i < length; ++i) {
		sum += vet[i];
	}
	avrg = sum / length;
	printf("Average = %ld\n", avrg);
}

void getProd(int length, long int vet[length]) {
	long int sum = 1;
	for(int i = 0; i < length; ++i) {
		sum *= vet[i];
	}
	printf("Prod = %ld\n", sum);
}

void countHits(int length, long int vet[length], int num) {
	int hits = 0;

	for(int i = 0; i < length; ++i) {
		if(vet[i] == num) hits++;
	}
	printf("hits = %d\n", hits);
}

void revert(int length, long int vet[length]) {
	long int copyVet[100];
	for(int i = 0; i < length; ++i) {
		copyVet[i] = vet[i];
	}

	for(int i = 0; i < length; ++i) {
		vet[i] = copyVet[length-i-1];
	}
}

int somaVet(int lengthNew, long int newVet[], int lengthA, long int vetA[], int lengthB, long int vetB[]) {
	
}

int main(int argc, char const *argv[]) {
	long int vet[100], length;

	scanf("%d", &length);
	while(length) {
		scanVet(length, vet);
		//printVet(length, vet);

		//getHighest(length, vet);
		//getLowest(length, vet);

		//fromToVet(vet, 1, 3);
		
		//getSum(length, vet);
		//getAvrg(length, vet);

		//getProd(length, vet);
		//countHits(length, vet, 65);

		//revert(length, vet);
		//printVet(length, vet);



		scanf("%d", &length);
	}



	return 0;
}
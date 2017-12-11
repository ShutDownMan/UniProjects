#include <stdio.h>
#define MAX 100

int calcSum(int length, int* vet) {
	int *p;
	int sum = 0;

	for (p = vet; p < vet+length; ++p) {
		sum += *p;
	}

	return sum;
}

int* readVet(int length, int* vet) {
	int *p;

	for (p = vet; p < vet+length; ++p) {
		scanf("%d", p);
	}

	return vet;
}

int main(int argc, char const *argv[]) {
	int nums[MAX];
	int length;

	scanf("%d", &length);

	while(length) {
		readVet(length, nums);

		printf("soma: %d\n", calcSum(length, nums));

		scanf("%d", &length);
	}

	return 0;
}
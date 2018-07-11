#include <stdio.h>

int getOnBitSum(int binVet[]) {
	int i, sum;

	for(i = sum = 0; i < 32; ++i) {
		sum += binVet[i];
	}

	return sum;
}

void printBinVet(int binVet[]) {
	int i, j, index;

	for(i = 0; i < sizeof(int)*2; ++i) {
		for(j = 0; j < 4; ++j) {
			index = i*4 + j;

			printf("%d", binVet[index]);
		}
		printf(" ");
	}
	printf("= [%d]\n", getOnBitSum(binVet));
}

void showBin(int x) {
	int i;
	int binVet[32] = {0};

	for(i = 31; i && x; --i, x >>= 1) {
		binVet[i] = x & 1;
	}

	printBinVet(binVet);
}

int main(void) {
	int cdt, x;

	scanf("%d", &x);
	while(x != -1) {
		showBin(x);
		scanf("%d", &x);
	}

	return 0;
}
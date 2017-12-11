#include <stdio.h>

int main() {
	int i, n, output[10];

	scanf("%d", &n);

	output[0] = n;

	for(i = 1; i < 10; ++i) {
		output[i] = output[i-1] * 2;
	}

	for(i = 0; i < 10; ++i) {
		printf("N[%d] = %d\n", i, output[i]);
	}
}
#include <stdio.h>

int main() {
	int iterations, n, i;

	scanf("%d", &iterations);

	for (i = 0; i < iterations; ++i)
	{
		n = i+1;
		printf("%d %d %d\n", n, n*n, n*n*n);
	}

	return 0;

}
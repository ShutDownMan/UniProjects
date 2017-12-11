#include <stdio.h>

int main(int argc, char const *argv[]) {
	int iterations, n, i;
	char even, positive;

	scanf("%d", &iterations);

	for (i = 0; i < iterations; ++i)
	{
		scanf("%d", &n);

		if(n == 0){
			printf("NULL\n");
			continue;
		}

		positive = (n > 0);

		even = (n % 2 == 0);

		printf("%s %s\n", (even) ? "EVEN":"ODD", (positive) ? "POSITIVE":"NEGATIVE");		
	}

	return 0;
}
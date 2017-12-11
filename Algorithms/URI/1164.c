#include <stdio.h>
#include <math.h>

int main() {
	int iterations, i, n, sum = 0, j = 1;

	// Get number of itarations necessary
	scanf("%d", &iterations);

	// Iterate through the problem as many times asked
	for (i = 0; i < iterations; ++i) {
		// get number to work with
		scanf("%d", &n);

		sum = 0;
		for (j = 1; j < n; ++j) {
			// If current number divides perfecly
			if(n%j == 0 && n != j){
				// Sums it for later check
				sum += j;
			}
		}

		if(sum == n) {
			printf("%d eh perfeito\n", n);
		} else {
			printf("%d nao eh perfeito\n", n);
		}
	}

	return 0;

}

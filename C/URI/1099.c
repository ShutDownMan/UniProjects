#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	int in_n, in_a, in_b, cdt, i, sum;

	scanf("%d", &in_n);

	for(cdt = 0; cdt < in_n; ++cdt) {
		// Scan "x" e "y"
		scanf("%d %d", &in_a, &in_b);

		sum = 0;
		// para i = menor numero, i é menor que maior número, i++
		for(i = fmin(in_a, in_b); i < fmax(in_a, in_b); ++i) {
			// Soma somente se for impar
			sum += (i %2 != 0) ? i : 0;
		}

		// Print da soma
		printf("%d\n", sum);
	}

	return 0;
}
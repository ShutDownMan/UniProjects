#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	int in_a, in_b, i, sum = 0;

	// Scan "x" e "y"
	scanf("%d %d", &in_a, &in_b);

	// para i = menor numero, i é menor que maior número, i++
	for(i = fmin(in_a, in_b)+1; i < fmax(in_a, in_b); ++i) {
		// Soma somente se for impar
		sum += (i %2 != 0) ? i : 0;
	}

	// Print da soma
	printf("%d\n", sum);
	return 0;
}
#include <stdio.h>
#include <math.h>

#define MAX 24

int main(int argc, char const *argv[]) {
	int count, n, row, col, k, length, aux;
	int mat[MAX][MAX], res[MAX][MAX], base[MAX] = {0};

	scanf("%d", &count);

	n = count;
	while(count--) {
		scanf("%d", &length);

		for (row = 0; row < length; ++row) {
			for (col = 0; col < length; ++col) {
				scanf("%d", &mat[row][col]);
			}
		}

		for (row = 0; row < length; ++row) {
			for (col = 0; col < length; ++col) {
				res[row][col] = mat[row][col] * mat[row][col];
				aux = log10(res[row][col])+1;
				base[col] = (base[col] < aux) ? aux : base[col];
			}
		}

		printf("Quadrado da matriz #%d:\n", (n-count)+3);

		for (row = 0; row < length; ++row) {
			for (col = 0; col < length; ++col) {
				printf("%*d", base[col], res[row][col]);
				if(col < length-1) printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
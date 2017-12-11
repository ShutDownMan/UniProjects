#include <stdio.h>
#include <stdlib.h>

#define MAX 128
#define MAXCOL 128

void loadmat(int** mat, int length, int width) {
	int i, j;

	for (i = 0; i < length; ++i) {
		for (j = 0; j < width; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void printmat(int** mat, int length, int width) {
	int i, j;

	for (i = 0; i < length; ++i) {
		for (j = 0; j < width; ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[]) {
	int* pont, length;

	scanf("%d", &length);

	pont = malloc(sizeof(int)*length);

	loadmat((int**)pont, 5, 2);

	printmat((int**)pont, 5, 2);

	return 0;
}
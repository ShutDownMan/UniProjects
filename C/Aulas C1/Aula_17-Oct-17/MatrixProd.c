#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define MAXROW 256
#define MAXCOL 256


int loadmat(char filename[], int mat[MAXROW][MAXCOL], int* nr, int* nc) {
	int i, j;
	FILE* matfile;

	if(!(matfile = fopen(filename, "r"))) return 0;

	fscanf(matfile, "%d %d", nr, nc);
	//printf("%d %d\n", *nr, *nc);

	for (i = 0; i < *nr; ++i) {
		for (j = 0; j < *nc; ++j) {
			fscanf(matfile, "%d", &mat[i][j]);
		}
	}

	fclose(matfile);

	return 1;
}

void printmat(FILE* outputfile, int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, j;

	for (i = 0; i < nr; ++i) {
		for (j = 0; j < nc; ++j) {
			fprintf(outputfile, "%3d ", mat[i][j]);
		}
		fprintf(outputfile, "\n");
	}
}

void product(int first[MAXROW][MAXCOL], int second[MAXROW][MAXCOL], int nr1, int nc1, int nr2, int nc2) {
	int i, j, k, sum;
	int result[MAX][MAX];

	if(nr1 != nc2) {
		printf("Matrices with entered orders can't be multiplied with each other.\n");
		return;
	}

	sum = 0;
	for (i = 0; i < nr1; i++) {
		for (j = 0; j < nc2; j++) {
			for (k = 0; k < nr2; k++) {
				sum += first[i][k]*second[k][j];
			}

			result[i][j] = sum;
			sum = 0;
		}
	}

	printf("Product of entered matrices:\n");
	printmat(stdout, result, nc1, nr2);
}

int main(int argc, char const *argv[]) {
	int nr1 = 0, nc1 = 0, firstmat[MAXROW][MAXCOL];
	int nr2 = 0, nc2 = 0, secondmat[MAXROW][MAXCOL];
	FILE *matfile; char filename[MAX];

	printf("Enter the file name of first matrix: ");
	gets(filename);
	loadmat(filename, firstmat, &nr1, &nc1);
	printmat(stdout, firstmat, nr1, nc1);

	printf("Enter the file name of second matrix: ");
	gets(filename);
	loadmat(filename, secondmat, &nr2, &nc2);
	printmat(stdout, secondmat, nr2, nc2);


	product(firstmat, secondmat, nr1, nc1, nr2, nc2);

	return 0;
}
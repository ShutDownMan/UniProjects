#include <stdio.h>
#define MAXROW 6
#define MAXCOL 6
#define ARRAYARGS int nrow, int ncol, int mat[nrow][ncol]

void createmat(ARRAYARGS) {
	int row, col;

	for (row = 0; row < nrow; ++row) {
		for (col = 0; col < ncol; ++col) {
			mat[row][col] = (row <= ncol-col-1);
		}
	}
}

void printmat(ARRAYARGS) {
	int row, col;

	for (row = 0; row < MAXROW; ++row) {
		for (col = 0; col < MAXCOL; ++col) {
			printf("%3d ", mat[row][col]);
		}
		printf("\n");
	}
}

void printsht(ARRAYARGS) {
	int *p = (int*)mat;

	for ( ; p < (mat + nrow); ++p) {
		if(!((p-(int*)mat)%ncol)) printf("\n");
		printf("%3d ", *p);
	}
	printf("\n");
}

void printpt(ARRAYARGS) {
	 int row, col;

	for (row = 0; row < nrow; ++row) {
		for (col = 0; col < ncol; ++col) {
			printf("%3d ", *(*(mat+row)+col));
		}
	}
}

void readmat(ARRAYARGS) {
	int row, col;

	for (row = 0; row < nrow; ++row) {
		for (col = 0; col < ncol; ++col) {
			scanf("%d", &mat[row][col]);
		}
	}
}

int main(int argc, char const *argv[]) {
	/*
	int nrow, ncol;
	int mat[MAXROW][MAXCOL] = {0};

	//createmat(nrow, ncol, mat);

	scanf("%d %d", &nrow, &ncol);

	while(nrow || ncol) {
		readmat(nrow, ncol, mat);

		printpt(nrow, ncol, mat);

		printf("\n------------------\n");

		printmat(nrow, ncol, mat);

		scanf("%d %d", &nrow, &ncol);
	}
	*/

	printf("args %d\n", argc);

	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	return 0;
}
#include <stdio.h>

#define MAX 256
#define MAXROW 256
#define MAXCOL 256

int loadmat(int mat[MAXROW][MAXCOL], int* nr, int* nc);
void printvet(int vet[MAX], int length);

void sumrows(int mat[MAXROW][MAXCOL], int nr, int nc, int vetrowsum[], int* vetlength);
void sumcols(int mat[MAXROW][MAXCOL], int nr, int nc, int vetcolsum[], int* vetlength);

int sumdiagprinc(int mat[MAXROW][MAXCOL], int nr, int nc);
int sumdiagsec(int mat[MAXROW][MAXCOL], int nr, int nc);

int main(int argc, char const *argv[]) {
	int mat[MAXROW][MAXCOL], nr, nc;
	int vetrowsum[MAX], vetrowsumlength;
	int vetcolsum[MAX], vetcolsumlength;

	loadmat(mat, &nr, &nc);

	printf("Rows sum :-\n");
	sumrows(mat, nr, nc, vetrowsum, &vetrowsumlength);
	printvet(vetrowsum, vetrowsumlength);

	printf("Cols sum :-\n");
	sumcols(mat, nr, nc, vetcolsum, &vetcolsumlength);
	printvet(vetcolsum, vetcolsumlength);

	printf("Principal diag sum :-\n");
	printf("%d\n", sumdiagprinc(mat, nr, nc));

	printf("Secondary diag sum :-\n");
	printf("%d\n", sumdiagsec(mat, nr, nc));

	return 0;
}

int loadmat(int mat[MAXROW][MAXCOL], int* nr, int* nc) {
	int i, j;

	fscanf(stdin, "%d %d", nr, nc);

	for (i = 0; i < *nr; ++i) {
		for (j = 0; j < *nc; ++j) {
			fscanf(stdin, "%d", &mat[i][j]);
		}
	}

	return 1;
}

void printvet(int vet[MAX], int length) {
	int i;

	for (i = 0; i < length; ++i) {
		printf("%3d ", vet[i]);
	}
	printf("\n");
}

int sumdiagprinc(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nr; ++i) {
		sum += mat[i][i];
	}

	return sum;
}

int sumdiagsec(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nr; ++i) {
		sum += mat[i][nr-i-1];
	}

	return sum;
}

int sumrow(int mat[MAXROW][MAXCOL], int row, int nc) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nc; ++i) {
		sum += mat[row][i];
	}

	return sum;
}

int sumcol(int mat[MAXROW][MAXCOL], int nr, int col) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nr; ++i) {
		sum += mat[i][col];
	}

	return sum;
}

void sumrows(int mat[MAXROW][MAXCOL], int nr, int nc, int vetrowsum[], int* vetlength) {
	int i, sum;

	for (i = 0; i < nr; ++i) {
		vetrowsum[i] = sumrow(mat, i, nc);
		//printf("%3d ", vetrowsum[i]);
	}

	*vetlength = nr;
}

void sumcols(int mat[MAXROW][MAXCOL], int nr, int nc, int vetcolsum[], int* vetlength) {
	int i, sum;

	for (i = 0; i < nc; ++i) {
		vetcolsum[i] = sumcol(mat, nr, i);
		//printf("%3d ", vetcolsum[i]);
	}

	*vetlength = nc;
}
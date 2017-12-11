#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define MAXROW 256
#define MAXCOL 256

int loadmat(char filename[], int mat[MAXROW][MAXCOL], int* nr, int* nc);

int processa(FILE* outputfile, char filename[], int mat[MAXROW][MAXCOL], int nr, int nc);

void printmat(FILE* outputfile, int mat[MAXROW][MAXCOL], int nr, int nc);
char* isidentity(int mat[MAXROW][MAXCOL], int nr, int nc);
int sumdiagpri(int mat[MAXROW][MAXCOL], int nr, int nc);
int sumdiagsec(int mat[MAXROW][MAXCOL], int nr, int nc);
char* issymetric(int mat[MAXROW][MAXCOL], int nr, int nc);

int main(int argc, char const *argv[]) {
	int mat[MAXROW][MAXCOL];
	int nr, nc	;
	FILE *matlist, *relatfile;
	char filename[MAX];

	if(!(matlist = fopen("matrizes.txt", "r"))) return 1;
	if(!(relatfile = fopen("relat.txt", "w"))) return 2;

	while(!feof(matlist)) {
		//fgets(matlist, filename);
		fscanf(matlist, "%[^\n]%*c", filename);
		//fprintf(stderr, "%s\n", filename);

		if(loadmat(filename, mat, &nr, &nc)) {
			processa(relatfile, filename, mat, nr, nc);
		} else {
			fprintf(relatfile, "%s\nARQUIVO NÃO EXISTENTE\n", filename);
		}
	}

	fclose(matlist);
	fclose(relatfile);
	system("PAUSE");
	return 0;
}

int loadmat(char filename[], int mat[MAXROW][MAXCOL], int* nr, int* nc) {
	int i, j;
	FILE* matfile;

	if(!(matfile = fopen(filename, "r"))) return 0;

	fscanf(matfile, "%d %d", nr, nc);

	for (i = 0; i < *nr; ++i) {
		for (j = 0; j < *nc; ++j) {
			fscanf(matfile, "%d", &mat[i][j]);
		}
	}

	return 1;
}

int processa(FILE* outputfile, char filename[], int mat[MAXROW][MAXCOL], int nr, int nc) {

	fprintf(outputfile, "%s\n", filename);
	printmat(outputfile, mat, nr, nc);

	if(nr == nc) {
		fprintf(outputfile, "QUADRADA => SIM\n");
		fprintf(outputfile, "IDENTIDADE => %s\n", isidentity(mat, nr, nc));
		fprintf(outputfile, "PERMUTAÇÃO => %s\n", issymetric(mat, nr, nc));
		fprintf(outputfile, "SOMA DIAG PRINCIPAL => %d\n", sumdiagpri(mat, nr, nc));
		fprintf(outputfile, "SOMA DIAG SECUNDÁRIA => %d\n", sumdiagsec(mat, nr, nc));
		//fprintf(outputfile, "QUADRADO MÁGICO => %s\n", ismagicsquare(mat, nr, nc));
	} else {
		fprintf(outputfile, "QUADRADA => NÃO\n");
		fprintf(outputfile, "IDENTIDADE => N/A\n");
		fprintf(outputfile, "PERMUTAÇÃO => N/A\n");
		fprintf(outputfile, "QUADRADO MÁGICO => N/A\n");
		fprintf(outputfile, "SOMA DIAG PRINCIPAL => N/A\n");
		fprintf(outputfile, "SOMA DIAG SECUNDÁRIA => N/A\n");
	}


	return 0;
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

char* isidentity(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, j;

	if(nr != nc) return "N/A";

	for (i = 0; i < nr; ++i) {
		for (j = 0; j < nc; ++j) {
			if(i == j) {
				if(mat[i][j] != 1) return "NÃO";
			} else {
				if(mat[i][j] != 0) return "NÃO";
			}
		}
	}

	return "SIM";
}

int sumdiagpri(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nc; ++i) {
		sum += mat[i][i];
	}

	return sum;
}

int sumdiagsec(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, j, sum;

	sum = 0;
	for (i = 0; i < nr; ++i) {
		for (j = 0; j < nc; ++j) {
			if(i + j == nr-1) sum += mat[i][j];
		}
	}

	return sum;
}

char* issymetric(int mat[MAXROW][MAXCOL], int nr, int nc) {
	int i, j;

	for (i = 0; i < nr; ++i) {
		for (j = 0; j < nc; ++j) {
			if(mat[i][j] != mat[j][i]) return "NÃO";
		}
	}

	return "SIM";
}


int sumrow(int mat[MAXROW][MAXCOL], int row, int nc) {
	int i, sum;

	sum = 0;
	for (i = 0; i < nc; ++i) {
		sum += mat[row][i];
	}

	return sum;
}

void sumrows(int mat[MAXROW][MAXCOL], int nr, int nc, int vetrowsum[], int* vetlength) {
	int i, sum;

	for (i = 0; i < nr; ++i) {
		vetrowsum[i] = sumrow(mat, i, nc);
		printf("%3d ", vetrowsum[i]);
	}

	*vetlength = nr;

	printf("\n");
}

void sumcols(int mat[MAXROW][MAXCOL], int nr, int nc, int vetcolsum[], int* vetlength) {
	int i, sum;

	for (i = 0; i < nr; ++i) {
		vet[i] = sumcol(mat, nr, i);
		printf("%3d ", vet[i]);
	}

	*vetlength = nc;

	printf("\n");
}
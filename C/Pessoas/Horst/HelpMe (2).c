#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXL 100
#define MAXC 100

int loadmat (char fn[], int matriz[][MAXC], int* nl, int *nc){
	FILE *f;
	int i, j;

	if (!(f = fopen(fn, "r"))) return 0;
	fscanf(f, "%d %d", nl, nc);

	for (i = 0; i < *nl; i++)
		for (j = 0; j < *nc; j++){
			fscanf(f, "%d", &matriz[i][j]);
		}
		fclose(f);
	return 1;
}

void processa (FILE* f, char fn[], int matriz[][MAXC], int nl, int nc){
	int i, j;

	fprintf(f, "%s\n", fn);

	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++) {
			fprintf(f, "%5d", matriz[i][j]);
		}
		fprintf(f, "\n");
	}
}

int main (){
	FILE *f, *frelat;
	int matriz[MAXL][MAXC], nl , nc;
	char fn[MAX];

	if(!(f = fopen("matrizes.txt", "r"))) return 1;
	if(!(frelat = fopen("retat.txt", "w"))) return 2;

	while(!feof(f)){
		fscanf(f, "%[^\n]%*c", &fn);

		if(loadmat(fn, matriz, &nl, &nc)){
			processa(frelat, fn, matriz, nl, nc);
		} else {
			fprintf(frelat, "%s ARQUIVO NAO EXISTENTE\n", fn);
		}
	}
	fclose(f);
	fclose(frelat);
	system("PAUSE");

	return 0;
}
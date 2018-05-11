#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 256
#define MAXROW 26
#define MAXCOL 26

#define MINEPROBABILITY 0.4

void inicializarCampoRevelado(int campo[MAXROW][MAXCOL], int nRow, int nCol);
void printarCampo(int campo[MAXROW][MAXCOL], int nRow, int nCol);
void printarGraphics(int campo[MAXROW][MAXCOL], int nRow, int nCol);
void criarCampo(int campo[MAXROW][MAXCOL], int nRow, int nCol);

int revelar(int campoEscondido[][MAXCOL], int campoRevelado[][MAXCOL], int nRow, int nCol, int row, int col);
int revelarVizinhos(int campoEscondido[][MAXCOL], int campoRevelado[][MAXCOL], int nRow, int nCol, int row, int col);

void lerDims(int* nRow, int* nCol);

int abs(int a);

int main(int argc, char const *argv[]) {
	int campoEscondido[MAXROW][MAXCOL], nRow, nCol;
	int campoRevelado[MAXROW][MAXCOL];

	char letter;
	int number, gameState;

	lerDims(&nRow, &nCol);

	criarCampo(campoEscondido, nRow, nCol);
	inicializarCampoRevelado(campoRevelado, nRow, nCol);

	printarCampo(campoEscondido, nRow, nCol);
	printarGraphics(campoRevelado, nRow, nCol);

	gameState = 0;
	while(!gameState) {
		fprintf(stdout, "Digite a coordenada a ser revelada: ");
		fscanf(stdin, "%d%c", &number, &letter);

		gameState = revelar(campoEscondido, campoRevelado, nRow, nCol, number-1, letter-'A');

		printarGraphics(campoRevelado, nRow, nCol);
	}

	if(gameState > 0) {
		fprintf(stdout, "---\nYOU WON!\n---\n");
	} else {
		fprintf(stdout, "---\nGAME OVER!\n---\n");
	}

	system("PAUSE");
	return 0;
}

void lerDims(int* nRow, int* nCol) {
	fprintf(stdout, "Digite o numero de linhas do campo: ");
	fscanf(stdin, "%d%*c", nRow);
	fprintf(stdout, "Digite o numero de colunas do campo: ");
	fscanf(stdin, "%d%*c", nCol);
}

void criarCampo(int campo[MAXROW][MAXCOL], int nRow, int nCol) {
	int i, j;

	for (i = 0; i < nRow; ++i) {
		for (j = 0; j < nCol; ++j) {
			campo[i][j] = -((rand() / (double)RAND_MAX) < MINEPROBABILITY);
		}
	}

}

void printarCampo(int campo[MAXROW][MAXCOL], int nRow, int nCol) {
	int i, j;

	for (i = 0; i < nCol; ++i) {
		fprintf(stdout, "__%c", 'A'+i);
	}
	fprintf(stdout, "_\n");

	for (i = 0; i < nRow; ++i) {

		for (j = 0; j < nCol; ++j) {
			fprintf(stdout, "%3d", campo[i][j]);
		}
		fprintf(stdout, " |%d\n", i+1);
	}
}

void printarGraphics(int campo[MAXROW][MAXCOL], int nRow, int nCol) {
	int i, j;
	char c;

	system("cls");

	fprintf(stdout, "  %c",218);

	for (i = 0; i < nCol; ++i) {
		fprintf(stdout, "%c%c", 196, 'A'+i);
	}
	fprintf(stdout, "%c%c\n", 196, 191);

	for (i = 0; i < nRow; ++i) {

		fprintf(stdout, "%2d%c", i+1,179);

		for (j = 0; j < nCol; ++j) {
			c = (campo[i][j] == -2) ? 254 : '0'+campo[i][j];

			fprintf(stdout, " %c", c);
		}
		fprintf(stdout, " %c%-2d\n", 179, i+1);
	}

	fprintf(stdout, "  %c", 192);

	for (i = 0; i < nCol; ++i) {
		fprintf(stdout, "%c%c", 196, 'A'+i);
	}
	fprintf(stdout, "%c%c\n", 196, 217);
}

void inicializarCampoRevelado(int campo[MAXROW][MAXCOL], int nRow, int nCol) {
	int i, j;

	for (i = 0; i < nRow; ++i) {
		for (j = 0; j < nCol; ++j) {
			campo[i][j] = -2;
		}
	}

}

int revelarVizinhos(int campoEscondido[][MAXCOL], int campoRevelado[][MAXCOL], int nRow, int nCol, int row, int col) {
	int i, j, revelados;

	if(campoEscondido[row][col] != -1) campoRevelado[row][col] = 0;

	revelados = 0;
	for (i = row-1; i < row+2; ++i) {
		for (j = col-1; j < col+2; ++j) {
			if(i >= 0 && i < nRow && j >= 0 && j < nCol) {
				if(campoRevelado[i][j] == -2) {
					if(campoEscondido[i][j] == -1) campoRevelado[row][col]++;

					if(campoEscondido[i][j] == 0 && abs(row-i) + abs(col-j) == 1) {
						revelarVizinhos(campoEscondido, campoRevelado, nRow, nCol, i, j);
						revelados++;
					}
				}
			}
		}
	}
	return revelados;
}

int revelar(int campoEscondido[][MAXCOL], int campoRevelado[][MAXCOL], int nRow, int nCol, int row, int col) {

	if(col >= 0 && col < nRow && row >= 0 && row < nCol) {
		if(campoEscondido[row][col] == -1) return -1;

		revelarVizinhos(campoEscondido, campoRevelado, nRow, nCol, row, col);
	}

	return 0;
}

int abs(int a) {
	return (a > 0) ? a : -a;
}
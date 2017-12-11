#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAXROW 256
#define MAXCOL 256
#define MAX 256

int loadalunos(FILE* f, char nomes[MAXROW][MAXCOL], int* qnomes, float notas[MAXROW][MAXCOL], int qnotas) {
	int i, j;

	for (i = 0; !feof(f); ++i) {
		fscanf(f, "%[^\n]%*c", nomes[i]);
		//fprintf(stderr, "-- %s --\n", nomes[i]);

		for (j = 0; j < qnotas; ++j) {
			fscanf(f, "%f%*c", &notas[i][j]);
			//fprintf(stderr, "%f\n", notas[i][j]);
		}
	}

	*qnomes = i - 1;

	//fprintf(stderr, "%d %d\n", *qnomes, qnotas);

	return 1;
}

int loadpesos(FILE* f, float lstpesos[MAXROW][MAXCOL], int qnotas, int* qpesos) {
	int i, j;

	for (i = 0; !feof(f); ++i) {

		for (j = 0; j < qnotas; ++j) {
			fscanf(f, "%f", &lstpesos[i][j]);
			//fprintf(stderr, "%f\n", lstpesos[i][j]);
		}
	}
	*qpesos = i;

	//fprintf(stderr, "%d\n", *qpesos);

	return 1;
}

void printtabs(FILE* f, float num) {
	int i;

	for (i = 0; i < num; ++i) {	
		fprintf(f, "\t");
	}
}

void fprintftab(FILE* f, char str[]) {
	int i;

	fprintf(f, "%s", str);
	printtabs(f, 10.75 - (strlen(str)/4.0));
}

void printheader(FILE* f, int qnotas, int qmedias) {
	int i;

	printtabs(f, 8);
	fprintf(f, "Simulação com várias médias\n\n");

	printtabs(f, 12);
	for (i = 0; i < qnotas; ++i)
		fprintf(f, " N%d  ", i+1);
	for (i = 0; i < qmedias; ++i)
		fprintf(f, " M%d  ", i+1);
	fprintf(f, "\n");
}


int alunospassados(float medias[], int qalunos) {
	int i, passados;

	passados = 0;
	for (i = 0; i < qalunos; ++i) {
		//fprintf(stderr, "media = %f\n", medias[i]);
		if(medias[i] >= 7) passados++;
	}

	return passados;
}

int bestmedia(float lstmedias[MAXROW][MAXCOL], int qmedias, int qalunos) {
	int i, best, bestind, current;

	best = bestind = -1;
	for (i = 0; i < qmedias; ++i) {
		current = alunospassados(lstmedias[i], qalunos);
		fprintf(stderr, "passados = %d\n", current);

		if(current > best) {
			best = current;
			bestind = i;
		}
	}
	fprintf(stderr, "best passado[%d] = %d\n", bestind+1, best);

	return bestind;
}

int simula(FILE* f, char lstnomes[MAXROW][MAXCOL], int qnomes, float lstnotas[MAXROW][MAXCOL], int qnotas, float lstpesos[MAXROW][MAXCOL], int qpesos, float lstmedias[MAXROW][MAXCOL]) {
	int i, j, k;
	float soma;

	printheader(f, qnotas, qpesos);

	for (i = 0; i < qnomes; ++i) {
		fprintf(f, "%02d - ", i+1);
		fprintftab(f, lstnomes[i]);
		//fprintf(f, "%s ", lstnomes[i]);

		for (j = 0; j < qpesos; ++j) {


			soma = 0;
			for (k = 0; k < qnotas; ++k) {
				soma += lstpesos[j][k]*lstnotas[i][k];
			}
			lstmedias[i][j] = soma;
		}

		for (j = 0; j < qnotas; ++j) {
			fprintf(f, "%4.1f ", lstnotas[i][j]);
		}
		for (j = 0; j < qpesos; ++j) {
			fprintf(f, "%4.1f ", lstmedias[i][j]);
		}

		fprintf(f, "\n");
	}

	return 1;
}

int final(FILE* f, char lstnomes[MAXROW][MAXCOL], int qnomes, float lstnotas[MAXROW][MAXCOL], int qnotas, float lstmedias[MAXROW][MAXCOL], int qmedias, float lstpesos[MAXROW][MAXCOL]) {
	int i, j, bestmediaind;

	bestmediaind = bestmedia(lstmedias, qmedias, qnomes);

	// TODO: printar os paranauê

	for (i = 0; i < qnomes; ++i) {
		// printa nome

		for (j = 0; j < qnotas; ++j) {
			// printa notas
		}

		for (j = 0; j < qmedias; ++j) {
			// printa medias
		}

	}


	return 1;
}

int main(int argc, char const *argv[]) {
	FILE *falunos, *fpesos, *fsimula, *ffinal;
	char lstnomes[MAXROW][MAXCOL];
	float lstnotas[MAXROW][MAXCOL], lstpesos[MAXROW][MAXCOL], lstmedias[MAXROW][MAXCOL];
	int qnomes, qnotas, qpesos;

	qnotas = 4;

	if(!(falunos = fopen("Alunos.txt", "r"))) return 0;
	if(!(fpesos = fopen("Pesos.txt", "r"))) return 0;
	if(!(fsimula = fopen("simula.txt", "w"))) return 0;
	if(!(ffinal = fopen("final.txt", "w"))) return 0;

	loadalunos(falunos, lstnomes, &qnomes, lstnotas, qnotas);
	loadpesos(fpesos, lstpesos, qnotas, &qpesos);

	simula(fsimula, lstnomes, qnomes, lstnotas, qnotas, lstpesos, qpesos, lstmedias);

	final(ffinal, lstnomes, qnomes, lstnotas, qnotas, lstmedias, qpesos, lstmedias);

	fclose(falunos);
	fclose(fpesos);
	fclose(fsimula);
	fclose(ffinal);

	return 0;
}
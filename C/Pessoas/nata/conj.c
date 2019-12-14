//ajustes_bacon
//o do consumo de luz lá e os caralhos

#include <math.h>
#include <stdio.h>

#define MAX_VAL 100 // Número máximo de medidas
#define MAX_CON 200 // Número máximo de conjuntos

typedef struct {
	char titulo[100]; // Título do conjunto de medidas
	float x[MAX_VAL]; // Medidas x
	float y[MAX_VAL]; // Medidas y
	float media_x;
	float dp_x;
	float media_y;
	float dp_y;
	int n; // Quantidade de valores
} tConjunto;

typedef struct {
	tConjunto vet[MAX_CON]; // Vetor de conjuntos
	int n; // Número de conjuntos
} tConjuntos;

void load(tConjuntos* conjuntos) {
	FILE* file = fopen("ajuste.txt", "r");

	char chr;
	int i, j, n;

	// Lê cada conjunto até o fim do arquivo ou até o número máximo de conjuntos
	for (i=0; i<MAX_CON && !feof(file); i++) {

		fscanf(file, "%[^\n]%*c", conjuntos->vet[i].titulo);

		if (feof(file)) {
			// Não conta este conjunto pois o arquivo já chegou ao fim
			break;
		}

		chr = '\0'; // Inicializa chr com um valor diferente de '\n'
		for (j=0; chr != '\n'; j++) { // Lê um número e um caractere até encontrar um '\n'
			fscanf(file, "%f%c", &conjuntos->vet[i].x[j], &chr);
		}

		// Número de valores lidos permanece em j
		conjuntos->vet[i].n = j;
		n = j;

		for (j=0; j<n; j++) {
			fscanf(file, "%f%*c", &conjuntos->vet[i].y[j]);
		}
	}

	// A quantidade de conjuntos lidos permanece em i
	conjuntos->n = i;

	// Fecha o arquivo
	fclose(file);
}

void calcConjunto(tConjunto* conjunto) {

	// Copia os valores do conjunto pra variáveis locais
	int n = conjunto->n;
	float* x = conjunto->x;
	float* y = conjunto->y;

	int i, j;

	// Calcula o somatório dos vetores
	float total_x = 0;
	float total_y = 0;
	for (i=0; i<n; i++) {
		total_x += x[i];
		total_y += y[i];
	}

	// Calcula as médias
	conjunto->media_x = total_x/n;
	conjunto->media_y = total_y/n;

	// Calcula o desvio padrão
	total_x = 0;
	total_y = 0;
	float dif;
	for (i=0; i<n; i++) {

		dif = x[i] - conjunto->media_x;
		total_x += dif*dif;

		dif = y[i] - conjunto->media_y;
		total_y += dif*dif;
	}
	conjunto->dp_x = sqrt(total_x/(n - 1));
	conjunto->dp_y = sqrt(total_y/(n - 1));

}

void calcConjuntos(tConjuntos* conjuntos) {
	int i;
	for (i=0; i<conjuntos->n; i++) {
		calcConjunto(&conjuntos->vet[i]);
	}
}

void geraSaida(tConjuntos* conjuntos) {
	int i;

	// Cria o arquivo de saídas
	FILE* file = fopen("saida.txt", "w");

	fprintf(file, "NUM %-30s     X/MED      X/DP     X/MED      X/DP\n", "Nome");
	for (i=0; i<conjuntos->n; i++) {

		// Cria um ponteiro do cojunto atual numa variável local para facilitar o código
		tConjunto* conjunto = &conjuntos->vet[i];

		fprintf(file, "%3d %-30s ", i + 1, conjunto->titulo);
		fprintf(file, "%9.1f ", conjunto->media_x);
		fprintf(file, "%9.1f ", conjunto->dp_x);
		fprintf(file, "%9.1f ", conjunto->media_y);
		fprintf(file, "%9.1f\n", conjunto->dp_y);
	}

	// Fecha o arquivo
	fclose(file);
}

int main() {
	tConjuntos conjuntos;
	load(&conjuntos);
	calcConjuntos(&conjuntos);
	geraSaida(&conjuntos);
}
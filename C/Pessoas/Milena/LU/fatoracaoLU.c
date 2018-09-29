#include <stdio.h>
#include <stdlib.h>
#include "eliminacaogauss.h"

double **criarMatriz(int linhas, int colunas) {
	double **novaMatriz = (double **)malloc(sizeof(double**)*linhas);

	int i, j;
	for(i = 0; i < linhas; i++) {
		novaMatriz[i] = (double*)malloc(sizeof(double)*colunas);
		for(j = 0; j < colunas; ++j) {
			novaMatriz[i][j] = 0;
		}
	}

	return novaMatriz;
}

void scanMatriz(double **matriz, int linhas, int colunas) {
    int i, j;
    printf("Digite os valores:\n");
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
        	printf("matriz[%d][%d] = ", i, j);
            scanf(" %lf", &matriz[i][j]);
        }
    }
}

double *criarVetor(int tamanho) {
	double *novoVetor = (double *)malloc(sizeof(double)*tamanho);
	int i;

	for(i = 0; i < tamanho; ++i) {
		novoVetor[i] = 0;
	}

	return novoVetor;
}

void scanVetor(double vetor[], int tamanho) {
	int i;
	for(i = 0; i < tamanho; ++i) {
		printf("vetor[%d] = ", i);
		scanf("%lf", &vetor[i]);
	}
}

void printMatriz(double **matriz, int linhas, int colunas) {
    int i, j;
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("%lf\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void printVetor(double vetor[], int tamanho) {
	int i;
	for(i = 0; i < tamanho; ++i) {
		printf("%lf\t", vetor[i]);
	}
	printf("\n");
}

double *calcularVetorY(double **matrizU, double *vetorB, double **matrizL, int ordem) {
	double *vetorY = criarVetor(ordem);
	double soma;
	int i, j;

	vetorY[0] = vetorB[0]/matrizL[0][0];

	for(i = 1; i < ordem; ++i) {
		soma = 0;
		for(j = 0; j < i+1; ++j) {
			soma += matrizL[i][j]*vetorY[j];
		}
		vetorY[i] = (vetorB[i] - soma)/matrizL[i][i];
	}

	return vetorY;
}

double *calcularVetorX(double **matrizU, double *vetorY, int ordem) {
	double *vetorX = criarVetor(ordem);
	double soma;
	int i, j;

    vetorX[ordem-1] = vetorY[ordem-1]/matrizU[ordem-1][ordem-1];

	for(i = ordem-2; i >= 0; --i) {
		soma = 0;
		for(j = i+1; j < ordem; ++j) {
			soma += matrizU[i][j]*vetorX[j];
		}
		vetorX[i] = (vetorY[i] - soma)/matrizU[i][i];
	}

	return vetorX;
}

void calcularLowerUpper(double **matrizA, double **matrizL, int ordem) {
	int i, j, k;
	int aux_pivo = 0;
	double *aux, pivo;

	for(i = 0; i < ordem; ++i) {
		matrizL[i][i] = 1;
	}

	for(k = 0; k < ordem-1; k++) {
		for(i = k + 1; i < ordem; i++) {
			pivo = matrizL[i][k] = matrizA[i][k]/matrizA[k][k];
			for(j = k + 1; j <= ordem; j++) {
				matrizA[i][j] -= pivo*matrizA[k][j];
			}
			matrizA[i][k] = 0;
		}
	}
}

int main() {
	int ordem;
	double **matrizA, **matrizLower;
	double *vetorB, *vetorY, *vetorX;

	printf("Digite a ordem da matriz: ");
	scanf("%d", &ordem);
	printf("\n");

	matrizA = criarMatriz(ordem, ordem);
	matrizLower = criarMatriz(ordem, ordem);
	vetorB = criarVetor(ordem);

	scanMatriz(matrizA, ordem, ordem);

	printf("\n");
	printMatriz(matrizA, ordem, ordem);
	calcularLowerUpper(matrizA, matrizLower, ordem);

	printf("\nmatriz Upper:\n");
	printMatriz(matrizA, ordem, ordem);
	printf("\nmatriz Lower:\n");
	printMatriz(matrizLower, ordem, ordem);

	do {
		/// scan de vetor B
		printf("\nDigite um vetor B:\n");
		scanVetor(vetorB, ordem);

		printVetor(vetorB, ordem);

		/// calcula vetor Y
		vetorY = calcularVetorY(matrizA, vetorB, matrizLower, ordem);

		printf("\nVetorY:\n");
		printVetor(vetorY, ordem);

		/// calcula vetor X
		vetorX = calcularVetorX(matrizA, vetorY, ordem);

		printf("\nVetorX:\n");
		printVetor(vetorX, ordem);
		printf("---------------\n");
	} while(1);

	return 0;
}

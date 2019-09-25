#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

/*!
	@brief escaneia da entrada padrão matriz de elementos A
	@param ordem, ordem da matriz a ser lida
	@return matriz inicializada
	@precondition nenhuma
	@postcondition matriz é inicializada preenchida e retornada
*/
Matriz *scanMatrizA(int ordem);

/*!
	@brief escaneia da entrada padrão matriz de elementos B
	@param ordem, ordem da matriz a ser lida
	@return matriz inicializada
	@precondition nenhuma
	@postcondition matriz é inicializada preenchida e retornada
*/
Matriz *scanMatrizB(int ordem);

/*!
	@brief resolve sistema linear formado pelas matrizes A e B \
	método de Gauss-Jacobi
	@param AB, matriz extendida formada por A e B
	@param ordem, quantidade de incógnitas a serem resolvidas
	@param erro, erro máximo de condição nas iterações
	@param maxK, iterações máximas permitidas
	@precondition nenhuma
	@postcondition é printado na saida padrão o valor encontrado \
	das incógnitas
*/
void itrGaussJacobi(Matriz *AB, int ordem, double erro, int maxK);

/*!
	@brief função auxiliar para printar o valor das incógnitas
	@param resultado, vetor contendo o valor das incógnitas
	@param tamanho, tamanho do vetor
	@precondition nenhuma
	@postcondition nenhuma
*/
void printResultado(double resultado[], int tamanho);

int main(void) {
	/// Matrizes utilizadas nos cálculos
	Matriz *matrizA, *matrizB, *matrizAB;
	double erro;
	int ordem, iteracoes;

	/// ordem é lida da entrada padrão
	printf("\nDigite a ordem da matriz A: \n");
	scanf("%d", &ordem);
	printf("\nMatriz de ordem %d\n", ordem);

	/// scan das matrizes A e B
	matrizA = scanMatrizA(ordem);
	matrizB = scanMatrizB(ordem);

	/// extende matriz A e B
	matrizAB = matrizExtendida(matrizA, matrizB);

	printf("\nMatriz extendida:\n");
	printMatriz(matrizAB);

	/// lê da entrada padrão o erro maximo
	printf("\nDigite o erro maximo: ");
	scanf("%lf", &erro);

	/// lê da entrada padrão o maximo de iterações
	printf("\nDigite o numero maximo de iteracoes: ");
	scanf("%d", &iteracoes);

	/// resolve sistema linear produzido pela matriz se possível
	itrGaussJacobi(matrizAB, ordem, erro, iteracoes);

	printf("Pressione qualquer tecla para sair do programa.\n");
	getc(stdin);

	/// libera memória das matrizes utilizadas nos cálculos
	freeMatriz(matrizA);
	freeMatriz(matrizB);
	freeMatriz(matrizAB);

	return 0;
}

Matriz *scanMatrizA(int ordem) {
	Matriz *A = NULL;

	/// uma matriz é lida com tamanho de ordem
	printf("\nDigite matiz A\n");
	A = scanMatriz(ordem, ordem);

	/// matriz lida é printada na saida padrão
	printf("\nMatriz lida:\n");
	printMatriz(A);

	return A;
}

Matriz *scanMatrizB(int ordem) {
	printf("\nDigite matriz B\n");
	Matriz *B = scanMatriz(ordem, 1);

	printf("\nMatriz lida:\n");
	printMatriz(B);

	return B;
}

void itrGaussJacobi(Matriz *matrizAB, int ordem, double erro, int maxK) {
	int i, j, k = maxK;
	double maxErro;
	double numerador, denominador, somatoria;
	/// inicializa matrizes auxiliares
	double vetorXProx[ordem], vetorXAtual[ordem];

	for(i = 0; i < ordem; ++i) {
		vetorXProx[i] = vetorXAtual[i] = 0;
	}

	printf("\nResolvendo por Gauss-Jacobi...\n");
	/// iteração sobre resultados
	printf("xi		soma	mii\n");
	do {
		/// para cada linha na matriz
		for(i = 0; i < ordem; ++i) {
			/// faz somatória do numerador
			for(j = somatoria = 0; j < ordem; ++j) {
				if(j != i) {
					somatoria += matrizAB->m[i][j]*vetorXAtual[j];
				}
			}
			/// calcula numerador (xi - sum)
			numerador = matrizAB->m[i][ordem] - somatoria;

			/// calcula denominador
			denominador = matrizAB->m[i][i];

			/// armazena resultados e calcula erro
			vetorXProx[i] = numerador/denominador;

			printf("%lf		%lf		%lf\n", matrizAB->m[i][ordem], somatoria, matrizAB->m[i][i]);
		}

		for(j = maxErro = 0; j < ordem; ++j) {
			/// valor absoluto do maior erro
			if(fabs(vetorXProx[j]-vetorXAtual[j]) > maxErro) {
				maxErro = fabs(vetorXProx[j]-vetorXAtual[j]);
			}
			vetorXAtual[j] = vetorXProx[j];
		}

	} while(maxErro > erro && --k);

	if(maxErro > erro) {
		printf("Divergencia dos resultados nas iteracoes\n");
	}

	/// printa resultado final
	printResultado(vetorXProx, ordem);
	printf("|Erro| = %g\n", maxErro);
}

void printResultado(double resultado[], int tamanho) {
	int i;

	/// printa vetor resultado
	printf("\nVetor X:\n");
	for(i = 0; i < tamanho; ++i) {
		printf("\tx%d = %lf\n", i+1, resultado[i]);
	}
}

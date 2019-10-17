#include <stdio.h>
#include <stdlib.h>

void diferenca(double conjX[10], double conjY[10], double conjD[10], int* tamConj) {
	int i, j, verifica;
	(*tamConj) = 0;

	for (i = 0; i < 10; ++i) {
		verifica = 0;

		for (j = 0; j < 10 && !verifica; ++j) {
			if(conjX[i] == conjY[j]) {
				verifica = 1;
			}
		}

		if(verifica == 0)
			conjD[(*tamConj)++] = conjX[i];
	}
}

void ler10num(double conj[10], char *conjNome) {
	int i, p, tamConj;
	double num;

	tamConj = 0;

	printf("Digite uma sequencia de 10 numeros reais para o vetor %s:\n", conjNome);

	while (tamConj < 10){
		p = 0;

		printf("Este e o numero %d faltam %d\n", tamConj+1, 9-tamConj);
		scanf("%lf", &num);

		for (i = 0; i < tamConj; i++){
			if(num == conj[i]) {
				p = 1;
			}
		}

		if(p == 0) {
			conj[tamConj++] = num;
		} else {
			printf("Voce digitou o mesmo numero! Por favor, digite outro:\n");
		}
	}

	for (i = 0; i < 10; i++){
		printf("%.2lf ", conj[i]);
	}

	printf("\n");
}


void carregaConjunto (double X[10], double Y[10])
{
	ler10num(X, "X");
	ler10num(Y, "Y");
}

void imprimeConjunto(double conj[10], int tam) {
	int i;

	printf("[");
	for (i = 0; i < tam; ++i) {
		printf("%g", conj[i]);
		if(i+1 != tam)
			printf(", ");
	}
	printf("]\n");
}

int main()
{
	double X[10], Y[10], D[10];
	int tamConjD;

	carregaConjunto(X, Y);
	diferenca(X, Y, D, &tamConjD);

	imprimeConjunto(X, 10);
	imprimeConjunto(Y, 10);
	imprimeConjunto(D, tamConjD);

	return 0;
}

#include <stdio.h>

int diferenca(double conjX[10], double conjY[10], double conjD[10]);

void imprimeConjunto(double conj[10], int tam);

int main(int argc, char const *argv[]) {
	double conjX[10] = {1.5, 5.8, 6.1, 2.2, 8.1, 4.8, 7.5, 2.1, 6.9};
	double conjY[10] = {1.5, 5.9, 6.6, 2.1, 8, 4.8, 9, 15.2, 7.5, 0};
	double conjD[10];
	int conjDTam;

	conjDTam = diferenca(conjX, conjY, conjD);

	imprimeConjunto(conjD, conjDTam);

	return 0;
}

int diferenca(double conjX[10], double conjY[10], double conjD[10]) {
	int i, j, contains;
	int conjDTam = 0;

	/// Para cada elemento em X
	for (i = 0; i < 10; ++i) {
		contains = 0;
		/// Para cada elemento em Y
		for (j = 0; j < 10 && !contains; ++j) {
			/// Se elemento de Y existe em X
			if(conjX[i] == conjY[j]) {
				/// Seta a flag
				contains = 1;
			}
		}

		/// Se não contém
		if(!contains)
			/// Adiciona em D
			conjD[conjDTam++] = conjX[i];
	}

	return conjDTam;
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
#include <stdio.h>

void printaQuadrado(int tamanho, char c) {
	int linha, coluna;

	for(linha = 1; linha <= tamanho; ++linha) {
		for(coluna = 1; coluna <= tamanho; ++coluna) {
			if(linha == 1 || linha == tamanho || coluna == 1 || coluna == tamanho) {
				printf("%c", c);
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void) {
	int tamanho;
	char c;

	scanf("%d %c", &tamanho, &c);
	while(tamanho != -1) {
		printaQuadrado(tamanho, c);

		scanf("%d %c", &tamanho, &c);
	}

	return 0;
}
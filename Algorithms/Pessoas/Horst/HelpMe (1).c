#include <stdio.h>
#define maxl 100
#define maxc 100

void lerMatriz (int matriz[][maxc], int linha, int coluna){
	int i,j;

	for ( i = 0; i < linha; ++i)
		for (j = 0; j < coluna; ++j)
			scanf("%d", &matriz[i][j]);
}

void printMatriz (int matriz [][maxc], int linha, int coluna){
	int i, j;

	for (i = 0; i < linha; i++){
		for (j = 0; j < coluna; j++)
			printf("%4d", matriz[i][j]);
	printf("\n");
	}
}

int somaMatriz (int matriz[][maxc], int linha, int coluna){
	int i, j, soma = 0;

	for (i = 0; i < linha; i++)
		for (j = 0; j < coluna; ++j)
		soma += matriz [i][j];

	return soma;
}

int main (){
	int matriz [maxl][maxc], linha, coluna;

	scanf("%d %d", &linha, &coluna);
	while (linha||coluna){
		lerMatriz (matriz, linha, coluna);
		printMatriz (matriz, linha, coluna);
		printf("%d\n", somaMatriz(matriz, linha, coluna));
		scanf("%d %d", &linha, &coluna);
	}
	return 0;
}
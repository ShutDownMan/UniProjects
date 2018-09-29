#include "matriz.h"

/*!
	@brief aloca memória e inicializa campos da matriz
	@param linhas, quantidade de linhas da matriz
	@param colunas, quantidade de colunas da matriz
	@return matriz alocada e inicializada
	@precondition nenhuma
	@postcondition matriz é alocada, inicializada e retornada
*/
Matriz *inicializaMatriz(int linhas, int colunas) {
	/// aloca memória para estrutura de controle da matriz
	Matriz *novaMatriz = (Matriz *)malloc(sizeof(Matriz));

	/// aloca espaço para o vetor de linhas da matriz de tamanho 'linhas' \
	(vetor de vetores)
	novaMatriz->m = (double **)malloc(sizeof(double *)*linhas);

	/// para cada linha na matriz
	for(int i = 0; i < linhas; ++i) {
		/// aloca espaço para um vetor de tamanho 'colunas'
		novaMatriz->m[i] = (double *)malloc(sizeof(double)*colunas);
		for(int j = 0; j < colunas; ++j) {
			novaMatriz->m[i][j] = 0;
		}
	}

	/// inicializa campos de ordem da matriz
	novaMatriz->tamanhoLinhas = linhas;
	novaMatriz->tamanhoColunas = colunas;

	/// retorna matriz alocada e inicializada
	return novaMatriz;
}

/*!
	@brief escaneia matriz da entrada padrão
	@param linhas, quantidade de linhas da matriz
	@param colunas, quantidade de colunas da matriz
	@return matriz inicializada e preenchida
	@precondition nenhuma
	@postcondition matriz é alocada, inicializada, preenchida e retornada
*/
Matriz *scanMatriz(int linhas, int colunas) {
	/// inicializa estutura de controle com parametros passados
	Matriz *novaMatriz = inicializaMatriz(linhas, colunas);
	int i, j;

	/// para cada linha na matriz
	for(i = 0; i < linhas; ++i) {
		/// para cada coluna na matriz
		for(j = 0; j < colunas; ++j) {
			/// scaneia o elemento atual
			printf("m%d%d = ", i+1, j+1);
			scanf(" %lf", &novaMatriz->m[i][j]);
		}
	}

	/// retorna matriz lida
	return novaMatriz;
}

/*!
	@brief printa matriz na saída padrão
	@param matriz, matriz a ser printada
	@precondition nenhuma
	@postcondition nenhuma
*/
void printMatriz(Matriz *matriz) {
	int i, j;

	/// para cada linha na matriz
	for(i = 0; i < matriz->tamanhoLinhas; ++i) {
		/// para cada coluna na matriz
		printf("%c ", 179); //< │
		for(j = 0; j < matriz->tamanhoColunas; ++j) {
			/// printa elemento atual
			printaElemento(matriz->m[i][j]);
		}
		printf("%c\n", 179); //< │
	}
}

/*!
	@brief função auxiliar de scanMatriz para printar único elemento
	@param num, elemento a ser printado
	@precondition nenhuma
	@postcondition nenhuma
*/
void printaElemento(double num) {
	int precisao = 5;

	/// se elemento atual for negativo
	if(num < 0) {
		/// diminui precisão no print
		precisao--;
	}

	/// se número é diferente de 0
	if(num != 0)
		precisao -= (int)log10(num); //< diminui precisão no print
	/// se precisão ter valor negativo, se torna 0
	precisao = (precisao > 0) ? precisao : 0;

	/// printa elemento na saida padrão
	printf("%.*lf ", precisao, num);
}

/*!
	@brief cria matriz que extende matriz A com matriz B e a retorna
	@param matrizA, matriz base
	@param matrizB, extensão
	@return cria matriz que comporta matriz A e B
	@precondition número de linhas em A tem que ser igual a B
	@postcondition matriz é criada, alocada e retornada
*/
Matriz *matrizExtendida(Matriz *matrizA, Matriz *matrizB) {
	/// matriz tem tamanho de linhas de A e tamanho de colunas de A+B
	Matriz *extendida = inicializaMatriz(matrizA->tamanhoLinhas, matrizA->tamanhoColunas+matrizB->tamanhoColunas);
	int i, j;

	/// para cada linha em matrizA
	for(i = 0; i < matrizA->tamanhoLinhas; ++i) {
		/// para cada coluna em matrizA
		for(j = 0; j < matrizA->tamanhoColunas; ++j) {
			/// atribui para matriz extendida o valor do elemento em A
			extendida->m[i][j] = matrizA->m[i][j];
		}
	}

	/// para cada linha em matrizB
	for(i = 0; i < matrizB->tamanhoLinhas; ++i) {
		/// para cada coluna em matrizB
		for(j = 0; j < matrizB->tamanhoColunas; ++j) {
			/// atribui para matriz extendida o valor do elemento em matrizB
			extendida->m[i][j+matrizA->tamanhoColunas] = matrizB->m[i][j];
		}
	}

	return extendida;
}

/*!
	@brief transforma matriz em uma diagonalmente dominante
	@param matriz, matriz a ser modificada
	@param ordem, ordem da matriz
	@return matriz passada
	@precondition nenhuma
	@postcondition matriz é transformada em matriz diagonalmente dominante
*/
Matriz *diagonalmenteDominante(Matriz *matriz, int ordem) {
	int i, j;
	int dominantes[ordem];

	/// para cada linha na matriz
	for(i = 0; i < ordem; ++i) {
		dominantes[i] = i;
		/// procura pelo valor dominante
		for(j = 0; j < ordem; ++j) {
			if(fabs(matriz->m[i][j]) > fabs(matriz->m[i][dominantes[i]])) {
				dominantes[i] = j;
			}
		}
	}

	/// ordena linhas pelos valores dominantes em cada linha
	ordenarPonteirosPorPosicoes(dominantes, matriz->m, ordem);

	return matriz;
}

/*!
	@brief função auxiliar de diagonalmenteDominante
	@param posicoes, armazena as posições dominantes de cada linha
	@param matriz, matriz a ser modificada
	@param tamanho, quantidade de linhas da matriz
	@precondition nenhuma
	@postcondition matriz é transformada em matriz diagonalmente dominante
*/
void ordenarPonteirosPorPosicoes(int posicoes[], double *matriz[], int tamanho) {
	int i, j, pos;
	double auxVal, *auxPtr;

	/// para cada linha da matriz
	for(i = 0; i < tamanho; i++) {
		/// posição inicial é invalida
		pos = -1;
		/// para cada elemento no vetor de posições
		for(j = 0; j < tamanho; j++) {
			/// se o elemento dominante se iguala a linha atual
			if(posicoes[j] == i) {
				/// se posição armazenada é invalida ou \
				valor na posição atual é maior que posição escolhida
				if(pos < 0 || (fabs(matriz[i][posicoes[j]]) > fabs(matriz[j][posicoes[pos]]))) {
					/// posição é escolhida
					pos = j;
				}
			}
		}
		/// se posição é invalida, nenhuma troca é feita
		if(pos < 0) pos = i;
		/// troca posição atual de i com posição escolhida
		auxVal = posicoes[i]; posicoes[i] = posicoes[pos]; posicoes[pos] = auxVal;
		auxPtr = matriz[i]; matriz[i] = matriz[pos]; matriz[pos] = auxPtr;
	}
}

/*!
	@brief libera memória ultilizada pela matriz
	@param matriz, matriz a ser liberada
	@precondition nenhuma
	@postcondition memória da matriz é liberada
*/
void freeMatriz(Matriz *matriz) {
	/// para cada linha na matriz
	for(int i = 0; i < matriz->tamanhoLinhas; ++i) {
		/// libera memória do vetor
		free(matriz->m[i]);
	}
	/// libera vetor de colunas
	free(matriz->m);
	/// libera estrutura de controle
	free(matriz);
}
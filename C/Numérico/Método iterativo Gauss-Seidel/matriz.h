#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// estrutura de controle Matriz
typedef struct matriz {
	/// matriz de doubles interna
	double **m;
	/// tamanho de linhas e colunas
	int tamanhoLinhas, tamanhoColunas;
} Matriz;

/*!
	@brief aloca memória e inicializa campos da matriz
	@param linhas, quantidade de linhas da matriz
	@param colunas, quantidade de colunas da matriz
	@return matriz alocada e inicializada
	@precondition nenhuma
	@postcondition matriz é alocada, inicializada e retornada
*/
Matriz *inicializaMatriz(int linhas, int colunas);

/*!
	@brief escaneia da entrada padrão matriz
	@param linhas, quantidade de linhas da matriz
	@param colunas, quantidade de colunas da matriz
	@return matriz inicializada e preenchida
	@precondition nenhuma
	@postcondition matriz é alocada, inicializada, preenchida e retornada
*/
Matriz *scanMatriz(int linhas, int colunas);

/*!
	@brief printa matriz na saída padrão
	@param matriz, matriz a ser printada
	@precondition nenhuma
	@postcondition nenhuma
*/
void printMatriz(Matriz *matriz);

/*!
	@brief função auxiliar de scanMatriz para printar único elemento
	@param num, elemento a ser printado
	@precondition nenhuma
	@postcondition nenhuma
*/
void printaElemento(double num);

/*!
	@brief cria matriz que extende matriz A com matriz B e a retorna
	@param matrizA, matriz base
	@param matrizB, extensão
	@return cria matriz que comporta matriz A e B
	@precondition número de linhas em A tem que ser igual a B
	@postcondition matriz é criada, alocada e retornada
*/
Matriz *matrizExtendida(Matriz *matrizA, Matriz *matrizB);

/*!
	@brief transforma matriz em uma diagonalmente dominante
	@param matriz, matriz a ser modificada
	@param ordem, ordem da matriz
	@return matriz passada
	@precondition nenhuma
	@postcondition matriz é transformada em matriz diagonalmente dominante
*/
Matriz *diagonalmenteDominante(Matriz *matriz, int ordem);

/*!
	@brief função auxiliar de diagonalmenteDominante
	@param posicoes, armazena as posições dominantes em cada linha
	@param ptrs, armazena as linhas da matriz
	@param tamanho, quantidade de linhas da matriz
	@precondition nenhuma
	@postcondition matriz é transformada em matriz diagonalmente dominante
*/
void ordenarPonteirosPorPosicoes(int posicoes[], double *ptrs[], int tamanho);

/*!
	@brief libera memória ultilizada pela matriz
	@param matriz, matriz a ser liberada
	@precondition nenhuma
	@postcondition memória da matriz é liberada
*/
void freeMatriz(Matriz *matriz);

#endif //< MATRIZ_H
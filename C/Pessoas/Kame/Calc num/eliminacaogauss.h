#ifndef ELIMINACAOGAUSS
#define ELIMINACAOGAUSS

/*!
 * \brief imprimeMatriz Imprime a matriz
 * \param m Matriz
 * \param lin Quantidade de linhas
 * \param col Quantidade de colunas
 */
void imprimeMatriz(double **m, int lin, int col);

/*!
 * \brief matriz scaneia os valores
 * \param m
 * \param lin
 * \param col
 */
void matriz(double **m, int lin, int col);

/*!
 * \brief criar aloca memoria para a matriz
 * \param lin
 * \param col
 * \return matriz alocada
 */
double **criar(int lin, int col);

/*!
 * \brief tam_pivo tamanho do triangulo inferior
 * \param ordem
 * \return tamanho
 */
int tam_pivo(int ordem);

/*!
 * \brief elimGauss eliminacao de gauss
 * \param m
 * \param ordem quantidade incognitas
 * \param pivo vetor de pivos utilizados
 */
void elimGauss(double **m, int ordem, double pivo[]);

/*!
 * \brief solucao resolve a eliminacao de gauss, descobre os xs
 * \param m
 * \param ordem
 */
void solucao(double **m, int ordem);

#endif // ELIMINACAOGAUSS


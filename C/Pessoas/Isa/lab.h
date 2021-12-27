#ifndef __LAB_H
#define __LAB_H
#include <stdio.h>
/*
* Abre o arquivo cujo nome eh recebido por parametro ("arquivo") para leitura.
* Retorna um ponteiro para o arquivo aberto.
*/
FILE *abre_arquivo(const char *arquivo);
/*
* Fecha o arquivo recebido por parametro.
* Retorna 0 caso consiga fechar o arquivo, qualquer outro valor caso contrario.
*/
int fecha_arquivo(FILE *arq);
/*
* Le os valores que estao dentro do "arquivo" e retorna um vetor contendo os valores.
* Retorna dentro de "qtd_numeros" a quantidade de números existentes dentro do arquivo lido.
* Caso não for possível ler o arquivo, "qtd_numeros" deve conter ZERO e retornar a constante NULL.
* Se "qtd_numeros" for invalido, a leitura deve ser invalidade e retornar a constante NULL.
*/
double *le_valores(const char *arquivo, unsigned int *qtd_numeros);
/*
* Essa função retorna o maior valor presente no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
*/
double maior(double* valores, unsigned int qtd_numeros);
/*
* Essa função retorna o menor valor presente no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
* */
double menor(double* valores, unsigned int qtd_numeros);
/*
* Essa função retorna a média dos valores presentes no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
*/
double media(double* valores, unsigned int qtd_numeros);
/*
* Essa função retorna o desvio padrão dos valores presentes no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
* */
double desvio(double* valores, unsigned int qtd_numeros);
/*
* Essa função retorna a amplitude(diferença entre o maior e o menor número) dos valores presentes no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h)
*/
double amplitude(double* valores, unsigned int qtd_numeros);
/*
* Essa função retorna o valor que está localizado em uma "posicao" do array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h).
* Caso for posição invalida, retorna a constante HUGE_VAL (em math.h).
*/
double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao);
/*
* Essa função retorna o número que mais se repete e quantas vezes ele aparece (em caso de igualdade, o 
* primeiro encontrado tem preferência) no array.
* Retorna dentro de "qtd_repeticao" a quantidade de vezes que o determinado número se repete no array.
* Caso for um array inválido, retorna a constante HUGE_VAL (em math.h) e ZERO em "qtd_repeticao".
*/
double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao);

/*
* Essa função retorna se o caracter a ser comparado é espaço vazio, enter ou tab.
* @param char a ser comparado
* @return 0 caso seja diferente de enter, tab e espaço, 1 caso seja igual.
*/
int isSpace(char chr);

/* Essa função retira os espaços em branco/enter's das extremidades da string.
* @param str string a ser manipulada
*/
void trim(char str[]);

/* Essa função move de srt para sub, uma substring que vai do inicio de str até antes do primeiro ";" 
* ou até o final. A substring e o ";" são removidos de str.
* @param str string a ser manipulada
*/
void next(char *str, char sub[]);

double media(double* valores, unsigned int qtd_numeros);


#endif
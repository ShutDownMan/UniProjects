#ifndef AERONAVE_H
#define AERONAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aeronave{
	char modelo[20];
	float comprimento;
	float altura;
	float envergadura;
	float velocidade;
	float alcance_max;
	int assentos;
	int banheiros;
} typedef Aeronave;

struct celula_aeronave{
	Aeronave *aeronave;
	struct celula_aeronave *prox;
} typedef Celula_Aeronave;

struct lista_aeronave{
	Celula_Aeronave *primeiro;
	Celula_Aeronave *ultimo;
} typedef Lista_Aeronave;

//Cria uma celula nova 
//Entrada: Nenhuma
//Retorno: Uma nova celula apos receber malloc
//Pre-condicao: Nenhuma
//Pos-condicao: Celula criada
Celula_Aeronave *set_celula_aeronave(void);

//Realiza a leitura dos dados de uma aeronave
//Entrada: Nenhuma
//Retorno: Struct Aeronave com os dados preenchidos
//Pre-condicao: Nenhuma
//Pos-condicao: Leitura de dados realizada
Aeronave *scaneia_aeronave(void);

//Verifica se a lista de aeronaves esta vazia
//Entrada: A lista na qual sera realizada a checagem
//Retorno: Se a lista esta vazia ou nao
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int vazia_aeronave(Lista_Aeronave *l);

//Checa o tamanho de uma lista de aeronaves
//Entrada: A lista na qual sera realizada a checagem
//Retorno: O numero de aeronaves presentes na lista
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Tamanho da lista eh checado
int checa_tamanho_lista_aeronave(Lista_Aeronave *l);

//Insere uma aeronave no inicio da lista
//Entrada: A lista na qual a aeronave sera inserida e a aeronave que sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de aeronave nao nulo
//Pos-condicao: Aeronave inserido no comeco da lista
void insere_aeronave_comeco(Lista_Aeronave *l, Aeronave *a);

//Insere uma aeronave no final da lista
//Entrada: A lista na qual a aeronave sera inserida e a aeronave que sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de aeronave nao nulo
//Pos-condicao: Aeronave inserida no final da lista
void insere_aeronave_final(Lista_Aeronave *l, Aeronave *a);

//Insere uma aeronave em uma posicao especifica na lista
//Entrada: A lista na qual a aeronave sera inserida, a aeronave que sera inserida e a posicao na qual ela sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de Aeronave nao nulo
//Pos-condicao: Aeronave inserida na lista
void insere_aeronave_meio(Lista_Aeronave *l, Aeronave *a, int posicao);

//Remove uma aeronave no comeco da lista
//Entrada: A lista que contem as aeronaves
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave no comeco da lista removida
void remove_aeronave_comeco(Lista_Aeronave *l);

//Remove uma aeronave no final da lista
//Entrada: A lista que contem as aeronaves
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave no final da lista removida
void remove_aeronave_final(Lista_Aeronave *l);

//Remove uma aeronave em uma posicao especifica na lista
//Entrada: A lista que contem as aeronaves e a posicao que esta a aeronave que sera removida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave removida da lista
void remove_aeronave_meio(Lista_Aeronave *l, int posicao);

//Consultar uma aeronave presente na lista atraves do seu modelo
//Entrada: A lista onde ocorrera a busca e o modelo que sera procurado
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave printada
void consulta_aeronave(Lista_Aeronave *l, char modelo[]);

//Printar apenas uma aeronave
//Entrada: A celula que contem a aronave que sera printada e a posicao que a aeronave esta na lista
//Retorno: Nenhum
//Pre-condicao: Ponteiro de Celula nao nulo
//Pos-condicao: Aeronave printada
void printa_aeronave(Celula_Aeronave *c, int n);

//Printa todas as aeronaves presentes na lista
//Entrada: A lista com as aeronaves que serao printadas
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista printada
void printa_lista_aeronave(Lista_Aeronave *l);

#endif
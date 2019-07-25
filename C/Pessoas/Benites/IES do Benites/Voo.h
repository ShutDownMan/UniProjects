#ifndef VOO_H
#define VOO_H

#include "Participante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct voo{
	char prefixo[20];
	char origem[5];
	char destino[5];
	int hora_partida;
	int minuto_partida;
	int hora_chegada;
	int minuto_chegada;
	char duracao[10];
	char tipo[50];	
} typedef Voo;

struct celula_voo{
	Voo *voo;
	struct celula_voo *prox;
} typedef Celula_Voo;

struct lista_voo{
	Celula_Voo *primeiro;
	Celula_Voo *ultimo;
} typedef Lista_Voo;

//Cria uma celula nova 
//Entrada: Nenhuma
//Retorno: Uma nova celula apos receber malloc
//Pre-condicao: Nenhuma
//Pos-condicao: Celula criada
Celula_Voo *set_celula_voo(void);

//Realiza a leitura dos dados de um voo
//Entrada: Nenhuma
//Retorno: Struct Voo com os dados preenchidos
//Pre-condicao: Nenhuma
//Pos-condicao: Leitura de dados realizada
Voo *scaneia_voo(void);

//Verifica se a lista de voos esta vazia
//Entrada: A lista na qual sera realizada a checagem
//Retorno: Se a lista esta vazia ou nao
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int vazia_voo(Lista_Voo *l);

//Checa o tamanho de uma lista de voos
//Entrada: A lista na qual sera realizada a checagem
//Retorno: O numero de voos presentes na lista
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Tamanho da lista eh checado
int checa_tamanho_lista_voo(Lista_Voo *l);

//Insere um voo no inicio da lista
//Entrada: A lista na qual o voo sera inserido e o voo que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido no comeco da lista
void insere_voo_comeco(Lista_Voo *l, Voo *v);

//Insere um voo no final da lista
//Entrada: A lista na qual o voo sera inserido e o voo que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido no final da lista
void insere_voo_final(Lista_Voo *l, Voo *v);

//Insere um voo em uma posicao especifica na lista
//Entrada: A lista na qual o voo sera inserido, o voo que sera inserido e a posicao na qual ele sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido na lista
void insere_voo_meio(Lista_Voo *l, Voo *v, int posicao);

//Remove um voo no comeco da lista
//Entrada: A lista que contem os voos
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo no comeco da lista removido
void remove_voo_comeco(Lista_Voo *l);

//Remove um voo no final da lista
//Entrada: A lista que contem os voos
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo no final da lista removido
void remove_voo_final(Lista_Voo *l);

//Remove um voo em uma posicao especifica na lista
//Entrada: A lista que contem os voos e a posicao que esta o voo que sera removido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo removido da lista
void remove_voo_meio(Lista_Voo *l, int posicao);

//Consultar um voo presente na lista atraves do seu prefixo
//Entrada: A lista onde ocorrera a busca e o prefixo que sera procurado
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo printado
void consulta_voo(Lista_Voo *l, char prefixo[]);

//Printar apenas um voo
//Entrada: A celula que contem o voo que sera printado e a posicao que o voo esta na lista
//Retorno: Nenhum
//Pre-condicao: Ponteiro de Celula nao nulo
//Pos-condicao: Voo printado
void printa_voo(Celula_Voo *c, int n);

//Printa todos os voos presentes na lista
//Entrada: A lista com os voos que serao printados
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista printada
void printa_lista_voo(Lista_Voo *l);

// Copiar os dados do arquivo para uma string
// Entrada: Nome do arquivo, endereco a ser inserida string, posicao no arquivo e condicao de parada
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: string copiada
void copia(char* nome_arq, char* dado, int pos, char fim);

// Ler os dados de um arquivo e inserir no programa
// Entrada: Nome do arquivo, lista de voos e lista de participantes
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: elementos sao inseridos na lista
void ler_arquivo(char *nome_arq, Lista_Voo *lvoo, Lista_Participante *lp);

//Checa se um determinado prefixo ja existe na lista
//Entrada: A lista com os voos e o prefixo que sera buscado
//Retorno: 1 Se o prefixo esta presente na lista e 0 se o prefixo nao esta presente
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int checa_prefixo(Lista_Voo *l, char prefixo[]);

//Checa o status de determinado voo baseado no horario atual
//Entrada: Hora e minutos do voo que sera checado e a struct que contem a hora atual
//Retorno: Nenhum
//Pre-condicao: Nenhuma
//Pos-condicao: Status checado
void checa_status_voo(int hora, int minuto, struct tm *hora_atual);

//Imprime o painel de voos contendo todos os voos, seus prefixos, suas partidas, seu destino e seu status
//Entrada: A lista que contem os voos e a struct que contem a hora atual
//Retorno: Nenhum
//Pre-condicao: Nenhuma
//Pos-condicao: Painel printado
void painel_de_voos(Lista_Voo *l, struct tm *hora_atual);


#endif




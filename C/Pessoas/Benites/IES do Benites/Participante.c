#include "Participante.h"

//Cria uma nova celula
//Entrada: Nenhuma
//Retorno: Uma nova celula apos receber malloc
//Pre-condicao: Nenhuma
//Pos-condicao: Celula criada
Celula_Participante *set_celula_participante(void){
	Celula_Participante *c = malloc(sizeof(Celula_Participante));
	c->prox = NULL;
	return c;
}

//Verifica se a lista de participantes esta vazia
//Entrada: A lista na qual sera realizada a checagem
//Retorno: Se a lista esta vazia ou nao
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int vazia_participante(Lista_Participante *l){
	return l->primeiro == NULL;	
}

//Checa o tamanho de uma lista de participantes
//Entrada: A lista na qual sera realizada a checagem
//Retorno: O numero de voos presentes na lista
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Tamanho da lista eh checado
int checa_tamanho_lista_participante(Lista_Participante *l){
	int i = 0;
	Celula_Participante *aux = NULL;
	for(aux = l->primeiro; aux != NULL; i++){
		aux = aux->prox;
	}
	return i;
}

//Realiza a leitura dos dados de um participante
//Entrada: Nenhuma
//Retorno: Struct Participante com os dados preenchidos
//Pre-condicao: Nenhuma
//Pos-condicao: Leitura de dados realizada
Participante *scaneia_participante(void){
	Participante *p = malloc(sizeof(Participante));
	printf("Programa: ");
	scanf("%[^\n]%*c", p->programa);
	fflush(stdin);	
	printf("Nome: ");
	scanf("%[^\n]%*c", p->nome);
	fflush(stdin);	
	printf("Cpf: ");
	scanf("%[^\n]%*c", p->cpf);
	fflush(stdin);	
	printf("Categoria: ");
	scanf("%[^\n]%*c", p->categoria);
	fflush(stdin);
	printf("Saldo de milhas: ");
	scanf("%f", &(p->saldo));
	fflush(stdin);
	return p;
}

//Insere um participante no inicio da lista
//Entrada: A lista na qual o participante sera inserido e o participante que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de participante nao nulo
//Pos-condicao: Participante inserido no comeco da lista
void insere_participante_comeco(Lista_Participante *l, Participante *p){
	if(vazia_participante(l)){
		Celula_Participante *c = set_celula_participante();
		c->participante = p;
		l->primeiro = c;
		l->ultimo = c;
	}
	else{
		Celula_Participante *c = set_celula_participante();
		c->participante = p;
		c->prox = l->primeiro;
		l->primeiro = c;
	}	
}

//Insere um participante no final da lista
//Entrada: A lista na qual o participante sera inserido e o participante que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de participante nao nulo
//Pos-condicao: Participante inserido no final da lista
void insere_participante_final(Lista_Participante *l, Participante *p){
	if(vazia_participante(l)){
		Celula_Participante *c = set_celula_participante();
		c->participante = p;
		l->primeiro = c;
		l->ultimo = c;
	}	
	else{
		Celula_Participante *c = set_celula_participante();
		c->participante = p;
		l->ultimo->prox = c;
		l->ultimo = c;		
	}
}

//Insere um participante em uma posicao especifica na lista
//Entrada: A lista na qual o participante sera inserido, o participante que sera inserido e a posicao na qual ele sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de participante nao nulo
//Pos-condicao: Participante inserido na lista
void insere_participante_meio(Lista_Participante *l, Participante *p, int posicao){
	int i = 1;
	Celula_Participante *aux = NULL, *cel_nova = NULL, *cel_antiga = NULL;
	if(vazia_participante(l)){
		printf("A lista esta vazia, portanto o elemento sera inserido na posicao 1.\n");
		insere_participante_comeco(l, p);
		return;
	}
	if(posicao == 1){
		insere_participante_comeco(l, p);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	cel_antiga = aux->prox;
	cel_nova = set_celula_participante();
	cel_nova->participante = p;
	aux->prox = cel_nova;
	cel_nova->prox = cel_antiga;
}

//Remove um participante no comeco da lista
//Entrada: A lista que contem os participantes
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Participante no comeco da lista removido
void remove_participante_comeco(Lista_Participante *l){
	Celula_Participante *aux = NULL;
	if(vazia_participante(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->participante);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	aux = l->primeiro;
	l->primeiro = aux->prox;
	free(aux->participante);
	free(aux);
}

//Remove um voo no final da lista
//Entrada: A lista que contem os participantes
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Participante no final da lista removido
void remove_participante_final(Lista_Participante *l){
	Celula_Participante *aux = NULL;
	if(vazia_participante(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->participante);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	for(aux = l->primeiro; aux->prox != l->ultimo; aux = aux->prox);
	l->ultimo = aux;
	aux = aux->prox;
	free(aux->participante);
	free(aux);
	l->ultimo->prox = NULL;
}

//Remove um participante em uma posicao especifica na lista
//Entrada: A lista que contem os participantes e a posicao que esta o participante que sera removido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Participante removido da lista
void remove_participante_meio(Lista_Participante *l, int posicao){
	int i = 1;
	Celula_Participante *aux = NULL, *celula_retirada = NULL;
	if(vazia_participante(l)){
		printf("A lista esta vazia.\n");
		return;
	}
	if(posicao == 1){
		remove_participante_comeco(l);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	if(aux->prox == l->ultimo){
		l->ultimo = aux;
		aux = aux->prox;
		free(aux->participante);
		free(aux);
		l->ultimo->prox = NULL;
		return;
	}
	else{
		celula_retirada = aux->prox;
		aux->prox = celula_retirada->prox;
		free(celula_retirada->participante);
		free(celula_retirada);
	}
}

//Printa apenas um participante
//Entrada: A celula que contem o participante que sera printado e a posicao que o participante esta na lista
//Retorno: Nenhum
//Pre-condicao: Ponteiro de Celula nao nulo
//Pos-condicao: Participante printado
void printa_participante(Celula_Participante *c, int n){
	printf("Individuo n: %d\n", n);
	printf("Programa: %s\n", c->participante->programa);
	printf("Nome: %s\n", c->participante->nome);
	printf("Cpf: %s\n", c->participante->cpf);
	printf("Categoria: %s\n", c->participante->categoria);
	printf("Saldo de milhas: %f\n", c->participante->saldo);
	printf("\n");
	fflush(stdin);
}

//Printa todos os participantes presentes na lista
//Entrada: A lista com os participantes que serao printados
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista printada
void printa_lista_participante(Lista_Participante *l){
	int i = 1;
	Celula_Participante *aux = NULL;
	if(vazia_participante(l)){
		printf("A lista esta vazia\n");
	}
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
		printa_participante(aux, i);
		i++;
	}
	printf("\n");
}

//Consultar um participante presente na lista atraves do seu cpf
//Entrada: A lista onde ocorrera a busca e o cpf que sera procurado
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Participante printado
void consulta_participante(Lista_Participante *l, char cpf[]){
	Celula_Participante *aux = NULL;
	int i = 1;
	if(vazia_participante(l)){
		printf("A lista esta vazia.\n");
	}
	for(aux = l->primeiro; aux != NULL && strcmp(aux->participante->cpf, cpf) != 0; aux = aux->prox, i++);
	if(aux == NULL){
		printf("Participante nao encontrado na lista.\n");
	}
	else{
		printa_participante(aux, i);
	}
}

//Checa se um determinado cpf ja existe na lista
//Entrada: A lista com os participantes e o cpf que sera buscado
//Retorno: 1 Se o cpf esta presente na lista e 0 se o cpf nao esta presente
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int checa_cpf(Lista_Participante *l, char cpf[]){
	Celula_Participante *aux;
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
		if(strcmp(aux->participante->cpf, cpf) == 0){
			return 1;
		}
	}
	return 0;
}
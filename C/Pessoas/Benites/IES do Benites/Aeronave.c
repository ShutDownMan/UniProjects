#include "Aeronave.h"

//Cria uma celula nova 
//Entrada: Nenhuma
//Retorno: Uma nova celula apos receber malloc
//Pre-condicao: Nenhuma
//Pos-condicao: Celula criada
Celula_Aeronave *set_celula_aeronave(void){
	Celula_Aeronave *c = malloc(sizeof(Celula_Aeronave));
	c->prox = NULL;
	return c;
}

//Realiza a leitura dos dados de uma aeronave
//Entrada: Nenhuma
//Retorno: Struct Aeronave com os dados preenchidos
//Pre-condicao: Nenhuma
//Pos-condicao: Leitura de dados realizada
Aeronave *scaneia_aeronave(void){
	Aeronave *a = malloc(sizeof(Aeronave));
	printf("Modelo: ");
	scanf("%[^\n]%*c", a->modelo);
	fflush(stdin);	
	printf("Comprimento: ");
	scanf("%f", &(a->comprimento));
	fflush(stdin);	
	printf("Altura: ");
	scanf("%f", &(a->altura));
	fflush(stdin);	
	printf("Envergadura: ");
	scanf("%f", &(a->envergadura));
	fflush(stdin);
	printf("Velocidade de cruzeiro: ");
	scanf("%f", &(a->velocidade));
	fflush(stdin);
	printf("Alcance maximo: ");
	scanf("%f", &(a->alcance_max));
	fflush(stdin);
	printf("Quantidade de assentos: ");
	scanf("%d", &(a->assentos));
	fflush(stdin);
	printf("Quantidade de banheiros: ");
	scanf("%d", &(a->banheiros));
	fflush(stdin);		
	return a;
}

//Verifica se a lista de aeronaves esta vazia
//Entrada: A lista na qual sera realizada a checagem
//Retorno: Se a lista esta vazia ou nao
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int vazia_aeronave(Lista_Aeronave *l){
	return l->primeiro == NULL;	
}

//Checa o tamanho de uma lista de aeronaves
//Entrada: A lista na qual sera realizada a checagem
//Retorno: O numero de aeronaves presentes na lista
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Tamanho da lista eh checado
int checa_tamanho_lista_aeronave(Lista_Aeronave *l){
	int i = 0;
	Celula_Aeronave *aux = NULL;
	for(aux = l->primeiro; aux != NULL; i++){
		aux = aux->prox;
	}
	return i;	
}

//Insere uma aeronave no inicio da lista
//Entrada: A lista na qual a aeronave sera inserida e a aeronave que sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de aeronave nao nulo
//Pos-condicao: Aeronave inserida no comeco da lista
void insere_aeronave_comeco(Lista_Aeronave *l, Aeronave *a){
	if(vazia_aeronave(l)){
		Celula_Aeronave *c = set_celula_aeronave();
		c->aeronave = a;
		l->primeiro = c;
		l->ultimo = c;
	}
	else{
		Celula_Aeronave *c = set_celula_aeronave();
		c->aeronave = a;
		c->prox = l->primeiro;
		l->primeiro = c;
	}	
}

//Insere uma aeronave no final da lista
//Entrada: A lista na qual a aeronave sera inserida e a aeronave que sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de aeronave nao nulo
//Pos-condicao: Aeronave inserida no final da lista
void insere_aeronave_final(Lista_Aeronave *l, Aeronave *a){
	if(vazia_aeronave(l)){
		Celula_Aeronave *c = set_celula_aeronave();
		c->aeronave = a;
		l->primeiro = c;
		l->ultimo = c;
	}	
	else{
		Celula_Aeronave *c = set_celula_aeronave();
		c->aeronave = a;
		l->ultimo->prox = c;
		l->ultimo = c;		
	}	
}

//Insere uma aeronave em uma posicao especifica na lista
//Entrada: A lista na qual a aeronave sera inserida, a aeronave que sera inserida e a posicao na qual ela sera inserida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de Aeronave nao nulo
//Pos-condicao: Aeronave inserida na lista
void insere_aeronave_meio(Lista_Aeronave *l, Aeronave *a, int posicao){
	int i = 1;
	Celula_Aeronave *aux = NULL, *cel_nova = NULL, *cel_antiga = NULL;
	if(vazia_aeronave(l)){
		printf("A lista esta vazia, portanto o elemento sera inserido na posicao 1.\n");
		insere_aeronave_comeco(l, a);
		return;
	}
	if(posicao == 1){
		insere_aeronave_comeco(l, a);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	cel_antiga = aux->prox;
	cel_nova = set_celula_aeronave();
	cel_nova->aeronave = a;
	aux->prox = cel_nova;
	cel_nova->prox = cel_antiga;
}

//Remove uma aeronave no comeco da lista
//Entrada: A lista que contem as aeronaves
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave no comeco da lista removida
void remove_aeronave_comeco(Lista_Aeronave *l){
	Celula_Aeronave *aux = NULL;
	if(vazia_aeronave(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->aeronave);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	aux = l->primeiro;
	l->primeiro = aux->prox;
	free(aux->aeronave);
	free(aux);
}

//Remove uma aeronave no final da lista
//Entrada: A lista que contem as aeronaves
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave no final da lista removida
void remove_aeronave_final(Lista_Aeronave *l){
	Celula_Aeronave *aux = NULL;
	if(vazia_aeronave(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->aeronave);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	for(aux = l->primeiro; aux->prox != l->ultimo; aux = aux->prox);
	l->ultimo = aux;
	aux = aux->prox;
	free(aux->aeronave);
	free(aux);
	l->ultimo->prox = NULL;	
}

//Remove uma aeronave em uma posicao especifica na lista
//Entrada: A lista que contem as aeronaves e a posicao que esta a aeronave que sera removida
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave removida da lista
void remove_aeronave_meio(Lista_Aeronave *l, int posicao){
	int i = 1;
	Celula_Aeronave *aux = NULL, *celula_retirada = NULL;
	if(vazia_aeronave(l)){
		printf("A lista esta vazia.\n");
		return;
	}
	if(posicao == 1){
		remove_aeronave_comeco(l);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	if(aux->prox == l->ultimo){
		l->ultimo = aux;
		aux = aux->prox;
		free(aux->aeronave);
		free(aux);
		l->ultimo->prox = NULL;
		return;
	}
	else{
		celula_retirada = aux->prox;
		aux->prox = celula_retirada->prox;
		free(celula_retirada->aeronave);
		free(celula_retirada);
	}	
}

//Consultar uma aeronave presente na lista atraves do seu modelo
//Entrada: A lista onde ocorrera a busca e o modelo que sera procurado
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Aeronave printada
void consulta_aeronave(Lista_Aeronave *l, char modelo[]){
	Celula_Aeronave *aux = NULL;
	int i = 1;
	if(vazia_aeronave(l)){
		printf("A lista esta vazia.\n");
	}
	for(aux = l->primeiro; aux != NULL && strcmp(aux->aeronave->modelo, modelo) != 0; aux = aux->prox, i++);
	if(aux == NULL){
		printf("Aeronave nao encontrada na lista.\n");
	}
	else{
		printa_aeronave(aux, i);
	}	
}

//Printar apenas uma aeronave
//Entrada: A celula que contem a aronave que sera printada e a posicao que a aeronave esta na lista
//Retorno: Nenhum
//Pre-condicao: Ponteiro de Celula nao nulo
//Pos-condicao: Aeronave printada
void printa_aeronave(Celula_Aeronave *c, int n){
	printf("Individuo n: %d\n", n);
	printf("Modelo: %s\n", c->aeronave->modelo);
	printf("Comprimento: %f\n", c->aeronave->comprimento);
	printf("Altura: %f\n", c->aeronave->altura);
	printf("Envergadura: %f\n", c->aeronave->envergadura);
	printf("Velocidade de cruzeiro: %f\n", c->aeronave->velocidade);
	printf("Alcance maximo: %f\n", c->aeronave->alcance_max);
	printf("Quantidade de assentos: %d\n", c->aeronave->assentos);
	printf("Quantidade de banheiros: %d\n", c->aeronave->banheiros);
	fflush(stdin);
}

//Printa todas as aeronaves presentes na lista
//Entrada: A lista com as aeronaves que serao printadas
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista printada
void printa_lista_aeronave(Lista_Aeronave *l){
	int i = 1;
	Celula_Aeronave *aux = NULL;
	if(vazia_aeronave(l)){
		printf("A lista esta vazia\n");
	}
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
		printa_aeronave(aux, i);
		i++;
	}
	printf("\n");
}

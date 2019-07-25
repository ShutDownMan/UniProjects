#include "Voo.h"
#include "Participante.h"

//Cria uma celula nova 
//Entrada: Nenhuma
//Retorno: Uma nova celula apos receber malloc
//Pre-condicao: Nenhuma
//Pos-condicao: Celula criada
Celula_Voo *set_celula_voo(void){
	Celula_Voo *c = malloc(sizeof(Celula_Voo));
	c->prox = NULL;
	return c;
}

//Verifica se a lista de voos esta vazia
//Entrada: A lista na qual sera realizada a checagem
//Retorno: Se a lista esta vazia ou nao
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int vazia_voo(Lista_Voo *l){
	return l->primeiro == NULL;
}

//Checa o tamanho de uma lista de voos
//Entrada: A lista na qual sera realizada a checagem
//Retorno: O numero de voos presentes na lista
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Tamanho da lista eh checado
int checa_tamanho_lista_voo(Lista_Voo *l){
	int i = 0;
	Celula_Voo *aux = NULL;
	for(aux = l->primeiro; aux != NULL; i++){
		aux = aux->prox;
	}
	return i;
}

//Realiza a leitura dos dados de um voo
//Entrada: Nenhuma
//Retorno: Struct Voo com os dados preenchidos
//Pre-condicao: Nenhuma
//Pos-condicao: Leitura de dados realizada
Voo *scaneia_voo(void){ //So pra testar as funçoes enquanto nao ta pronta a parte do arquivo
	Voo *v = malloc(sizeof(Voo));
	printf("Prefixo: ");
	scanf("%[^\n]%*c", v->prefixo);
	fflush(stdin);
	printf("Origem: ");
	scanf("%[^\n]%*c", v->origem);
	fflush(stdin);
	printf("Destino: ");
	scanf("%[^\n]%*c", v->destino);
	fflush(stdin);
	while(strcmp(v->destino, v->origem) == 0){
		printf("O voo nao pode ter o mesmo origem e destino, por favor entre com outros.\n");
		printf("Origem: ");
		scanf("%[^\n]%*c", v->origem);
		fflush(stdin);
		printf("Destino: ");
		scanf("%[^\n]%*c", v->destino);
		fflush(stdin);
	}
	printf("Partida (hh:mm): ");
	scanf("%d:%d", &(v->hora_partida), &(v->minuto_partida));
	while(v->hora_partida < 0 || v->minuto_partida < 0 || v->hora_partida > 23 || v->minuto_partida > 59){
		printf("Entrada invalida, por favor entre com uma hora entre 0 e 23 e um minuto entre 0 e 59.\n");
		printf("Partida (hh:mm): ");
		scanf("%d:%d", &(v->hora_partida), &(v->minuto_partida));
		fflush(stdin);
	}
	fflush(stdin);
	printf("Chegada (hh:mm): ");
	scanf("%d:%d", &(v->hora_chegada), &(v->minuto_chegada));
	while(v->hora_chegada < 0 || v->minuto_chegada < 0 || v->hora_chegada > 23 || v->minuto_chegada > 59){
		printf("Entrada invalida, por favor entre com uma hora entre 0 e 23 e um minuto entre 0 e 59.\n");
		printf("Chegada (hh:mm): ");
		scanf("%d:%d", &(v->hora_partida), &(v->minuto_partida));
	}
	fflush(stdin);
	printf("Duracao: ");
	scanf("%[^\n]%*c", v->duracao);
	fflush(stdin);
	printf("Tipo: ");
	scanf("%[^\n]%*c", v->tipo);
	fflush(stdin);
	return v;
}


//Insere um voo no inicio da lista
//Entrada: A lista na qual o voo sera inserido e o voo que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido no comeco da lista
void insere_voo_comeco(Lista_Voo *l, Voo *v){
	if(vazia_voo(l)){
		Celula_Voo *c = set_celula_voo();
		c->voo = v;
		l->primeiro = c;
		l->ultimo = c;
	}
	else{
		Celula_Voo *c = set_celula_voo();
		c->voo = v;
		c->prox = l->primeiro;
		l->primeiro = c;
	}
}

//Insere um voo no final da lista
//Entrada: A lista na qual o voo sera inserido e o voo que sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido no final da lista
void insere_voo_final(Lista_Voo *l, Voo *v){
	if(vazia_voo(l)){
		Celula_Voo *c = set_celula_voo();
		c->voo = v;
		l->primeiro = c;
		l->ultimo = c;
	}	
	else{
		Celula_Voo *c = set_celula_voo();
		c->voo = v;
		l->ultimo->prox = c;
		l->ultimo = c;		
	}
}

//Insere um voo em uma posicao especifica na lista
//Entrada: A lista na qual o voo sera inserido, o voo que sera inserido e a posicao na qual ele sera inserido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo, ponteiro de voo nao nulo
//Pos-condicao: Voo inserido na lista
void insere_voo_meio(Lista_Voo *l, Voo *v, int posicao){
	int i = 1;
	Celula_Voo *aux = NULL, *cel_nova = NULL, *cel_antiga = NULL;
	if(vazia_voo(l)){
		printf("A lista esta vazia, portanto o elemento sera inserido na posicao 1.\n");
		insere_voo_comeco(l, v);
		return;
	}
	if(posicao == 1){
		insere_voo_comeco(l, v);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	cel_antiga = aux->prox;
	cel_nova = set_celula_voo();
	cel_nova->voo = v;
	aux->prox = cel_nova;
	cel_nova->prox = cel_antiga;
}

//Remove um voo no comeco da lista
//Entrada: A lista que contem os voos
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo no comeco da lista removido
void remove_voo_comeco(Lista_Voo *l){
	Celula_Voo *aux = NULL;
	if(vazia_voo(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->voo);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	aux = l->primeiro;
	l->primeiro = aux->prox;
	free(aux->voo);
	free(aux);
}

//Remove um voo no final da lista
//Entrada: A lista que contem os voos
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo no final da lista removido
void remove_voo_final(Lista_Voo *l){
	Celula_Voo *aux = NULL;
	if(vazia_voo(l)){
		printf("Lista esta vazia\n");
		return;
	}
	if(l->primeiro == l->ultimo){
		aux = l->primeiro;
		free(aux->voo);
		free(aux);
		l->primeiro = NULL;
		l->ultimo = NULL;
		return;
	}
	for(aux = l->primeiro; aux->prox != l->ultimo; aux = aux->prox);
	l->ultimo = aux;
	aux = aux->prox;
	free(aux->voo);
	free(aux);
	l->ultimo->prox = NULL;
}

//Remove um voo em uma posicao especifica na lista
//Entrada: A lista que contem os voos e a posicao que esta o voo que sera removido
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo removido da lista
void remove_voo_meio(Lista_Voo *l, int posicao){
	int i = 1;
	Celula_Voo *aux = NULL, *celula_retirada = NULL;
	if(vazia_voo(l)){
		printf("A lista esta vazia.\n");
		return;
	}
	if(posicao == 1){
		remove_voo_comeco(l);
		return;
	}
	for(aux = l->primeiro; i < posicao - 1; i++){
		aux = aux->prox;
	}
	if(aux->prox == l->ultimo){
		l->ultimo = aux;
		aux = aux->prox;
		free(aux->voo);
		free(aux);
		l->ultimo->prox = NULL;
		return;
	}
	else{
		celula_retirada = aux->prox;
		aux->prox = celula_retirada->prox;
		free(celula_retirada->voo);
		free(celula_retirada);
	}
}

//Printar apenas um voo
//Entrada: A celula que contem o voo que sera printado e a posicao que o voo esta na lista
//Retorno: Nenhum
//Pre-condicao: Ponteiro de Celula nao nulo
//Pos-condicao: Voo printado
void printa_voo(Celula_Voo *c, int n){
	printf("Voo n: %d\n", n);
	printf("Prefixo: %s\n", c->voo->prefixo);
	printf("Origem: %s\n", c->voo->origem);
	printf("Destino: %s\n", c->voo->destino);
	printf("Partida: %d:%d\n", c->voo->hora_partida, c->voo->minuto_partida);
	printf("Chegada: %d:%d\n", c->voo->hora_chegada, c->voo->minuto_chegada);
	printf("Duracao: %s\n", c->voo->duracao);
	printf("Tipo: %s\n", c->voo->tipo);
	printf("\n");
	fflush(stdin);
}

//Printa todos os voos presentes na lista
//Entrada: A lista com os voos que serao printados
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista printada
void printa_lista_voo(Lista_Voo *l){
	int i = 1;
	Celula_Voo *aux = NULL;
	if(vazia_voo(l)){
		printf("A lista esta vazia\n");
	}
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
		printa_voo(aux, i);
		i++;
	}
	printf("\n");
}

//Consultar um voo presente na lista atraves do seu prefixo
//Entrada: A lista onde ocorrera a busca e o prefixo que sera procurado
//Retorno: Nenhum
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Voo printado
void consulta_voo(Lista_Voo *l, char prefixo[]){
	Celula_Voo *aux = NULL;
	int i = 1;
	if(vazia_voo(l)){
		printf("A lista esta vazia.\n");
	}
	for(aux = l->primeiro; aux != NULL && strcmp(aux->voo->prefixo, prefixo) != 0; aux = aux->prox, i++);
	if(aux == NULL){
		printf("Voo nao encontrado na lista.\n");
	}
	else{
		printa_voo(aux, i);
	}
}

//Checa se um determinado prefixo ja existe na lista
//Entrada: A lista com os voos e o prefixo que sera buscado
//Retorno: 1 Se o prefixo esta presente na lista e 0 se o prefixo nao esta presente
//Pre-condicao: Ponteiro de lista nao nulo
//Pos-condicao: Lista verificada
int checa_prefixo(Lista_Voo *l, char prefixo[]){
	Celula_Voo *aux;
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
		if(strcmp(aux->voo->prefixo, prefixo) == 0){
			return 1;
		}
	}
	return 0;
}

//Checa o status de determinado voo baseado no horario atual
//Entrada: Hora e minutos do voo que sera checado e a struct que contem a hora atual
//Retorno: Nenhum
//Pre-condicao: Nenhuma
//Pos-condicao: Status checado
void checa_status_voo(int hora, int minuto, struct tm *hora_atual){
	int minutos_voo, minutos_atual, status;
	minutos_voo = (hora * 60) + minuto;
	minutos_atual = (hora_atual->tm_hour * 60) + hora_atual->tm_min;
	status = minutos_voo - minutos_atual;
	if(status > 0){
		if(status >= 60){
			printf("Check-in aberto.\n");
		}
		if(status < 60 && status > 30){
			printf("Check-in fechado.\n");
		}
		if(status <= 30 && status > 20){
			printf("Embarque proximo.\n");
		}
		if(status <= 20 && status > 10){
			printf("Embarque imediato.\n");
		}
		if(status <= 10 && status > 0){
			printf("Ultima chamada.\n");
		}
	}
	if(status <= 0){
		if(status <= 0 && status > -10){
			printf("Partindo.\n");
		}	
		if(status <= -10){
			printf("Voo encerrado.\n");
		}
	}
}

//Imprime o painel de voos contendo todos os voos, seus prefixos, suas partidas, seu destino e seu status
//Entrada: A lista que contem os voos e a struct que contem a hora atual
//Retorno: Nenhum
//Pre-condicao: Nenhuma
//Pos-condicao: Painel printado
void painel_de_voos(Lista_Voo *l, struct tm *hora_atual){
	if(vazia_voo(l)){
		printf("Nenhum voo foi cadastrado.\n");
		fflush(stdin);
		return;
	}
	Celula_Voo *aux;
	printf("|| Prefixo         || Origem  || Destino || Partida   || Status\n");
	for(aux = l->primeiro; aux != NULL; aux = aux->prox){
	printf("|| %s              || %s      || %s      || %d:%d     || ", aux->voo->prefixo, aux->voo->origem, aux->voo->destino, aux->voo->hora_partida, aux->voo->minuto_partida);
	checa_status_voo(aux->voo->hora_partida, aux->voo->minuto_partida, hora_atual);
	fflush(stdin);
	}
}

/*
// Copiar os dados do arquivo para uma string
// Entrada: Nome do arquivo, endereco a ser inserida string, posicao no arquivo e condicao de parada
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: string copiada
void copia(char* nome_arq, char* dado, int pos, char fim){
	char test;
	int i;
	FILE *f;
	if((f=fopen(nome_arq,"r"))==NULL) printf("Erro ao abrir arquivo\n");
	
	
	
	fseek(f, pos, SEEK_SET);
	i=0;
	do{
		test = getc(f);
		if(test!=' ' && test!= fim){
			dado[i]= test;
			i++;
		}
		
	}while(test!=fim);
	
	dado[i] = '\0';
	
	fclose(f);
}

// Ler os dados de um arquivo e inserir no programa
// Entrada: Nome do arquivo, lista de voos e lista de participantes
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: elementos sao inseridos na lista
void ler_arquivo(char *nome_arq, Lista_Voo *lvoo, Lista_Participante *lp){
	char test;
	char aux[20];
	int i=0, j=0;
	char professor_lixo_do_carai;
	
	Voo *voo;	
	Participante *p;
	
	FILE *f;
	if((f=fopen(nome_arq, "r")) == NULL) printf("Erro ao abrir arquivo!\n");
	
	else{
			
		while(!feof(f)){
			
			
				
			test = fgetc(f);	
			
			i++;
			if(test == 'V'){	
				voo = (Voo*)malloc(sizeof(Voo));
				
				while(getc(f)!=';') i++;
				i++;	 
				copia(nome_arq, voo->prefixo, i, ';');	
				
				while(getc(f)!=';') i++;
				i++;
				copia(nome_arq, voo->origem, i, ';');
				
				while(getc(f)!=';') i++;
				i++;
				copia(nome_arq, voo->destino, i, ';');
	
				while(getc(f)!=';') i++;
				i++;
				copia(nome_arq, voo->partida, i, ';');
	
				while(getc(f)!=';') i++;
				i++;
				copia(nome_arq, voo->chegada, i, ';');
	
				while(getc(f)!=';') i++;
				i++;
				copia(nome_arq, voo->duracao, i, ';');
				
				while(getc(f)!=';') i++;
				i++;
				test = getc(f);
				while(test==' '){
					test = getc(f);
					i++;
				}
				
				j=0;
				
				do{
					
					voo->tipo[j] = test; 
					j++;
					test = getc(f);
					i++;
				}while(test!='\n');
				
				voo->tipo[j] ='\0';
				
				insere_voo_final(lvoo, voo);
			}
			
			else if(test == 'P'){
				p = (Participante*)malloc(sizeof(Participante));	
				
				while(getc(f)!=';') i++;
				i++;	 
				copia(nome_arq, p->programa, i, ';');			
				
				while(getc(f)!=';') i++;
				i++;
				test = getc(f);
				while(test==' '){
					test = getc(f);
					i++;
				}
				
				j=0;
				
				do{
					p->nome[j] = test; 
					j++;
					test = getc(f);
					i++;
				}while(test!=';');
				
				
				p->nome[j] ='\0';
				
				i++;
				
				copia(nome_arq, p->cpf, i, ';');
	
				
				while(getc(f)!=';') i++;
				i++;	 
				copia(nome_arq, p->categoria, i, ';');
				
				
				while(getc(f)!=';') i++;
				i++;	 
				copia(nome_arq, aux, i, '\n');
				
				while(getc(f)!='\n') i++;
				
				p->saldo = strtof(aux, NULL);

				insere_participante_final(lp, p);
				
			}
			
			i+=2;
			
			
			
				
		}
		
		printf("Arquivo lido com sucesso!\n");
		
	}
	fclose(f);
	
	
}	
*/










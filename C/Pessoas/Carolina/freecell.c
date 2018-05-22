#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //colorir coisas

#define CELLS 			4
#define FOUNDATION 		4
#define TABLEAU 		8
#define MAX_CHAR 		20
#define MAX_NAIPES 		4
#define MAX_CARD_NAIPE 	13
#define MAX_CARD 		52

const char naipes[][MAX_CHAR] = {"clubs", "diamond", "heart", "spade"};

struct Card{
	char valor; 			//0 1 2 3 4 5 6 7 8 9 J Q K --> A 2 3 4 5 6 7 8 9 10 J Q k
	char naipe[MAX_CHAR]; 	//clubs, diamond, heart, spade
}typedef Card;

struct No{
	Card carta; 	//info
	struct No *prox;
}typedef No;

struct Pilha{
	int size;
	No *topo; 		//prox
}typedef Pilha;

struct Mesa{
	Card  *free_cells[CELLS]; 		//vetor de ponteiro de cartas
	Pilha *foundation[FOUNDATION]; 	//vetor de ponteiro de pilhas de cartas
	Pilha *tableau[TABLEAU]; 		//vetor de ponteiro de pilhas de cartas
}typedef Mesa;


void show_carta(Card c){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;


	if(!strcmp(c.naipe,"clubs") || !strcmp(c.naipe,"spade")){
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	}else{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
	
	if(c.valor == '0'){
		printf("[ A %8s]", c.naipe);
	}else if(c.valor < '9'){
		printf("[ %c %8s]", c.valor+1, c.naipe);
	}else if(c.valor == '9'){
		printf("[10 %8s]", c.naipe);
	}else if(c.valor > '9'){
		printf("[ %c %8s]", c.valor, c.naipe);
	}


	/* Restore original attributes */
	SetConsoleTextAttribute(hConsole, saved_attributes);
}

void show_baralho(Card baralho[], int size){
	int i=0; //id do naipe
	int j=0; //id da carta
	int k=0; //id da carta no naipe
	for(i ; i<MAX_NAIPES ; i++){
		for(k=0 ; k<MAX_CARD_NAIPE ; k++){
			show_carta(baralho[j++]);
		}
		printf("\n");
	}
}

void insert(Pilha *p, Card c){
	if(!p->topo){
		p->topo = (No*)malloc(sizeof(No));
		p->topo->carta = c;
		p->topo->prox = NULL;
		p->size = 1;
	}else{
		No *aux = (No*)malloc(sizeof(No));
		aux->carta = c;
		aux->prox = p->topo;
		p->topo = aux;
		p->size++;
	}
}

void init_cells(Card *c[], int size){
	int i;
	for(i=0 ; i<size ; i++){
		c[i] = NULL;
	}
}

void init_foundation(Pilha *p[], int size){
	int i;
	for(i=0 ; i<size ; i++){
		p[i] = (Pilha*)malloc(sizeof(Pilha));
		p[i]->size = 0;
		p[i]->topo = NULL;
	}
}

void init_tableau(Pilha *p[], int size, Card baralho[]){
	int i;
	for(i=0 ; i<size ; i++){
		p[i] = (Pilha*)malloc(sizeof(Pilha));
		p[i]->size = 0;
		p[i]->topo = NULL;
	}

	int j=0; //id da carta
	for(i=0 ; i<MAX_CARD ; i++){
		printf("inserindo carta ");
		show_carta(baralho[j]);
		printf(" na coluna %d\n", (i%TABLEAU)+1);
		insert(p[i%TABLEAU], baralho[j++]);
	}
}

void init_mesa(Mesa *mesa, Card baralho[]){
	init_cells(mesa->free_cells, CELLS);
	init_foundation(mesa->foundation, FOUNDATION);
	init_tableau(mesa->tableau, TABLEAU, baralho);
}

void show_iezima_carta_recursivo(No *p, int pos_atual, int pos_final){
	if(!p){
		printf("[           ]");
	}else if(pos_atual == pos_final){
		show_carta(p->carta);
	}else{
		show_iezima_carta_recursivo(p->prox, pos_atual+1, pos_final);
	}
}

void show_iezima_carta(Pilha p, int i){
	
	show_iezima_carta_recursivo(p.topo,0,i);
}

void show_mesa(Mesa mesa){
	printf("\n\n");


	int i=0;
	int j=0;

	printf("                     FREE  CELLS                                                         FOUNDATION\n\n");

	for(i=0 ; i<CELLS ; i++){
		if(!mesa.free_cells[i]){
			printf("[           ]" );
		}else{
			show_carta(*mesa.free_cells[i]);
		}
	}

	printf("                ");

	for(i=0 ; i<FOUNDATION ; i++){
		if(!mesa.foundation[i]->topo){
			printf("[           ]" );
		}else{
			show_carta(mesa.foundation[i]->topo->carta);
		}
	}

	printf("\n      A            B            C            D                            E            F            G            H\n");

	printf("\n\n");

	// for(i=0 ; i<TABLEAU ; i++){
		// 	No *p = mesa.tableau[i]->topo;
		// 	printf("coluna [%d] -> ", i+1);
		// 	while(p){
		// 		show_carta(p->carta);
		// 		p = p->prox;
		// 	}
		// 	printf("\n");
		// }

	printf("                                                        TABLEAU\n\n");

	for(j=0 ; j<10 ; j++){ // TODO maior size pilha tableau
		printf("        ");
		for(i=0 ; i<TABLEAU ; i++){
			Pilha p = *mesa.tableau[i];
			show_iezima_carta(p,p.size-j-1);
		}
		printf("\n");
	}

	printf("              1            2            3            4            5            6            7            8\n");
}

void init_baralho(Card b[]){
	int i=0; 	//valor da carta
	int j=0; 	//id da carta
	int k=0; 	//id do naipe

	for(k=0 ; k<MAX_NAIPES ; k++){
		for(i=0 ; i<=9 ; i++){
			b[j].valor = i+'0';
			strcpy(b[j++].naipe, naipes[k]);
		}

		b[j].valor = 'J';
		strcpy(b[j++].naipe, naipes[k]);

		b[j].valor = 'Q';
		strcpy(b[j++].naipe, naipes[k]);

		b[j].valor = 'K';
		strcpy(b[j++].naipe, naipes[k]);
	}
}

int main(){

	Card baralho[MAX_CARD];
	init_baralho(baralho);
	show_baralho(baralho, MAX_CARD);

	Mesa mesa;
	init_mesa(&mesa, baralho);
	show_mesa(mesa);
	// show_opcoes();
	// comeca_o_jogo();  <-  nao fiz ainda

}

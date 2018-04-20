#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "SistemaAlunos.h"

#define MAX 256

int main(int argc, char const *argv[]){
	lista aluno = {.tamanho = 0, .iniList = NULL, .finalList = NULL};
	MenuUser(&aluno);

	return 0;
}


void createForm(lista *list){
	aluno *NewAluno;

	if(NewAluno = lerAluno()){
		NewAluno->id = list->tamanho++;

		printf("\n>Aluno Adicionado com Sucesso.\n");
        printf(">Armazenando dados a lista.\n\n");

        if(insert(list, NewAluno)){
        	printf(">Aluno Adicionado na Lista com Sucesso.\n\n");
        } else {

        	printf(">Ocorreu um erro ao adicionar dados na lista.\n\n");
        } 
	} else {
        	printf(">Ocorreu um erro ao carregar dados.\n\n");
        }
        pause();
        MenuUser(list);

}

aluno *lerAluno(){
	aluno *NewAluno = malloc(sizeof(aluno));
	char str[MAX];
	char c;

	cls();
	printf("Novo Cadastro\n");
	printf("\nNome:");
	scanf("%[^\n]%*c", str);

	while(!stringValida(str)) {

		cls();
		printf("Novo Cadastro\n");

		printf("Digite um nome V%clido: ", 160);
		scanf("%[^\n]%*c", str);
	}
	NewAluno->name = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

	cls();
	printf("Novo Cadastro\n");

	printf("\nEndere%co: ", 135);
	scanf("%[^\n]%*c", str);

	NewAluno->ende = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

	cls();
	printf("Novo Cadastro\n");

	printf("\nMat%cria: ", 130);
	scanf("%[^\n]%*c", str);

	while(!stringValida(str)) {

		cls();
		printf("Novo Cadastro\n");

		printf("Digite uma Mat%cria v%clida: ", 130, 160);
		scanf("%[^\n]%*c", str);
	}
	NewAluno->materia = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

	cls();
	printf("Novo Cadastro\n");
	printf("\nStatus:");
	printf("\nPressione 'A' para ativo ou 'I' para Inativo:");
	c = selectUser(c);

	while(c != 'A' && c != 'I'){

		cls();
		printf("Novo Cadastro\n");
		printf("\nPressione 'A' para ativo ou 'I' para Inativo:");
		printf("\nEscolha um Status V%clido:", 160);
		c = selectUser(c);

	}
	if(c == 'A') strcpy(str, "ATIVO");
		else{
			if(c == 'I') strcpy(str, "INATIVO");
		}

	NewAluno->status = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

	return NewAluno;
}

int insert(lista *list, aluno *alu){
	if(existe(list->iniList)){
		list->iniList = criarNo(alu);
		return 1;
	}
	list->finalList = criarNo(alu);
	insertNo(list->iniList, alu);
}

no *insertNo(no *no, aluno *alu){

	if(existe(no)) return NULL;

	if(no->prox) {
		insertNo(no->prox, alu);
		return no;
	}

	no->prox = criarNo(alu);
	return no;
}

void MenuUser(lista *list){
	cls();

	printf("--------------SISTEMA DE CADASTRO---------------\n\n");

	printf("(A) -> Novo Cadastro;\n");
	printf("(L) -> Mostrar Todos;\n");
	printf("(U) -> Alterar;\n");
	printf("(N) -> Salvar;\n");
	printf("(O) -> Sair;\n");
	selectMenu(list);
}

char selectUser(char c){
	c = getch();
	return toupper(c);
}

void selectMenu(lista *list){
	aluno *alu;

	char c;
	c = selectUser(c);

	while(1){

		switch(c){
			case 'A':
				createForm(list);
				break;

			case 'L':
				printList(list);
				break;

			case 'U':
				UpdateMenu(list);
				break;

			case 'N':
				break;

			case 'O':
				exit(0);
				break;

			default:
				printf("Selecione uma op%c%co V%clida\n", 135, 198, 160);
				c = selectUser(c);
				break;
		}

	}


}

void update(lista *list){
	aluno *aluno;
	char c;

	c = selectUser(c);
	while(1){
		switch(c){

			case 'L':
				aluno = findStudent(list);
				break;

			case 'U':
				updateID(aluno);
				break;

			case 'C':
				updateName(aluno);
				break;

			case 'I':
				updateEnd(aluno);
				break;

			case 'A':
				updateMateria(aluno);
				break;

			case 'N':
				showList(aluno);
				break;

			case 'O':
				exit(0);
				break;

			default:
				return;
				break;
		}
		
		if(aluno){
			cls();
			showList(aluno);
		}
	}
}


int contains(char c, char validCmds[]){

	int i, present;

	for(i = present = 0; validCmds[i] && !(present = (validCmds[i] == c)); i++);
		 return present;

}

void showSearch(lista *list){
    cls();
    printf("Menu de Pesquisa: \n\n");
    printf("(A) -> Mostrar Entradas\n");
    printf("(U) -> Pesquisa por Nome\n");;
    printf("(V) -> Voltar\n");
    findStudent(list);
}

aluno *searchName(lista *list){
	aluno *AlunoEncontrado;
	char name[MAX];

	cls();
	printf("Pesquisa por Nome\n\n");
	printf("Digite um nome valido: ");
	scanf("%[^\n]%*c", name);

	while(!stringValida(name)) {

		cls();
		printf("Pesquisa por Nome\n\n");
		printf("Nome Invalido!\n");
		printf("Digite um nome Valido: ");
		scanf("%[^\n]%*c", name);
	}

	cls();
	AlunoEncontrado = FindFormName(list, name);

	if(AlunoEncontrado){
		printf("Nome (%s) Encontrado com Sucesso\n", name);
		showList(AlunoEncontrado);

	} else {
		printf("Problemas ao encontrar o Aluno '%s'\n", name);

	}
	pause();
	return AlunoEncontrado;
}

aluno *FindFormName(lista *list, char name[]){
	no *tracer;
	int present;

	if(existe(list->iniList)) return NULL;

	present = 0;

	for(tracer = list->iniList; tracer && !(present = !strcmp(tracer->aluno->name, name)); tracer = tracer->prox)
		;

	if(present)
		return tracer->aluno;
	return NULL;

}

aluno *findStudent(lista *list){

	lista *ListaEncontrada = NULL;
	aluno *AlunoEncontrado = NULL;
	char c;
	c = selectUser(c);
	while(1){
		switch(c){
			case 'A':
				printList(list);
				break;

			case 'U':
				AlunoEncontrado = searchName(list);
				break;

			case 'V':
				update(list);
				break;

			default:
				return AlunoEncontrado;
				c = selectUser(c);
				break;
		}

		if(AlunoEncontrado)
			return AlunoEncontrado;
	}
	return AlunoEncontrado;

}

void updateID(aluno *alu){

	if(!alu) return;

	cls();
	showList(alu);
	printf("Digite o Novo ID: ");
	scanf("%d", &alu->id);

	printf("ID atualizado com Sucesso\n");
}

void updateName(aluno *alu){

	char str[MAX];
	if(!alu) return;

	cls();
	showList(alu);
	printf("Digite o Novo Nome: ");
	scanf("%[^\n]%*c", str);

	while(!stringValida(str)){
		cls();
		showList(alu);
		printf("Nome Invalido\n");
		printf("Digite um Nome valido: ");
		scanf("%[^\n]%*c", str);
	}
	alu->name = strcpy(realloc(alu->name, (sizeof(strlen(str))+1)), str);

	printf("Nome Atualizado com Sucesso\n");

}

void updateEnd(aluno *alu){

	char str[MAX];
	if(!alu) return;

	cls();
	showList(alu);
	printf("Digite o Novo Endereco: ");
	scanf("%[^\n]%*c", str);

	alu->ende = strcpy(realloc(alu->name, (sizeof(strlen(str))+1)), str);

	printf("Endereco Atualizado com Sucesso\n");

}

void updateMateria(aluno *alu){

	char str[MAX];
	if(!alu) return;

	cls();
	showList(alu);
	printf("Digite uma Nova Materia: ");
	scanf("%[^\n]%*c", str);

	while(!stringValida(str)){
		cls();
		showList(alu);
		printf("Materia Invalido\n");
		printf("Digite uma Materia valida: ");
		scanf("%[^\n]%*c", str);
	}
	alu->materia = strcpy(realloc(alu->name, (sizeof(strlen(str))+1)), str);

	printf("Nome Atualizado com Sucesso\n");
}

void UpdateMenu(lista *list){

	cls();
	printf("Menu de Atualizacao de Informacoes: \n\n");

	printf("(L) -> Pesquisar Aluno\n");
    printf("(U) -> Atualizar ID\n");
    printf("(C) -> Atualizar Nome\n");
    printf("(I) -> Atualizar Materia\n");
    printf("(A) -> Atualizar Status\n");
    printf("(N) -> Mostrar Aluno Encontrado\n");
    printf("(O) -> Voltar\n");
    update(list);

}

void printList(lista *list){
	no *pointer;
	char c;
	cls();
	printf("Numero de Cadastros: (%d)\n\n", list->tamanho);

	for(pointer = list->iniList; pointer; pointer = pointer->prox) {
        showList(pointer->aluno);
    }
    printf("Pressione 'V' para voltar ao menu Principal\n");
    c = selectUser(c);
    while(1){

      switch(c){
    	case 'V':
	    	MenuUser(list);
	    	break;
	    default:
	    	cls();
	    	printf("Op%c%co inv%clida\n", 135, 198, 160);
	    	c = selectUser(c);
	    	break;
  	  }

    }

   
}

void showList(aluno *std){

	printf("ID: [%04d]\n", std->id);
	printf("Nome: %s\n", std->name);
	printf("Endere%co: %s\n", 135, std->ende);
	printf("Mat%cria: %s\n", 130, std->materia);
	printf("Status: %s\n", std->status);

	printf("\n");
}	

no *criarNo(aluno *alu){
	no *novoNo = malloc(sizeof(no));

	if(novoNo) {
		novoNo->aluno = alu;
		novoNo->prox = NULL;
	}

	return novoNo;
}

void confirma() {
	printf("Pressione uma tecla para continuar\n");
	getch();
} 

int existe(no *node) {
	return !node;
}

int stringValida(char nome[]){
	int i, atual;

	for(i = atual = 0; nome[i] && !(atual =(!isalpha(nome[i]) && nome[i] != ' ')); i++);

		return !atual;
}

void cls(){
	system("CLS");
}

void pause(){
	system("PAUSE");
}

void freeList(lista *list){
	if(!list) return;

	freeNode(list->iniList);
	free(list->iniList);
}

void freeNode(no *node){
	if(existe(node)) return;

	freeNode(node);
	free(node);
}
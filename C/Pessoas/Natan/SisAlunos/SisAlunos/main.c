#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "SistemaAlunos.h"

#define MAX 256

int main(int argc, char const *argv[]){

	MenuUser();

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
        MenuUser();

}

aluno *lerAluno(){
	aluno *NewAluno = malloc(sizeof(aluno));
	char str[MAX];

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

char MenuUser(){
	cls();

	printf("--------------SISTEMA DE CADASTRO---------------\n\n");

	printf("(L) -> Novo Cadastro;\n");
	printf("(U) -> Mostrar Todos;\n");
	printf("(C) -> Inserir;\n");
	printf("(I) -> Alterar;\n");
	printf("(A) -> Deletar;\n");
	printf("(N) -> Salvar;\n");
	printf("(O) -> Sair;\n");
	selectMenu();
}

char selectUser(char c){
	c = getch();
	return toupper(c);
}

void selectMenu(lista *list){
	//lista aluno = {.tamanho = 0, .iniList = NULL, .finalList = NULL};
	char c;
	c = selectUser(c);

	switch(c){
		case 'L':
			createForm(list);
			break;

			case 'U':
			printList(list);
			break;

		case 'O':
			break;

		default: 
			printf("Selecione uma opcao Valida\n");
			pause();
			MenuUser();
			break;
			
	}

}


void printList(lista *list){
	no *pointer;

	cls();
	printf("Numero de Cadastros: (%d)\n", list->tamanho);

	for(pointer = list->iniList; pointer; pointer = pointer->prox) {
        showList(pointer->aluno);
    }	
}

void showList(aluno *std){

	printf("ID: %d\n", std->id);
	printf("Nome: %s\n", std->name);
	printf("Endere%co: %s\n", 135, std->ende);
	printf("Mat%cria: %s\n", 130, std->materia);
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

void freeNode(no *node){
	if(existe(node)) return;

	freeNode(node);
	free(node);
}
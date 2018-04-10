#ifndef SISTEMAALUNOS_H
#define SISTEMAALUNOS_H

typedef struct aluno{
	int id;
	char *name;
	char *ende;
	char *materia;
} aluno;

typedef struct NoAluno{
	aluno *aluno;
	struct NoAluno *prox;
} no;

typedef struct lista{
	int tamanho;
	no *iniList;
	no *finalList;
} lista;


char MenuUser(lista *list);

void selectMenu(lista *list);

no *criarNo(aluno *alu);

void createForm(lista *lista);

aluno *lerAluno();

char selectUser(char c);

void printList(lista *list);

void showList(aluno *std);

no *insertNo(no *no, aluno *alu);

int insert(lista *list, aluno *alu);

void cls();

void pause();

int stringValida(char nome[]);

void freeNode(no *node);

void confirma();

int existe(no *node);

///void freeNodes(no *node);
#endif
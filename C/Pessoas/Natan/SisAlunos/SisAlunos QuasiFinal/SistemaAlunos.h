#ifndef SISTEMAALUNOS_H
#define SISTEMAALUNOS_H

typedef struct aluno{
	int id;
	char *name;
	char *ende;
	char *materia;
	char *status;
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


void MenuUser(lista *list);

aluno *searchName(lista *list);

aluno *FindFormName(lista *list, char name[]);

aluno *FindFormID(lista *list, int id);

aluno *findStudent(lista *list);

void UpdateMenu(lista *list);

void update(lista *list);

void selectMenu(lista *list);

void showSearch(lista *list);

void updateID(aluno *alu);

void updateName(aluno *alu);

void updateEnd(aluno *alu);

void updateMateria(aluno *alu);

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

int contains(char c, char validCmds[]);

void confirma();

void freeList(lista *list);

int existe(no *node);

///void freeNodes(no *node);
#endif
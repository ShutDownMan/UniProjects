#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int dia, mes, ano;
} Data;

typedef struct no {
	char nome[50];
	char cpf[50];
	double salario_ini;
	Data data;
	struct no *pprox;
} Lista;

void limpastdin() {
	char c;
	while(c = getchar() != '\n' && EOF);
}

int vazia(Lista *no) {
	return !no;
}

Lista* leCadastro() {
	Lista *novoCadastro = (Lista *)malloc(sizeof(Lista));

	system("cls");

	// printf("Digite o nome: ");
	// fgets(novoCadastro->nome, 51, stdin);
	// strtok(novoCadastro->nome, "\n");

	printf("Digite o CPF: ");
	fgets(novoCadastro->cpf, 51, stdin);
	strtok(novoCadastro->cpf, "\n");

	// printf("Digite o salario inicial: ");
	// scanf("%lf", &novoCadastro->salario_ini);

	// printf("Digite o dia: ");
	// scanf("%d", &novoCadastro->data.dia);

	// printf("Digite o mes: ");
	// scanf("%d", &novoCadastro->data.mes);

	// printf("Digite o ano: ");
	// scanf("%d", &novoCadastro->data.ano);

	novoCadastro->pprox = NULL;

	return novoCadastro;
}

void cadastrafuncionario(Lista **cabeca) {
	int opcao;
	Lista *novoCadastro = leCadastro();

	if(vazia(*cabeca)) {
		*cabeca = novoCadastro;
	} else {
		novoCadastro->pprox = *cabeca;
		*cabeca = novoCadastro;
	}

	printf("\n\nDeseja cadastrar outro funcionario? <1> Sim  <2> Nao\n");
	scanf("%d", &opcao);
	// limpastdin();

	if(opcao == 1) cadastrafuncionario(cabeca);
}

void cadastraEmIndice(Lista **cabeca, int indice) {
	Lista *noAtual = *cabeca;
	int i;

	if(indice == 1) {
		cadastrafuncionario(cabeca);
		return;
	}

	for(i = 2; i < indice; ++i) {
		noAtual = noAtual->pprox;
		if(!noAtual) {
			printf("Indice inválido\n");
			return;
		}
	}

	Lista *novoCadastro = leCadastro();
	novoCadastro->pprox = noAtual->pprox;
	noAtual->pprox = novoCadastro;
}

void removerEmIndice(Lista **cabeca, int indice) {
	Lista *noAtual = *cabeca, *aux = NULL;
	int i;

	if(vazia(*cabeca)) {
		printf("Lista é vazia\n");
		return;
	}

	if(indice == 1) {
		aux = *cabeca;
		*cabeca = (*cabeca)->pprox;
		free(aux);
		return;
	}

	for(i = 2; i < indice; ++i) {
		noAtual = noAtual->pprox;
		if(!noAtual) {
			printf("Indice inválido\n");
			return;
		}
	}

	aux = noAtual->pprox;
	if(aux) {
		noAtual->pprox = aux->pprox;
	} else {
		noAtual->pprox = NULL;
	}
	free(aux);
}

void menu() {

	system("cls");
	printf("*********************************************************\n\
	*                  Lista Encadeada                      *\n\
	*                                                       *\n\
	*  1 - para cadastrar o programador no inicio da lista  *\n\
	*  2 - para mostrar lista de programadores              *\n\
	*  3 - para deletar o primeiro programador da lista     *\n\
	*  4 - para consultar um programador                    *\n\
	*  5 - para cadastrar um programador em outro indice    *\n\
	*  6 - para deletar um programador da lista             *\n\
	*  Outro valor - para sair do programa                  *\n\
	*********************************************************\n\n");

}

int main() {
	Lista* cabeca = NULL;

	int opcao;

	while(1)
	{
		menu();
		scanf("%d", &opcao);
		limpastdin();

		switch(opcao)
		{
			case 1:
			{
				cadastrafuncionario(&cabeca);
				break;
			}
			case 2:
			{
				// imprimelista(aux, inicio);
				break;
			}
			case 3:
			{
				// deletafuncionario(&dados, &inicio);
				break;
			}
			case 4:
			{
				// consultafuncionario(aux, inicio);
				break;
			}
			case 5:
			{
				int indice;
				limpastdin();
				printf("Informe o indice: ");
				scanf("%d", &indice);
				cadastraEmIndice(&cabeca, indice);
				break;
			}
			case 6:
			{
				break;
			}
			case 7:
			{
				int indice;
				limpastdin();
				printf("Informe o indice: ");
				scanf("%d", &indice);
				removerEmIndice(&cabeca, indice);
				break;
			}
			default:
			{
				// free(dados);
				// free(aux);
				// free(inicio);
				return 0;
			}
		}
	}
}
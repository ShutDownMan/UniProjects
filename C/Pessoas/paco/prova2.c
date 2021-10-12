#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 256

typedef struct
{
	char *vestimenta;
	char item;
	int preferencia;
	float valor;
} LISTA;

void showinfo(LISTA *lp, int n, char *nome)
{
	int i;
	char *file_name = (char *)malloc(sizeof(char) * MAX_STR);
	file_name = strcat(strcpy(file_name, nome), ".txt");
	FILE *f_filho = fopen(file_name, "w+");

	for (i = 0; i < n; i++)
	{
		fprintf(f_filho, "%c %.2f %d %s\n", lp[i].item, lp[i].valor, lp[i].preferencia, lp[i].vestimenta);
	}
}

void ordem(LISTA *lp, int n)
{
	LISTA temp;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (lp[i].item != lp[j].item)
				{
					if (lp[i].item > lp[j].item)
					{
						// printf("%s -> %s\n", lp[i].vestimenta, lp[j].vestimenta);
						temp = lp[i];
						lp[i] = lp[j];
						lp[j] = temp;
					}
				}
				else if (lp[i].preferencia > lp[j].preferencia)
				{
					temp = lp[i];
					lp[i] = lp[j];
					lp[j] = temp;
				}
				else if (lp[i].preferencia == lp[j].preferencia)
				{
					if (lp[i].valor < lp[j].valor)
					{
						temp = lp[i];
						lp[i] = lp[j];
						lp[j] = temp;
					}
					else if (lp[i].valor == lp[j].valor)
					{
						if (strcmp(lp[i].vestimenta, lp[j].vestimenta) < 0)
						{
							temp = lp[i];
							lp[i] = lp[j];
							lp[j] = temp;
						}
					}
				}
			}
		}
	}
}

LISTA *lerdados(FILE *f, LISTA *lp, int qtd, char *nome)
{
	int i = 0;

	lp = (LISTA *)malloc(sizeof(LISTA) * qtd);

	for (i = 0; i < qtd; i++)
	{
		lp[i].vestimenta = (char *)malloc(sizeof(char) * MAX_STR);
		fscanf(f, " %c %s %f %d", &lp[i].item, lp[i].vestimenta, &lp[i].valor, &lp[i].preferencia);
		//printf("%c %s %f %d\n",lp[i].item, lp[i].vestimenta, lp[i].valor, lp[i].preferencia);
	}
	return lp;
}
void freelista(LISTA *natal, int n)
{
	int i;
	for (i = 0; i < 0; i++)
	{
		free(natal[i].vestimenta);
	}
	free(natal);
}

int main()
{
	LISTA *guarda_roupa;
	int qtd;
	char *nome;
	FILE *f = fopen("entrada.txt", "r");
	nome = (char *)malloc(sizeof(char) * MAX_STR);

	while (fscanf(f, "%s %d ", nome, &qtd) != EOF)
	{
		guarda_roupa = lerdados(f, guarda_roupa, qtd, nome);
		ordem(guarda_roupa, qtd);
		showinfo(guarda_roupa, qtd, nome);
	}

	freelista(guarda_roupa, qtd);
	free(nome);
	fclose(f);

	return 0;
}

/*

*/
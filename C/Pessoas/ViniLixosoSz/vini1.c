#include <stdio.h>
#include <stdlib.h>

typedef struct no
{

	int info;
	struct no *prox;

} Lista;

Lista *crialista()
{

	return (Lista *)malloc(sizeof(Lista));
}

int vazia(Lista *l)
{

	return (l == NULL);
}

Lista *insere(Lista *l, int info)
{

	if (vazia(l))
	{

		Lista *nova = crialista();
		nova->info = info;
		nova->prox = NULL;
		l = nova;
		return l;
	}

	l->prox = insere(l->prox, info);
	return l;
}

Lista *remover(Lista *l1, Lista *l2)
{
	Lista *tracer1;
	Lista *tracer2;
	Lista *last;

	for (tracer2 = l2; tracer2; tracer2 = tracer2->prox)
	{
		int currentInfo = tracer2->info;

		last = l1;
		for (tracer1 = l1->prox; tracer1; tracer1 = last->prox)
		{
			if (currentInfo == tracer1->info)
			{
				last->prox = tracer1->prox;
				free(tracer1);
			}
			else
			{

				last = tracer1;
			}
		}

		if (l1->info == currentInfo)
		{
			last = l1;
			l1 = l1->prox;
			free(last);
		}
	}

	return l1;
}

void imprime(Lista *l)
{

	if (!vazia(l))
	{

		printf("%d\n", l->info);

		imprime(l->prox);
	}
	else
		printf("\n");
}

int main()
{

	Lista *l = crialista();
	l = NULL;
	Lista *l2 = crialista();
	l2 = NULL;

	l = insere(l, 5);
	l = insere(l, 5);
	l = insere(l, 5);
	l = insere(l, 69);
	l = insere(l, 12);
	l = insere(l, 8);
	l = insere(l, 10);
	l = insere(l, 1);
	l = insere(l, 4);

	l2 = insere(l2, 5);
	l2 = insere(l2, 69);
	l2 = insere(l2, 12);
	l2 = insere(l2, 4);

	printf("lista:\n");
	imprime(l);
	printf("---------------------\n");
	imprime(l2);

	l = remover(l, l2);

	printf("=====================\n");

	imprime(l);

	return 0;
}
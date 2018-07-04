#include <stdio.h>
#include <stdlib.h>
#define MAX 255

int determinar_data(int *dia, int *mes, int *ano)
{
	int bissexto = 0; int flag; //flag determina se o valor correspondente é valido no calendario
	if ((*dia > 31) || (*mes > 12))
	{
		return flag = 1;
	}

	if (*mes == 2)
	{
		bissexto = (!(*ano % 400) || ((*ano % 100) && !(*ano % 4)));

		if (*dia == 28) {
			if(bissexto) {
				(*dia)++;
			} else {
				(*mes)++;
			}
		} else {

		}

		if (bissexto)
		{
			if (*dia > 29)
			{
				return 1;
			}
		}
		else
		{
			if (*dia > 28)
			{
				return flag = 1;
			}
			*dia = 1;
			*mes += 1;
		}
	}
	else if (*mes < 8)
	{
		if ((*mes % 2) == 0)
		{
			if(*dia > 30)
			{
				return flag = 1;
			}
			if(*dia == 30)
			{
				*dia = 1;
				*mes += 1;
			}
			else
				*dia += 1;
		}
		else
		{
			if(*dia == 31)
			{
				*dia = 1;
				*mes += 1;
			}
			else
				*dia += 1;
		}
	}

	else if (*mes >= 8)
	{
		if((*mes % 2) == 1)
		{
			if(*dia > 30)
			{
				return flag = 1;
			}
			if(*dia == 30)
			{
				*dia = 1;
				*mes += 1;
			}
			else
				*dia += 1;
		}
		else
		{
			if(*dia == 31)
			{
				*dia = 1;
				if(*mes == 12)
				{
					*mes = 1;
					*ano += 1;
				}
				else
					*mes += 1;
			}
			else
				*dia += 1;
		}
	}
	return flag = 0;
}

int main()
{
	int diaG, mesG, anoG, flag;
	int i, n;

	system("cls");
	printf("Digite a quantidade de datas que deseja calcular o dia posterior\n");
	scanf("%d", &n);

	if (n < 0 || diaG < 0 || mesG < 0 || anoG < 0)
	{
		printf("Valor invalido\n");
		return 0;
	}

	for (i=1; i<=n; i++)
	{
		printf("Digite o dia para a data %d:\n", i);
		scanf("%d", &diaG);
		printf("Digite o mes para a data %d:\n", i);
		scanf("%d", &mesG);
		printf("Digite o ano para a data %d:\n", i);
		scanf("%d", &anoG);
		flag = determinar_data(&diaG, &mesG, &anoG);
		if (flag)
		{
			printf("Data invalido\n");
		}
		else
		{
			printf("O proximo dia da data %d e: %d/%d/%d\n", i, diaG, mesG, anoG);
		}
	}

	system("pause");
	return 0;
}
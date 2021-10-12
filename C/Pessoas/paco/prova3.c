#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 1500

char *lerTexto()
{
	char *texto = (char *)malloc(sizeof(char) * (MAX_STR + 1));
	int n = 0;

	while (fgets(texto + n, MAX_STR - n, stdin))
	{
		n += strlen(texto + n);
	}

	printf("%s\n", texto);
	printf("-----------\n");

	return texto;
}

char *corrigeEspacos(char *texto)
{
	int i, j;
	char *novo_texto = (char *)malloc(sizeof(char) * (MAX_STR + 1));

	for (i = j = 0; texto[i];)
	{
		if (texto[i] == ' ')
		{
			while (texto[++i] == ' ')
				;
			if (texto[i] != ',' && texto[i] != '.' && texto[i] != ';')
			{
				novo_texto[j++] = ' ';
			}
		}
		else if (texto[i] == ',' || texto[i] == '.' || texto[i] == ';')
		{
			novo_texto[j++] = texto[i++];
			novo_texto[j++] = ' ';
			if (texto[i] == ' ')
				while (texto[++i] == ' ')
					;
		}
		else
		{
			novo_texto[j++] = texto[i++];
		}
	}
	novo_texto[j] = '\0';
	// printf(">%d\n", j);

	return novo_texto;
}

int main(void)
{
	char *texto = NULL;
	char *novo_texto = NULL;

	texto = lerTexto();
	novo_texto = corrigeEspacos(texto);
	printf("%s\n", novo_texto);

	free(texto);
	free(novo_texto);

	return 0;
}

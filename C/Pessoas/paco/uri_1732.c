#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *palavra;
    int repeticao;

} TEXTO;

void ordena_palavra(TEXTO *ler, int n)
{
    TEXTO temp;
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && strcmp(ler[i].palavra, ler[j].palavra) < 0)
            {
                temp = ler[i];
                ler[i] = ler[j];
                ler[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d %s -> %d\n", i + 1, ler[i].palavra, ler[i].repeticao);
    }
}

TEXTO *remove_duplicado(TEXTO *ler, int *n)
{
    int i, j, k;
    int t = *n;

    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *n; j++)
        {
            if (i != j && j < t && i < t && strcmp(ler[i].palavra, ler[j].palavra) == 0)
            {
                ler[i].repeticao++;
                k = j;
                while (k < *n)
                {
                    ler[k] = ler[k + 1];
                    k++;
                }
                t--;
            }
        }
    }
    *n = t;
    return ler;
}

void ordena_repeticao(TEXTO *ler, int n)
{
    int i, j;
    TEXTO temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && ler[i].repeticao > ler[j].repeticao)
            {
                temp = ler[i];
                ler[i] = ler[j];
                ler[j] = temp;
            }
            else if (i != j && ler[i].repeticao == ler[j].repeticao)
            {
                if (strcmp(ler[i].palavra, ler[j].palavra) < 0)
                {
                    temp = ler[i];
                    ler[i] = ler[j];
                    ler[j] = temp;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d %s -> %d\n", i + 1, ler[i].palavra, ler[i].repeticao);
    }
}

char *maiusculo(char *str)
{

    for(int i = 0; str[i]; str[i++] = toupper(str[i]))
        ;

    return str;
}

TEXTO *separa(TEXTO *ler, int minimo, char *texto, int *count_palavras)
{
    int tam_palavra;
    int i;
    ler = (TEXTO *)malloc(sizeof(TEXTO) * 10000);
    char *palavra = (char *)malloc(sizeof(char) * 100);

    for (i = 0; texto[i]; i += tam_palavra + 1)
    {
        ler[*count_palavras].palavra = (char *)malloc(sizeof(char) * 100);

        // printf(" %s/", texto);
        //sscanf(texto + count_letras, "%s", palavra);
        tam_palavra = 0;
        while ((texto[i + tam_palavra] >= 'a' && texto[i + tam_palavra] <= 'z') || (texto[i + tam_palavra] >= 'A' && texto[i + tam_palavra] <= 'Z'))
        {
            palavra[tam_palavra] = texto[i + tam_palavra];
            tam_palavra++;
        }
        palavra[tam_palavra] = '\0';

        if (tam_palavra > minimo)
        {
            palavra = maiusculo(palavra);
            ler[*count_palavras].palavra = (char *)realloc(ler[*count_palavras].palavra, tam_palavra + 1);
            strcpy(ler[*count_palavras].palavra, palavra);
            ler[*count_palavras].repeticao = 1;
            (*count_palavras)++;
            printf(">%s/", palavra);
        }
    }
    free(palavra);
    ler = (TEXTO *)realloc(ler, *count_palavras);

    return ler;
}

char *lerdado(int *minimo, int *opcao, char *texto)
{
    int n = 0;
    texto = (char *)malloc(sizeof(char) * 10000);

    scanf("%d %d%*c", minimo, opcao);
    while(fgets(texto + n, 10000 - n, stdin)) {
        n += strlen(texto + n);
    }

    printf("%s\n", texto);

    return texto;
}

int main()
{
    int minimoLetras = 0, desc = 0;
    char *texto = NULL;
    TEXTO *repeticoes = NULL;
    int count_palavras = 0;
    
    texto = lerdado(&minimoLetras, &desc, texto);

    repeticoes = separa(repeticoes, minimoLetras, texto, &count_palavras);

    repeticoes = remove_duplicado(repeticoes, &count_palavras);
    if (desc == 0)
    {
        ordena_palavra(repeticoes, count_palavras);
    }
    else
    {
        ordena_repeticao(repeticoes, count_palavras);
    }
    printf("TOTAL PALAVRAS -> %d", count_palavras);

    return 0;
}
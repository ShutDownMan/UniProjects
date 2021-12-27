#include "lab.h"
#include <stdlib.h>
#include <math.h>

FILE *abre_arquivo(const char *arquivo){
	if(!arquivo){
		puts("Erro");
		return NULL;	
	} 
	FILE *f = fopen(arquivo, "r");
	return f;
}

int fecha_arquivo(FILE *arq){
	if(!arq) return 1;

	return fclose(arq);
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
	if(!arquivo){
		puts("Erro");
		return NULL;	
	} 

	FILE* file = abre_arquivo(arquivo);

	if (!file) {
		puts("Erro no arquivo.");
		return NULL;
	}	
	char linha[10000], sub[50];
	double *l1 = malloc(sizeof(double) * 1000);
	double *l2 = malloc(sizeof(double) * 1000);
	char *eptr = NULL;

	for (int i = 0;!feof(file); i++) {
		fgets(linha, 10000, file);
		trim(linha); //tira enter e espaço do final
		next(linha, sub);
		trim(sub);
		trim(linha);

		if (!*linha) {
			continue;
		}

		eptr = sub + 50;
		l1[i] = strtod(sub, &eptr);
		eptr = linha + 1000;
		l2[i] = strtod(linha, &eptr);

		*qtd_numeros += 2;
	}
	if(*qtd_numeros <= 0) return NULL;

	double *final = malloc(sizeof(double) * (*qtd_numeros));
	int i = 0;
	for(; i < (int)*qtd_numeros/2; i++)
		final[i] = l1[i];
	
	for(int j = 0; j < (int)*qtd_numeros/2; j++){
		final[i] = l2[j];
		i++;
	}

	free(l1);
	free(l2);

	if(fecha_arquivo(file) != 0) puts("Erro ao fechar arquivo.\n");

	return final;
}

int isSpace(char chr) {
	return chr == ' ' || chr == '\n' || chr == '\t';
}

void trim(char str[]) {
	char *dst = str;
	char *src = str;
	while (isSpace(*src)) {
		++ src;
	}
	while (*src) {
		*dst++ = *src++;
	}
	if (dst > str) {
		while (isSpace(dst[-1])) {
			-- dst;
		}
	}
	*dst = '\0';
}

void next(char *str, char sub[]) {
	char *dst = str;
	while (*str && *str != ' ' && *str != ';' && *str != ',') {
		*sub++ = *str++;
	}
	*sub = '\0';
	if (*str == ' ' || *str == ';' || *str == ',') {
		++ str;
		while (*str) {
			*dst++ = *str++;
		}
		*dst = '\0';
	} else {
		*str = '\0';
	}
}

double maior(double* valores, unsigned int qtd_numeros){
	double maiorN = 0;

	if(valores == NULL || qtd_numeros == 0) return HUGE_VAL;
	for(int i = 0; i < (int)qtd_numeros; i++)
		if(valores[i] > maiorN) 
			maiorN = valores[i];
	return maiorN;
}

double menor(double* valores, unsigned int qtd_numeros){
	if(valores == NULL || qtd_numeros == 0) return HUGE_VAL;
	
	double menorN = valores[0];

	for(int i = 0; i < (int)qtd_numeros; i++)
		if(valores[i] < menorN) 
			menorN = valores[i];
	return menorN;
}

double media(double* valores, unsigned int qtd_numeros){
	double m = 0;

	if(valores == NULL) return HUGE_VAL;
	for(int i = 0; i < (int)qtd_numeros; i++)
		m += valores[i];

	m = m/qtd_numeros;
	return m;
}

double desvio(double* valores, unsigned int qtd_numeros){
	double m = media(valores, qtd_numeros);
	double somatorio = 0, dp, x = 0;

	if(valores == NULL) return HUGE_VAL;

	for(int i = 0; i < (int)qtd_numeros; i++){
		x = valores[i] - m;
		somatorio = somatorio + pow(x, 2);	
	}
		somatorio = somatorio/qtd_numeros;
	dp = sqrt(somatorio);
	return dp;
}

double amplitude(double* valores, unsigned int qtd_numeros){
	return (maior(valores, qtd_numeros) - menor(valores, qtd_numeros));
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
	if(valores == NULL) return HUGE_VAL;
		qtd_numeros = qtd_numeros;
	return valores[posicao-1];
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
	double moda = HUGE_VAL;
    int i = 0, j = 0;
    char achado = 0;
    *qtd_repeticao = 0;

    if(!valores) {
        return moda;
    }

    unsigned int contagem_tam = 0, alocado_tam = 256;
    unsigned int *contagem = (unsigned int *)malloc(sizeof(unsigned int) * alocado_tam);
    double *contagem_val = (double *)malloc(sizeof(double) * alocado_tam);

    for(i = 0; i < (int)qtd_numeros; ++i) {
        achado = 0;
        for(j = 0; j < (int)contagem_tam; ++j) {
            if(contagem_val[j] == valores[i]) {
                contagem[j]++;
                achado = 1;
            }
        }
        if(achado == 0) {
            contagem[contagem_tam] = 1;
            contagem_val[contagem_tam] = valores[i];
            contagem_tam++;

            if(contagem_tam == alocado_tam) {
                alocado_tam = 2 * alocado_tam;
                contagem = (unsigned int *)realloc(contagem, alocado_tam);
                contagem_val = (double *)realloc(contagem_val, alocado_tam);
            }
        }
    }
    if(!contagem_tam) {
        return moda;
    }
    *qtd_repeticao = contagem[0];
    for(i = 1; i < (int)contagem_tam; ++i) {
        if(contagem[i] > *qtd_repeticao) {
            moda = contagem_val[i];
            *qtd_repeticao = contagem[i];
        }
    }
    free(contagem);
    free(contagem_val);
    return moda;
}


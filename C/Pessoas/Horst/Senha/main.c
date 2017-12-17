#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct codigo
{
	char *senha;
	int indice;
}_codigo;

int load (char *fn, _codigo *cripto[], int* num_senhas);
int analisaSenha( _codigo *cripto[], int num_senhas);
int senha (char *str);
int relatorio (char * fn, _codigo *cripto[], int num_senhas, int tipo);
int relat(char *fn, _codigo *cripto[], int num_senhas);
void libera(_codigo *cripto[], int num_senhas);
int relatDecres(char *fn, _codigo *cripto[], int num_senhas);
void first(_codigo *cripto[], int num_senhas);
int getHighest(_codigo *cripto[], int num_senhas);
void swap(_codigo** a, _codigo** b);

int main(int argc, char const *argv[]) {
	_codigo **cripto; // ponteiro que aponta pro vetor de ponteiro
	int num_senhas;

	cripto = malloc(MAX * sizeof(_codigo*)); // aloca espaço para 100 ponteiro de struct _codigo

	if(!load("senhas.txt", cripto, &num_senhas)) {

		cripto = realloc(cripto, num_senhas*sizeof(_codigo*)); // realocando com o tamanho exato do vetor

		analisaSenha(cripto, num_senhas);

		relatorio("indice.txt", cripto, num_senhas, 1);
		relatorio("indice2.txt", cripto, num_senhas, 2);

		libera(cripto, num_senhas);
	}
	return 0;
}

int load (char *fn, _codigo *cripto[], int* num_senhas) {
	FILE* f;
	int i;

	f = fopen(fn, "r"); if(!f) return 1;

	for(i = 0; !feof(f); i ++) {

		cripto[i] = malloc(sizeof(_codigo));
		cripto[i]->senha = malloc(sizeof(char)*MAX);

		fscanf(f, "%[^\n]%*c", cripto[i]->senha);

		cripto[i]->senha = realloc(cripto[i]->senha, sizeof(char)*strlen(cripto[i]->senha));
	}

	*num_senhas = i;
	fclose(f);

	return 0;
}

int analisaSenha(_codigo *cripto[], int num_senhas) {
	int i;

	for(i = 0; i < num_senhas; i++) {

		cripto[i]->indice = senha(cripto[i]->senha);

	}
	return 0;
}

int senha (char *str) {
	int i;
	int indice = 0;
	int l_minuscula = 0;
	int l_maiuscula = 0;
	int dig_num = 0;
	int carac_esp = 0;

	if(strlen(str) >= 8) indice += 20;

	for(i = 0; str[i]; i++) {
		if(islower(str[i])) {
			l_minuscula++;
		} else
			if(isupper(str[i])) {
				l_maiuscula++;
			} else
				if(isdigit(str[i])) {
					dig_num++;
				} else
					if(!isalnum(str[i])) {
						carac_esp++;
				}
	}

	if(l_minuscula) indice += 20;
	if(l_maiuscula) indice += 20;
	if(dig_num) indice += 20;
	if(carac_esp) indice += 20;

	return indice;
}

int relatorio (char* fn, _codigo *cripto[], int num_senhas, int tipo) {

	switch(tipo) {
		case 1: relat(fn, cripto, num_senhas);
		case 2: relatDecres(fn, cripto, num_senhas);
	}

	return 0;
}

int relat(char *fn, _codigo *cripto[], int num_senhas) {
	FILE* frelat;
	int i;

	frelat = fopen(fn, "w"); if(!frelat) return 1;

	for(i = 0; i < num_senhas; i++) {

		fprintf(frelat, "SENHA\t\t\t");
		fprintf(frelat, "INDICE\n");

		fprintf(frelat, "%s\t\t", cripto[i]->senha);
		fprintf(frelat, "%d\n", cripto[i]->indice);
	}
}

int relatDecres(char *fn, _codigo *cripto[], int num_senhas) {
	int i;
	FILE* frelat;

	frelat = fopen(fn, "w"); if(!frelat) return 1;

	for (i = 0; i < num_senhas; ++i) {
		first(&cripto[i], num_senhas-i);
	}

	for(i = 0; i < num_senhas; i++) {

		fprintf(frelat, "SENHA\t\t\t");
		fprintf(frelat, "INDICE\n");

		fprintf(frelat, "%s\t\t", cripto[i]->senha);
		fprintf(frelat, "%d\n", cripto[i]->indice);
	}
	return 0;
}

void first(_codigo *cripto[], int num_senhas) {
	int ind;

	ind = getHighest(cripto, num_senhas);

	if(cripto[ind]->indice > cripto[0]->indice) {
		swap(&cripto[0], &cripto[ind]);
	}
}

int getHighest(_codigo *cripto[], int num_senhas) {
	int i, ind = 0;

	for (i = 1; i < num_senhas; ++i) {
		if(cripto[i]->indice > cripto[ind]->indice) {
			ind = i;
		}
	}
	return ind;
}

void swap(_codigo** a, _codigo** b) {
	_codigo* tmp = *a;
	*a = *b;
	*b = tmp;
}

void libera (_codigo *cripto[], int num_senhas) {
	int i;

	for( i = 0; i < num_senhas; i++) {
		free(cripto[i]->senha);
		free(cripto[i]);
	}
	free(cripto);

}
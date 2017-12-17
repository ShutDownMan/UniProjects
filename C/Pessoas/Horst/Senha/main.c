#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct codigo {
	char *senha;
	int indice;
} codigo;

int load (char *fn, codigo *cripto[], int* num_senhas);
int analisaSenha( codigo *cripto[], int num_senhas);
int senha (char *str);

int relatorio (char * fn, codigo *cripto[], int num_senhas, int tipo);
int relat(char *fn, codigo *cripto[], int num_senhas);

int relatDecres(char *fn, codigo *cripto[], int num_senhas);
void first(codigo *cripto[], int num_senhas);
int getHighest(codigo *cripto[], int num_senhas);
void swap(codigo** a, codigo** b);

void libera(codigo *cripto[], int num_senhas);

int main(int argc, char const *argv[]) {
	// vetor de ponteiro de codigo
	codigo **cripto;
	// tamanho do vetor
	int num_senhas;

	// aloca espaço para 100 ponteiro de struct codigo
	cripto = malloc(MAX * sizeof(codigo*));

	// carrega para a memória as senhas do arquivo "senhas.txt"
	if(!load("senhas.txt", cripto, &num_senhas)) {

		// realocando com o tamanho exato do vetor
		cripto = realloc(cripto, num_senhas*sizeof(codigo*));

		// gera os indices das senhas
		analisaSenha(cripto, num_senhas);

		// gera relatório com indices
		relatorio("indice.txt", cripto, num_senhas, 1);
		// gera relatório ordenado (decrescente)
		relatorio("indice2.txt", cripto, num_senhas, 2);

		// libera toda memória dinamicamente alocada
		libera(cripto, num_senhas);
	}

	return 0;
}

int load (char *fn, codigo *cripto[], int* num_senhas) {
	FILE* f;
	int i;

	// abre arquivo
	f = fopen(fn, "r"); if(!f) return 1;

	// enquanto não final de arquivo
	for(i = 0; !feof(f); i ++) {

		// aloca memoria para struct codigo
		cripto[i] = malloc(sizeof(codigo));
		// aloca memoria para string senha
		cripto[i]->senha = malloc(sizeof(char)*MAX);

		// lê linha do arquivo e armazena em senha
		fscanf(f, "%[^\n]%*c", cripto[i]->senha);

		// realoca memoria para tamanho de senha
		cripto[i]->senha = realloc(cripto[i]->senha, sizeof(char)*strlen(cripto[i]->senha));
	}

	// num de senhas lidas = i
	*num_senhas = i;
	// fecha arquivo
	fclose(f);

	return 0;
}

int analisaSenha(codigo *cripto[], int num_senhas) {
	int i;

	// para cada senha i
	for(i = 0; i < num_senhas; i++) {
		// calcule indice da senha
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

	// para cada char "i" de senha
	for(i = 0; str[i]; i++) {
		// str[i] é minusculo?
		if(islower(str[i])) {
			l_minuscula++;
		} else {
			// é maiúsculo?
			if(isupper(str[i])) {
				l_maiuscula++;
			} else {
				// é número
				if(isdigit(str[i])) {
					dig_num++;
				} else {
					// não é alfa numérico?
					if(!isalnum(str[i])) {
						carac_esp++;
					}
				}
			}
		}
	}

	// add nos indices
	if(l_minuscula) indice += 20;
	if(l_maiuscula) indice += 20;
	if(dig_num) indice += 20;
	if(carac_esp) indice += 20;

	return indice;
}

int relatorio (char* fn, codigo *cripto[], int num_senhas, int tipo) {

	// para cada tipo de relatório
	switch(tipo) {
		case 1: relat(fn, cripto, num_senhas);
		case 2: relatDecres(fn, cripto, num_senhas);
	}

	return 0;
}

int relat(char *fn, codigo *cripto[], int num_senhas) {
	FILE* frelat;
	int i;

	// abr arquivo
	frelat = fopen(fn, "w"); if(!frelat) return 1;

	// para cada senha
	for(i = 0; i < num_senhas; i++) {
		fprintf(frelat, "SENHA\t\t\t");
		fprintf(frelat, "INDICE\n");

		fprintf(frelat, "%-24s", cripto[i]->senha);
		fprintf(frelat, "%d\n", cripto[i]->indice);
	}
}

int relatDecres(char *fn, codigo *cripto[], int num_senhas) {
	int i;
	FILE* frelat;

	// abre arquivo
	frelat = fopen(fn, "w"); if(!frelat) return 1;

	// para cada senha
	for (i = 0; i < num_senhas; ++i) {
		// troque o maior pela atual
		first(&cripto[i], num_senhas-i);
	}

	// para cada senha
	for(i = 0; i < num_senhas; i++) {
		fprintf(frelat, "SENHA\t\t\t");
		fprintf(frelat, "INDICE\n");

		fprintf(frelat, "%-24s", cripto[i]->senha);
		fprintf(frelat, "%d\n", cripto[i]->indice);
	}
	return 0;
}

void first(codigo *cripto[], int num_senhas) {
	int ind;

	// pega a senha com maior indice
	ind = getHighest(cripto, num_senhas);

	// se for maior troca de lugar
	if(cripto[ind]->indice > cripto[0]->indice) {
		swap(&cripto[0], &cripto[ind]);
	}
}

int getHighest(codigo *cripto[], int num_senhas) {
	int i, ind = 0;

	// para cada senha
	for (i = 1; i < num_senhas; ++i) {
		// acha o maior indice
		if(cripto[i]->indice > cripto[ind]->indice) {
			ind = i;
		}
	}
	return ind;
}

void swap(codigo** a, codigo** b) {
	codigo* tmp = *a;
	*a = *b;
	*b = tmp;
}

void libera (codigo *cripto[], int num_senhas) {
	int i;

	for( i = 0; i < num_senhas; i++) {
		free(cripto[i]->senha);
		free(cripto[i]);
	}
	free(cripto);

}
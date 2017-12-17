#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
#define ANO 2017

typedef struct automovel {
	char* marca;
	int ano;
	char* cor;
	float valor;
	float IPVA;
} _automovel;

int load(char* fn, _automovel *carro[], int* num_carros);
int relat(char *fn, _automovel *carro[], int num_carros, int valor);
void libera(_automovel* carro[], int num_carros);
float IPVA(_automovel *carro[], int num_carros, int timer);
float calcIPVA(_automovel *carro, int timer);
int relatIPVA(char *fn, _automovel *carro, int num_carros, float IPVA);

int main(int argc, char const *argv[]){
	_automovel **carros;//ponteiro q aponta pro vetor de ponteiros
	int num_carros;
	int valor;


	carros = malloc(1000*sizeof(_automovel));//aloca um valor qualquer pro valor

	if(!load("carros.txt", carros, &num_carros))

		printf("Digite uma valor maximo que deseja...\n");
		scanf("%d", &valor);
		relat("relat.txt", carros, num_carros, valor);

		carros = realloc(carros, num_carros*sizeof(_automovel*));//realoca com o valor exato do vetor

		IPVA(carros, num_carros, ANO);
		libera(carros, num_carros);
		free(carros);

	return 0;
}

int load(char* fn, _automovel *carro[], int* num_carros){
	FILE* f;
	int i;
	char char_temp[100];

	f = fopen(fn, "r"); if(!f) return 1;
		for(i = 0; !feof(f); i++){

			carro[i] = malloc(sizeof(_automovel));
			carro[i] -> marca = malloc(100);

			fscanf(f, "%[^\n]", carro[i]->marca);

			carro[i]->marca = realloc(carro[i]->marca, strlen(carro[i]->marca)+1);

			fscanf(f, "%d%*c", &carro[i]->ano);
			fscanf(f, "%[^\n]", char_temp);

			carro[i]->cor = malloc(strlen(char_temp)+1);
			strcpy(carro[i]->cor, char_temp);

			fscanf(f, "%f%*c ", &carro[i]->valor);
		}
		*num_carros = i;
		fclose(f);

		return 0;
}

int relat(char *fn, _automovel *carro[], int num_carros, int valor){
	FILE* frelat;
	int i;

	frelat = fopen(fn, "w"); if(!frelat) return 1;

	fprintf(frelat, "Carros com valores igual ou menor que %d\n\n", valor);
	for(i = 0; i < num_carros; i++){
		if(carro[i]->valor <= valor){
			fprintf(frelat, "Marca: %s\n", carro[i]->marca);
			fprintf(frelat, "Cor: %s\n", carro[i]->cor);
			fprintf(frelat, "Ano: %d\n", carro[i]->ano);
		}
		fprintf(frelat, "\n");
	}
	return 0;
}

void libera(_automovel* carro[], int num_carros){
	int i;

	for(i = 0; i < num_carros; i++){
		free(carro[i]->marca);
		free(carro[i]->cor);
		free(carro[i]);
	}
}

float IPVA(_automovel *carro[], int num_carros, int timer){
	int i;
	float IPVA;

	for(i = 0; i < num_carros; i++){
		IPVA = calcIPVA(carro[i], timer);
		relatIPVA("IPVA.txt", carro[i], num_carros, IPVA);
	}
}

float calcIPVA(_automovel *carro, int timer) {

	printf("%d\n", timer);

	if(carro->ano <= (timer - 20)) return 0;
	if(carro->ano <= (timer - 10)) return (carro->valor * 0.015);
	if(carro->ano > (timer - 10)) return (carro->valor * 0.025);

}

int relatIPVA(char *fn, _automovel *carro, int num_carros, float IPVA){
	FILE* fIPVA;

	fIPVA = fopen(fn, "a"); if(!fIPVA) return 1;

	fprintf(fIPVA, "Marca: %s\n", carro->marca);
	fprintf(fIPVA, "Cor: %s\n", carro->cor);
	fprintf(fIPVA, "Ano: %d\n", carro->ano);
	fprintf(fIPVA, "IPVA: R$: %.2f\n", IPVA);
	fprintf(fIPVA, "\n");

	return 0;
}
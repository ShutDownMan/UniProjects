#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	char nome [100];
	float peso;
	float altura;
	char sex;
	int dia, mes, ano;
} pess;

void load (FILE *fi, pess pessoa[], int *tam){
	int i;
	for(i=0;!feof(fi);i++){
		fscanf(fi,"%[^\n]",pessoa[i].nome);
		fscanf(fi,"%f",&pessoa[i].peso);
		fscanf(fi,"%f%*c",&pessoa[i].altura);
		fscanf(fi,"%c",&pessoa[i].sex);
		fscanf(fi,"%d%d%d%*c",&pessoa[i].dia, &pessoa[i].mes, &pessoa[i].ano);

	}
	*tam=i;
}

void printimc (pess pessoa[], int tam){
	int i;
	for (i = 0; i < tam; ++i) {
		printf("%s\n", pessoa[i].nome);
		printf("IMC: %f\n", pessoa[i].peso/(pessoa[i].altura*pessoa[i].altura));
	}
}

int main (){
	pess pessoa [MAX];
	FILE *fi;
	int tam;

	if(!(fi=fopen("teste.txt","r"))){printf("Fodeo"); return 1;}

	load(fi,pessoa,&tam);

	printimc(pessoa, tam);

	return 0;
}
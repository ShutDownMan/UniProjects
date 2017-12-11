#include <stdio.h>
#include <stdlib.h>
#define MAX 128

typedef struct Aluno
{
	char nome[MAX];
	float notas [4];
}Aluno;

int load (char fn[], Aluno alunos[],int *qalunos);
void relat(char fn[], Aluno alunos[],int  qalunos);


int main(int argc, char const *argv[]){
	Aluno alunos[MAX];
	int qalunos;

	if(!load("alunos.txt", alunos, &qalunos)) return 1;
	
	relat("relat.txt", alunos, qalunos);

 
	return 0;
}

int load (char fn[], Aluno alunos[], int *qalunos){
	FILE *falunos;
	int i, j;

	if (falunos = fopen(fn, "r")) {

		for (i = 0; !feof(falunos); ++i) {
			fscanf (falunos, "%[^\n]%*c", alunos[i].nome);

			for (j = 0; j < 4; ++j) {
				fscanf (falunos, "%f%*c", &alunos[i].notas[j]);
			}
		}

		*qalunos = i;
		return 1;  
	} else {
		return 0;
	}

	fclose(falunos);
}

void relat (char fn[], Aluno alunos[], int qalunos){
	FILE* frelat;
	int i, j;

	if (frelat = fopen(fn, "w")){
		for (i = 0; i < qalunos; ++i) {
			fprintf(frelat, "%s\t", alunos[i].nome);

			for (j = 0; j < 4; ++j) {
				fprintf(frelat, "%g ", alunos[i].notas[j]);
			}
			fprintf(frelat, "\n");
		}
	} else 
		printf("Erro\n");

	fclose(frelat);   
}
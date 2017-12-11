#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

typedef struct {
	char* nome;
	float notas[4], media;
} Aluno;

int load(char fileName[], Aluno* alunos[], int* qAlunos);
int fRelat(char fileName[], Aluno* alunos[], int qAlunos, int relatType);
int calc(Aluno* alunos[], int qAlunos);
int libera(Aluno* alunos[], int qAlunos);

int ordFis(Aluno* alunos[], int qAlunos);

Aluno* read(FILE* f, Aluno* aluno);
Aluno* write1(FILE* fw, Aluno* aluno);
Aluno* write2(FILE* fw, Aluno* aluno);
Aluno* write3(FILE* fw, Aluno* aluno);

int main(int argc, char const *argv[]) {
	Aluno* alunos[MAX];
	int qAlunos;

	if(!(load("Alunos.txt", alunos, &qAlunos))) {
		fRelat("relat.txt", alunos, qAlunos, 1);
		calc(alunos, qAlunos);
		fRelat("relat2.txt", alunos, qAlunos, 2);
		//fRelat("relat3.txt", alunos, qAlunos, 3);
		//ordFis(alunos, qAlunos);
		//fRelat("ord.txt", alunos, qAlunos, 3);
		libera(alunos, qAlunos);
	}

	return 0;
}

int libera(Aluno* alunos[], int qAlunos) {
	int i;

	for (i = 0; i < qAlunos; ++i) {
		free(alunos[i]);
	}

}

int calc(Aluno* alunos[], int qAlunos) {
	int i, j;
	float soma;

	for (i = 0; i < qAlunos; ++i) {
		soma = 0;
		for (j = 0; j < 4; ++j) {
			soma += alunos[i]->notas[j];
		}
		alunos[i]->media = soma/4;
	}
	return 0;
}

int ordFis(Aluno* alunos[], int qAlunos) {

	
}

int load(char fileName[], Aluno* alunos[], int* qAlunos) {
	FILE* fr;
	int i;

	if(!(fr = fopen(fileName, "r"))) return 1;

	for (i = 0; !feof(fr); ++i) {
		alunos[i] = read(fr, alunos[i]);
	}

	*qAlunos = i;

	fclose(fr);
	return 0;
}

Aluno* read(FILE* fr, Aluno* aluno) {
	int i;

	aluno = malloc(sizeof(Aluno));
	aluno->nome = malloc(MAX);

	fscanf(fr, "%[^\n]%*c", aluno->nome);

	aluno->nome = realloc(aluno->nome, strlen(aluno->nome));

	for (i = 0; i < 4; ++i) {
		fscanf(fr, "%f%*c", &aluno->notas[i]);
	}

	return aluno;
}

int fRelat(char fileName[], Aluno* alunos[], int qAlunos, int relatType) {
	int i;
	FILE* fw;

	if(!(fw = fopen(fileName, "w"))) return 1;

	for (i = 0; i < qAlunos; ++i) {
		switch(relatType) {
			case 1:
				write1(fw, alunos[i]);
				break;
			case 2:
				write2(fw, alunos[i]);
				break;
			case 3:
				write3(fw, alunos[i]);
				break;
			default:
				break;
		}
	}

	fclose(fw);
	return 0;
}

Aluno* write1(FILE* fw, Aluno* aluno) {
	int i;

	fprintf(fw, "%s\n", aluno->nome);

	for (i = 0; i < 4; ++i) {
		fprintf(fw, "%.1f ", aluno->notas[i]);
	}
	fprintf(fw, "\n");

	return aluno;
}

Aluno* write2(FILE* fw, Aluno* aluno) {
	int i;

	fprintf(fw, "%-40s ", aluno->nome);

	for (i = 0; i < 4; ++i) {
		fprintf(fw, "%.1f ", aluno->notas[i]);
	}
	fprintf(fw, "%.1f", aluno->media);

	fprintf(fw, "\n");

	return aluno;
}

Aluno* write3(FILE* fw, Aluno* aluno) {
	int i;

	fprintf(fw, "%-40s ", aluno->nome);

	for (i = 0; i < 4; ++i) {
		fprintf(fw, "%.1f ", aluno->notas[i]);
	}
	fprintf(fw, "%.1f \n", aluno->media);

	return aluno;
}
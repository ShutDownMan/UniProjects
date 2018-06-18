#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct none {
	char *qnt;

	char *sortType;

	char *fileNameIn;

	char *fileNameOut;
} NONE;

typedef struct arg {
    //tipo de comando
    char tipo[10];
    //tamanho do vetor
    int qnt = 0;
    //tipo de ordenacao
    char ordem[20] = {0};
    //arquivo de entrada
    char fileNameI[50] = {0};
    //arquuivo de saida
    char fineNameO[50] = {0};
}Arg;

void lerVet(char fileName[], int *vet[], int *tam) {
	FILE *f = fopen(fileName, "r+");
	int i;

	/// tamanho original de 8
	(*tam) = 8;
	(*vet) = (int *)malloc((*tam) * sizeof(int));
	/// para um i começando em 0 e incrementando até o fim do arquivo
	for (i = 0; !feof(f); ++i) {
		/// se chegou no limite do vetor
		if(i == (*tam)) {
			/// dobra o tamanho e realoca todo o vetor
			(*tam) *= 2;
			(*vet) = (int *)realloc((*vet), (*tam) * sizeof(int));
		}
		/// lê o número da linha atual
		fscanf(f, "%d", ((*vet) + i));
	}

	/// já sabendo que o tamanho do vetor vai se manter fixo até ser desalocado
	/// é realocado para o tamanho exato de elementos
	(*tam) = i;
	(*vet) = (int *)realloc((*vet), (*tam) * sizeof(int));

	fclose(f);
}

void lerVet2(int **vet, int *tam){
	FILE* f;
	int i;
	//char char_name[20];

	//scanf("%[^\n]%*c", char_name);

	if((f = fopen("vet.txt", "r")) != NULL){
		*vet = (int*)malloc((*tam)*sizeof(int));
		for(i = 0; !feof(f) ; i++){
			if(i == *tam) {
				*tam *= 2;
				*vet = (int*)realloc(*vet, (*tam)*sizeof(int));
			}
			fscanf(f, "%d", ((*vet) + i));
			printf("%d\n", (*vet)[i]);
		}
		*tam = i;
	}else{
		printf("erro ao abrir o arquivo!\n");
	}
	fclose(f);
}

void mostrar(int vet[], int tam) {
	int i;

	for(i = 0; i < tam; ++i) {
		printf("vet[%02d] = %d\n", i, vet[i]);
	}
}

int main(int argc, char const *argv[]) {
	int tam = 10;
	int *vet = NULL;

	//tipo de comando
	char tipo[10] = {0};
	//tamanho do vetor
	char qnt[10] = {0};
	//tipo de ordenacao
	char ordem[20] = {0};
	//arquivo de entrada
	char fileNameI[50] = {0};
	//arquuivo de saida
	char fineNameO[50] = {0};

//	lerVet("vet.txt", &vet, &tam);
//	lerVet2(&vet, &tam);
//	mostrar(vet, tam);

	printf("ok\n");
	if(argc){
		if(!strcmp(argv[1], "N")) {
			printf("eh N\n");
			strcpy(qnt, argv[2]);
			strcpy(tipo, argv[3]);
			strcpy(fineNameO, argv[4]);
		} else {
			if(!strcmp(argv[1], "C")) {
				strcpy(fileNameI, argv[2]);
				strcpy(tipo, argv[3]);
				strcpy(fineNameO, argv[4]);
			} else {
				printf("erro\n");
			}
			printf("erro\n");
		}
	} else {
		printf("erro!\n");
	}

	printf("=> %s\n", tipo);
	printf("=> %s\n", qnt);
	printf("=> %s\n", ordem);
	printf("=> %s\n", fineNameO);
	printf("=> %s\n", fileNameI);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main(){

	FILE *arq;
	int totalwr, v[MAX]={1,2,3,4,5};

	arq=fopen("Vetor.txt","wb");

	if(arq==NULL){
		
		printf("Erro na Abertura do Arquivo\n");
		
		system("pause");

		return 1;

	}

	totalwr = fwrite(v,sizeof(int),MAX,arq);

	if(totalwr != MAX){

		printf("Erro na Escrita\n");

		return 1;

	}

	fclose(arq);

	return 0;

}
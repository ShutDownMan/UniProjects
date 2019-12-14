#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpaStdin(){
	char c;
	while ((c=getchar()) != '\n' && c!=EOF);
}

struct Time{
	char nome[255];
	double pontuacao;
	int vitorias;
	int cartaov;
};
typedef struct Time time;

void alocacaoVetor(time **v, int *n){
	printf("Digite o numero de times\n");
//	scanf("%d", &*n);
	scanf("%d", n);

	while((*n)<2 || (*n)>20){
		printf ("Erro no valor digitado. Digite um valor entre 2 e 20\n");
		scanf("%d", n);
	}
	
	*v = (time*)malloc(sizeof(time)*(*n));
}
void carregaTimes( time *v, int n){
	int i;
	
	for(i=0;i<(n);i++){
		limpaStdin();
		printf("Digite os dados do %d time\n",i+1);
		printf("Nome:");
		fgets(v[i].nome, 255, stdin);
		strtok(v[i].nome, "\n");
		printf("Pontuacao:");
		scanf("%lf", &(v[i].pontuacao));
		printf("Numero de vitorias:");
		scanf("%d", &(v[i].vitorias));
		printf("Numero de cartao vermelho:");
		scanf("%d", &(v[i].cartaov));
		printf("\n");
	}
}

void imprimeTimes(time *x, int n){
	int i;
	
	for (i=0;i<n;i++){
		printf("Dados do %d time\n", i+1);
		printf("Nome do time: %s\n", x[i].nome);
		printf("Pontuacao: %.2lf\n", x[i].pontuacao);
		printf("Vitorias: %d\n", x[i].vitorias);
		printf("Cartao vermelho: %d\n", x[i].cartaov);
		printf("\n");
	}
	
}

void insertionSortordenacao(time *x, int n){
	int i, j, d;
	time aux;
	
	printf("Como deseja ordenar os times\n");
	printf("Nome - Digite 1\n");
	printf("Pontuacao - Digite 2\n");
	printf("Vitorias - Digite 3\n");
	printf("Cartao Vermelho - Digite 4\n");
	scanf("%d",&d);
	printf("\n");
	
	if(d==1){
		for(i=0;i<n;i++){
			printf("I = %d\n", i);
			aux = x[i];
        	for(j = i;(j>0) && (strcmp(aux.nome, x[j-1].nome)<0);j--){
				printf("J = %d\n", j);
        		x[j]=x[j-1];
        		x[j]=aux;
            }
        }
	}

	if(d==2){
		for(j=0; j<n; j++){
			aux=x[j];
				for(i=j;(i>0)&&(aux.pontuacao<x[i-1].pontuacao);i--)
					x[i]=x[i-1];
					x[i]=aux;
		}
	}
	if(d==3){
		for(j=0; j<n; j++){
			aux=x[j];
				for(i=j;(i>0)&&(aux.pontuacao<x[i-1].pontuacao);i--)
					x[i]=x[i-1];
					x[i]=aux;
		}
	}
	if(d==4){
	for(j=0; j<n; j++){
			aux=x[j];
				for(i=j;(i>0)&&(aux.pontuacao<x[i-1].pontuacao);i--)
					x[i]=x[i-1];
					x[i]=aux;
		}
	}
}
int main(){
	time *vetor;
	int n;
	
	alocacaoVetor(&vetor, &n);
	carregaTimes(vetor,n);
//	imprimeTimes(vetor,n);
	insertionSortordenacao(vetor, n);
	imprimeTimes(vetor,n);
	
	return 0;
	
}


#include <stdio.h>
int paisagem(int vetor[], int c){
	int i,aux[100],j;
	for(i=0;i<c;i++)
		scanf("%d",&vetor[i]);
	for(i=1;i<c;i++){
		aux[i-1] = (vetor[i]<vetor[i-1]);
	}
		printf("\n");
	for(i=0;i<c-1;i++){
		if(aux[i]==aux[i+1])return 0;
	}

	return 1;
}
int main(){
	int c,r,x,paisa[100];

	scanf("%d",&c);

	x=paisagem(paisa,c);

	printf("%d\n",x);
}

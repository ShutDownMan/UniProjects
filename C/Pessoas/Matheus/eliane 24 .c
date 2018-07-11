#include<stdio.h>

int meu_cu(int a, int b){
	int i,resto,resto2;
	for(i=0;resto > i; a/=10){
		resto=a%10;
	}

	for(i = 0; i < resto2; b/=10) {
		resto2=b%10;
	}
	if (resto == resto2){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
}

int main(){
	int a,aux,b;
	scanf("%d", &aux);
	while (aux--)
	{
		scanf("%d%d", &a,&b);
		meu_cu(a,b);

	}

}
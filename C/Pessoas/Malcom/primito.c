#include <stdio.h>
#include <math.h>

int isprime(int a);

int main(void){
	int a;

	scanf("%d", &a);

	if(isprime(a)){
		printf("eh\n");
	} else {
		printf("nao eh\n");
	}

	return 0;
}

int isprime(int a){
	int i,isp=1;
	for(i=2;i<a && isp;i++){
		isp = (a%i !=0);

	}

	return isp;
}
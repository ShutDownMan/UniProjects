#include <stdio.h>

double x, y;

int main () {
	
	scanf("%lf%lf", &x, &y);
	if (y>0 && x!=0){
		if(x>0){
			printf("Q1\n");
		}
		else{
			printf("Q2\n");
		}
	}
	if (y<0 && x!=0){
		if(x>0){
			printf("Q4\n");
		}
		else{
			printf("Q3\n");
		}
		
	}
	if(x==0 && y!=0){
		printf("Eixo Y\n");
	}
	if (y==0 && x!=0){
		printf("Eixo X\n");
	}
	
	if(x == 0 && y == 0){
		printf("Origem\n");
	}
return 0;	
}
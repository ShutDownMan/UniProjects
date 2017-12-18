#include <stdio.h>
#include <math.h>

#define false 0
#define true 1

int main (){
	
	double a;
	int b;
	
	b = false;
	
	scanf ( "%lf", &a);
	
	if (0<=a && a<=25){
		b = true;
		printf("Intervalo [0,25]\n");
	}
	
	if (25<a && a<=50){
		b = true;
		printf("Intervalo (25,50]\n");
	}
	
	if (50<a && a<=75){
		b =  true;
		printf("Intervalo (50,75]\n");
	}
	
	if (75<a && a<=100){
		b = true;
		printf("Intervalo (75,100]\n");
	}
	
	
	if (b!=true) {
		
		printf("Fora de intervalo\n");
	}
return 0;
}
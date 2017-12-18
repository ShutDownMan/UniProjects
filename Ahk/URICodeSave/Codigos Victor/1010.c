#include <stdio.h>

double a[6];
int i;

int main (){
	
	for (i = 0; i < 6; i++){
	
		scanf( "%lf", &a[i]);	
	}

/*	for (i = 0; i < 6; i++){
	
			printf ("%.2lf\n ", a[i]);
	}
*/	
	printf( "VALOR A PAGAR: R$ %.2lf\n", a[1] * a[2] + a[4] * a[5]);

return 0;
}
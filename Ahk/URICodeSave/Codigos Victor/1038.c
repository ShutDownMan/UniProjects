#include <stdio.h>
#include <math.h>

int main (){
	
	int a, b;
	
	scanf ( "%d%d", &a, &b);
	
	if (a==1){

		printf("Total: R$ %.2lf\n", b*4.00);
	}
	
	if (a==2){

		printf("Total: R$ %.2lf\n", b*4.5);
	}
	
	if (a==3){

		printf("Total: R$ %.2lf\n", b*5.0);
	}
	
	if (a==4){

		printf("Total: R$ %.2lf\n", b*2.0);
	}
	
	
	if (a==5) {
		
		printf("Total: R$ %.2lf\n", b*1.5);
	}
return 0;
}
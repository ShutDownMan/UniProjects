#include <stdio.h>

int main () {
   int a;
   
	scanf("%d", &a);
	
	
	
	printf ("%d ano(s)\n%d mes(es)\n%d dia(s)\n", a/365, (a%365)/30, a%365%30 );

	
   return 0;
	
}
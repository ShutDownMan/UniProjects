#include <stdio.h>
#include <math.h>
int main () {
   int a[4], i;   
        
    for (i = 0; i < 3 ; i++){
    	
 		 scanf("%d", &a[i]);
 		 
 		 if (a[4] < a[i])
 		 	a[4] = a[i];
	}
	 	
	printf ("%d eh o maior\n", a[4]);
 
   return 0;
}
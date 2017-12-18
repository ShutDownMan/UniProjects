#include <stdio.h>
#include <math.h>
int main () {

   double a, b, c;   
        
 		 scanf("%lf%lf%lf", &a, &b, &c);
   

      printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", a * c / 2, 3.14159 * pow (c , 2), (a + b) / 2 * c, pow (b , 2), a * b  );
 
   return 0;
}
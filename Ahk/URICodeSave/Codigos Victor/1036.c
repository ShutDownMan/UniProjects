#include <stdio.h>
#include <math.h>

int main (){
	
	double a, b, c, d;
	
	scanf ( "%lf%lf%lf", &a, &b, &c);
	
	d = pow(b,2) - 4*a*c;
	
	if (d<0 || a==0)
	{
		printf("Impossivel calcular\n");
	}

	else
	{
		printf("R1 = %.5lf\nR2 = %.5lf\n", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
	}

return 0;
}
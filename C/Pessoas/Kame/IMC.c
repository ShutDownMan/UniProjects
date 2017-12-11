#include <stdio.h>

int main()
{
	float imc, p, a;
	printf("Entre com um peso e altura\n");
	scanf("%f%f", &p, &a);
	imc=p/(a*a);
	printf("IMC = %.3f\n", imc);
	return 0;
}
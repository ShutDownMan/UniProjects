#include <stdio.h>
#include <math.h>

void sort(double * a, double * b);

int main()
{
	double input[3];

	scanf("%lf %lf %lf", &input[0], &input[1], &input[2]);

	sort(&input[0], &input[1]);
	sort(&input[1], &input[2]);
	sort(&input[0], &input[1]);

	if(input[0] >= input[1] + input[2])
	{
		printf("NAO FORMA TRIANGULO\n");
		return 0;
	}

	if(pow(input[0], 2) == pow(input[1], 2) + pow(input[2], 2))
	{
		printf("TRIANGULO RETANGULO\n");
	}

	if(pow(input[0], 2) > pow(input[1], 2) + pow(input[2], 2))
	{
		printf("TRIANGULO OBTUSANGULO\n");
	}

	if(pow(input[0], 2) < pow(input[1], 2) + pow(input[2], 2))
	{
		printf("TRIANGULO ACUTANGULO\n");
	}

	if(input[0] == input[1] && input[1] == input[2]){
		printf("TRIANGULO EQUILATERO\n");
	}
	else
	{
		if((input[0] == input[1]) || (input[0] == input[2]) || (input[1] == input[2])){
			printf("TRIANGULO ISOSCELES\n");
		}
	}

	return 0;

}

void sort(double * a, double* b){
	if(*a > *b){
		return;
	}

	double c = *a;
	*a = *b;
	*b = c;
}
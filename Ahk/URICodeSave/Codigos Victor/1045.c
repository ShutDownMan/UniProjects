#include <stdio.h>
#include <math.h>

int main (){

	double sides[3];
	int i;

	for (i=0; i < 3; ++i)
	{
		scanf(" %lf", &sides[i]);
	}

	for (int n=0; n < 3; ++n)
	{
		for ( i=0; i < 2; ++i)
		{
			while(sides[i]<sides[i+1])
			{
				double swap;

				swap = sides[i+1];

				sides[i+1] = sides[i];

				sides[i] = swap;
			}
		}
	}
	if (sides[0] >= sides[2] + sides[1])
	{
		printf("NAO FORMA TRIANGULO\n");
	}
	else
	{

		if (pow(sides[0],2) == pow(sides[2],2) + pow(sides[1],2))
		{
			printf("TRIANGULO RETANGULO\n");
		}

		if (pow(sides[0],2) > pow(sides[2],2) + pow(sides[1],2))
		{
			printf("TRIANGULO OBTUSANGULO\n");
		}

		if (pow(sides[0],2) < pow(sides[2],2) + pow(sides[1],2))
		{
			printf("TRIANGULO ACUTANGULO\n");
		}

		if (sides[0] == sides[1] && sides[1] == sides[2])
		{
			i=1;
			printf("TRIANGULO EQUILATERO\n");
		}

		if (sides[0] == sides[2] && i != 1 || sides[2] == sides[1] && i != 1  || sides[1] == sides[0] && i != 1)
		{
			printf("TRIANGULO ISOSCELES\n");
		}
	}

	return 0;
}
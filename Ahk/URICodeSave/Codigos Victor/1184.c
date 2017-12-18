#include <stdio.h>
#include <math.h>

void scanner();
double operate(char operation);

double matrix[12][12];

int main ()
{
	char operation;

	scanf("%c", &operation);

	scanner();
	printf("%.1lf\n", operate(operation));
}

void scanner()
{
	int i, j;
	for (i = 0; i < 12; ++i)
	{
		for ( j = 0; j < 12; ++j)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}
}
double operate(char operation)
{
	double sum = 0;
	int i, j, d = 0;
	for ( i = 0; i < 12; ++i)
	{
		for ( j = i+1  ; j < 12; ++j)
		{
			sum += matrix[j][i];
			d++;
		}
	}
	if(operation == 'S') return sum;
	return sum/d;
}
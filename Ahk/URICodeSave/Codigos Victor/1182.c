#include <stdio.h>
#include <math.h>

void scanner();
double operate(char operation, int column);

double matrix[12][12];

int main ()
{
	int column;
	char operation;

	scanf("%d %c", &column, &operation);

	scanner();
	printf("%.1lf\n", operate(operation, column));
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
double operate(char operation, int column)
{
	double sum = 0;
	int i;
	for ( i = 0; i < 12; ++i)
	{
		sum += matrix[i][column];
	}
	if(operation == 'S') return sum;
	return sum/12;
}